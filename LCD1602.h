#ifndef __LCD1602_H__
#define __LCD1602_H__
#define uchar unsigned char
#define uint unsigned int
void LCD_Init();
void LCD_ShowString(uchar Line,uchar Col,char *String);
void LCD_ShowChar(uchar Line,uchar Col,uchar Char);
void LCD_ShowNum(uchar Line,uchar Col,int Num);
void LCD_ShowHex(uchar Line,uchar Col,uint Num);
void LCD_WriteCommand(uchar Command);
#endif