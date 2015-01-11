/*

#include "pebble.h"

#define ACCEL_STEP_MS 50
#define VEC_SIZE 4
  
#define _S_THRESHOLD_ 2000000
#define _E_THRESHOLD_ 10000

typedef int Vec4d[VEC_SIZE];

static Window *window;

//static GRect window_frame;

static AppTimer *timer;

//static DataLoggingSessionRef logging_session;

static Vec4d *prev_data;

static int in_action = false;

static int p_count = 0;

static void timer_callback(void *data) {
  AccelData accel = (AccelData) { .x = 0, .y = 0, .z = 0 };
  CompassHeadingData comp;
  compass_service_peek(&comp);
  accel_service_peek(&accel);
  
  //APP_LOG(APP_LOG_LEVEL_INFO,"A: %d, %d, %d; H: %d",dat[0], dat[1], dat[2], dat[3]);
  
  Vec4d ratio;
  ratio[0] = accel.x-(*prev_data)[0];
  ratio[1] = accel.y-(*prev_data)[1];
  ratio[2] = accel.z-(*prev_data)[2];
  ratio[3] = comp.true_heading-(*prev_data)[3];
  
  int mag_diff = (ratio[0]*ratio[0] + ratio[1]*ratio[1] + ratio[2]*ratio[2]);
  
  //APP_LOG(APP_LOG_LEVEL_INFO,"T: %d; M: %d; C: %d", in_action, mag_diff, p_count);
  
  if (!in_action && (mag_diff > _S_THRESHOLD_)){
    vibes_short_pulse();
   //APP_LOG(APP_LOG_LEVEL_INFO,"Punch! %d", ++p_count);
    // Start action
    in_action = true;
  }else if ( in_action && (mag_diff < _E_THRESHOLD_)){
  //  vibes_cancel();
     
    in_action = false;

  }
   // APP_LOG(APP_LOG_LEVEL_INFO,"V: %d", velocity);
  (*prev_data)[0] = accel.x; 
  (*prev_data)[1] = accel.y; 
  (*prev_data)[2] = accel.z; 
  (*prev_data)[3] = comp.true_heading; 

  timer = app_timer_register(ACCEL_STEP_MS, timer_callback, NULL);
}
static void window_load(Window *window) {
  //Layer *window_layer = window_get_root_layer(window);
  //GRect frame = window_frame = layer_get_frame(window_layer);
}

static void window_unload(Window *window) {
}

static void init(void) {
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload
  });
  window_stack_push(window, true );
  window_set_background_color(window, GColorBlack);

  accel_data_service_subscribe(0, NULL);
  compass_service_subscribe(NULL);
  //logging_session=data_logging_create(0x1,DATA_LOGGING_UINT, 4, false);
  
  prev_data = calloc (sizeof(Vec4d), 1);

  timer = app_timer_register(ACCEL_STEP_MS, timer_callback, NULL);
}

static void deinit(void) {
  accel_data_service_unsubscribe();
  //data_logging_finish(logging_session);
  
  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
*/
