#ifndef W_UI_H
#define W_UI_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "./shared.h"
#include <math.h>

#define BUTTON_DEFAULT_COLOR al_map_rgb(131, 166, 255)
#define BUTTON_MENU_COLOR al_map_rgb(255, 197, 173)

typedef enum button_style {
  DEFAULT,
  MENU,
} button_style_t;

void draw_button(ALLEGRO_EVENT event,
                 int x,
                 int y,
                 int w,
                 int h,
                 button_style_t style,
                 const char* text,
                 void (*f)(void));

void draw_grid(int x,
               int y,
               int w,
               int h,
               int cell_size,
               ALLEGRO_COLOR color);

void draw_coord(int x,
                int y,
                const char* text,
                ALLEGRO_COLOR color);

void draw_vector(float x1,
                 float y1,
                 float x2,
                 float y2,
                 ALLEGRO_COLOR color);

#endif