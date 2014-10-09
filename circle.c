#include "stdio.h"
#include "main.h"
#include <math.h>

#include "libs/armmath.h"


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

	float i,j;

	for(i=0;i<rad;i++)
	{
		for(j=0;j<(i+1);j++)
		{
			float dist = pythagorasf( j,i );
			if(dist <= rad-1)
			{
				setLedXY(x-j,y+i,r,g,b);
				setLedXY(x+j,y+i,r,g,b);
				setLedXY(x+j,y-i,r,g,b);
				setLedXY(x-j,y-i,r,g,b);

				setLedXY(x-i,y-j,r,g,b);
				setLedXY(x-i,y+j,r,g,b);
				setLedXY(x+i,y+j,r,g,b);
				setLedXY(x+i,y-j,r,g,b);

			}else if(dist < rad)
			{
				dla_plot(x-j,y+i,r,g,b,1-(dist-rad+1));
				dla_plot(x+j,y+i,r,g,b,1-(dist-rad+1));
				dla_plot(x+j,y-i,r,g,b,1-(dist-rad+1));
				dla_plot(x-j,y-i,r,g,b,1-(dist-rad+1));

				dla_plot(x-i,y+j,r,g,b,1-(dist-rad+1));
				dla_plot(x+i,y+j,r,g,b,1-(dist-rad+1));
				dla_plot(x+i,y-j,r,g,b,1-(dist-rad+1));
				dla_plot(x-i,y-j,r,g,b,1-(dist-rad+1));
			}
		}
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

	float i,j;

	t++;

	for(i=0;i<rad;i++)
	{
		for(j=0;j<(i+1);j++)
		{
			float dist = pythagorasf( j,i );
			if((dist <= rad-1)&&(dist >= ((rad-t)+1)))
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
			else if((dist < rad)&&(dist > rad-1))
			{
				dla_plot(x-j,y+i,r,g,b,1-(dist-rad+1));
				dla_plot(x+j,y+i,r,g,b,1-(dist-rad+1));
				dla_plot(x+j,y-i,r,g,b,1-(dist-rad+1));
				dla_plot(x-j,y-i,r,g,b,1-(dist-rad+1));

				dla_plot(x-i,y+j,r,g,b,1-(dist-rad+1));
				dla_plot(x+i,y+j,r,g,b,1-(dist-rad+1));
				dla_plot(x+i,y-j,r,g,b,1-(dist-rad+1));
				dla_plot(x-i,y-j,r,g,b,1-(dist-rad+1));
			}
			else if((dist < (rad-t+1))&&(dist > rad-t))
			{
				dla_plot(x-j,y+i,r,g,b,dist-(rad-t));
				dla_plot(x+j,y+i,r,g,b,dist-(rad-t));
				dla_plot(x+j,y-i,r,g,b,dist-(rad-t));
				dla_plot(x-j,y-i,r,g,b,dist-(rad-t));

				dla_plot(x-i,y+j,r,g,b,dist-(rad-t));
				dla_plot(x+i,y+j,r,g,b,dist-(rad-t));
				dla_plot(x+i,y-j,r,g,b,dist-(rad-t));
				dla_plot(x-i,y-j,r,g,b,dist-(rad-t));
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
	d = pow(b,2) - pow(a,2)*b + pow(a,2)/4;
	onEllipsePoint(xcenter,ycenter,x,y,r,g,b2);
	while( (a*a*(y-.5)) > (b*b*(x+1)) )
	{
		if(d<0)
		{
			d = d + pow(b,2)*(2*x+3);
			x=x+1;
		}
		else
		{
			d = d + pow(b,2)*(2*x+3) + pow(a,2)*(-2*y+2);
			x=x+1;
			y=y-1;
		}
		onEllipsePoint(xcenter,ycenter,x,y,r,g,b2);
	}
	d = b*b*pow((x+.5),2) + a*a*pow((y-1),2) - a*a*b*b;
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


