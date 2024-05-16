/**
 * @file ball_logic.h
 * @brief Function prototypes for ball logic functions
*/

#ifndef BALL_LOGIC_H
#define BALL_LOGIC_H


/**
 * @brief Initializes the velocity vector of the ball.
 * 
 * @param field Pointer to the GameField structure representing the game field.
 * 
 *  This function initializes the velocity vector of the ball with random values.
 * 
 * 
 */

void ball_vec_init(GameField *field);


/**
 * @brief Resets the position and velocity of the ball
 * 
 * @param field Pointer to the GameField structure representing the game field.
 * 
 * This function resets the position and velocity of the ball to the initial state.
 * 
 * 
 */

void reset_ball(GameField *field);


/**
 * @brief Checks for collisions and updates game state.
 * 
 * @param field Pointer to the GameField structure representing the game field.
 * @param bounce_count The count of consecutive bounces.
 * @param red_score Pointer to the variable storing the red player's score.
 * @param blue_score Pointer to the variable storing the blue player's score.
 * @return The updated count of consecutive bounces.
 *
 * This function checks for collisions between the ball and players,
 * updates game scores, and resets the ball if necessary.
 *
 * 
 */

int check_collision(GameField *field, int bounce_count, int *red_score, int *blue_score);

#endif /* BALL_LOGIC_H */

