// punch.h
// header file for detecting punches
//
// By: Andrew Kwong 

#ifndef __PUNCH_H__
#define __PUNCH_H__

#include "pebble.h"

static int punch_Recent = 0;
static int punch_d20 = 0;
static int punch_d4 = 0;

static int punch_callback(void *data);

static void reg_callback(void *data);

static void pch_init();

static void pch_dinit();

#endif

