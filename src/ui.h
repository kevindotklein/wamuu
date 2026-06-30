#ifndef W_UI_H
#define W_UI_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "./shared.h"

#define BUTTON_DEFAULT_COLOR al_map_rgb(131, 166, 255)

typedef enum button_style {
  DEFAULT,
} button_style_t;

void draw_button(ALLEGRO_EVENT event,
                 int x,
                 int y,
                 int w,
                 int h,
                 button_style_t style,
                 const char* text,
                 void (*f)(void));

#endif