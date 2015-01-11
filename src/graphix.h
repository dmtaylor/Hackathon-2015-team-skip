#ifndef __GRAPHIX_H__
#define __GRAPHIX_H__

#include <pebble.h>

#include "punch_type.h"

void graphix(uint32_t max_health , uint32_t curr_health , uint32_t prev_dmg , uint16_t curr_level ,
	char* adj , char* name , enum punch_type punch_type);

void ungraphix();

#endif
