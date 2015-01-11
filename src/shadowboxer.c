#include <pebble.h>

#include "graphix.h"
#include "data.h"

#define PLAYER_STORE 5
#define MONSTER_STORE 6

player_info* player;
monster_info* monster;
uint16_t game_level;

void init(){
	
	/*// Loads stored game data
	if(persist_exists(PLAYER_STORE)){
		persist_read_data(PLAYER_STORE, player, sizeof(player_info));
	}
	else{
		player = build_player();
	}*/
	
	// testing reading and writing
	player = build_player();
	
	game_level = player->curr_level;
	
	/*if(persist_exists(MONSTER_STORE)){
		persist_read_data(MONSTER_STORE, monster, sizeof(monster_info));
	}
	else{
		monster = gen_monster(game_level);
	}*/
	
	monster = gen_monster(game_level);
	
	graphix(200,200,50,"foo","bar");
}

void deinit(){
  ungraphix();
  
  persist_write_data(PLAYER_STORE, player, sizeof(player_info));
  
  persist_write_data(MONSTER_STORE, monster, sizeof(monster_info));
  
}

int main(void){
  init();
  
  app_event_loop();
  
  deinit();
  
  
}
  
