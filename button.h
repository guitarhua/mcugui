#ifndef _BUTTON_H
#define _BUTTON_H

#include "mcugui.h"

void draw_button_icon(uint16_t x, uint16_t y, uint8_t w, uint8_t filled,const char *text,
	uint8_t r,
	uint8_t g,
	uint8_t b, 
	uint8_t r2,
	uint8_t g2,
	uint8_t b2 
	);

void draw_button_icon2(uint16_t x, uint16_t y, uint8_t w, uint8_t filled,const char *text,const char *text2,
	uint8_t r,
	uint8_t g,
	uint8_t b, 
	uint8_t r2,
	uint8_t g2,
	uint8_t b2,
	uint8_t r3,
	uint8_t g3,
	uint8_t b3 
	);

void draw_button_h(uint16_t x, uint16_t y, uint8_t w, uint8_t height,const char *text,
	uint8_t r,
	uint8_t g,
	uint8_t b, 
	uint8_t r2,
	uint8_t g2,
	uint8_t b2 
	);

void draw_button(uint16_t x, uint16_t y, uint8_t w, uint8_t filled,const char *text,
	uint8_t r,
	uint8_t g,
	uint8_t b, 
	uint8_t r2,
	uint8_t g2,
	uint8_t b2 
	);

void draw_button8(uint16_t x, uint16_t y, uint8_t w, uint8_t filled,const char *text,
	uint8_t r,
	uint8_t g,
	uint8_t b,
	uint8_t r2,
	uint8_t g2,
	uint8_t b2 
	);



#endif

