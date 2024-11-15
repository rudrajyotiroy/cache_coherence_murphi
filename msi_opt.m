
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
---- 3-hop MSI protocol, coarse-vector representation (Page 180(158) of book)

----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------
const
	ProcCount: 3;          -- number processors
	ValueCount:   2;       -- number of data values.
	numVCs:	3;
	QMax: 2;
	NumVCs: 3;
	NetMax: ProcCount+10;
	enableProcTrace: 0;
	enableMsgTrace: 0;
  maxMsgs: enableMsgTrace*100 + 2;

----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type
	Proc: scalarset(ProcCount);   -- unordered range of processors
	Value: scalarset(ValueCount); -- arbitrary values for tracking coherence
	Home: enum { HomeDir };
	Node: union { Home , Proc };
	VCType: 0..NumVCs-1;
  counter_t: 0..maxMsgs-1;
	AckCount:	(1-ProcCount)..ProcCount-1; -- Negative values for debugging only
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
      mid: counter_t; -- debug purpose
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
										-- MX_D = Dir_M get_S forwarded, waiting for data to go to S or I depending on ack>0
                    Dir_MX_D,
										-- MM_D = Dir_M get_M forwarded, waiting for ack to change owner
										Dir_MM_A,
										-- SM_A = Dir_S get_M invalidations sent, waiting for acks
										Dir_SM_A
                  };
      owner: Node;	-- Assuming has only one memory location
      val: Value;   -- Assuming has only one memory location
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
      val: Value;
			ack_cnt: AckCount;
    End;


----------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------
var
	HomeNode:  HomeState;
	Procs: array [Proc] of ProcState;
	Net:   array [Node] of multiset [NetMax] of Message;  -- One multiset for each destination - messages are arbitrarily reordered by the multiset
	InBox: array [Node] of array [channel_t] of Message; -- If a message is not processed, it is placed in InBox, blocking that virtual channel
	msg_processed: boolean;
  running_msgid: counter_t;
	LastWrite: Value; -- Used to confirm that writes are not lost; this variable would not exist in real hardware

----------------------------------------------------------------------
-- Procedures
----------------------------------------------------------------------
Procedure MsgEnumToStr(m: MessageType);
begin
  switch m
    case GetS: put "GetS";
    case GetM: put "GetM";
    case PutS: put "PutS";
    case PutM: put "PutM";
    case Data: put "Data";
    case InvAck: put "InvAck";
    case PutAck: put "PutAck";
    case FwdAck: put "FwdAck";
    case Inv: put "Inv";
    case FwdGetS: put "FwdGetS";
    case FwdGetM: put "FwdGetM";
  else
    put "Unknown MessageType";
  end;
end;

procedure NodeEnumToStr(n: Node);
begin
  if IsMember(n, Proc) then
    -- Node is a processor
    switch Procs[n].state
      case Proc_M: put "Proc_M";
      case Proc_S: put "Proc_S";
      case Proc_I: put "Proc_I";
      case Proc_IS_D: put "Proc_IS_D";
      case Proc_IM_A: put "Proc_IM_A";
      case Proc_IM_AD: put "Proc_IM_AD";
      case Proc_II_A: put "Proc_II_A";
      case Proc_SM_A: put "Proc_SM_A";
      case Proc_SM_AD: put "Proc_SM_AD";
      case Proc_SI_A: put "Proc_SI_A";
      case Proc_MI_A: put "Proc_MI_A";
    else
      put "Unknown ProcState";
    end;
    else
    -- Node is the HomeNode
    switch HomeNode.state
      case Dir_M: put "Dir_M";
      case Dir_S: put "Dir_S";
      case Dir_I: put "Dir_I";
      case Dir_MX_D: put "Dir_MX_D";
      case Dir_MM_A: put "Dir_MM_A";
      case Dir_SM_A: put "Dir_SM_A";
    else
      put "Unknown HomeState";
    end;
  end;
end;

Procedure msgTrace(mid:counter_t;
         mtype:MessageType;
				 dst:			Node;
				 src:			Node;
				 vc:			channel_t;
				 val:			Value;
				 fwd_to:  Node;
         ack_cnt: AckCount;
         );
  if enableMsgTrace=1 then
		put "Msg ";
    put mid;
    put ":: type: ";
		MsgEnumToStr(mtype);
		put ", src: ";
		put src;
		put ", dst: ";
		put dst;
		put ", ack_cnt: ";
		put ack_cnt;
    put ", src_state: ";
    NodeEnumToStr(src);
    put ", dst_state: ";
    NodeEnumToStr(dst);
		if(!isundefined(fwd_to)) then
			put ", fwd_to: ";
			put fwd_to;
		endif;
		if(!isundefined(val)) then
			put ", val: ";
			put val;
		endif;
		put "\n";
	endif;
End;


Procedure Send(mtype:MessageType;
				 dst:			Node;
				 src:			Node;
				 vc:			channel_t;
				 val:			Value;
				 fwd_to:  Node;
         ack_cnt: AckCount;
				 );
var msg:Message;
var 
Begin
	Assert (MultiSetCount(i:Net[dst], true) < NetMax) "Too many messages";
  if(enableMsgTrace=1) then
    put " Create ";
  endif;
  msg.mid   := running_msgid;
  if(running_msgid = (maxMsgs-1)) then
    running_msgid := 0;
  end;
  running_msgid :=  running_msgid + 1;
	msgTrace(msg.mid, mtype, dst, src, vc, val, fwd_to, ack_cnt);
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

Function IsSharerListEmpty() : Boolean;
Begin
  return MultiSetCount(i: HomeNode.sharers, true) = 0
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
	if(enableProcTrace=1) then
		put "Receiving "; put msg.mtype; put " from processor "; put msg.src; put " on "; put msg.vc; 
		put " at home -- "; put HomeNode.state;
		if(msg.mtype = InvAck) then
			put " -- ";
			put HomeNode.ack_cnt;
		endif;
	endif;

	-- The line below is not needed in Valid/Invalid protocol.  However, the 
	-- compiler barfs if we put this inside a switch, so it is useful to
	-- pre-calculate the sharer count here
	sharerCount := MultiSetCount(i:HomeNode.sharers, true);


	-- default to 'processing' message.  set to false otherwise
	msg_processed := true;

	switch HomeNode.state
	case Dir_I:
		switch msg.mtype
    case GetS:
			-- Send data to Req, add Req to Sharer/S
      HomeNode.state := Dir_S;
      AddToSharersList(msg.src);
      Send(Data, msg.src, HomeDir, ResponseChannel, HomeNode.val, UNDEFINED, 0);
		case GetM:
			-- Send data to Req, set Owner to Req/M
			HomeNode.state := Dir_M;
			HomeNode.owner := msg.src;
			Send(Data, msg.src, HomeDir, ResponseChannel, HomeNode.val, UNDEFINED, sharerCount);
		case PutS:
			-- Send Put-Ack 
			Send(PutAck, msg.src, HomeDir, ResponseChannel, UNDEFINED, UNDEFINED, 0);
		case PutM:
			-- From NonOwner, Send Put-Ack
			assert (msg.src != HomeNode.owner) "error at Dir_I: PutM from owner";
			Send(PutAck, msg.src, HomeDir, ResponseChannel, UNDEFINED, UNDEFINED, 0);
		else
			ErrorUnhandledMsg(msg, HomeDir);
		endswitch;

  case Dir_S:
    assert !IsSharerListEmpty() "sharerCount == 0"; --TODO move to invariant
    switch msg.mtype
    case GetS:
			-- Send data to Req, add Req to Sharers
      AddToSharersList(msg.src);
      Send(Data, msg.src, HomeDir, ResponseChannel, HomeNode.val, UNDEFINED, 0);
		case GetM:
			-- Send data to Req, send Inv to Sharers, clear Sharers, set Owner to Req/M
      if IsSharer(msg.src) then
				-- If req is only sharer, directly jump to M, else wait in SM_A for ack from all sharers to invalidate
        if sharerCount = 1 then
          HomeNode.state := Dir_M;
        else
          HomeNode.state := Dir_SM_A;
          HomeNode.ack_cnt := sharerCount - 1; -- Current node will not invalidate
          SendInvReqToSharers(msg.src);
        endif;
        Send(Data, msg.src, HomeDir, ResponseChannel, HomeNode.val, UNDEFINED, sharerCount - 1);
      else
				-- if req is not a current sharer
        HomeNode.state := Dir_SM_A;
        HomeNode.ack_cnt := sharerCount; -- current node will also invalidate
        SendInvReqToSharers(msg.src);
        Send(Data, msg.src, HomeDir, ResponseChannel, HomeNode.val, UNDEFINED, sharerCount);
      endif;
      undefine HomeNode.sharers;
			HomeNode.owner := msg.src;
		case PutS:
			-- Remove Req from Sharers, sent Put-Ack to Req
			Send(PutAck, msg.src, HomeDir, ResponseChannel, UNDEFINED, UNDEFINED, 0); 
      RemoveFromSharersList(msg.src);
      if IsSharerListEmpty() then
				-- PutS last, invalid
        HomeNode.state := Dir_I;
      endif;
		case PutM:
			-- Remove Req from Sharers, sent Put-Ack to Req
			Send(PutAck, msg.src, HomeDir, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      RemoveFromSharersList(msg.src);
      if IsSharerListEmpty() then
        HomeNode.state := Dir_I;
      endif;
		else
			ErrorUnhandledMsg(msg, HomeDir);
		endswitch;

  case Dir_M:
    switch msg.mtype
    case GetS:
			-- Send Fwd-GetS to Owner, add Req and Owner to Sharers, clear Owner/MX_D
      HomeNode.state := Dir_MX_D;
      Send(FwdGetS, HomeNode.owner, HomeDir, ForwardChannel, UNDEFINED, msg.src, 0);
      AddToSharersList(msg.src);
      AddToSharersList(HomeNode.owner);
      undefine HomeNode.owner;
    case GetM:
			-- Send Fwd-GetM to Owner, set owner to Req/MM_A
      HomeNode.state := Dir_MM_A;
      Send(FwdGetM, HomeNode.owner, HomeDir, ForwardChannel, UNDEFINED, msg.src, 0);
      HomeNode.owner := msg.src;
    case PutS:
			-- Send PutAck to req
      Send(PutAck, msg.src, HomeDir, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case PutM:
			-- Copy data to memory, clear Owner, send Put-Ack to Req/I
      if HomeNode.owner = msg.src then
        HomeNode.val := msg.val;
        undefine HomeNode.owner;
        HomeNode.state := Dir_I;
      endif;
      Send(PutAck, msg.src, HomeDir, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    else
      ErrorUnhandledMsg(msg, HomeDir);
    endswitch;

  case Dir_MX_D:
    switch msg.mtype
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case FwdAck:
      -- FwdAck+Data indicates that the FwdGetS has reached the target node
      HomeNode.state := Dir_S;
      HomeNode.val := msg.val;
    case Data:
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg, HomeDir);
    endswitch;
  
  case Dir_MM_A:
    switch msg.mtype
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case Data:
      msg_processed := false;
    case FwdAck:
      -- FwdAck+Data indicates that the FwdGetS has reached the target node
      HomeNode.state := Dir_M;
      HomeNode.val := msg.val;
    else
      ErrorUnhandledMsg(msg, HomeDir);
    endswitch;

  case Dir_SM_A:
    switch msg.mtype
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case Data:
      msg_processed := false;
    case InvAck:
			-- After all inv-acks received, reset 
      HomeNode.ack_cnt := HomeNode.ack_cnt - 1;
      if HomeNode.ack_cnt = 0 then
        HomeNode.state := Dir_M;
      endif;
    else
      ErrorUnhandledMsg(msg, HomeDir);
    endswitch;

  endswitch;
End;


Procedure ProcReceive(msg:Message; p:Proc);
Begin

	-- default to 'processing' message.  set to false otherwise
	msg_processed := true;

	alias pstate:Procs[p].state do
	alias pval:Procs[p].val do
	alias pcnt:Procs[p].ack_cnt do

	if(enableProcTrace=1) then
 		put "Receiving "; put msg.mtype; put " from "; put msg.src; put " on "; put msg.vc; 
 		put " at proc "; put p; put "\n";
		if(msg.mtype = InvAck) then
			put " -- ";
			put pcnt;
		endif;
	endif;

	switch pstate
  case Proc_I:
      -- Should not get external messages in this state
      ErrorUnhandledMsg(msg, p);

  case Proc_IS_D:
    switch msg.mtype
    case Inv:
      msg_processed := false;
    case Data:
      -- Update val, Move to S, increment ack_cnt
      assert msg.ack_cnt = 0 "Error at Proc_IS_D, ack_cnt must be 0 since no modify request";
      pstate := Proc_S;
      pval := msg.val;
      pcnt := pcnt + msg.ack_cnt;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_IM_AD:
    switch msg.mtype
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case Data:
      if msg.src = HomeDir then -- data is from directory controller
        assert (pcnt <= 0) "error at Proc_IM_AD, ack_cnt > 0."; -- Can be negative upto msg.ack_cnt
        pcnt :=  pcnt + msg.ack_cnt;
        assert (pcnt >= 0) "error at Proc_IM_AD, ack_cnt < 0."; 
        if pcnt = 0 then
          -- No sharers left to ack, move to Proc_M
          pstate := Proc_M;
          LastWrite := pval;
        else
          -- Wait for ack in IM_A
          pstate := Proc_IM_A;
        endif;
      else -- data is from previous owner
        -- update value and move to M
        pstate := Proc_M;
        LastWrite := pval;
      endif;
    case InvAck:
      -- decrement pending InvAck count (if all received, it will be resolved on getting data)
      pcnt := pcnt - 1;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_IM_A:
    switch msg.mtype
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case InvAck:
      -- decrement pending InvAck count, data might have been received already
      pcnt := pcnt - 1;
      if pcnt = 0 then
        pstate := Proc_M;
        LastWrite := pval;
      endif;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_S:
    switch msg.mtype
    case Inv:
      -- Send InvAck to req (and homedir)/I
      pstate := Proc_I;
      Send(InvAck, msg.fwd_to, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(InvAck, HomeDir, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      undefine pval;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_SM_AD:
    switch msg.mtype
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case Inv:
      -- Send InvAck to req (and homedir)/IM_AD
      pstate := Proc_IM_AD;
      Send(InvAck, msg.fwd_to, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(InvAck, HomeDir, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case Data:
      assert (msg.src = HomeDir) "error at Proc_SM_AD, Data not from dir.";
      if msg.ack_cnt = 0 then
        pstate := Proc_M;
        LastWrite := pval;
      else
        assert (pcnt <= 0) "error at Proc_SM_AD, ack_cnt > 0.";
        pcnt :=  pcnt + msg.ack_cnt;
        assert (pcnt >= 0) "error at Proc_SM_AD, ack_cnt < 0.";
        if pcnt = 0 then
          -- All acks were already received
          pstate := Proc_M;
          LastWrite := pval; --update lastwrite event
        else
          -- Acks remaining
          pstate := Proc_SM_A;
        endif;
      endif;
    case InvAck:
      -- assert (pcnt = 0) "error at Proc_SM_AD, ack_cnt == 0."; -- Can go negative
      pcnt := pcnt - 1;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_SM_A:
    switch msg.mtype
    case FwdGetS:
      msg_processed := false;
    case FwdGetM:
      msg_processed := false;
    case InvAck:
      -- Move to M/update lastwrite
      pcnt := pcnt - 1;
      if pcnt = 0 then
        pstate := Proc_M;
        LastWrite := pval;
      endif;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_M:
    switch msg.mtype
    case FwdGetS:
      -- Send data to req and FwdAck to home, downgrade to S
      pstate := Proc_S;
      Send(FwdAck, HomeDir,  p, ResponseChannel, pval, UNDEFINED, 0);
      Send(Data, msg.fwd_to, p, ResponseChannel, pval, UNDEFINED, 0);
    case FwdGetM:
      -- Send data to req and FwdAck to home, downgrade to I
      pstate := Proc_I;
      Send(Data, msg.fwd_to, p, ResponseChannel, pval, UNDEFINED, 0);
      Send(FwdAck, HomeDir,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      undefine pval;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_MI_A:
    switch msg.mtype
    case FwdGetS:
      -- Send data to req and FwdAck to home, downgrade to SI_A
      pstate := Proc_SI_A;
      Send(FwdAck, HomeDir,  p, ResponseChannel, pval, UNDEFINED, 0);
      Send(Data, msg.fwd_to, p, ResponseChannel, pval, UNDEFINED, 0);
    case FwdGetM:
      -- Send data to req and FwdAck to home, downgrade to MI_A
      pstate := Proc_II_A;
      Send(Data, msg.fwd_to, p, ResponseChannel, pval, UNDEFINED, 0);
      Send(FwdAck, HomeDir,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case PutAck:
      -- Move to I
      pstate := Proc_I;
      undefine pval;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_SI_A:
    switch msg.mtype
    case Inv:
      -- Move to II_A, send InvAck to Home and req
      pstate := Proc_II_A;
      Send(InvAck, msg.fwd_to,  p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
      Send(InvAck, HomeDir, p, ResponseChannel, UNDEFINED, UNDEFINED, 0);
    case PutAck:
      -- Move to I
      pstate := Proc_I;
      undefine pval;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case Proc_II_A:
    switch msg.mtype
    case PutAck:
      -- Move to I
      pstate := Proc_I;
      undefine pval;
    else
      ErrorUnhandledMsg(msg,  p);
    endswitch;

	----------------------------
	-- Error catch
	----------------------------
	else
		ErrorUnhandledState();

	endswitch;
	
	endalias;
	endalias;
	endalias;
End;

----------------------------------------------------------------------
-- Rules
----------------------------------------------------------------------

-- Processor actions (affecting coherency) - spontaneous state transitions
ruleset n: Proc Do
  alias p: Procs[n] Do

    rule "M ==(evict)==> I"
      p.state = Proc_M
    ==>
      p.state := Proc_MI_A;
      if(enableMsgTrace=1) then
        put "M ==(evict)==> I";
      endif;
      Send(PutM, HomeDir, n, RequestChannel, p.val, UNDEFINED, 0);
    endrule;

    rule "S ==(evict)==> I"
      p.state = Proc_S
    ==>
      p.state := Proc_SI_A;
      if(enableMsgTrace=1) then
        put "S ==(evict)==> I";
      endif;
      Send(PutS, HomeDir, n, RequestChannel, UNDEFINED, UNDEFINED, 0);
    endrule;

    ruleset v: Value Do
      rule "S ==(store)==> M"
        p.state = Proc_S
      ==>
        p.state := Proc_SM_AD;
        if(enableMsgTrace=1) then
          put "S ==(store)==> M";
        endif;
        p.val := v;      
        Send(GetM, HomeDir, n, RequestChannel, UNDEFINED, UNDEFINED, 0);
      endrule;
    endruleset;

    ruleset v: Value Do
      rule "I ==(store)==> M"
        p.state = Proc_I
      ==>
        p.state := Proc_IM_AD;
        if(enableMsgTrace=1) then
          put "I ==(store)==> M";
        endif;
        p.val := v;      
        Send(GetM, HomeDir, n, RequestChannel, UNDEFINED, UNDEFINED, 0);
      endrule;
    endruleset;

    rule "I ==(load)==> S"
      p.state = Proc_I 
    ==>
      p.state := Proc_IS_D;
      if(enableMsgTrace=1) then
        put "I ==(load)==> S";
      endif;
      Send(GetS, HomeDir, n, RequestChannel, UNDEFINED, UNDEFINED, 0);
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
      if(enableMsgTrace=1) then
        put "  Receive ";
      endif;
      msgTrace(msg.mid, msg.mtype, n, msg.src, msg.vc, msg.val, msg.fwd_to, msg.ack_cnt);
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
	
		endalias;
		endalias;
		endalias;
	endchoose;  

	-- Try to deliver a message from a blocked VC; perhaps the node can handle it now
	ruleset vc:channel_t do
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

  -- directory node initialization
  HomeNode.state := Dir_I;
  HomeNode.ack_cnt := 0;
  undefine HomeNode.sharers;
	For v:Value do
  	HomeNode.val := v;
	endfor;
	LastWrite := HomeNode.val;
  running_msgid := 0;
  
  -- processor initialization
	-- independent iterations ignore warning
  for i: Proc do
    Procs[i].state := Proc_I;
		Procs[i].ack_cnt := 0;
    undefine Procs[i].val;
  endfor;

  -- network initialization
  undefine Net;
endstartstate;

----------------------------------------------------------------------
-- Invariants
----------------------------------------------------------------------

invariant "Invalid implies empty owner"
	HomeNode.state = Dir_I
		->
			IsUndefined(HomeNode.owner);

invariant "val in memory matches val of last write, when invalid"
		 HomeNode.state = Dir_I 
		->
			HomeNode.val = LastWrite;

invariant "values in valid state match last write"
	Forall n : Proc Do	
		 Procs[n].state = Proc_M | Procs[n].state = Proc_S
		->
			Procs[n].val = LastWrite --LastWrite is updated whenever a new val is created 
	end;
	
invariant "val is undefined while invalid"
	Forall n : Proc Do	
		 Procs[n].state = Proc_I
		->
			IsUndefined(Procs[n].val)
	end;

-- invariant "Proc ackcounts are negative"
-- 	Forall n : Proc Do	
-- 		 !(Procs[n].state = Proc_I)
-- 		->
-- 		 !(Procs[n].ack_cnt < 0)
-- 	end;

-- invariant "Home directory ackcounts are negative"	
-- 	!(HomeNode.state = Dir_I)
-- 		->
-- 	!(HomeNode.ack_cnt < 0)
	
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

invariant "values in memory matches val of last write, when shared or invalid"
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
