#ifndef __GRAPHIX_H__
#define __GRAPHIX_H__

#include <pebble.h>

void graphix(uint32_t max_health , uint32_t curr_health , uint32_t prev_dmg, char* adj, char* name);

void ungraphix();

#endif
