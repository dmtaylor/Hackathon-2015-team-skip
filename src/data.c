// data.c
// program file for monster handling and other data
//
// By: Team Skip

#include <pebble.h>

#include "data.h"
#define LEVEL_STEP 16

char* get_monster_name(uint16_t level){
	if(level == 0){
		//fprintf(stderr, "Error: monster level invalid\n");
		return NULL;
	}
	
	if(level <= MAX_LEVEL/LEVEL_STEP){
		
	}
	else if(level>MAX_LEVEL/LEVEL_STEP && level<=2*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>2*(MAX_LEVEL/LEVEL_STEP) && level<=3*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>3*(MAX_LEVEL/LEVEL_STEP) && level<=4*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>4*(MAX_LEVEL/LEVEL_STEP) && level<=5*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>5*(MAX_LEVEL/LEVEL_STEP) && level<=6*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>6*(MAX_LEVEL/LEVEL_STEP) && level<=7*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>7*(MAX_LEVEL/LEVEL_STEP) && level<=8*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>8*(MAX_LEVEL/LEVEL_STEP) && level<=9*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>9*(MAX_LEVEL/LEVEL_STEP) && level<=10*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>10*(MAX_LEVEL/LEVEL_STEP) && level<=11*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>11*(MAX_LEVEL/LEVEL_STEP) && level<=12*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>12*(MAX_LEVEL/LEVEL_STEP) && level<=13*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>13*(MAX_LEVEL/LEVEL_STEP) && level<=14*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>14*(MAX_LEVEL/LEVEL_STEP) && level<=15*(MAX_LEVEL/LEVEL_STEP)){
		
	}
	else if(level>15*(MAX_LEVEL/LEVEL_STEP) && level<=MAX_LEVEL){
		
	}
}

char* get_monster_adj(uint16_t type){
	if(type == 0){
		//fprintf(stderr, "Error: Monster type invalid\n");
		return NULL;
	}
	int adj_val;
	else if(type == 1){
		
	}
	else if(type == 2){
		
	}
	else if(type == 3){
		
	}
	else if(type == 4){
		
	}
	
}

monster_info* gen_monster(uint16_t monster_level){
	if(monster_level == 0){
		//fprintf(stderr, "Error: Invalid monster level\n");
		return NULL;
	}
	
	monster_info* monster = malloc(sizeof(monster_info));
	if (monster == NULL){
		fprintf(stderr, "Error: malloc failed\n");
		return NULL;
	}
	
	monster->name = get_monster_name(monster_level);
	monster->type = rand() % 4 + 1;
	monster->adj = get_monster_adj(monster_level);
	monster->level = monster_level;
	monster->max_health = (10*monster_level) + (rand() % monster_level);
	monster->curr_health = monster->max_health;
	
	return monster;
}

char monster_is_dead(monster_info* monster){
	if(monster == NULL){
		//fprintf(stderr, "Error: Null monster pointer\n");
		return 255;
	}
	if(monster->curr_health == 0){
		return 1;
	}
	else{
		return 0;
	}
}

void update_monster_health(monster_info* monster, uint32_t damage){
	if(monster == NULL){
		//fprintf(stderr, "Error: Null monster to update health");
		return;
	}
	
	if(damage>=monster->curr_health){
		monster->curr_health =0;
	}
	else {
		monster->curr_health = monster->curr_health - damage;
	}
	return;
}

char get_monster_type(monster_info* monster){
	if(monster == NULL){
		//fprintf(stderr, "Error: Null monster to get type\n");
		return 0;
	}
	return monster->type;
}

void update_player_info(player_info* player, monster_info* monster){
	if(player== NULL){
		//fprintf(stderr, "Error: player info null, cannot be updated\n");
		return;
	}
	if(monster == NULL){
		//fprintf(stderr, "Error: monster info null, player cannot be updated\n");
		return;
	}
	int new_xp = player->curr_xp + 2*monster->level;
	
	if(new_xp >= player->next_xp){
		player->curr_xp = 0;
		player->curr_level++;
		player->next_xp *= 2;
	}
	else{
		player->curr_xp = new_xp;
	}
	
	return;
}

uint16_t get_player_level(player_info* player){
	if(player == NULL){
		//fprintf(stderr, "Error: Null player to get level");
		return 0;
	}
	return player->level;
}

double get_damage_mod(player_info* player){
	if(player == NULL){
		//fprintf(stderr, "Error: Null player to get mod");
		return 0;
	}
	return player->damage_mod;
}


