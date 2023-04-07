#include <REGX52.H>
#include "delay.h"
#include "LCD1602.h"
unsigned char i=0;
char string[12];
char key()
{
	char Keynumber=10;
	P1=0xff;
	P1_7=0;
	if(P1_3==0){delay(20);if(P1_3==0){Keynumber=1;}}
	if(P1_2==0){delay(20);if(P1_2==0){Keynumber=2;}}
	if(P1_1==0){delay(20);if(P1_1==0){Keynumber=3;}}
	if(P1_0==0){delay(20);if(P1_0==0){Keynumber=4;}}
	                  
	P1=0xff;          
	P1_6=0;           
	if(P1_3==0){delay(20);if(P1_3==0){Keynumber=5;}}
	if(P1_2==0){delay(20);if(P1_2==0){Keynumber=6;}}
	if(P1_1==0){delay(20);if(P1_1==0){Keynumber=7;}}
	if(P1_0==0){delay(20);if(P1_0==0){Keynumber=8;}}
	                 
	P1=0xff;         
	P1_5=0;          
	if(P1_3==0){delay(20);if(P1_3==0){Keynumber=9;}}
	if(P1_2==0){delay(20);if(P1_2==0){Keynumber=0;}}
	if(P1_1==0){delay(20);if(P1_1==0){Keynumber=11;}}
	if(P1_0==0){delay(20);if(P1_0==0){Keynumber=12;}}
	                 
	P1=0xff;         
	P1_4=0;          
	if(P1_3==0){delay(20);if(P1_3==0){Keynumber=13;}}
	if(P1_2==0){delay(20);if(P1_2==0){Keynumber=14;}}
	if(P1_1==0){delay(20);if(P1_1==0){Keynumber=15;i=0;}}//清屏加返回键值
	if(P1_0==0){delay(20);if(P1_0==0){Keynumber=16;}}
	return Keynumber;
}