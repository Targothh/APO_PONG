/**
 * @file knob_handler.h
 * @brief Functions for handling knob input
 * 
 * This file contains functions for reading knob inputs and controlling game objects
 * based on the knob positions.
 */

#ifndef KNOB_HANDLER_H
#define KNOB_HANDLER_H

/**
 * @brief Checks the position of the red knob and moves the corresponding player.
 *
 * This function reads the position of the red knob and determines the direction
 * of movement for the corresponding player. It then calls the move_player function
 * to update the player's position accordingly.
 *
 * @param field Pointer to the GameField structure representing the game field.
 * @param spiled_base Pointer to the base address of the SPI LED controller.
 * @param red_curr The current position of the red knob.
 * @return The new position of the red knob.
 */

uint8_t check_red_knob(GameField *field, unsigned char *spiled_base, uint8_t red_curr);


/**
 * @brief Checks the position of the blue knob and moves the corresponding player.
 *
 * This function reads the position of the blue knob and determines the direction
 * of movement for the corresponding player. It then calls the move_player function
 * to update the player's position accordingly.
 *
 * @param field Pointer to the GameField structure representing the game field.
 * @param spiled_base Pointer to the base address of the SPI LED controller.
 * @param blue_curr The current position of the blue knob.
 * @return The new position of the blue knob.
 */
uint8_t check_blue_knob(GameField *field, unsigned char *spiled_base, uint8_t blue_curr);

#endif /* KNOB_HANDLER_H */