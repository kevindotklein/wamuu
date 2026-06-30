#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdbool.h>
#include <allegro5/allegro_ttf.h>
#include "./defs.h"
#include "./ui.h"
#include "./shared.h"

bool running;
mode_t mode;
ALLEGRO_FONT* font = NULL;

void handle_keys(ALLEGRO_EVENT event);
void render(ALLEGRO_EVENT event, mode_t mode);

int main(void) {
  al_init();
  al_init_primitives_addon();
  al_init_font_addon();
  al_install_keyboard();
  al_init_ttf_addon();
  al_install_mouse();

  al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
  ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
  font = al_load_font("./assets/fonts/gelasio.ttf", 20, 0);
  al_set_window_title(display, "wamuu");
  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
  ALLEGRO_EVENT_QUEUE* events = al_create_event_queue();

  al_register_event_source(events, al_get_display_event_source(display));
  al_register_event_source(events, al_get_timer_event_source(timer));
  al_register_event_source(events, al_get_keyboard_event_source());
  al_register_event_source(events, al_get_mouse_event_source());
  al_start_timer(timer);

  running = true;
  mode = MAIN_MENU;
  while(running) {
    ALLEGRO_EVENT event;
    al_wait_for_event(events, &event);

    do {
        switch (event.type) {
            case ALLEGRO_EVENT_KEY_DOWN:
                handle_keys(event);
                break;
        
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                running = false;
                break;
        }
    } while (al_get_next_event(events, &event));

    render(event, mode);
    al_flip_display();

  }

  al_destroy_font(font);
  al_destroy_display(display);
  al_destroy_event_queue(events);

  return 0;
}

void vectors_button(void) {mode = VECTORS;}
void main_menu_button(void) {mode = MAIN_MENU;}

void render(ALLEGRO_EVENT event, mode_t mode) {
  al_clear_to_color(BG_COLOR);

  switch (mode) {
    case MAIN_MENU: {
      al_draw_text(font, al_map_rgb(0, 0, 0), (1920/2)-50, 100, 0, "WAMUU (beta)");
      draw_button(event, 1920/3, 200, 110, 40, DEFAULT, "VECTORS", vectors_button);
    } break;

    case VECTORS: {
      al_draw_text(font, al_map_rgb(0, 0, 0), (1920/2)-50, 100, 0, "VECTORS");
      draw_grid((1920/2)-400, 200, 800, 600, 50, al_map_rgb(0, 0, 0));
      draw_coord((1920/2), 500, "(0,0)", al_map_rgb(255, 0, 0));
      draw_button(event, 30, 20, 150, 40, MENU, "MAIN MENU", main_menu_button);

      draw_vector(0, 0, 2, 0, al_map_rgb(0, 50, 180));
      draw_vector(0, 0, 2, 1, al_map_rgb(200, 50, 180));
    } break;
  
    default:
      break;
  }
}

void handle_keys(ALLEGRO_EVENT event) {
  switch (event.keyboard.keycode) {
    case ALLEGRO_KEY_ESCAPE:
      running = false;
      break;
    default:
      break;
  }
}

