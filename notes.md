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