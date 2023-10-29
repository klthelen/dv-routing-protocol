/*
 * generics.h
 * Definition file for generic struct and functions for nodes.
 */

struct distance_table {
  int costs[MAX_NODES][MAX_NODES];
};

/* Generic Functions
 * The individual functions in each nodes are redundant copy + pastes.
 * The functionalities can all be expressed with 3 generic versions.
 * Note that these versions use pointers to the calling node's NeighborCosts and distance_tables
 * That is, they can still reference and update the information for individual nodes, but 
 * adding additional nodes to the network is trivial. 
 */
void generic_init(int nodeNumber, struct NeighborCosts **neighbor, struct distance_table *dtptr);
void generic_rtupdate(int nodeNumber, struct NeighborCosts **neighbor, struct distance_table *dtptr, struct RoutePacket *rcvdpkt);
void generic_printdt(int nodeNumber, struct NeighborCosts **neighbor, struct distance_table *dtptr);




