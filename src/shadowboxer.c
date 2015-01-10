#include <pebble.h>

#include "graphix.h"

uint32_t test_max_health = 200;
uint32_t test_curr_health = 200;

void timer_test_handler()
{
	graphix(test_max_health,test_curr_health,0);
	app_timer_register(100,timer_test_handler,NULL);
}

void init(){
  timer_test_handler();
}

void deinit(){
  ungraphix();
  
  
}

int main(void){
  init();
  
  app_event_loop();
  
  deinit();
  
  
}
  
