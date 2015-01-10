// data.c
// program file for monster handling and other data
//
// By: Team Skip

#include <pebble.h>

#include "data.h"
#define LEVEL_STEP 16

char* get_monster_name(uint16_t level){
	if(level == 0){
		fprintf(stderr, "Error: monster level invalid\n");
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
		fprintf(stderr, "Error: Monster type invalid\n");
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
		fprintf(stderr, "Error: Invalid monster level\n");
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
