/**
 * @file move_objects.h
 * @brief Function prototypes for moving game objects.
 
*/

#ifndef MOVE_OBJECTS_H
#define MOVE_OBJECTS_H

/**
 * @brief Moves the ball on the game field according to its speed.
 * 
 * This function updates the position of the ball by adding its speed
 * components to its current position.
 * 
 * @param field Pointer to the GameField structure representing the game field.
 */

void move_ball(GameField *field);


/**
 * @brief Moves a player on the game field in the specified direction.
 * 
 * This function updates the position of the specified player based on the
 * direction provided and the player's speed.
 * 
 * @param field Pointer to the GameField structure representing the game field.
 * @param player The player to move (1 or 2).
 * @param direction The direction of movement (-1 for down, 1 for up).
 */

void move_player(GameField *field, int player, int direction);

#endif /* MOVE_OBJECTS_H */

