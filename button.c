#include <string.h>

#include "button.h"
#include "rect.h"
#include "circle.h"
#include "text.h"

void draw_button_icon(uint16_t x, uint16_t y, uint8_t w, uint8_t filled,const char *text,
	uint8_t r,
	uint8_t g,
	uint8_t b,
	uint8_t r2,
	uint8_t g2,
	uint8_t b2 )
{

	if(filled == 1)
	{

		draw_filledCircle(x+15,y+15,15.0f,r,g,b);
		draw_filledCircle(x+15,y+40,15.0f,r,g,b);
		draw_filledCircle((x+w)-15,y+15,15.0f,r,g,b);
		draw_filledCircle((x+w)-15,y+40,15.0f,r,g,b);
		draw_filledRect(x+15,y,w-30,54,r,g,b);
		draw_filledRect(x,y+15,w-1,24,r,g,b);
	}
	else
	{
		draw_filledCircle(x+15,y+15,15.0f,0,0,0);
		draw_filledCircle((x+w)-15,y+15,15.0f,0,0,0);
		draw_circle(x+15,y+15,15.0f,3.0f,r,g,b);
		draw_circle((x+w)-15,y+15,15.0f,3.0f,r,g,b);
		draw_filledRect(x+15,y,w-30,29,0,0,0);

	}

	uint8_t length = strlen(text)*6;
	uint16_t pos = ((w-7)>>1)-(length>>1);
	draw_text_8x6(x+11+pos,y+40,text,r2,g2,b2);
};

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
)
{

	if(filled == 1)
	{

		draw_filledCircle(x+15,y+15,15.0f,r,g,b);
		draw_filledCircle(x+15,y+40,15.0f,r,g,b);
		draw_filledCircle((x+w)-15,y+15,15.0f,r,g,b);
		draw_filledCircle((x+w)-15,y+40,15.0f,r,g,b);
		draw_filledRect(x+15,y,w-30,54,r,g,b);
		draw_filledRect(x,y+15,w-1,24,r,g,b);
	}
	else
	{
		draw_filledCircle(x+15,y+15,15.0f,0,0,0);
		draw_filledCircle((x+w)-15,y+15,15.0f,0,0,0);
		draw_circle(x+15,y+15,15.0f,3.0f,r,g,b);
		draw_circle((x+w)-15,y+15,15.0f,3.0f,r,g,b);
		draw_filledRect(x+15,y,w-30,29,0,0,0);

	}

	uint8_t length = strlen(text)*6;
	uint16_t pos = ((w-7)>>1)-(length>>1);
	draw_text_8x6(x+11+pos,y+40,text,r2,g2,b2);

	uint8_t length2 = strlen(text2)*6;
	uint16_t pos2 = ((w-7)>>1)-(length2>>1);
	draw_text_8x6(x+11+pos2,y+20,text2,r3,g3,b3);
};


void draw_button_h(uint16_t x, uint16_t y, uint8_t w, uint8_t height,const char *text,
	uint8_t r,
	uint8_t g,
	uint8_t b,
	uint8_t r2,
	uint8_t g2,
	uint8_t b2 )
{

	draw_filledCircle(x+15,y+15,15.0f,r,g,b);
	draw_filledCircle(x+15,y+(height-15),15.0f,r,g,b);
	draw_filledCircle((x+w)-15,y+15,15.0f,r,g,b);
	draw_filledCircle((x+w)-15,y+(height-15),15.0f,r,g,b);
	draw_filledRect(x+15,y,w-30,height-1,r,g,b);
	draw_filledRect(x,y+15,w-1,height-30,r,g,b);

	uint8_t length = strlen(text)*6;
	uint16_t pos = (w>>1)-(length>>1);
	draw_text_8x6(x+pos,(y+(height>>1))-4,text,r2,g2,b2);
};

void draw_button(uint16_t x, uint16_t y, uint8_t w, uint8_t filled,const char *text,
	uint8_t r,
	uint8_t g,
	uint8_t b,
	uint8_t r2,
	uint8_t g2,
	uint8_t b2 )
{

	if(filled == 1)
	{

		draw_filledCircle(x+15,y+15,15.0f,r,g,b);
		draw_filledCircle((x+w)-15,y+15,15.0f,r,g,b);
		draw_filledRect(x+15,y,w-30,29,r,g,b);
	}
	else
	{
		draw_filledCircle(x+15,y+15,15.0f,0,0,0);
		draw_filledCircle((x+w)-15,y+15,15.0f,0,0,0);
		draw_circle(x+15,y+15,15.0f,3.0f,r,g,b);
		draw_circle((x+w)-15,y+15,15.0f,3.0f,r,g,b);
		draw_filledRect(x+15,y,w-30,29,0,0,0);

		for(uint8_t i=x+16;i<((x+w)-14);i++)
		{
			setLedXY(i,y+1,r,g,b);
			setLedXY(i,y+2,r,g,b);
			setLedXY(i,y+3,r,g,b);
			
			setLedXY(i,y+27,r,g,b);
			setLedXY(i,y+28,r,g,b);
			setLedXY(i,y+29,r,g,b);
		}

	}

	uint16_t textWidth = get_text_width_16pt(text);

	uint16_t pos = ((w-24)>>1)-(textWidth>>1);

	draw_text_16pt(x+12+pos,y+6,text,r2,g2,b2);

};

void draw_button8(uint16_t x, uint16_t y, uint8_t w, uint8_t filled,const char *text,
	uint8_t r,
	uint8_t g,
	uint8_t b,
	uint8_t r2,
	uint8_t g2,
	uint8_t b2 )
{

	if(filled == 1)
	{

		draw_filledCircle(x+7,y+7,7.0f,r,g,b);
		draw_filledCircle((x+w)-7,y+7,7.0f,r,g,b);
		draw_filledRect(x+7,y,w-14,13,r,g,b);
	}
	else
	{
		draw_filledCircle(x+7,y+7,7.0f,0,0,0);
		draw_filledCircle((x+w)-7,y+7,7.0f,0,0,0);
		draw_circle(x+7,y+7,7.0f,1.0f,r,g,b);
		draw_circle((x+w)-7,y+7,7.0f,1.0f,r,g,b);
		draw_filledRect(x+7,y,w-14,13,0,0,0);

		for(uint8_t i=x+8;i<((x+w)-6);i++)
		{
			setLedXY(i,y+1,r,g,b);
			
			setLedXY(i,y+13,r,g,b);
		}

	}

	uint8_t length = strlen(text)*6;
	uint16_t pos = ((w-7)>>1)-(length>>1);
	draw_text_8x6(x+8+pos,y,text,r2,g2,b2);




};

