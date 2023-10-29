/*
 * node6.c
 * Implementation file for node6
 */

#include <stdio.h>
#include "dv.h"
#include "generics.h"

struct distance_table dt6;
struct NeighborCosts *neighbor6;

void rtinit6() {
  generic_init(6, &neighbor6, &dt6);
}

void rtupdate6(struct RoutePacket *rcvdpkt) {
  generic_rtupdate(6, &neighbor6, &dt6, rcvdpkt);
}
