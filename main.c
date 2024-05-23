
#define _POSIX_C_SOURCE 200112L

#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "serialize_lock.h"
#include "objects_init.h"
#include "lcd_handler.h"
#include "knob_handler.h"
#include "redraw_objects.h"
#include "move_objects.h"
#include "ball_logic.h"
#include "menu.h"
#include "led_line.h"

int main(int argc, char *argv[])
{

  int red_score = 0;
  int blue_score = 0;

  /* Initialize the LCD */
  unsigned char *parlcd_mem_base;
  parlcd_mem_base = map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
  if (parlcd_mem_base == NULL) {
    return 1;
  }

  unsigned char *spiled_base;
  spiled_base = map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
  if (spiled_base == NULL) {
    return 1;
  }

  unsigned char *led_base = map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
  if (led_base == NULL){
    exit(1);
  }
  *(volatile uint32_t*)(led_base + SPILED_REG_LED_LINE_o) = 0x00;

  GameField field;
  Ball ball;
  Player player1;
  Player player2;
  int bounce_count = 0;
  uint16_t *buffer;

  buffer = buffer_init();
  init_game(&field, &player1, &player2, &ball, parlcd_mem_base, buffer, led_base);

  uint8_t red_curr = *(spiled_base + SPILED_REG_KNOBS_8BIT_o + 2);
  uint8_t blue_curr = *(spiled_base + SPILED_REG_KNOBS_8BIT_o);

  int green_press = 0;

  ball_vec_init(&field);

  while (green_press == 0){
    draw_menu(&field);
    green_press = (*(volatile uint32_t*)(spiled_base + SPILED_REG_KNOBS_8BIT_o) >> 25) & 1;
  }

  while(1){
    init_background(&field, BLACK);
    clear_player(&field, 1);
    clear_player(&field,2);

    uint8_t red_old = red_curr;
    uint8_t blue_old = blue_curr;

    red_curr = check_red_knob(&field, spiled_base, red_old);
    blue_curr = check_blue_knob(&field, spiled_base, blue_old);

    draw_player(&field, 1);
    draw_player(&field, 2);
    draw_text(buffer, &font_winFreeSystem14x16, 480/2 - 40, 10, 2, 48+red_score, WHITE);
    draw_text(buffer, &font_winFreeSystem14x16, 480/2 + 40, 10, 2, 48+blue_score, WHITE);

    bounce_count = check_collision(&field, bounce_count, &red_score, &blue_score);
    clear_ball(&field);
    move_ball(&field);
    draw_ball(&field);
    draw(buffer, parlcd_mem_base);
    sleep(0.5);

    if (blue_score == 11 || red_score == 11){
      for (int y = 0; y < 320; y++){
        for (int x = 0; x < 480; x++){
            draw_pixel(buffer, x, y, BLACK);
        }
      }
      draw_text(buffer, &font_winFreeSystem14x16, 80, 320 * 0.3, 4, 71, WHITE); // G
      draw_text(buffer, &font_winFreeSystem14x16, 120, 320 * 0.3, 4, 65, WHITE); // A
      draw_text(buffer, &font_winFreeSystem14x16, 160, 320 * 0.3, 4, 77, WHITE); // M
      draw_text(buffer, &font_winFreeSystem14x16, 200, 320 * 0.3, 4, 69, WHITE); // E
      draw_text(buffer, &font_winFreeSystem14x16, 230, 320 * 0.3, 4, 32, WHITE); // space
      draw_text(buffer, &font_winFreeSystem14x16, 250, 320 * 0.3, 4, 79, WHITE); // O
      draw_text(buffer, &font_winFreeSystem14x16, 290, 320 * 0.3, 4, 86, WHITE); // V
      draw_text(buffer, &font_winFreeSystem14x16, 330, 320 * 0.3, 4, 69, WHITE); // E
      draw_text(buffer, &font_winFreeSystem14x16, 350, 320 * 0.3, 4, 82, WHITE); // R
      draw(buffer, parlcd_mem_base);
      break;
  } 

  ligh_led_line(led_base);
  }
  return 0;
}
