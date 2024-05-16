/**
 * @file redraw_objects.h
 * @brief Function prototypes for drawing game objects on the screen
 */

#ifndef REDRAW_OBJECTS_H
#define REDRAW_OBJECTS_H

/**
 * @brief Draws the player's racket on the screen
 * 
 * @param field Pointer to the GameField structure
 * @param player Player number (1 or 2)
 */

void draw_player(GameField *field, int player);



/**
 * @brief Draws the ball on the screen
 * 
 * @param field Pointer to the GameField structure
 */

void draw_ball(GameField *field);



/**
 * @brief Clears the player's racket from the screen
 * 
 * @param field Pointer to the GameField structure
 * @param player Player number (1 or 2)
 */

void clear_player(GameField *field, int player);


/**
 * @brief Clears the ball from the screen
 * 
 * @param field Pointer to the GameField structure
 */
 
void clear_ball(GameField *field);

#endif /* REDRAW_OBJECTS_H */