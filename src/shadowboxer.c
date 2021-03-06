#include <pebble.h>

#include "graphix.h"
#include "data.h"
#include "punch.h"

#define PLAYER_STORE 5
#define MONSTER_STORE 6

player_info* player;
monster_info* monster;
uint16_t game_level;

static AppTimer *timer;

void timer_callback(void* data){
	// TODO
  reg_callback(NULL);
  
  uint32_t damage_dealt = 0;
  
  if( punch_Recent ){
	  roll_d4();
	  
	  if(get_monster_type(monster) == punch_Recent){
	  	damage_dealt = (uint32_t)((player->damage_mod) * punch_d10);
	  }
	  else{
		  damage_dealt = (uint32_t)((player->damage_mod) * punch_d4);
	  }
    damage_dealt += 1;
	  update_monster_health(monster, damage_dealt);
	  if(monsterReady() && monster_is_dead(monster)){
		  update_player_info(player, monster);
		  game_level = player->curr_level;
		  free(monster);
		  monster = gen_monster(game_level);
		  if(monsterReady() && monster==NULL){
			  app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 28,
					"Error: Monster creation failed\n");
			  return;
		  }
	  }
  }

  //APP_LOG(APP_LOG_LEVEL_INFO, "D: %lu; P: %d, %d; T: %d", damage_dealt, punch_d4, punch_d10, punch_Recent);
	
	if(damage_dealt){
		ungraphix();
		graphix(monster->max_health,monster->curr_health,damage_dealt, player->curr_level,
			monster->adj,monster->name,get_monster_type(monster));
	}
	
	timer = app_timer_register(GAME_UPDATE_MS, timer_callback, NULL);
}

void init(){
    
    srand(time(NULL));
    
    // Loads stored game data
    if(persist_exists(PLAYER_STORE)){
        player = malloc(sizeof(player_info));
        if(player == NULL){
            app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 48,
					"Error: Player malloc failed\n");
        }
        persist_read_data(PLAYER_STORE, player, sizeof(player_info));
    }
    else{
        player = build_player();
        if(player == NULL){
            app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 56,
				"Error: Player create failed\n");
        }
    }
    
    // testing reading and writing
    //player = build_player();
    
    if(player==NULL){
		app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 65,
				"Error: Player malloc failed\n");
    }
    game_level = player->curr_level;
    
    if(persist_exists(MONSTER_STORE)){
        monster = malloc(sizeof(monster_info));
        if(monster == NULL){
            app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 73,
				"Error: Monster malloc failed\n");
        }
        persist_read_data(MONSTER_STORE, monster, sizeof(monster_info));
    }
    else{
        monster = gen_monster(game_level);
        if(monster == NULL){
            app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 81,
				"Error: Monster malloc failed\n");
        }
    }
    
    if(monster == NULL){
        app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 87,
				"Error: Monster malloc failed\n");
    }
    
    
    pch_init();
    
    //monster = gen_monster(game_level);
	
	
	// temp code
	graphix(monster->max_health,monster->curr_health,0,player->curr_level,
			monster->adj,monster->name,get_monster_type(monster));
			
	timer = app_timer_register(GAME_UPDATE_MS, timer_callback, NULL);

}

void deinit(){
  ungraphix();
  
  pch_dinit();
  
  persist_write_data(PLAYER_STORE, player, sizeof(player_info));
  
  persist_write_data(MONSTER_STORE, monster, sizeof(monster_info));
  
  //free(player);
  //free(monster);
  
}

int main(void){
  init();
  
  app_event_loop();
  
  deinit();
  
  
}
  
