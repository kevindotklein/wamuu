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
  
    default:
      color = BUTTON_DEFAULT_COLOR;
      break;
  }
    
  al_draw_filled_rectangle(x, y, x+w, y+h, color);
  al_draw_rectangle(x, y, x+w, y+h, al_map_rgb(0, 0, 0), 1);
  al_draw_text(font, al_map_rgb(0, 0, 0), x + (w/2), y + (h/2) - 12, ALLEGRO_ALIGN_CENTER, text);
}