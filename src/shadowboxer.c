#include <pebble.h>

#include "graphix.h"

uint32_t test_max_health = 200;
uint32_t test_curr_health = 200;

void timer_test_handler()
{
	graphix(test_max_health,test_curr_health,0);
	test_curr_health--;
}

void init(){
	tick_timer_service_subscribe(SECOND_UNIT,timer_test_handler);
}

void deinit(){
  ungraphix();
  
  
}

int main(void){
  init();
  
  app_event_loop();
  
  deinit();
  
  
}
  
