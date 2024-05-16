#include "lcd_handler.h"
#include "objects_init.h"
#include "mzapo_parlcd.h"

#define BLACK   0x0000


void draw_menu(GameField *field){
    for (int y = 0; y < field->height; y++){
        for (int x = 0; x < field->width; x++){
            draw_pixel(field->buffer, x, y, BLACK);
        }
    }
    draw(field->buffer, field->parlcd_mem_base);
    sleep(5);
}