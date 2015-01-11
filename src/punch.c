#include "pebble.h"
#include "punch.h"

#define VEC_SIZE 4
  
#define _S_THRESHOLD_ 2000000
#define _E_THRESHOLD_ 10000
#define _X_THRESHOLD_ 1200

static AppTimer *pch_timer;

typedef int Vec4d[VEC_SIZE];

//static GRect window_frame;

//static DataLoggingSessionRef logging_session;

static Vec4d prev_data;
static Vec4d max_acc;

static int in_action = false;
static int start_action=false;
static int laction=false;
static int raction=false;
static int lreturn=false;
static int rreturn=false;

//returns type of punch; 1=jab, 2=uppercut
int getPunch(){
  int p_type = 3;
  if( max_acc[1] < -1700 ){
    return p_type;
  }
  p_type = 2;
  if( max_acc[2] < -1700 || max_acc[2] > 1700 ){
    return p_type;
  }
  p_type = 1;
  if( max_acc[0] < -1500 || max_acc[0] > 1500 ){
    return p_type;
  }
  return 0;
}

static void roll_d10( int magnitude ){
  punch_d10 = (magnitude / 1000000) * 2 / 5;
}

void roll_d4(){
  int i;
  for(i = 0; i < VEC_SIZE; i++)
    if(punch_d4 < max_acc[i])
      punch_d4 = max_acc[i];
  punch_d4 /= 1000;
}

int punch_callback(void *data) {
  AccelData accel = (AccelData) { .x = 0, .y = 0, .z = 0 };
  accel_service_peek(&accel);
  
  
  Vec4d ratio;
  ratio[0] = accel.x-(prev_data)[0];
  ratio[1] = accel.y-(prev_data)[1];
  ratio[2] = accel.z-(prev_data)[2];
  
  int p_type = 0;
  
  int mag_diff = (ratio[0]*ratio[0] + ratio[1]*ratio[1] + ratio[2]*ratio[2]);
  
  if (!in_action && (mag_diff > _S_THRESHOLD_)){  //start
   //APP_LOG(APP_LOG_LEVEL_INFO,"Punch! %d", ++p_count);
    // Start action
    in_action = true;
    start_action = true;
  }
  if ( start_action && accel.x > _X_THRESHOLD_){ //laction
     // In action
    start_action = false;
    laction = true;
  }
  if ( start_action && accel.x < -_X_THRESHOLD_){ //raction
      start_action = false;
      raction = true;
  }
  if (laction && accel.x < -_X_THRESHOLD_){
      laction = false;
      p_type=getPunch();
      roll_d10(mag_diff);
      lreturn = true;
  }
  if ( raction && accel.x > _X_THRESHOLD_){
      raction = false;
      rreturn = true;
      p_type=getPunch();
      roll_d10(mag_diff);
  }
  if ( lreturn && accel.x > _X_THRESHOLD_){
      lreturn = false;
      in_action = false;
  }
  if ( rreturn && accel.x < -_X_THRESHOLD_){
      rreturn = false;
      in_action = false;
  }
  
   // APP_LOG(APP_LOG_LEVEL_INFO,"V: %d", velocity);
  if(in_action){
     if(accel.x*accel.x > max_acc[0]*max_acc[0]) max_acc[0] = accel.x; 
     if(accel.y< max_acc[1]) max_acc[1] = accel.y;
     if(accel.z*accel.z > max_acc[2]*max_acc[2]) max_acc[2] = accel.z; 
  }else{
    max_acc[0] = 0;
    max_acc[1] = 0;
    max_acc[2] = 0;
  }
  (prev_data)[0] = accel.x; 
  (prev_data)[1] = accel.y; 
  (prev_data)[2] = accel.z; 
  //APP_LOG(APP_LOG_LEVEL_INFO, "M: %d", max_acc[0]);
  //APP_LOG(APP_LOG_LEVEL_INFO,"A: %d, %d, %d; M: %d; T: %d", accel.x, accel.y, accel.z, comp_head, p_type);
  return p_type;
}

void reg_callback(void *data){
  int p_type = punch_callback(data);
  if(p_type == 1) vibes_double_pulse();
  else if (p_type == 2) vibes_long_pulse();
  else if (p_type == 3) vibes_short_pulse();
  
   //APP_LOG(APP_LOG_LEVEL_INFO,"T: %d", p_type);

  punch_Recent = p_type;
	
  pch_timer = app_timer_register(GAME_UPDATE_MS, reg_callback, NULL);
}

void pch_init(){
  punch_Recent = 0;
  punch_d10 = 0;
  punch_d4 = 0;
  
  accel_data_service_subscribe(0, NULL);
  pch_timer = app_timer_register(GAME_UPDATE_MS, reg_callback, NULL);
}

void pch_dinit(){
  accel_data_service_unsubscribe();
}
/* IMPORTANT CODE TO LOOK AT
  
  */
