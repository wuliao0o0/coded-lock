#include <REGX52.H>
#include <string.h>
#include "delay.h"
#include "LCD1602.h"
#include "key.h"
#include "timer0.h"
#define uchar unsigned char
sbit motor=P1^0;
void main()
{
	uchar j;
	char password[]="20302211038";
//	uchar mark;
	uchar s[12];
	uchar keynum=10;
	LCD_Init();
	Timer0Init();
	while(1)
	{
		motor=0;
		delay(80);
		if(key()>9)
		{	
			if(key()==16)
			{
				if(strcmp(string,password)==0)
				{
					LCD_ShowString(2,1,"right");
					motor=1;
					delay(1000);
				}
				else
				{
					LCD_ShowString(2,1,"false");
					motor=0;
				}
			}
			continue;
		}
		else
		{
			keynum=key();
			if(keynum<10)
			{
				keynum+='0';
				string[i++]+=keynum;
				LCD_ShowChar(1,i,keynum);
				
			}
		}
		
	}
}
