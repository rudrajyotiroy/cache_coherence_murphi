-- EECS570 PA2 Waypoint 1 (28/10/24)
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
---- 4-hop MOSI protocol, coarse-vector representation

----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------

const
    numProc:    3;      -- number of processors
    numDir:     1;      -- number of directories
    queueLen:   10;     -- maximum length of each queue at controller
	ValueCount: 2;      -- number of data values
    verbosity:  1;      -- set verbosity level
----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type

    -- Node ID 0 to (numDir - 1) for directories
    -- Node ID numDIr to (numDir + numProc - 1) for processors
    node_n:    	0..(numProc + numDir-1);
	value_t: 	scalarset(ValueCount); -- arbitrary values for tracking coherence
    
    -- Types of channel
    channel_t: enum {
        req,
        resp,
        fwd
    };

    -- Request channel
    mtype_req_t: enum {
        GetS,
        GetM,
        PutS,
        PutM
    };

    -- Response channel
    mtype_resp_t: enum {
        DataAck,
        InvAck,
        PutAck,
        FwdAck
    };

    -- Forward channel
    mtype_fwd_t: enum {
        Inv,
        FwdGetS,
        FwdGetM
    };

    -- Define state-space for messages
    mtype_t: union { mtype_req_t, mtype_resp_t, mtype_fwd_t };

    proc_state_t: enum {
        -- Stable states
        Proc_M,
        Proc_O,
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
        Proc_MI_A,
        Proc_OM_AC,
        Proc_OM_A,
        Proc_OI_A
    };

    dir_state_t: enum {
        -- Stable states
        Dir_M,
        Dir_O,
        Dir_S,
        Dir_I
        -- Transition states
    };

    ops_t: enum {
        -- Spontaneous operations at cache-controller level
        load,
        store,
        evict,
        serve_req_queue,
        serve_resp_queue,
        serve_ack_queue
    };

    -- Define each message data-structure
    message_t:
    Record
        mtype:  mtype_t;
		value:	value_t;
        src:    node_n; -- Source node number
        dest:   node_n; -- Destination node number
        fwdTo:  node_n; -- Forwarding node number
        numAck: node_n; -- Max number of acks (0 for no ack)
    End;

    -- Define each processor cache controller
    proc_t:
    Record
        state:      proc_state_t;
        value:      value_t;
        isStalled:  boolean;
        req_queue:  multiset[queueLen] of message_t; 
        resp_queue: multiset[queueLen] of message_t; 
        fwd_queue:  multiset[queueLen] of message_t; 
    End;

    -- Define each directory controller
    dir_t:
    Record
        state:      dir_state_t;
        value:      value_t;
		owner:		node_n;
        sharers:    array [0..(numProc + numDir-1)] of boolean; -- Coarse vector
        req_queue:  multiset[queueLen] of message_t; 
        resp_queue: multiset[queueLen] of message_t; 
        fwd_queue:  multiset[queueLen] of message_t; 
    End;


----------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------
var
    proc:   	array [node_n] of proc_t;
    dir:    	dir_t; -- TODO/ Can be extended to multiple directories if implemented later
	lastWrite:	value_t;


----------------------------------------------------------------------
-- State logger functions
----------------------------------------------------------------------
Procedure LogNodeState(
    p:  node_n;
    vb: 0..3;
);
Begin
    if (verbosity >= vb) then
        if p>0 then
            put "node:  PROC ";
            put p;

            put ", state: ";
            put proc[p].state;

            put ", value: ";
            put proc[p].value;

            put ", isStalled: ";
            put proc[p].isStalled;

            put ", req_queue_size: ";
            put MultiSetCount(i : proc[p].req_queue, true);

            put ", resp_queue_size: ";
            put MultiSetCount(i : proc[p].resp_queue, true);

            put ", fwd_queue_size: ";
            put MultiSetCount(i : proc[p].fwd_queue, true);
            put "\n";
        else
            put "node:  DIR";

            put ", state: ";
            put dir.state;

            put ", value: ";
            put dir.value;

            put ", req_queue_size: ";
            put MultiSetCount(i : dir.req_queue, true);

            put ", resp_queue_size: ";
            put MultiSetCount(i : dir.resp_queue, true);

            put ", fwd_queue_size: ";
            put MultiSetCount(i : dir.fwd_queue, true);
            put "\n";
        endif;
    endif;
End;

Procedure LogMessage(
    msg:    message_t;
    vb:     0..3;
);
Begin
    if (verbosity >= vb) then
        Put "message:   mType "; Put msg.mtype;
        Put ", value: "; Put msg.value;
        Put ", src: "; Put msg.src;
        Put ", dest: "; Put msg.dest;
        Put ", fwdTo: "; Put msg.fwdTo;
        Put ", numAck: "; Put msg.numAck;
        Put "\n";
    endif;
End;

----------------------------------------------------------------------
-- Router handle for routing generated response
----------------------------------------------------------------------
Procedure Send(
	mtype:	mtype_t;
	src:	node_n;
	dest:	node_n;
    chan:   channel_t;
    value:  value_t;
    fwdTo:  node_n;
    numAck: node_n;
);
var msg: message_t;
Begin
    msg.mtype   := mtype;
    msg.src     := src;
    msg.dest    := dest;
    msg.value   := value;
    msg.fwdTo   := fwdTo;
    msg.numAck  := numAck;
    LogMessage(msg, 2);
    LogNodeState(msg.dest, 3);
    switch chan
        case req:
            if msg.dest>0 then
                Assert (MultiSetCount(i : proc[msg.dest].req_queue, true) < queueLen) "Message queue is full";
                MultiSetAdd(msg, proc[msg.dest].req_queue);
            else
                Assert (MultiSetCount(i : dir.req_queue, true) < queueLen) "Message queue is full";
                MultiSetAdd(msg, dir.req_queue);
            endif;
        case resp:
            if msg.dest>0 then
                Assert (MultiSetCount(i : proc[msg.dest].resp_queue, true) < queueLen) "Message queue is full";
                MultiSetAdd(msg, proc[msg.dest].resp_queue);
            else
                Assert (MultiSetCount(i : dir.resp_queue, true) < queueLen) "Message queue is full";
                MultiSetAdd(msg, dir.resp_queue);
            endif;
        case fwd:
            if msg.dest>0 then
                Assert (MultiSetCount(i : proc[msg.dest].fwd_queue, true) < queueLen) "Message queue is full";
                MultiSetAdd(msg, proc[msg.dest].fwd_queue);
            else
                Assert (MultiSetCount(i : dir.fwd_queue, true) < queueLen) "Message queue is full";
                MultiSetAdd(msg, dir.fwd_queue);
            endif;
End;



----------------------------------------------------------------------
-- Start state to initialize all queues, invalidate all sharers
----------------------------------------------------------------------
startstate
    For i: 0..(numProc-1) Do
        proc[i].state := Proc_I;
        proc[i].isStalled := false;
    End;

    For i: node_n Do
        dir.sharers[i] := false;
    End;

    dir.state := Dir_I;
endstartstate;