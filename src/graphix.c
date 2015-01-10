#include <pebble.h>

#include "graphix.h"

static Window *s_main_window;
static Layer *s_canvas_layer;

void canvas_update_proc(Layer *this_layer, GContext *ctx)
{
	graphics_context_set_stroke_color(ctx,GColorBlack);
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
	s_main_window = window_create();
	window_set_window_handlers(s_main_window,(WindowHandlers){
		.load = __load;
		.unload = __unload;
	});
	window_stack_push(s_main_window,true);
}

void ungraphix()
{
	window_destroy(s_main_window);
}