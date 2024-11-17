***Problem: Proc 2 negative count on receiving invack from proc 1***

**Problem**

Proc 2 State: IM_AD, msg 365

*Backtrace:*

proc 2 I ==(store)==> M Create Msg 361 GetM to Home, IM_AD
Home Receive msg 361:
send 363: Inv to proc 1
send 364: Data to proc 2, ackcount 1 - this never reaches proc 2
Proc 1 receives msg 363:
send 365: InvAck to 2 - causes it to become negative

**Solution**

Remove the invariants dictating InvAcks be positive


***Problem: Proc 1 negative count on receiving invack from proc 3***

**Problem**

Proc 1 State: SM_AD, msg 55

*Backtrace:*

Proc 1 :: S ==(store)==> M Create Msg 47:: type: GetM, src: 1, dst: 6, ack_cnt: 0, src_state: Proc_SM_AD, dst_state: Dir_S
Receiving Msg 47, GetM from processor Proc_1 on RequestChannel at home -- HomeNode.state:Dir_S
Home send data (Msg 52, ack_cnt: 2) to Proc_1, never reaches   
Msg 51 : Proc_3 recv and send back Inv msg 55
Proc 1 receives msg 55: causes it to become negative

**Solution**

*** CMI deadlock 1 ***

I ==(load)==> S Create Msg 0:: type: GetS, src: 2, dst: 7, ack_cnt: 0, src_state: Proc_IS_D, dst_state: Dir_I
I ==(store)==> M Create Msg 1:: type: GetM, src: 3, dst: 7, ack_cnt: 0, src_state: Proc_IM_D, dst_state: Dir_I
I ==(store)==> M Create Msg 2:: type: GetM, src: 1, dst: 7, ack_cnt: 0, src_state: Proc_IM_D, dst_state: Dir_I
  Receive Msg 0:: type: GetS, src: 2, dst: 7, ack_cnt: 0, src_state: Proc_IS_D, dst_state: Dir_I
Receiving GetS from processor Proc_2 on RequestChannel at home -- HomeNode.state:Dir_I
 Create Msg 3:: type: Data, src: 7, dst: 2, ack_cnt: 0, src_state: Dir_S, dst_state: Proc_IS_D, val: 6
  Receive Msg 1:: type: GetM, src: 3, dst: 7, ack_cnt: 0, src_state: Proc_IM_D, dst_state: Dir_S
Receiving GetM from processor Proc_3 on RequestChannel at home -- HomeNode.state:Dir_S
 Create Msg 4:: type: Data, src: 7, dst: 3, ack_cnt: 1, src_state: Dir_SM_A, dst_state: Proc_IM_D, val: 6
  Receive Msg 4:: type: Data, src: 7, dst: 3, ack_cnt: 1, src_state: Dir_SM_A, dst_state: Proc_IM_D, val: 6
Receiving Data from HomeDir on ResponseChannel at proc 3
  Receive Msg 3:: type: Data, src: 7, dst: 2, ack_cnt: 0, src_state: Dir_SM_A, dst_state: Proc_IS_D, val: 6
Receiving Data from HomeDir on ResponseChannel at proc 2
S ==(store)==> M Create Msg 5:: type: GetM, src: 2, dst: 7, ack_cnt: 0, src_state: Proc_SM_D, dst_state: Dir_SM_A
  Receive Msg 2:: type: GetM, src: 1, dst: 7, ack_cnt: 0, src_state: Proc_IM_D, dst_state: Dir_SM_A
Receiving GetM from processor Proc_1 on RequestChannel at home -- HomeNode.state:Dir_SM_A
M ==(evict)==> I Create Msg 6:: type: PutM, src: 3, dst: 7, ack_cnt: 0, src_state: Proc_MI_A, dst_state: Dir_SM_A, val: 6
Receiving GetM from processor Proc_1 on RequestChannel at home -- HomeNode.state:Dir_SM_A

Dir_S had sent Data to Proc_3 with SharerCount 1 (Proc_1)
Dir_SM_A is waiting for response from Proc_3 (IM_D)
Wrong pcnt action - solved

GetM is blocking request-port in SM_A. So cannot Nack to GetS.
Without Nack Proc_2 cannot move from IS_D
By passing GetS through Fwd Channel this is solved. Analysis?

AckCount is still wrong
SI_A is decrementing ackcount irrespective of whether it was already invalidated
PutAck has not reached
Solution : Modify assertion to allow negative values of ack_cnt