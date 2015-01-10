#include <pebble.h>



void init(){
  graphix(0,0,0);
  
}

void deinit(){
  ungraphix();
  
  
}

int main(void){
  init();
  
  app_event_loop();
  
  deinit();
  
  
}
  
