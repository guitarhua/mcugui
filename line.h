#ifndef _WULINE_H
#define _WULINE_H

#include "mcugui.h"

void draw_line(
	unsigned int x0, unsigned int y0,
	unsigned int x1, unsigned int y1,
	uint8_t r,
	uint8_t g,
	uint8_t b );

void draw_line_width(
	unsigned int x0, unsigned int y0, 
	unsigned int x1, unsigned int y1, 
	float wd,
	uint8_t r, 
	uint8_t g, 
	uint8_t b );


#endif

