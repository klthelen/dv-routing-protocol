/*
 * node9.c
 * Implementation file for node9
 */

#include <stdio.h>
#include "dv.h"
#include "generics.h"

struct distance_table dt9;
struct NeighborCosts *neighbor9;

void rtinit9() {
  generic_init(9, &neighbor9, &dt9);
}

void rtupdate9(struct RoutePacket *rcvdpkt) {
  generic_rtupdate(9, &neighbor9, &dt9, rcvdpkt);
}
