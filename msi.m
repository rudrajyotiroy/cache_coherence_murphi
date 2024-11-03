
-- EECS570 PA2
-- Rudrajyoti Roy (rudraroy)

-- Question Assumptions:
---- The interconnect network may reorder messages arbitrarily. No packet loss
---- Multiple lanes, one send and receive port corresponding to each lane
---- Receive port is blocking, send port is non-blocking, unrestricted buffer space but not infinite
---- Each processor has a dedicated cache that is not shared with any other processor. All caches must be kept coherent by your cache coherency protocol. 
---- Processors may issue load and store operations only 
---- Only one storage location (address)
---- For cache conflict, need to model a cache write-back
---- Write-back operations may occur at any time between any pair of load/store operations. 
---- If the cache is in a clean state, you may simply set it to be invalid or take the appropriate action according to your CC protocol.
---- Cache replacements of dirty lines must obviously write the line back to memory.
---- Coherency unit is equal to one word and that all loads and stores read or write the entire word.
---- One memory unit in system, has a directory-based cache-consistency controller which ensures that only one processor can write to the memory block at a time (exclusive-ownership style protocol)
---- The directory representation is unimportant for this assignment. You should assume that you have a full directory (bit vector) that can keep track of all sharers.
---- The interconnect system can send messages from any unit to any other unit. It is OK if your protocol requires that a cache controller has to send a message to another cache controller.
---- Guaruntee Freshness for atleast 3 processors. Loads and stores issued by one processor are seen by that processor in program order.

-- Waypoint Specific:
---- 4-hop MSI protocol, coarse-vector representation

----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------
const
	ProcCount: 3;          -- number processors
	ValueCount:   2;       -- number of data values.
	numVCs:	3;
	QMax: 2;
	NumVCs: 3;
	NetMax: ProcCount+1;
	

----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type
	Proc: scalarset(ProcCount);   -- unordered range of processors
	Value: scalarset(ValueCount); -- arbitrary values for tracking coherence
	Home: enum { HomeDir };
	Node: union { Home , Proc };
	VCType: 0..NumVCs-1;
	AckCount:	0..ProcCount-1;
	channel_t: enum{
						RequestChannel,
						ResponseChannel,
						ForwardChannel
	};

	MessageType: enum {
											-- Request channel
											GetS,
											GetM,
											PutS,
											PutM,
											-- Response channel
											Data,
											InvAck,
											PutAck,
											FwdAck,
											-- Forward channel
											Inv,
											FwdGetS,
											FwdGetM
										};


	Message:
		Record
			mtype: MessageType;
			src: Node;
			-- do not need a destination for verification; the destination is indicated by which array entry in the Net the message is placed
			vc: channel_t;
			val: Value;
			fwd_to: Node;
			ack_cnt: AckCount;  
		End;

	HomeState: -- Directory controller states
    Record
      state: enum {
                    -- Stable states
                    Dir_M,
      							Dir_S,
                    Dir_I,
                    -- Transition states
                    Dir_MX_D,
                    Dir_SM_A,
                    Dir_MM_A
                  };
      owner: Node;	-- Assuming has only one memory location
      value: Value;   -- Assuming has only one memory location
      sharers: multiset [ProcCount] of Node;
      ack_cnt: AckCount;
    End;

  ProcState: -- Cache controller states
    Record
      state: enum {
                    -- Stable states
                    Proc_M,
                    Proc_S,
                    Proc_I,
                    -- Transition states
                    Proc_IS_D,
                    Proc_IM_A,
                    Proc_IM_AD,
                    Proc_II_A,
                    Proc_SM_A,
                    Proc_SM_AD,
                    Proc_SI_A,
                    Proc_MI_A
                  };
      value: Value;
      ack_cnt: AckCount; -- ack_cnt = 0 means don't need extra ack
    End;


----------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------
var
	HomeNode:  HomeState;
	Procs: array [Proc] of ProcState;
	Net:   array [Node] of multiset [NetMax] of Message;  -- One multiset for each destination - messages are arbitrarily reordered by the multiset
	InBox: array [Node] of array [VCType] of Message; -- If a message is not processed, it is placed in InBox, blocking that virtual channel
	msg_processed: boolean;
	LastWrite: Value; -- Used to confirm that writes are not lost; this variable would not exist in real hardware

----------------------------------------------------------------------
-- Procedures
----------------------------------------------------------------------
Procedure Send(mtype:MessageType;
				 dst:Node;
				 src:Node;
				 vc:channel_t;
				 val:Value;
				 fwd_to:  Node;
         ack_cnt: AckCount;
				 );
var msg:Message;
Begin
	Assert (MultiSetCount(i:Net[dst], true) < NetMax) "Too many messages";
	msg.mtype := mtype;
	msg.src   := src;
	msg.vc    := vc;
	msg.val   := val;
	msg.fwd_to  := fwd_to;
  msg.ack_cnt := ack_cnt;
	MultiSetAdd(msg, Net[dst]);
End;

Procedure ErrorUnhandledMsg(msg: Message; n: Node);
Begin
  put "\n====================Error Msg====================\n";
  put "mtype: ";
  put msg.mtype;
  put "\n";
  put "src: ";
  put msg.src;
  put "\n";
  put "src_state: ";
  if IsMember(msg.src, Proc) then
    put Procs[msg.src].state;
  else
    put HomeNode.state;
  endif;
  put "dst_state: ";
  if IsMember(n, Proc) then
    put Procs[n].state;
  else
    put HomeNode.state;
  endif;
  put "\n";
  error "Unhandled message type!";
End;

Procedure ErrorUnhandledState();
Begin
	error "Unhandled state!";
End;


-- These aren't needed for Valid/Invalid protocol, but this is a good way of writing these functions
Procedure AddToSharersList(n:Node);
Begin
	if MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) = 0
	then
		MultiSetAdd(n, HomeNode.sharers);
	endif;
End;

Function IsSharer(n:Node) : Boolean;
Begin
	return MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) > 0
End;

Procedure RemoveFromSharersList(n:Node);
Begin
	MultiSetRemovePred(i:HomeNode.sharers, HomeNode.sharers[i] = n);
End;

-- Sends a message to all sharers except rqst
Procedure SendInvReqToSharers(rqst:Node);
Begin
	for p : Proc do
    if IsSharer(p) & p != rqst then
      Send(Inv, p, HomeDir, ForwardChannel, UNDEFINED, rqst, 0);
    endif;
  endfor;
End;



Procedure HomeReceive(msg:Message);
var sharerCount:0..ProcCount;  -- for counting sharers
Begin
	-- Debug output may be helpful:
	put "Receiving "; put msg.mtype; put " on VC "; put msg.vc; 
	put " at home -- "; put HomeNode.state;

	-- The line below is not needed in Valid/Invalid protocol.  However, the 
	-- compiler barfs if we put this inside a switch, so it is useful to
	-- pre-calculate the sharer count here
	sharerCount := MultiSetCount(i:HomeNode.sharers, true);


	-- default to 'processing' message.  set to false otherwise
	msg_processed := true;

	switch HomeNode.state
	case H_Invalid:
		switch msg.mtype

		case ReadReq:
			HomeNode.state := H_Valid;
			HomeNode.owner := msg.src;
			Send(ReadAck, msg.src, HomeType, VC1, HomeNode.val);

		else
			ErrorUnhandledMsg(msg, HomeType);

		endswitch;

	case H_Valid:
		Assert (IsUndefined(HomeNode.owner) = false) 
			 "HomeNode has no owner, but line is Valid";

		switch msg.mtype
		case ReadReq:
			HomeNode.state := HT_Pending;     
			Send(RecallReq, HomeNode.owner, HomeType, VC0, UNDEFINED);
			HomeNode.owner := msg.src; --remember who the new owner will be
						
		case WBReq:
			assert (msg.src = HomeNode.owner) "Writeback from non-owner";
			HomeNode.state := H_Invalid;
			HomeNode.val := msg.val;
			Send(WBAck, msg.src, HomeType, VC1, UNDEFINED);
			undefine HomeNode.owner

		else
			ErrorUnhandledMsg(msg, HomeType);

		endswitch;

	case HT_Pending:
		switch msg.mtype
	 
		case WBReq:
			Assert (!IsUnDefined(HomeNode.owner)) "owner undefined";
			HomeNode.state := H_Valid;
			HomeNode.val := msg.val;
			Send(ReadAck, HomeNode.owner, HomeType, VC1, HomeNode.val);

		case ReadReq:
			msg_processed := false; -- stall message in InBox

		else
			ErrorUnhandledMsg(msg, HomeType);

		endswitch;
	endswitch;
End;


Procedure ProcReceive(msg:Message; p:Proc);
Begin
--  put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
--  put " at proc "; put p; put "\n";

	-- default to 'processing' message.  set to false otherwise
	msg_processed := true;

	alias ps:Procs[p].state do
	alias pv:Procs[p].val do

	switch ps
	case P_Valid:

		switch msg.mtype
		case RecallReq:
			Send(WBReq, msg.src, p, VC1, pv);
			Undefine pv;
			ps := P_Invalid;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	case PT_Pending:

		switch msg.mtype
		case ReadAck:
			pv := msg.val;
			ps := P_Valid;
		case RecallReq:
			msg_processed := false; -- stall message in InBox
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;


	case PT_WritebackPending:    

		switch msg.mtype
		case WBAck:
			ps := P_Invalid;
			undefine pv;
		case RecallReq:				-- treat a recall request as a Writeback acknowledgement
			ps := P_Invalid;
			undefine pv;
		else
			ErrorUnhandledMsg(msg, p);
		endswitch;

	----------------------------
	-- Error catch
	----------------------------
	else
		ErrorUnhandledState();

	endswitch;
	
	endalias;
	endalias;
End;

----------------------------------------------------------------------
-- Rules
----------------------------------------------------------------------

-- Processor actions (affecting coherency)

ruleset n:Proc Do
	alias p:Procs[n] Do

	ruleset v:Value Do
		rule "store new value"
	 	 (p.state = P_Valid)
			==>
 			 p.val := v;      
 			 LastWrite := v;  --We use LastWrite to sanity check that reads receive the value of the last write
		endrule;
	endruleset;

	rule "read request"
		p.state = P_Invalid 
	==>
		Send(ReadReq, HomeType, n, VC0, UNDEFINED);
		p.state := PT_Pending;
	endrule;


	rule "writeback"
		(p.state = P_Valid)
	==>
		Send(WBReq, HomeType, n, VC1, p.val); 
		p.state := PT_WritebackPending;
		undefine p.val;
	endrule;

	endalias;
endruleset;

-- Message delivery rules
ruleset n:Node do
	choose midx:Net[n] do
		alias chan:Net[n] do
		alias msg:chan[midx] do
		alias box:InBox[n] do

		-- Pick a random message in the network and delivier it
		rule "receive-net"
			(isundefined(box[msg.vc].mtype))
		==>

			if IsMember(n, Home)
			then
				HomeReceive(msg);
			else
				ProcReceive(msg, n);
			endif;

			if ! msg_processed
			then
				-- The node refused the message, stick it in the InBox to block the VC.
				box[msg.vc] := msg;
			endif;
		
			MultiSetRemove(midx, chan);
		
		endrule;
	
		endalias
		endalias;
		endalias;
	endchoose;  

	-- Try to deliver a message from a blocked VC; perhaps the node can handle it now
	ruleset vc:VCType do
		rule "receive-blocked-vc"
			(! isundefined(InBox[n][vc].mtype))
		==>
			if IsMember(n, Home)
			then
				HomeReceive(InBox[n][vc]);
			else
				ProcReceive(InBox[n][vc], n);
			endif;

			if msg_processed
			then
				-- Message has been handled, forget it
				undefine InBox[n][vc];
			endif;
		
		endrule;
	endruleset;

endruleset;

----------------------------------------------------------------------
-- Startstate
----------------------------------------------------------------------
startstate

	For v:Value do
	-- home node initialization
	HomeNode.state := H_Invalid;
	undefine HomeNode.owner;
	HomeNode.val := v;
	endfor;
	LastWrite := HomeNode.val;
	
	-- processor initialization
	for i:Proc do
		Procs[i].state := P_Invalid;
		undefine Procs[i].val;
	endfor;

	-- network initialization
	undefine Net;
endstartstate;

----------------------------------------------------------------------
-- Invariants
----------------------------------------------------------------------

invariant "Invalid implies empty owner"
	HomeNode.state = H_Invalid
		->
			IsUndefined(HomeNode.owner);

invariant "value in memory matches value of last write, when invalid"
		 HomeNode.state = H_Invalid 
		->
			HomeNode.val = LastWrite;

invariant "values in valid state match last write"
	Forall n : Proc Do	
		 Procs[n].state = P_Valid
		->
			Procs[n].val = LastWrite --LastWrite is updated whenever a new value is created 
	end;
	
invariant "value is undefined while invalid"
	Forall n : Proc Do	
		 Procs[n].state = P_Invalid
		->
			IsUndefined(Procs[n].val)
	end;
	
/*	
-- Here are some invariants that are helpful for validating shared state.

invariant "modified implies empty sharers list"
	HomeNode.state = H_Modified
		->
			MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "Invalid implies empty sharer list"
	HomeNode.state = H_Invalid
		->
			MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "values in memory matches value of last write, when shared or invalid"
	Forall n : Proc Do	
		 HomeNode.state = H_Shared | HomeNode.state = H_Invalid
		->
			HomeNode.val = LastWrite
	end;

invariant "values in shared state match memory"
	Forall n : Proc Do	
		 HomeNode.state = H_Shared & Procs[n].state = P_Shared
		->
			HomeNode.val = Procs[n].val
	end;
*/	
