/*
 * node5.c
 * Implementation file for node5
 */

#include <stdio.h>
#include "dv.h"
#include "generics.h"

struct distance_table dt5;
struct NeighborCosts *neighbor5;

void rtinit5() {
  generic_init(5, &neighbor5, &dt5);
}

void rtupdate5(struct RoutePacket *rcvdpkt) {
  generic_rtupdate(5, &neighbor5, &dt5, rcvdpkt);
}
