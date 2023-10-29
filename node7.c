/*
 * node7.c
 * Implementation file for node7
 */

#include <stdio.h>
#include "dv.h"
#include "generics.h"

struct distance_table dt7;
struct NeighborCosts *neighbor7;

void rtinit7() {
  generic_init(7, &neighbor7, &dt7);
}

void rtupdate7(struct RoutePacket *rcvdpkt) {
  generic_rtupdate(7, &neighbor7, &dt7, rcvdpkt);
}
