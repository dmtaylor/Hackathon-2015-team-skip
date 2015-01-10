// data.h
// header file for program data access functions
//
// By: Team Skip

#ifndef __DATA_H__
#define __DATA_H__

#include <pebble.h>

struct player_info{
	double damage_mod;
	uint16_t curr_level;
	uint32_t curr_xp;
	uint32_t next_xp;
};

struct monster_info{
	char* name;
	uint32_t curr_health;
	uint32_t max_health;
	uint16_t level;
	char type;
	// image info?
};






#endif
