#include "./ui.h"

void draw_button(ALLEGRO_EVENT event,
                 int x,
                 int y,
                 int w,
                 int h,
                 button_style_t style,
                 const char* text,
                 void (*f)(void)) {

  // click

  if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
      int mx = event.mouse.x;
      int my = event.mouse.y;
  
      if(mx >= x && mx <= (x + w) && my >= y && my <= (y + h)) {
        f();
      }
  }

  // render

  ALLEGRO_COLOR color;
  switch (style) {
    case DEFAULT:
      color = BUTTON_DEFAULT_COLOR;
      break;
    case MENU:
      color = BUTTON_MENU_COLOR;
      break;
    default:
      color = BUTTON_DEFAULT_COLOR;
      break;
  }
    
  al_draw_filled_rectangle(x, y, x+w, y+h, color);
  al_draw_rectangle(x, y, x+w, y+h, al_map_rgb(0, 0, 0), 1);
  al_draw_text(font, al_map_rgb(0, 0, 0), x + (w/2), y + (h/2) - 12, ALLEGRO_ALIGN_CENTER, text);
}

void draw_grid(int x,
               int y,
               int w,
               int h,
               int cell_size,
               ALLEGRO_COLOR color) {

  for(int i=x; i<=x+w; i+=cell_size) {
    al_draw_line(i, y, i, y+h, color, 1);
  }

  for(int i=y; i<=y+h; i+=cell_size) {
    al_draw_line(x, i, x+w, i, color, 1);
  }
}

void draw_coord(int x,
                int y,
                const char* text,
                ALLEGRO_COLOR color) {

  al_draw_filled_circle(x, y, 3, color);
  al_draw_text(font, al_map_rgb(0, 0, 0), x+5, y+5, 0, text);
}

void draw_vector(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color) {
  float nx1 = (1920/2) + x1;
  float ny1 = 500 - y1;
  float nx2 = nx1 + (x2*50);
  float ny2 = ny1 - (y2*50);

  float a = atan2f(ny2 - ny1, nx2 - nx1);
  float s = 10.0f;

  al_draw_line(nx1, ny1, nx2, ny2, color, 2);

  al_draw_line(nx2, ny2,
               nx2 - s * cosf(a - ALLEGRO_PI / 6),
               ny2 - s * sinf(a - ALLEGRO_PI / 6),
               color, 2);

  al_draw_line(nx2, ny2,
               nx2 - s * cosf(a + ALLEGRO_PI / 6),
               ny2 - s * sinf(a + ALLEGRO_PI / 6),
               color, 2);
}