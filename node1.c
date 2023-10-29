/*
 * node1.c
 * Implementation file for node1
 */

#include <stdio.h>
#include "dv.h"
#include "generics.h"

struct distance_table dt1;
struct NeighborCosts *neighbor1;

void rtinit1() {
  generic_init(1, &neighbor1, &dt1);
}

void rtupdate1(struct RoutePacket *rcvdpkt) {
  generic_rtupdate(1, &neighbor1, &dt1, rcvdpkt);
}

