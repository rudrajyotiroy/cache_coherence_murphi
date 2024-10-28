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
---- 4-hop MSI protocol, coarse-vector representation

----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------

const
    numProc:    3;      -- number of processors
    numDir:     1;      -- number of directories
    queueLen:   10;     -- maximum length of each queue at controller

----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type

    -- Node ID 0 to (numDir - 1) for directories
    -- Node ID numDIr to (numDir + numProc - 1) for processors
    node_n:    0..(numProc + numDir-1);

    -- Request channel (NULL state indicates no request pending at RCV port)
    mtype_req_t: enum {
        GetS,
        GetM,
        PutS,
        PutM,
    };

    -- Response channel
    mtype_resp_t: enum {
        DataAck,
        InvAck,
        PutAck,
        FwdAck,
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

    dir_state_t: enum {
        -- Stable states
        Dir_M,
        Dir_S,
        Dir_I,
        -- Transition states
        Dir_MX_D,
        Dir_SM_A,
        Dir_MM_A
    };

    ops_t: enum {
        -- Spontaneous processor operations
        load,
        store,
        writeback
    };

    -- Define each message data-structure
    message_t:
    Record
        m_id:   integer; -- Message ID (src side for debugging)
        mtype:  mtype_t;
        src:    node_n; -- Source node number
        dest:   node_n; -- Destination node number
        fwdTo:  node_n; -- Forwarding node number
        numAck: node_n; -- Max number of acks
    End;

    -- Define message queue at each node
    queue_t: record
        elements: array [0..queueLen - 1] of message_t;  -- Array to store elements
        head: 0..queueLen;  -- Head pointer for dequeue
        tail: 0..queueLen;  -- Tail pointer for enqueue
        count: 0..queueLen;  -- Count of elements in the queue
    end;

    -- Define each processor cache controller
    proc_t:
    Record
        m_id:       integer; -- Counter for request queue, will count outgoing msgs
        state:      proc_state_t;
        req_queue:  queue_t; 
        resp_queue: queue_t;
        fwd_queue:  queue_t;
    End;

    -- Define each directory controller
    dir_t:
    Record
        state:      dir_state_t;
        sharers:    array [0..(numProc + numDir-1)] of boolean; -- Coarse vector
        req_queue:  queue_t; 
        resp_queue: queue_t;
        fwd_queue:  queue_t;
    End;


----------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------
var
    proc:   array [0..(numProc - 1)] of proc_t;
    dir:    dir_t; -- TODO/ Can be extended to multiple directories if implemented later


----------------------------------------------------------------------
-- Start state to initialize all queues, invalidate all sharers
----------------------------------------------------------------------
startstate
    For i: 0..(numProc-1) Do
        proc[i].state := Proc_I;
        proc[i].m_id := 0;

        proc[i].req_queue.head := 0;
        proc[i].req_queue.tail := 0;
        proc[i].req_queue.count := 0;

        proc[i].resp_queue.head := 0;
        proc[i].resp_queue.tail := 0;
        proc[i].resp_queue.count := 0;

        proc[i].fwd_queue.head := 0;
        proc[i].fwd_queue.tail := 0;
        proc[i].fwd_queue.count := 0;
    End;

    For i: 0..(numProc + numDir-1) Do
        dir.sharers[i] := false;
    End;

    dir.state := Dir_I;
    dir.req_queue.head := 0;
    dir.req_queue.tail := 0;
    dir.req_queue.count := 0;

    dir.resp_queue.head := 0;
    dir.resp_queue.tail := 0;
    dir.resp_queue.count := 0;

    dir.fwd_queue.head := 0;
    dir.fwd_queue.tail := 0;
    dir.fwd_queue.count := 0;
endstartstate;

----------------------------------------------------------------------
-- Generic Enqueue procedure for a single queue
----------------------------------------------------------------------
Procedure Enqueue(var q: QueueType; msg: mtype_t);
Begin
  if q.count < queueLen then
    q.elements[q.tail] := msg;
    q.tail := (q.tail + 1) % queueLen;
    q.count := q.count + 1;
  else
    Error "Queue is full";
  endif;
End;

----------------------------------------------------------------------
-- Generic Dequeue procedure for a single queue
----------------------------------------------------------------------
Procedure Dequeue(var q: QueueType): mtype_t;
Var
  msg: mtype_t;
Begin
  if q.count > 0 then
    msg := q.elements[q.head];
    q.head := (q.head + 1) % queueLen;
    q.count := q.count - 1;
    return msg;
  else
    Error "Queue is empty";
  endif;
End;


