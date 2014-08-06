#include <string.h>

#include "mcugui/button.h"
#include "mcugui/rect.h"
#include "mcugui/circle.h"
#include "mcugui/text.h"
#include "main.h"

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
		draw_circle(x+7,y+7,7.0f,1.0f,r,g,b);
		draw_circle((x+w)-7,y+7,7.0f,1.0f,r,g,b);
		draw_filledRect(x+7,y,w-14,13,0,0,0);

		for(uint8_t i=x+8;i<((x+w)-6);i++)
		{
			setLedXY(i,y+1,r,g,b);
			
			setLedXY(i,y+13,r,g,b);
		}

	}

	uint8_t length = strlen(text)*7;
	uint16_t pos = ((w-7)>>1)-(length>>1);
	draw_text_8x6(x+8+pos,y,text,r2,g2,b2);




};

