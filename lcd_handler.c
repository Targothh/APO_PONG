#include "lcd_handler.h"
#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0

#define HEIGHT 320
#define WIDTH 480

uint16_t * buffer_init(){
    uint16_t * buffer;
    buffer = (uint16_t *) calloc(sizeof(uint16_t), WIDTH * HEIGHT);
    return buffer;
}

void draw_pixel(uint16_t * buffer, int x, int y, uint16_t data){
    buffer[x + WIDTH * y] = data;

}

void draw(uint16_t * buffer, unsigned char *parlcd_mem_base){
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for(int i = 0; i < WIDTH * HEIGHT; i++){
        parlcd_write_data(parlcd_mem_base, buffer[i]);
    }
}

int char_width(int ch, font_descriptor_t *font) {
  int width;
  if (!font->width) {
    width = font->maxwidth;
  } else {
    width = font->width[ch - font->firstchar];
  }
  return width;
}
 
void draw_scaling_pixel(uint16_t * buffer, int x, int y, int scale, uint16_t data){
    for(int i = 0; i < scale; i++){
        for(int j = 0; i < scale; j++){
            draw_pixel(buffer, x+i, y+j, data);
        }
    }
}

void draw_text(uint16_t * buffer, font_descriptor_t *font, int x, int y, int scale,  int char_code, int color){
    int w = char_width(char_code, font);
  const font_bits_t *ptr;
  if ((char_code >= font->firstchar) && (char_code-font->firstchar < font->size)) {
    if (font->offset) {
      ptr = &font->bits[font->offset[char_code-font->firstchar]];
    } else {
      int bw = (font->maxwidth+15)/16;
      ptr = &font->bits[(char_code - font->firstchar)*bw*font->height];
    }
    int i, j;
    for (i=0; i<font->height; i++) {
      font_bits_t val = *ptr;
      for (j=0; j<w; j++) {
        if ((val&0x8000)!=0) {
          draw_pixel(buffer ,x+scale*j, y+scale*i, color);
        }
        val<<=1;
      }
      ptr++;
    }
  }
    

}