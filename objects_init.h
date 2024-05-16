/**
 * @file objects_init.h
 * @brief Header file containing function prototypes for initializing game objects
 */

#ifndef OBJECTS_INIT_H
#define OBJECTS_INIT_H

#include <stdint.h>

/**
 * @struct Player
 * @brief Structure representing a player in the game
 */

typedef struct Player {
    int x;              // Pozice hráče na ose x
    int y;              // Pozice hráče na ose y
    int width;          // Šířka hráče
    int height;         // Výška hráče
    int speed;          // Rychlost pohybu hráče
} Player;

/**
 * @struct Ball
 * @brief Structure representing the ball in the game
 */

typedef struct Ball {
    int x;              // Pozice míčku na ose x
    int y;              // Pozice míčku na ose y
    int size;         // Velikost míčku
    int speed_x;        // Rychlost míčku na ose x
    int speed_y;
} Ball;

/**
 * @struct GameField
 * @brief Structure representing the game field
 */

typedef struct GameField {
    int width;          // Šířka herního pole
    int height;         // Výška herního pole
    Player player1;     // První hráč
    Player player2;     // Druhý hráč
    Ball ball;          // Míček
    unsigned char *parlcd_mem_base; // Adresa řídicího registru
    uint16_t *buffer;
    unsigned char *led_base;
} GameField;

/**
 * @brief Initializes the net on the game field
 * 
 * @param field Pointer to the GameField structure
 */

void init_net(GameField *field);

/**
 * @brief Initializes the background of the game field
 * 
 * @param field Pointer to the GameField structure
 * @param color Color of the background
 */

void init_background(GameField *field, uint16_t color);

/**
 * @brief Initializes a player on the game field
 * 
 * @param field Pointer to the GameField structure
 * @param player Number of the player
 * @param x X coordinate of the player
 * @param y Y coordinate of the player
 * @param width Width of the player
 * @param height Height of the player
 * @param speed Speed of the player
 */

void init_player(GameField *field, int player, int x, int y, int width, int height, int speed);

/**
 * @brief Initializes the ball on the game field
 * 
 * @param field Pointer to the GameField structure
 * @param x X coordinate of the ball
 * @param y Y coordinate of the ball
 * @param size Size of the ball
 * @param speed_x Speed of the ball on the x axis
 * @param speed_y Speed of the ball on the y axis
 */

void init_ball(GameField *field, int x, int y, int size, int speed_x, int speed_y);

/**
 * @brief Initializes the game field
 * 
 * @param field Pointer to the GameField structure
 * @param player1 Pointer to the first player
 * @param player2 Pointer to the second player
 * @param ball Pointer to the ball
 * @param parlcd_mem_base Address of the control register
 * @param buffer Pointer to the buffer
 * @param led_base Address of the LED control register
 */

void init_game(GameField *field, Player *player1, Player *player2, Ball *ball, unsigned char *parlcd_mem_base, uint16_t * buffer, unsigned char *led_base);


#endif /* OBJECTS_INIT_H */