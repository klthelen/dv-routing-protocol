/*
 * node2.c
 * Implementation file for node2
 */

#include <stdio.h>
#include "dv.h"
#include "generics.h"

struct distance_table dt2;
struct NeighborCosts *neighbor2;

void rtinit2() {
  generic_init(2, &neighbor2, &dt2);
}

void rtupdate2( struct RoutePacket *rcvdpkt ) {
  generic_rtupdate(2, &neighbor2, &dt2, rcvdpkt);
}
