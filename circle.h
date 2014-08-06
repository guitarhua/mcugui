#ifndef _CIRCLE_H
#define _CIRCLE_H

/*
 * void filledCircleSlice(
	unsigned int x, unsigned int y,
	float rad,
	uint8_t r,
	uint8_t g,
	uint8_t b,
	uint16_t slice_begin,
	uint16_t slide_end );
*/

#include <stdint.h>

void draw_filledCircle(
	unsigned int x, unsigned int y,
	float rad,
	uint8_t r,
	uint8_t g,
	uint8_t b );

void draw_circle(
	unsigned int x, unsigned int y,
	float rad,
	float t,
	uint8_t r,
	uint8_t g,
	uint8_t b );

void draw_filledEllipse(
	unsigned int x, unsigned int y,
	float radX,
	float radY,
	uint8_t r,
	uint8_t g,
	uint8_t b );

#endif

