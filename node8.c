/*
 * node8.c
 * Implementation file for node8
 */

#include <stdio.h>
#include "dv.h"
#include "generics.h"

struct distance_table dt8;
struct NeighborCosts *neighbor8;

void rtinit8() {
  generic_init(8, &neighbor8, &dt8);
}

void rtupdate8(struct RoutePacket *rcvdpkt) {
  generic_rtupdate(8, &neighbor8, &dt8, rcvdpkt);
}
