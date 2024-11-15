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

