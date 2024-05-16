#include "lcd_handler.h"
#include "objects_init.h"
#include "mzapo_parlcd.h"
#include "menu.h"

#define BLACK   0x0000
#define WHITE   0xFFFF


void draw_menu(GameField *field){
    for (int y = 0; y < field->height; y++){
        for (int x = 0; x < field->width; x++){
            draw_pixel(field->buffer, x, y, BLACK);
        }
    }
    draw_text(field->buffer, &font_winFreeSystem14x16, 100, field->height *0.3, 5, 80, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 180, field->height *0.3, 5, 79, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 260, field->height *0.3, 5, 78, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 340, field->height *0.3, 5, 71, WHITE);
    draw(field->buffer, field->parlcd_mem_base);
}
