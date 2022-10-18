# HomaAeolus

### 13 oct : still trying to create a simple situation with 2 or 3 hosts 

---

Three logs for three situation : 
- [2hostNoGrant.txt](/RpcTransportDesign/OMNeT++Simulation/homatransport/src/dcntopo/2hostsNoGrant.txt) is a simple situation where one host send a relatively small message (~1000 bytes).
- [2hostGrant.txt](/RpcTransportDesign/OMNeT++Simulation/homatransport/src/dcntopo/2hostGrant.txt) is a simple situation where one host send a message (~15000 bytes), in this configuration we can see the receiver host sending GRANT packets. 
- [2host+randompacketdrop.txt](/RpcTransportDesign/OMNeT++Simulation/homatransport/src/dcntopo/2host+randompacketdrop.txt) is a simple situation where the TOR randomly drops a packet (random = $\text{Unif}_{[0, 1)}$), in this case the sender does not receive GRANT packet anymore and thus stop sending packet. 

--- 

### 18 oct : implement the retransmisson mechanism in case of packet drops
	
How to implement retransmission ? 

Using timers : one at sender side and one at receiver side. 

Sender side : 
	- When the app gives a message to the transport, bind a timer (a self message) to this message. If we receive back a GRANT delete the timer, else resend the message. 
	
Receiver side :
	- Bind a timer to messages, in case of timeout prepare and send a RESEND packet to sender, else the timer will be canceled.
