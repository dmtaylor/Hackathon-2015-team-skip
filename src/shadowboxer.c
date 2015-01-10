#include <pebble.h>

#include "graphix.h"

void init(){
  graphix(200,170,0);
  
}

void deinit(){
  ungraphix();
  
  
}

int main(void){
  init();
  
  app_event_loop();
  
  deinit();
  
  
}
  
