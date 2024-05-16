/**
 * @file menu.h
 * @brief Functions for drawing and managing the game menu
 */

#ifndef MENU_H
#define MENU_H

/**
 * @brief Draws the menu on the screen
 * @param field Pointer to the GameField structure
 * 
 * 
 * This function draws the menu elements on the game field buffer to display
 * the game's title and instructions for starting the game.
 * 
 * 
 */
void draw_menu(GameField *field);

#endif /* MENU_H */