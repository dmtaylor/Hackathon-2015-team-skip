// data.c
// program file for monster handling and other data
//
// By: Team Skip

#include <pebble.h>

#include "data.h"
#define LEVEL_STEP 16

char* get_monster_name(uint16_t level){
	if(level == 0){
		app_log(APP_LOG_LEVEL_ERROR, "data.c", 13,
			"Error: Monster level invalid\n");
		return NULL;
	}
	
	int name_val = rand();
	char* name = NULL;
	
	if(level <= MAX_LEVEL/LEVEL_STEP){
		switch(name_val % 7){
			case 0:
				name = "Goblin";
				break;
			case 1:
				name = "Hireling";
				break;
			case 2:
				name = "Gnome";
				break;
			case 3:
				name = "Skeleton";
				break;
			case 4:
				name = "Cat";
				break;
			case 5:
				name = "Kobold";
				break;
			case 6:
				name = "Large Rat";
				break;
			default:
				break;
		}
	}
	else if(level>MAX_LEVEL/LEVEL_STEP && level<=2*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Ork";
				break;
			case 1:
				name = "Myconid";
				break;
			case 2:
				name = "Formian";
				break;
			case 3:
				name = "Spider";
				break;
			case 4:
				name = "Gnoll";
				break;
			case 5:
				name = "Hobgoblin";
				break;
			case 6:
				name = "Zombie";
				break;
			default:
				break;
		}
	}
	else if(level>2*(MAX_LEVEL/LEVEL_STEP) && level<=3*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Hag";
				break;
			case 1:
				name = "Harpy";
				break;
			case 2:
				name = "Kuo-Toa";
				break;
			case 3:
				name = "Lizardfolk";
				break;
			case 4:
				name = "Merman";
				break;
			case 5:
				name = "Sauhagin";
				break;
			case 6:
				name = "Bugbear";
				break;
			default:
				break;
		}
	}
	else if(level>3*(MAX_LEVEL/LEVEL_STEP) && level<=4*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 6){
			case 0:
				name = "Xorn";
				break;
			case 1:
				name = "Mimic";
				break;
			case 2:
				name = "Grimlock";
				break;
			case 3:
				name = "Githyanki";
				break;
			case 4:
				name = "Dragonling";
				break;
			case 5:
				name = "Small Ooze";
				break;
			case 6:
				name = "Chuul";
				break;
			default:
				break;
		}
	}
	else if(level>4*(MAX_LEVEL/LEVEL_STEP) && level<=5*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Owlbear";
				break;
			case 1:
				name = "Manticore";
				break;
			case 2:
				name = "Ghoul";
				break;
			case 3:
				name = "Gibbering Mouther";
				break;
			case 4:
				name = "Direwolf";
				break;
			case 5:
				name = "Darkmantle";
				break;
			case 6:
				name = "Carrion Beast";
				break;
			default:
				break;
		}
	}
	else if(level>5*(MAX_LEVEL/LEVEL_STEP) && level<=6*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Barghest";
				break;
			case 1:
				name = "Azer";
				break;
			case 2:
				name = "Young Dragon";
				break;
			case 3:
				name = "Ninja";
				break;
			case 4:
				name = "Pirate";
				break;
			case 5:
				name = "Gargoyle";
				break;
			case 6:
				name = "Golem";
				break;
			default:
				break;
		}
	}
	else if(level>6*(MAX_LEVEL/LEVEL_STEP) && level<=7*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Lamia";
				break;
			case 1:
				name = "Mohrg";
				break;
			case 2:
				name = "Ogre";
				break;
			case 3:
				name = "Troll";
				break;
			case 4:
				name = "Chaos Beast";
				break;
			case 5:
				name = "Devourer";
				break;
			case 6:
				name = "Doppelganger";
				break;
			default:
				break;
		}
	}
	else if(level>7*(MAX_LEVEL/LEVEL_STEP) && level<=8*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Medusa";
				break;
			case 1:
				name = "Rakshasa";
				break;
			case 2:
				name = "Slaad";
				break;
			case 3:
				name = "Thoqqua";
				break;
			case 4:
				name = "Vampire";
				break;
			case 5:
				name = "Umber Hulk";
				break;
			case 6:
				name = "Yuan-Ti";
				break;
			default:
				break;
		}
	}
	else if(level>8*(MAX_LEVEL/LEVEL_STEP) && level<=9*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Remorhaz";
				break;
			case 1:
				name = "Ettin";
				break;
			case 2:
				name = "Drider";
				break;
			case 3:
				name = "Adult Dragon";
				break;
			case 4:
				name = "Frost Worm";
				break;
			case 5:
				name = "Insect Spirit";
				break;
			case 6:
				name = "Fire Elemental";
			default:
				break;
		}
	}
	else if(level>9*(MAX_LEVEL/LEVEL_STEP) && level<=10*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Nightshade";
				break;
			case 1:
				name = "Pik-Achoo";
				break;
			case 2:
				name = "Salamander";
				break;
			case 3:
				name = "Dire Bear";
				break;
			case 4:
				name = "Centaur";
				break;
			case 5:
				name = "Couatl";
				break;
			case 6:
				name = "Belker";
				break;
			default:
				break;
		}
	}
	else if(level>10*(MAX_LEVEL/LEVEL_STEP) && level<=11*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Great Ooze";
				break;
			case 1:
				name = "Magmin";
				break;
			case 2:
				name = "Rast";
				break;
			case 3:
				name = "Earth Elemmental";
				break;
			case 4:
				name = "Griffon";
				break;
			case 5:
				name = "Monstrous Spider";
				break;
			case 6:
				name = "Drake";
				break;
			default:
				break;
		}
	}
	else if(level>11*(MAX_LEVEL/LEVEL_STEP) && level<=12*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Frost Giant";
				break;
			case 1:
				name = "Draugr";
				break;
			case 2:
				name = "Lindworm";
				break;
			case 3:
				name = "Grindylow";
				break;
			case 4:
				name = "Finman";
				break;
			case 5:
				name = "Askafroa";
				break;
			case 6:
				name = "Dybbuk";
				break;
			default:
				break;
		}
	}
	else if(level>12*(MAX_LEVEL/LEVEL_STEP) && level<=13*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Beholder";
				break;
			case 1:
				name = "Oni";
				break;
			case 2:
				name = "Kappa";
				break;
			case 3:
				name = "Pale Man";
				break;
			case 4:
				name = "Tengu";
				break;
			case 5:
				name = "Mogwai";
				break;
			case 6:
				name = "Jiangshi";
				break;
			default:
				break;
		}
	}
	else if(level>13*(MAX_LEVEL/LEVEL_STEP) && level<=14*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Shai-Hulud";
				break;
			case 1:
				name = "Mind Flayer";
				break;
			case 2:
				name = "Roc";
				break;
			case 3:
				name = "Bene Gesserit";
				break;
			case 4:
				name = "Sphinx";
				break;
			case 5:
				name = "Lich";
				break;
			case 6:
				name = "Orcus";
			default:
				break;
		}
	}
	else if(level > 14*(MAX_LEVEL/LEVEL_STEP) && level<=15*(MAX_LEVEL/LEVEL_STEP)){
		switch(name_val % 7){
			case 0:
				name = "Shoggoth";
				break;
			case 1:
				name = "Gug";
				break;
			case 2:
				name = "Mi-Go";
				break;
			case 3:
				name = "Deep One";
				break;
			case 4:
				name = "Balor";
				break;
			case 5:
				name = "Kraken";
				break;
			case 6:
				name = "Jinni";
				break;
			default:
				break;
		}
	}
	else if((level > 15*(MAX_LEVEL/LEVEL_STEP))){
		switch(name_val % 7){
			case 0:
				name = "Titan";
				break;
			case 1:
				name = "Tarrasque";
				break;
			case 2:
				name = "Ancient Dragon";
				break;
			case 3:
				name = "Dagon";
				break;
			case 4:
				name = "Shub-Niggurath";
				break;
			case 5:
				name = "Cthulhu";
				break;
			case 6:
				name = "Nylarhotep";
				break;
			default:
				break;
		}
	}
	return name;
}

char* get_monster_adj(uint16_t type){
	if(type == 0){
		app_log(APP_LOG_LEVEL_ERROR, "data.c", 455,
			"Error: Monster type invalid\n");
		return NULL;
	}
	int adj_val = rand();
	char* return_val = NULL;
	if(type == 1){
		switch(adj_val % 4){
			case 0:
				return_val="A Direct";
				break;
			case 1:
				return_val="A Fighting";
				break;
			case 2:
				return_val="A Strong";
				break;
			case 3:
				return_val="A Forceful";
				break;
			default:
				break;
		}
	}
	else if(type == 2){
		switch(adj_val % 4){
			case 0:
				return_val="A Leaning";
				break;
			case 1:
				return_val="A Sly";
				break;
			case 2:
				return_val="A Tricky";
				break;
			case 3:
				return_val="A Flanking";
				break;
			default:
				break;
		}
	}
	else if(type == 3){
		switch(adj_val % 4){
			case 0:
				return_val="A Intelligent";
				break;
			case 1:
				return_val="A Thinking";
				break;
			case 2:
				return_val="A Wise";
				break;
			case 3:
				return_val="A Contemplative";
				break;
			default:
				break;
		}
	}
	else if(type == 4){
		switch(adj_val % 4){
			case 0:
				return_val="A Nimble";
				break;
			case 1:
				return_val="A Evading";
				break;
			case 2:
				return_val="A Swift";
				break;
			case 3:
				return_val="A Fast";
				break;
			default:
				break;
		}
	}
	return return_val;
}

monster_info* gen_monster(uint16_t monster_level){
	if(monster_level == 0){
		app_log(APP_LOG_LEVEL_ERROR, "data.c", 538,
			"Error: Invalid monster level\n");
		return NULL;
	}
	
	monster_info* monster = malloc(sizeof(monster_info));
	if (monster == NULL){
		app_log(APP_LOG_LEVEL_ERROR, "data.c", 545,
			"Error: malloc failed\n");
		return NULL;
	}
	
	
	snprintf(monster->name, MAX_NAME_LEN, "%s", get_monster_name(monster_level));
	monster->type = rand() % 4 + 1;
	snprintf(monster->adj, MAX_ADJ_LEN, "%s", get_monster_adj(monster->type));
	monster->level = monster_level;
	monster->max_health = (10*monster_level) + (rand() % monster_level);
	monster->curr_health = monster->max_health;
	
	return monster;
}

char monster_is_dead(monster_info* monster){
	if(monster == NULL){
		app_log(APP_LOG_LEVEL_ERROR, "data.c", 563,
			"Error: Null monster pointer\n");
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
		app_log(APP_LOG_LEVEL_ERROR, "data.c", 577,
			"Error: Null monster to update health\n");
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
		app_log(APP_LOG_LEVEL_ERROR, "data.c", 593,
			"Error: Null monster to get type\n");
		return 0;
	}
	return monster->type;
}

player_info* build_player(void){
	player_info* player = malloc(sizeof(player_info));
	if(player == NULL){
		app_log(APP_LOG_LEVEL_ERROR, "data.c", 603,
			"Error: Player malloc failed\n");
		return NULL;
	}
	player->damage_mod = 1.0;
	player->curr_level = 1;
	player->curr_xp = 0;
	player->next_xp = 10;
	return player;
}

void update_player_info(player_info* player, monster_info* monster){
	if(player== NULL){
		app_log(APP_LOG_LEVEL_ERROR, "data.c", 617,
			"Error: Player info null, cannot be updated\n");
		return;
	}
	if(monster == NULL){
		app_log(APP_LOG_LEVEL_ERROR, "data.c", 621,
			"Error: Monster info null, cannot be updated\n");
		return;
	}
	uint32_t new_xp = player->curr_xp + 2*monster->level;
	
	if(new_xp >= player->next_xp){
		player->curr_xp = 0;
		player->curr_level++;
		player->next_xp *= 2;
		player->damage_mod += 0.2;
	}
	else{
		player->curr_xp = new_xp;
	}
	
	return;
}

uint16_t get_player_level(player_info* player){
	if(player == NULL){
		app_log(APP_LOG_LEVEL_ERROR, "data.c", 642,
			"Error: Null player to get level\n");
		return 0;
	}
	return player->curr_level;
}

double get_damage_mod(player_info* player){
	if(player == NULL){
		app_log(APP_LOG_LEVEL_ERROR, "data.c", 651,
			"Error: Null player to get mod\n");
		return 0;
	}
	return player->damage_mod;
}


