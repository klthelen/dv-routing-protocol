
# dv-routing-protocol

An implementation of distance vector routing protocol.

# NodeConfigurationFile

The NodeConfigurationFile is used to tell the program the initial distances each node has to each other node. Nodes that are not directly connected use a distance of 9999 to indicate that there is no path between them. The first line of the NodeConfigurationFile should be the total number of nodes. The row & column of the table represents the node (e.g., the distance at [0, 1] is the distance from node 0 to node 1). 

Note that this program as provided only supports up to 10 nodes, but more nodes can be easily added by adding additional node files.


# Testing

This program supports up to 10 nodes (node0, node1, ... , node9). <br/>

You can test the program as follows: <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`make all` <br/>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`./dv` <br/>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`make clean` <br/>

The program allows different 4 different trace levels. Use trace level 1 for just the DV routing protocol. The other trace levels offer extra information about the events.

You can also set the trace level at runtime with: <br/>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`./dv 1`<br/>