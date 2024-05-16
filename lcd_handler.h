#include <stdint.h>
#include <stdlib.h>
#include "mzapo_parlcd.h"
#include "font_types.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
uint16_t * buffer_init();
void draw_pixel(uint16_t * buffer, int x, int y, uint16_t data);
void draw(uint16_t *buffer, unsigned char *parlcd_mem_base);
void draw_text(uint16_t * buffer, font_descriptor_t *font, int x, int y, int scale, int char_code, int color);
void draw_scaling_pixel(uint16_t * buffer, int x, int y, int scale, uint16_t data);
