#include "lcd_handler.h"
#include "objects_init.h"
#include "mzapo_parlcd.h"
#include "menu.h"

#define BLACK   0x0000
#define WHITE   0xFFFF
#define GREEN   0x07E0


void draw_menu(GameField *field){
    for (int y = 0; y < field->height; y++){
        for (int x = 0; x < field->width; x++){
            draw_pixel(field->buffer, x, y, BLACK);
        }
    }
    //title
    draw_text(field->buffer, &font_winFreeSystem14x16, 90, field->height *0.3, 5, 80, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 170, field->height *0.3, 5, 79, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 250, field->height *0.3, 5, 78, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 330, field->height *0.3, 5, 71, WHITE);
    //press
    draw_text(field->buffer, &font_winFreeSystem14x16, 60, field->height *0.8, 2, 80, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 80, field->height *0.8, 2, 82, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 100, field->height *0.8, 2, 69, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 120, field->height *0.8, 2, 83, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 140, field->height *0.8, 2, 83, WHITE);
    //green
    draw_text(field->buffer, &font_winFreeSystem14x16, 170, field->height *0.8, 2, 71, GREEN);
    draw_text(field->buffer, &font_winFreeSystem14x16, 190, field->height *0.8, 2, 82, GREEN);
    draw_text(field->buffer, &font_winFreeSystem14x16, 210, field->height *0.8, 2, 69, GREEN);
    draw_text(field->buffer, &font_winFreeSystem14x16, 230, field->height *0.8, 2, 69, GREEN);
    draw_text(field->buffer, &font_winFreeSystem14x16, 250, field->height *0.8, 2, 78, GREEN);
    //to
    draw_text(field->buffer, &font_winFreeSystem14x16, 280, field->height *0.8, 2, 84, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 290, field->height *0.8, 2, 79, WHITE);
    //start
    draw_text(field->buffer, &font_winFreeSystem14x16, 320, field->height *0.8, 2, 83, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 340, field->height *0.8, 2, 84, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 360, field->height *0.8, 2, 65, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 380, field->height *0.8, 2, 82, WHITE);
    draw_text(field->buffer, &font_winFreeSystem14x16, 400, field->height *0.8, 2, 84, WHITE);
    
    draw(field->buffer, field->parlcd_mem_base);
}
