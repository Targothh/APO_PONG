/**
 * @file led_line.h
 * @brief Function prototypes for lighting up the LED line
*/

#ifndef LED_LINE_H
#define LED_LINE_H

/**
 * @brief Lights up all the LEDs on the LED line
 * 
 * This function lights up all the LEDs on the LED line for 3 seconds.
 * 
 * @param led_base Pointer to the base address of the LED line
 */

void light_all_leds(unsigned char *led_base);

/**
 * @brief Lights up the LEDs on the LED line one by one
 * 
 * This function lights up the LEDs on the LED line one by one, starting from the first LED.
 * 
 * @param led_base Pointer to the base address of the LED line
 */


void ligh_led_line(unsigned char *led_base);

#endif /* LED_LINE_H */
