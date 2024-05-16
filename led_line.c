/**
 * @file led_line.c
 * @brief Functions for lighting up the LED line
*/

#define _POSIX_C_SOURCE 200112L

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"

void light_all_leds(unsigned char *led_base) {
    uint32_t val_line = 0xFFFFFFFF;
    *(volatile uint32_t*)(led_base + SPILED_REG_LED_LINE_o) = val_line;
    sleep(3);

  *(volatile uint32_t*)(led_base + SPILED_REG_LED_LINE_o) = 0x00;

  return;
}

void ligh_led_line(unsigned char *led_base) {
    uint32_t val_line = 0x00000001;
    for (int i = 0; i < 30; i++) {
        *(volatile uint32_t*)(led_base + SPILED_REG_LED_LINE_o) = val_line;
        val_line <<= 1;
        sleep(1);
    }
    *(volatile uint32_t*)(led_base + SPILED_REG_LED_LINE_o) = 0x00;
    return;
}