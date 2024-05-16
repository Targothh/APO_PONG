#define _POSIX_C_SOURCE 200112L

#include "objects_init.h"
#include "redraw_objects.h"
#include "led_line.h"
#include "lcd_handler.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

void ball_vec_init(GameField *field){
    srand(time(NULL));
    field -> ball.speed_x = rand() %10 > 5 ? -4 : 4;
    field -> ball.speed_y = rand() %8 - 4;
}

void reset_ball(GameField *field){
    clear_ball(field);
    field->ball.x =  field->width/2 - 10;
    field->ball.y =  field->height/2 - 5;
    ball_vec_init(field);
    draw_ball(field);
    draw(field->buffer, field->parlcd_mem_base);
    light_all_leds(field->led_base);
}



int check_collision(GameField *field, int bounce_count, int *red_score, int *blue_score){
    if(bounce_count == 2){ //postupne zrychleni hry
        field -> ball.speed_x > 0 ?  field -> ball.speed_x ++ : field -> ball.speed_x --;
        field -> ball.speed_y > 0 ?  field -> ball.speed_y ++ : field -> ball.speed_y --;
        bounce_count = 0; 
    }

    if((field -> ball.y - field -> ball.size) <= 0){
        field -> ball.speed_y = field -> ball.speed_y * -1;
    } else if((field -> ball.y + field -> ball.size) >= 320){
        field -> ball.speed_y = field -> ball.speed_y * -1;
    }

    if((field -> ball.x + field -> ball.size) >= 480){
        *blue_score += 1;
        fprintf(stderr, "Blue score: %d\n", *blue_score);
        reset_ball(field);
    }

    if ((field -> ball.x) <= 0){
        *red_score += 1;
        fprintf(stderr, "Red score: %d\n", *red_score);
        reset_ball(field);
    }
    
    if((field -> ball.y + field -> ball.size) > (field -> player2.y) 
    && (field -> ball.y + field -> ball.size) < (field -> player2.y + field ->player2.height + field -> ball.size) 
    && (field -> ball.x + field -> ball.size) >= field -> player2.x){
        field -> ball.speed_y = field -> ball.speed_y + rand()%6 -3;
        field -> ball.speed_x = field -> ball.speed_x * -1;
        bounce_count ++;
        printf("Speed x:%d, speed x %d\n", field -> ball.speed_x, field -> ball.speed_y );
    }
    else if((field -> ball.y + field -> ball.size) > (field -> player1.y) 
    && (field -> ball.y + field -> ball.size) < (field -> player1.y + field ->player1.height + field -> ball.size) 
    && (field -> ball.x - field -> ball.size) <= field -> player1.x - field -> player1.width){ 
        field -> ball.speed_y = field -> ball.speed_y + rand()%8 -4;
        field -> ball.speed_x = field -> ball.speed_x * -1;
        bounce_count ++;
        printf("Speed x:%d, speed x %d\n", field -> ball.speed_x, field -> ball.speed_y );
    }
    return bounce_count;
}
