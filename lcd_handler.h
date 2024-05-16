/**
 * @file lcd_handler.h
 * @brief Functions for handling the LCD screen
*/

#ifndef LCD_HANDLER_H
#define LCD_HANDLER_H

#include <stdint.h>
#include <stdlib.h>
#include "mzapo_parlcd.h"
#include "font_types.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"


/**
 * @brief Initializes the buffer for the LCD screen
 * @return Pointer to the buffer
 * 
 * This function initializes the buffer for the LCD screen and returns a pointer to it.
 * This function allocates memory for a buffer representing the LCD display.
 * 
 */
uint16_t * buffer_init();


/**
 * @brief Draws a pixel on the LCD screen
 * @param buffer Pointer to the buffer
 * @param x X coordinate of the pixel
 * @param y Y coordinate of the pixel
 * @param data Color of the pixel
 * 
 * This function draws a pixel of a specified color at the given coordinates on the LCD screen.
 * 
 * 
 */

void draw_pixel(uint16_t * buffer, int x, int y, uint16_t data);

/**
 * @brief Draws the buffer on the LCD screen
 * @param buffer Pointer to the buffer
 * @param parlcd_mem_base Address of the control register
 * 
 * This function draws the buffer on the LCD screen using the control register.
 * 
 * 
 */


void draw(uint16_t *buffer, unsigned char *parlcd_mem_base);


/**
 * @brief Draws text on the LCD display buffer.
 * @param buffer Pointer to the buffer representing the LCD display.
 * @param font Pointer to the font descriptor.
 * @param x The x-coordinate of the starting position for the text.
 * @param y The y-coordinate of the starting position for the text.
 * @param scale The scaling factor for the text.
 * @param char_code The character code of the text to be drawn.
 * @param color The color of the text.
 * 
 * 
 * This function draws text on the LCD display buffer using the specified font.
 * 
 * 
 */
void draw_text(uint16_t * buffer, font_descriptor_t *font, int x, int y, int scale, int char_code, int color);

/**
 * @brief Draws a pixel on the LCD screen with scaling
 * @param buffer Pointer to the buffer
 * @param x X coordinate of the pixel
 * @param y Y coordinate of the pixel
 * @param scale Scaling factor
 * @param data Color of the pixel
 * 
 * This function sets the color of multiple adjacent pixels in the buffer, simulating scaling.
 * 
 * 
 */
void draw_scaling_pixel(uint16_t * buffer, int x, int y, int scale, uint16_t data);

#endif /* LCD_HANDLER_H */
