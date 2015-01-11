// data.h
// header file for program data access functions
//
// By: Team Skip

#ifndef __DATA_H__
#define __DATA_H__

#include <pebble.h>
#define MAX_NAME_LEN 64
#define MAX_ADJ_LEN 64
#define MAX_LEVEL 0xffff

typedef struct player_info{
	double damage_mod;
	uint16_t curr_level;
	uint32_t curr_xp;
	uint32_t next_xp;
} player_info;

typedef struct monster_info{
	char name[MAX_NAME_LEN];
	char adj[MAX_ADJ_LEN];
	uint32_t curr_health;
	uint32_t max_health;
	uint16_t level;
	char type;
	// image info?
} monster_info;

// gen_monster: Generates a new monster, will be called when monster
//              dies.
monster_info* gen_monster(uint16_t monster_level);

// monster_is_dead: Returns 1 if monster died, 0 otherwise
char monster_is_dead(monster_info* monster);

// update_monster_health: Subtracts damage from the current monster
//                        health. Damage is represented as a positive
//                        number and is subtracted
void update_monster_health(monster_info* monster, uint32_t damage);

// get_monster_type: returns the type for the monster
char get_monster_type(monster_info* monster);

// build_player: Creates a new 
player_info* build_player(void);

// update_player_info: Updates player info when monster is killed
void update_player_info(player_info* player, monster_info* monster);

// get_player_level: returns the current player level
uint16_t get_player_level(player_info* player);

// get_damage_mod: Returns the damage modifier for player, which is
//                 based on the current player level
double get_damage_mod(player_info* player);



#endif
