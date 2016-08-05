#include <math.h>

#include "circle.h"
#include "rect.h"

static void dla_plot(int x, int y, uint8_t r,uint8_t g , uint8_t b, float br)
{
	uint8_t o_red = 0;
	uint8_t o_green = 0;
	uint8_t o_blue = 0;

	getLedXY(x,y,&o_red,&o_green,&o_blue);

	r=br*r+((1-br)*o_red);
	g=br*g+((1-br)*o_green);
	b=br*b+((1-br)*o_blue);
	setLedXY(x, y, r,g,b);


}

void draw_filledCircle(
		unsigned int x, unsigned int y,
		float rad,
		uint8_t r,
		uint8_t g,
		uint8_t b )
{
	int inside = 0;

	int maxins = rad*rad;
	int maxcir = (rad-1)*(rad-1);

	for(int i=rad;i>=0;i--)
	{
		int dist_a = i*i;

		for(int j=0;j<(i+1);j++)
		{
			int dist = dist_a + j*j;

			if(dist <= maxcir)
			{
				setLedXY(x-j,y+i,r,g,b);
				setLedXY(x+j,y+i,r,g,b);
				setLedXY(x+j,y-i,r,g,b);
				setLedXY(x-j,y-i,r,g,b);

				setLedXY(x-i,y-j,r,g,b);
				setLedXY(x-i,y+j,r,g,b);
				setLedXY(x+i,y+j,r,g,b);
				setLedXY(x+i,y-j,r,g,b);

				if(j==i)
				{
					inside=i;
					i=0;
				}

			}else if(dist < maxins)
			{
				float pct = 1 - ((dist-maxcir)/(float)(maxins-maxcir));

				dla_plot(x-j,y+i,r,g,b,pct);
				dla_plot(x+j,y+i,r,g,b,pct);
				dla_plot(x+j,y-i,r,g,b,pct);
				dla_plot(x-j,y-i,r,g,b,pct);

				dla_plot(x-i,y+j,r,g,b,pct);
				dla_plot(x+i,y+j,r,g,b,pct);
				dla_plot(x+i,y-j,r,g,b,pct);
				dla_plot(x-i,y-j,r,g,b,pct);
			}
			else
			{
				j=i+1;
			}
		}
	}

	if(inside)
	{
		draw_filledRect(x-inside,y-inside,inside*2,inside*2,r,g,b);
	}
}

void draw_circle(
		unsigned int x, unsigned int y,
		float rad,
		float t,
		uint8_t r,
		uint8_t g,
		uint8_t b )
{
	
	int maxins = rad*rad;
	int maxbor = (rad-t)*(rad-t);
	int maxbor2 = (rad-(t+1))*(rad-(t+1));
	int maxcir = (rad-1)*(rad-1);

	for(int i=rad;i>=0;i--)
	{
		int dist_a = i*i;

		for(int j=0;j<(i+1);j++)
		{
			int dist = dist_a + j*j;
			
			if((dist <= maxcir)&&(dist >= maxbor))
			{
				setLedXY(x-j,y+i,r,g,b);
				setLedXY(x+j,y+i,r,g,b);
				setLedXY(x+j,y-i,r,g,b);
				setLedXY(x-j,y-i,r,g,b);

				setLedXY(x-i,y-j,r,g,b);
				setLedXY(x-i,y+j,r,g,b);
				setLedXY(x+i,y+j,r,g,b);
				setLedXY(x+i,y-j,r,g,b);

			}
			else if((dist < maxins)&&(dist > maxcir))
			{
				float pct = 1 - ((dist-maxcir)/(float)(maxins-maxcir));

				dla_plot(x-j,y+i,r,g,b,pct);
				dla_plot(x+j,y+i,r,g,b,pct);
				dla_plot(x+j,y-i,r,g,b,pct);
				dla_plot(x-j,y-i,r,g,b,pct);

				dla_plot(x-i,y+j,r,g,b,pct);
				dla_plot(x+i,y+j,r,g,b,pct);
				dla_plot(x+i,y-j,r,g,b,pct);
				dla_plot(x-i,y-j,r,g,b,pct);

			}
			else if((dist < maxbor)&&(dist >= maxbor2))
			{
				float pct = 1 - ((dist-maxbor)/(float)(maxbor2-maxbor));

				dla_plot(x-j,y+i,r,g,b,pct);
				dla_plot(x+j,y+i,r,g,b,pct);
				dla_plot(x+j,y-i,r,g,b,pct);
				dla_plot(x-j,y-i,r,g,b,pct);

				dla_plot(x-i,y+j,r,g,b,pct);
				dla_plot(x+i,y+j,r,g,b,pct);
				dla_plot(x+i,y-j,r,g,b,pct);
				dla_plot(x-i,y-j,r,g,b,pct);

			}
		}
	}



}

static void onEllipsePoint(int xCenter,int yCenter,float x,float y,uint8_t r , uint8_t g, uint8_t b)
{
	setLedXY((xCenter + x),( yCenter + y),r,g,b);
	setLedXY((xCenter - x),( yCenter + y),r,g,b);
	setLedXY((xCenter + x),( yCenter - y),r,g,b);
	setLedXY((xCenter - x),( yCenter - y),r,g,b);
}

void draw_filledEllipse(
		unsigned int xcenter, unsigned int ycenter,
		float a,
		float b,
		uint8_t r,
		uint8_t g,
		uint8_t b2 )
{
	float x,y,d;
	x = 0;
	y = b;
	d = powf(b,2) - powf(a,2)*b + powf(a,2)/4;
	onEllipsePoint(xcenter,ycenter,x,y,r,g,b2);
	while( (a*a*(y-.5)) > (b*b*(x+1)) )
	{
		if(d<0)
		{
			d = d + powf(b,2)*(2*x+3);
			x=x+1;
		}
		else
		{
			d = d + powf(b,2)*(2*x+3) + powf(a,2)*(-2*y+2);
			x=x+1;
			y=y-1;
		}
		onEllipsePoint(xcenter,ycenter,x,y,r,g,b2);
	}
	d = b*b*powf((x+.5),2) + a*a*powf((y-1),2) - a*a*b*b;
	while(y>0)
	{
		if(d<0)
		{
			d = d + b*b*(2*x+2) + a*a*(-2*y+3);
			x++;
			y++;
		}
		else
		{
			d = d + a*a*(-2*y+3);
			y--;
		}
		onEllipsePoint(xcenter,ycenter,x,y,r,g,b2);
	}
}


