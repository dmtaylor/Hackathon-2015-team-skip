/*

#include "pebble.h"

#define ACCEL_STEP_MS 50

typedef struct Vec2d {
  double x;
  double y;
} Vec2d;


static double next_radius = 3;

static Window *window;

static GRect window_frame;

static Layer *disc_layer;

static AppTimer *timer;

static DataSessionRef *logging_session;


static void timer_callback(void *data) {
  AccelData accel = (AccelData) { .x = 0, .y = 0, .z = 0 };
  CompassHeadingData comp=NULL;
  compass_service_peek(&comp);
  accel_service_peek(&accel);
  int data[4];
  data[0]=accel.x;
  data[1]=accel.y;
  data[2]=accel.z;
  data[3]=comp.CompassHeading;
  data_logging_log(logging_session, &data,4);
  


  timer = app_timer_register(ACCEL_STEP_MS, timer_callback, NULL);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect frame = window_frame = layer_get_frame(window_layer);

  disc_layer = layer_create(frame);
  layer_set_update_proc(disc_layer, disc_layer_update_callback);
  layer_add_child(window_layer, disc_layer);

  for (int i = 0; i < NUM_DISCS; i++) {
    disc_init(&discs[i]);
  }
}

static void window_unload(Window *window) {
  layer_destroy(disc_layer);
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
  logging_session=data_logging_create(0x1,DATA_LOGGING_UINT, 4, false);
  


  timer = app_timer_register(ACCEL_STEP_MS, timer_callback, NULL);
}

static void deinit(void) {
  accel_data_service_unsubscribe();
  data_logging_finish(logging_session);

  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
*/
