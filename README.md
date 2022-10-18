# HomaAeolus

### 13 oct : still trying to create a simple situation with 2 or 3 hosts 

---

Three logs for three situation : 
- [2hostNoGrant.txt](/RpcTransportDesign/OMNeT++Simulation/homatransport/src/dcntopo/2hostsNoGrant.txt) is a simple situation where one host send a relatively small message (~1000 bytes).
- [2hostGrant.txt](/RpcTransportDesign/OMNeT++Simulation/homatransport/src/dcntopo/2hostGrant.txt) is a simple situation where one host send a message (~15000 bytes), in this configuration we can see the receiver host sending GRANT packets. 
- [2host+randompacketdrop.txt](/RpcTransportDesign/OMNeT++Simulation/homatransport/src/dcntopo/2host+randompacketdrop.txt) is a simple situation where the TOR randomly drops a packet (random = $\text{Unif}_{[0, 1)}$), in this case the sender does not receive GRANT packet anymore and thus stop sending packet. 

--- 

### 18 oct : implement the retransmisson mechanism in case of packet drops
	
