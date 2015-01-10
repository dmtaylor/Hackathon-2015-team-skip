#include <pebble.h>

#include "graphix.h"

#define HEALTH_BAR_MARGIN_TOP     10
#define HEALTH_BAR_LENGTH        100
#define HEALTH_BAR_HEIGHT         20
#define HEALTH_BAR_OUTLINE_WHITE   1
#define HEALTH_BAR_OUTLINE_BLACK   1

#define HEALTH_BUFFER_SIZE        32
#define HEALTH_TEXT_WIDTH        100
#define HEALTH_TEXT_HEIGHT        20
#define HEALTH_TEXT_MARGIN_TOP     1

static Window *s_main_window;
static Layer *s_canvas_layer;

uint32_t _max_health;
uint32_t _curr_health;
uint32_t _prev_dmg;

char health_buffer[HEALTH_BUFFER_SIZE];

void canvas_update_proc(Layer *this_layer, GContext *ctx)
{
	GRect bounds = layer_get_bounds(this_layer);
	int16_t x_center = bounds.size.w / 2;
	graphics_context_set_stroke_color(ctx,GColorBlack);

	// black outline
	graphics_context_set_fill_color(ctx,GColorBlack);
	graphics_fill_rect(ctx,GRect(x_center - (HEALTH_BAR_LENGTH / 2)
		- HEALTH_BAR_OUTLINE_BLACK - HEALTH_BAR_OUTLINE_WHITE,
		HEALTH_BAR_MARGIN_TOP - HEALTH_BAR_OUTLINE_BLACK
		- HEALTH_BAR_OUTLINE_WHITE,HEALTH_BAR_LENGTH
		+ 2*HEALTH_BAR_OUTLINE_BLACK + 2*HEALTH_BAR_OUTLINE_WHITE,
		HEALTH_BAR_HEIGHT + 2*HEALTH_BAR_OUTLINE_BLACK
		+ 2*HEALTH_BAR_OUTLINE_WHITE),0,GCornerNone);

	// white outline
	graphics_context_set_fill_color(ctx,GColorWhite);
	graphics_fill_rect(ctx,GRect(x_center - (HEALTH_BAR_LENGTH / 2)
		- HEALTH_BAR_OUTLINE_WHITE,HEALTH_BAR_MARGIN_TOP
		- HEALTH_BAR_OUTLINE_WHITE,HEALTH_BAR_LENGTH
		+ 2*HEALTH_BAR_OUTLINE_WHITE,HEALTH_BAR_HEIGHT
		+ 2*HEALTH_BAR_OUTLINE_WHITE),0,GCornerNone);

	// health fill
	uint16_t rem_health = (uint16_t)((_curr_health / ((double)_max_health))
		* HEALTH_BAR_LENGTH);
	graphics_context_set_fill_color(ctx,GColorBlack);
	graphics_fill_rect(ctx,GRect(x_center - (HEALTH_BAR_LENGTH / 2),
		HEALTH_BAR_MARGIN_TOP,rem_health,HEALTH_BAR_HEIGHT),
		0,GCornerNone);

	snprintf(health_buffer,HEALTH_BUFFER_SIZE,"%d/%d",
		(int)_curr_health,(int)_max_health);

	graphics_context_set_text_color(ctx,GColorBlack);
	graphics_draw_text(ctx,health_buffer,
		fonts_get_system_font(FONT_KEY_GOTHIC_14),GRect(0,0,50,50),GTextOverflowModeTrailingEllipsis,
		GTextAlignmentCenter,NULL);

/*GRect(x_center
		- (HEALTH_TEXT_WIDTH / 2),HEALTH_BAR_MARGIN_TOP
		+ 3*HEALTH_BAR_OUTLINE_WHITE + 3*HEALTH_BAR_OUTLINE_BLACK
		+ HEALTH_TEXT_MARGIN_TOP,x_center + (HEALTH_TEXT_WIDTH / 2),
		HEALTH_BAR_MARGIN_TOP + 3*HEALTH_BAR_OUTLINE_WHITE
		+ 3*HEALTH_BAR_OUTLINE_BLACK + HEALTH_TEXT_MARGIN_TOP
		+ HEALTH_TEXT_HEIGHT)*/
}

void __load(Window* window)
{
	Layer* window_layer = window_get_root_layer(window);
	GRect window_bounds = layer_get_bounds(window_layer);
	
	s_canvas_layer = layer_create(GRect(0,0,window_bounds.size.w,window_bounds.size.h));
	layer_add_child(window_layer,s_canvas_layer);
	
	layer_set_update_proc(s_canvas_layer,canvas_update_proc);
}

void __unload(Window* window)
{
	layer_destroy(s_canvas_layer);
}

void graphix(uint32_t max_health , uint32_t curr_health , uint32_t prev_dmg)
{
	_max_health = max_health;
	_curr_health = curr_health;
	_prev_dmg = prev_dmg;

	s_main_window = window_create();
	window_set_window_handlers(s_main_window,(WindowHandlers){
		.load = __load,
		.unload = __unload,
	});
	window_stack_push(s_main_window,true);
}

void ungraphix()
{
	window_destroy(s_main_window);
}