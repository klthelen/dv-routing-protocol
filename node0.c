/*
 * node0.c
 * Implementation file for node0
 */

#include <stdio.h>
#include "dv.h"
#include "generics.h"

struct distance_table dt0;
struct NeighborCosts *neighbor0;

void rtinit0() {
  generic_init(0, &neighbor0, &dt0);
}

void rtupdate0(struct RoutePacket *rcvdpkt) {
  generic_rtupdate(0, &neighbor0, &dt0, rcvdpkt); 
}
