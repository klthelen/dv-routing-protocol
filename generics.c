/*
 * generics.c
 * Implementation file for generic functions for nodes. 
 */

#include <stdio.h>
#include "dv.h"
#include "generics.h"

extern int TraceLevel;
extern float clocktime;

void generic_init(int nodeNumber, struct NeighborCosts **neighbor, struct distance_table *dtptr) {
  *neighbor = getNeighborCosts(nodeNumber);

  // Initialize my col
  for (int row = 0; row < (*neighbor)->NodesInNetwork; row++) {
    dtptr->costs[row][nodeNumber] = (*neighbor)->NodeCosts[row];
  }
  for (int row = (*neighbor)->NodesInNetwork; row < MAX_NODES; row++) {
    dtptr->costs[row][nodeNumber] = INFINITY;
  }

  // Initialize the entire distance table
  for (int col = 0; col < (*neighbor)->NodesInNetwork; col++) {
    // If it's my col, skip because we've already done it
    if (col != nodeNumber) {
      for (int row = 0; row < (*neighbor)->NodesInNetwork; row++) {
        if (row == col) {
          dtptr->costs[row][col] = dtptr->costs[row][nodeNumber];
        }
        else {
          dtptr->costs[row][col] = INFINITY;
        }
      }
    }
  }

  // Output Trace:
  //     0. Print out a message whenever rinit() is called
  //     1. Print the content of the initial distance table
  if (TraceLevel == 1) {
    printf("At time t=%f, rinit%d() called.\n", clocktime, nodeNumber);
    generic_printdt(nodeNumber, neighbor, dtptr);
  }
  
  // Send my min costs to my neighbors
  for (int neighbors = 0; neighbors < (*neighbor)->NodesInNetwork; neighbors++) {
    int cost = (*neighbor)->NodeCosts[neighbors];
    if ((cost < INFINITY) && (cost > 0)) {
      struct RoutePacket packet;
      packet.sourceid = nodeNumber;
      packet.destid = neighbors;
      for (int row = 0; row < MAX_NODES; row++) {
        packet.mincost[row] = dtptr->costs[row][nodeNumber];
      }

      // Output Trace:
      //     2. Print what information is sent to the neighboring nodes
      if (TraceLevel == 1) {
        printf("At time t=%f, node %d sends packet to node %d with: ",
	       clocktime, packet.sourceid, packet.destid);
        for (int i = 0; i < (*neighbor)->NodesInNetwork; i++) {
          printf("  %4d", packet.mincost[i]);
        }
        printf("\n");
      }

      // Send the packet
      toLayer2(packet);
    }
  }
}

void generic_rtupdate(int nodeNumber, struct NeighborCosts **neighbor,
		      struct distance_table *dtptr, struct RoutePacket *rcvdpkt) {
  int sourceid = rcvdpkt->sourceid;                // Where this packet came from
  int destid = rcvdpkt->destid;                    // My node number
  int numOfNodes = (*neighbor)->NodesInNetwork;    // Number of nodes in the network
  
  // Update our understanding of sourceid's shortest paths
  for (int i = 0; i < MAX_NODES; i++) {
    if (rcvdpkt->mincost[i] < dtptr->costs[i][sourceid]) {
      dtptr->costs[i][sourceid] = rcvdpkt->mincost[i];
    }
  }

  // Use this information to try to update our shortest paths
  int distanceTableWasUpdated = 0;
  for (int i = 0; i < MAX_NODES; i++) {
    if (dtptr->costs[i][destid] > (dtptr->costs[sourceid][destid] + dtptr->costs[i][sourceid])) {
      dtptr->costs[i][destid] = dtptr->costs[sourceid][destid] + dtptr->costs[i][sourceid];
      distanceTableWasUpdated = 1;
    }
  }

  // Output Trace:
  //     0. Procedure should print out a message whenever rtupdate() is called
  //     1. Print the identity of the sender of the routing packet
  //     2. Print the content of the distance table
  if (TraceLevel == 1) {
    printf("At time t=%f, node %d receives a packet from node %d\n",
           clocktime, destid, sourceid);
    generic_printdt(destid, neighbor, dtptr);
  }

  if (distanceTableWasUpdated == 1) {
    if (TraceLevel == 1) {
      printf("As a result of distance table updates:\n");
    }
    // Send my min costs to my neighbors
    for (int neighbors = 0; neighbors < MAX_NODES; neighbors++) {
      int cost = (*neighbor)->NodeCosts[neighbors];
      if ((cost < INFINITY) && (cost > 0)) {
	struct RoutePacket packet;
	packet.sourceid = destid;
	packet.destid = neighbors;
	for (int row = 0; row < MAX_NODES; row++) {
	  packet.mincost[row] = dtptr->costs[row][destid];
	}

	// Output Trace:
	//     3. A description of any messages sent to neighboring nodes as a
	//        result of any distance table updates
	if (TraceLevel == 1) {
	  printf("At time t=%f, node %d sends packet to node %d with: ",
		 clocktime, packet.sourceid, packet.destid);
	  for (int i = 0; i < numOfNodes; i++) {
	    printf("  %4d", packet.mincost[i]);
	  }
	  printf("\n");
	}
	toLayer2(packet);
      }
    }
  }
}

void generic_printdt(int nodeNumber, struct NeighborCosts **neighbor, struct distance_table *dtptr) {
  int NumberOfNeighbors = 0;                       // How many neighbors
  int Neighbors[MAX_NODES];                        // Who are the neighbors

  // Determine our neighbors
  for (int i = 0; i < (*neighbor)->NodesInNetwork; i++) {
    if (((*neighbor)->NodeCosts[i] != INFINITY) && (i != nodeNumber)) {
      Neighbors[NumberOfNeighbors] = i;
      NumberOfNeighbors++;
    }
  }

  // Print the header
  printf("                via     \n");
  printf("   D%d |",nodeNumber );
  for (int i = 0; i < NumberOfNeighbors; i++) {
    printf("     %d", Neighbors[i]);
  }
  printf("\n");
  printf("  ----|-------------------------------\n");
  
  // For each node, print the cost by travelling thru each of our neighbors                     
  for (int i = 0; i < (*neighbor)->NodesInNetwork; i++) {
    if (i != nodeNumber) {
      printf("dest %d|", i);
      for (int j = 0; j < NumberOfNeighbors; j++) {
	printf("  %4d", dtptr->costs[i][Neighbors[j]]);
      }
      printf("\n");
    }
  }
  printf("\n");  
}
