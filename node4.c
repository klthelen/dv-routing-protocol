/*
 * node4.c
 * Implementation file for node4
 */

#include <stdio.h>
#include "dv.h"
#include "generics.h"

struct distance_table dt4;
struct NeighborCosts *neighbor4;

void rtinit4() {
  generic_init(4, &neighbor4, &dt4);
}

void rtupdate4(struct RoutePacket *rcvdpkt) {
  generic_rtupdate(4, &neighbor4, &dt4, rcvdpkt);
}
