/*
 * modified version of : http://rosettacode.org/wiki/Xiaolin_Wu's_line_algorithm
 */


// 3k code on avr


#include "stdio.h"
#include "mcugui.h"
#include <math.h>

static void dla_plot(int x, int y, uint8_t r,uint8_t g , uint8_t b, float br)
{
	uint8_t o_red=0;
	uint8_t o_green=0;
	uint8_t o_blue=0;

	getLedXY(x,y,&o_red,&o_green,&o_blue);

	r=br*r+((1-br)*o_red);
	g=br*g+((1-br)*o_green);
	b=br*b+((1-br)*o_blue);
	setLedXY(x, y, r,g,b);


}

#define ipart_(X) ((int)(X))
#define round_(X) ((int)(((float)(X))+0.5))
#define fpart_(X) (((float)(X))-(float)ipart_(X))
#define rfpart_(X) (1.0-fpart_(X))

#define swap_(a, b) do{ __typeof__(a) tmp;  tmp = a; a = b; b = tmp; }while(0)
void draw_line(
	unsigned int x1, unsigned int y1,
	unsigned int x2, unsigned int y2,
	uint8_t r,
	uint8_t g,
	uint8_t b )
{
	float dx = (float)x2 - (float)x1;
	float dy = (float)y2 - (float)y1;
	if ( fabs(dx) > fabs(dy) ) 
	{
		if ( x2 < x1 ) 
		{
			swap_(x1, x2);
			swap_(y1, y2);
		}
		float gradient = dy / dx;
		float xend = round_(x1);
		float yend = y1 + gradient*(xend - x1);
		float xgap = rfpart_(x1 + 0.5f);
		int xpxl1 = xend;
		int ypxl1 = ipart_(yend);
		dla_plot(xpxl1, ypxl1, r,g,b,rfpart_(yend)*xgap);
		dla_plot(xpxl1, ypxl1+1, r,g,b,fpart_(yend)*xgap);
		float intery = yend + gradient;

		xend = round_(x2);
		yend = y2 + gradient*(xend - x2);
		xgap = fpart_(x2+0.5f);
		int xpxl2 = xend;
		int ypxl2 = ipart_(yend);
		dla_plot(xpxl2, ypxl2, r,g,b,rfpart_(yend) * xgap);
		dla_plot(xpxl2, ypxl2 + 1, r,g,b,fpart_(yend) * xgap);

		int x;
		for(x=xpxl1+1; x <= (xpxl2-1); x++) 
		{
			dla_plot(x, ipart_(intery), r,g,b,rfpart_(intery));
			dla_plot(x, ipart_(intery) + 1, r,g,b,fpart_(intery));
			intery += gradient;
		}
	
	} 
	else 
	{
	
		if ( y2 < y1 ) 
		{
			swap_(x1, x2);
			swap_(y1, y2);
		}
		float gradient = dx / dy;
		float yend = round_(y1);
		float xend = x1 + gradient*(yend - y1);
		float ygap = rfpart_(y1 + 0.5f);
		int ypxl1 = yend;
		int xpxl1 = ipart_(xend);
		dla_plot(xpxl1, ypxl1, r,g,b,rfpart_(xend)*ygap);
		dla_plot(xpxl1, ypxl1+1, r,g,b,fpart_(xend)*ygap);
		float interx = xend + gradient;
	
		yend = round_(y2);
		xend = x2 + gradient*(yend - y2);
		ygap = fpart_(y2+0.5f);
		int ypxl2 = yend;
		int xpxl2 = ipart_(xend);
		dla_plot(xpxl2, ypxl2, r,g,b,rfpart_(xend) * ygap);
		dla_plot(xpxl2, ypxl2 + 1, r,g,b,fpart_(xend) * ygap);
	
		int y;
		for(y=ypxl1+1; y <= (ypxl2-1); y++) 
		{
			dla_plot(ipart_(interx), y, r,g,b,rfpart_(interx));
			dla_plot(ipart_(interx) + 1, y, r,g,b,fpart_(interx));
			interx += gradient;
		}
	}
}

#define abs(my_val) ((my_val) < 0) ? -(my_val) : (my_val)

void draw_line_width(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, float wd,uint8_t r, uint8_t g, uint8_t b)
{ 
	int dx = abs((signed int)(x1-x0)), sx = x0 < x1 ? 1 : -1; 
	int dy = abs((signed int)(y1-y0)), sy = y0 < y1 ? 1 : -1; 
	int err = dx-dy, e2;
	unsigned int x2, y2;                          /* error value e_xy */
	float ed = dx+dy == 0 ? 1 : sqrtf((float)dx*dx+(float)dy*dy);

	for (wd = (wd+1)/2; ; ) {                                   /* pixel loop */
		dla_plot(x0,y0,r,g,b,fmaxf(0.0f,abs(err-dx+dy)/ed-wd+1));
		e2 = err; x2 = x0;
		if (2*e2 >= -dx) {                                           /* x step */
			for (e2 += dy, y2 = y0; e2 < ed*wd && (y1 != y2 || dx > dy); e2 += dx)
				dla_plot(x0,y2+=sy,r,g,b,fmaxf(0.0f,abs(e2)/ed-wd+1));
			if (x0 == x1) break;
			e2 = err; err -= dy; x0 += sx; 
		} 
		if (2*e2 <= dy) {                                            /* y step */
			for (e2 = dx-e2; e2 < ed*wd && (x1 != x2 || dx < dy); e2 += dy)
				dla_plot(x2+sx,y0,r,g,b,fmaxf(0.0f,abs(e2)/ed-wd+1));
			if (y0 == y1) break;
			err += dx; y0 += sy; 
		}
	}
}

#undef abs
#undef swap_
#undef ipart_
#undef fpart_
#undef round_
#undef rfpart_


