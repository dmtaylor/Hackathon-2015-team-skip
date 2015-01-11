// punch.h
// header file for detecting punches
//
// By: Andrew Kwong 

#ifndef __PUNCH_H__
#define __PUNCH_H__

#include "pebble.h"
  
#define GAME_UPDATE_MS 50

int punch_Recent;
int punch_d10;
int punch_d4;

int punch_callback(void*);

void reg_callback(void*);

void pch_init();

void pch_dinit();

void roll_d4();

int monsterReady();

#endif

