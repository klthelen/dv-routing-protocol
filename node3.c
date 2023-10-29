/*
 * node3.c
 * Implementation file for node3
 */

#include <stdio.h>
#include "dv.h"
#include "generics.h"

struct distance_table dt3;
struct NeighborCosts *neighbor3;

void rtinit3() {
  generic_init(3, &neighbor3, &dt3);
}

void rtupdate3(struct RoutePacket *rcvdpkt) {
  generic_rtupdate(3, &neighbor3, &dt3, rcvdpkt);
}
