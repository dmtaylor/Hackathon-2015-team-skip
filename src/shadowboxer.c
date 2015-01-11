#include <pebble.h>

#include "graphix.h"
#include "data.h"

#define PLAYER_STORE 5
#define MONSTER_STORE 6

player_info* player;
monster_info* monster;
uint16_t game_level;

void init(){
<<<<<<< HEAD
    
    
    // Loads stored game data
    if(persist_exists(PLAYER_STORE)){
        player = malloc(sizeof(player_info));
        if(player == NULL){
            app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 20,
				"Error: Player malloc failed\n");
            exit(255);
        }
        persist_read_data(PLAYER_STORE, player, sizeof(player_info));
    }
    else{
        player = build_player();
        if(player == NULL){
            app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 30,
				"Error: Player create failed\n");
            exit(255);
        }
    }
    
    // testing reading and writing
    //player = build_player();
    
    if(player==NULL){
		app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 34,
				"Error: Player malloc failed\n");
        exit(255);
    }
    game_level = player->curr_level;
    
    if(persist_exists(MONSTER_STORE)){
        monster = malloc(sizeof(monster_info));
        if(monster == NULL){
            app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 42,
				"Error: Monster malloc failed\n");
            exit(255);
        }
        persist_read_data(MONSTER_STORE, monster, sizeof(monster_info));
    }
    else{
        monster = gen_monster(game_level);
        if(monster == NULL){
            app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 50,
				"Error: Monster malloc failed\n");
            exit(255);
        }
    }
    
    if(monster == NULL){
        app_log(APP_LOG_LEVEL_ERROR, "shadowboxer.c", 57,
				"Error: Monster malloc failed\n");
        exit(255);
    }
    
    //monster = gen_monster(game_level);
	
	graphix(200,200,50,"Super Powerful Very Angry","Monster with a Very Long Name",JAB);

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
  
