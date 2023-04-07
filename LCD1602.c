#include <REGX52.H>
#include "delay.h"
sbit LCD_E=P2^7;
sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
#define uchar unsigned char
#define uint unsigned int
#define LCD_DataPort P0 //数据口
///////////////////////////////////////////////////
void LCD_WriteCommand(uchar Command)
{
	LCD_RS=0; //低电平为写指令
	LCD_RW=0; //低电平为写
	LCD_DataPort=Command;//存放写的指令    指令模块
	LCD_E=1;//是否运行
	delay(1);
	LCD_E=0;
	delay(1);
}
///////////////////////////////////////////////////
void LCD_WriteData(uchar Data)
{
	LCD_RS=1; //高电平为写数据
	LCD_RW=0; //低电平为写
	LCD_DataPort=Data;//存放写的数据                 数据模块
	LCD_E=1;//是否运行
	delay(1);
	LCD_E=0;
	delay(1);
}
///////////////////////////////////////////////////
void LCD_SetAc(uchar Line,uchar Col)//设置写入数据的行列信息
{
	if(Line==1)
	{
		LCD_WriteCommand(0x80|(Col-1));
	}
	else
	{
		LCD_WriteCommand(0x80|(Col-1)+0x40);
	}
}	
///////////////////////////////////////////////////
void LCD_Init() //初始化
{
	LCD_WriteCommand(0x38);
	delay(10); 
	LCD_WriteCommand(0x38);
	delay(10);                  //delay time only(big board) 
	LCD_WriteCommand(0x38);
	delay(10); 
	LCD_WriteCommand(0x0c);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x01);
}

void LCD_ShowChar(uchar Line,uchar Col,uchar Char)
{
	LCD_SetAc(Line,Col);
	LCD_WriteData(Char);
}

/////////////////////////////////////////////////////////////
/**
   *@brief	显示输入的字符或者字符串
   *@param	Line 	字符(串)所在的行位置
   *@param 	Col		字符(串)所在的列位置  
	 *@retval	无
   */
void LCD_ShowString(uchar Line,uchar Col,char *String)
{
	uchar i;
	LCD_SetAc(Line,Col);
	for(i=0;String[i]!='\0';i++)
	{
		LCD_WriteData(String[i]);
	}
}
/////////////////////////////////////////////////////////////
/**
   *@brief 显示数字范围在(-32768~32767)
   *@param Line 显示数字所在的行位置
   *@param Col  显示数字所在的列位置
   *@param Num  显示的数字
   *@retval 无
   */
void LCD_ShowNum(uchar Line,uchar Col,int Num)
{
	int i;
	int result;
	uchar NumSpace[20];
	LCD_SetAc(Line,Col);
	if(Num==0)
		{LCD_WriteData(0+'0');}//显示输入的数字
	if(Num<0)
	{
		LCD_WriteData('-');
		Num=-Num;
	}
	for(i=0;Num>0;i++)
	{
		result=Num;
		result%=10;
		NumSpace[i]=result;//顺序存储
		Num/=10;
	}

	for(i-=1;i>=0;i--)
	{ 
		LCD_WriteData(NumSpace[i]+'0');//逆序输出
	}
}
///////////////////////////////////////////////////
/**
   *@brief 显示十六进制数据
   *@param Line&Col 显示数据的行列位置
   *@retval 无
   */
void LCD_ShowHex(uchar Line,uchar Col,uint Num)
{
	int i;
	int result;
	uchar NumSpace[20];
	LCD_SetAc(Line,Col);
	if(Num==0)
		{LCD_WriteData(0+'0');}//显示输入的数字
	for(i=0;Num>0;i++)
	{
		result=Num;
		result%=16;
		NumSpace[i]=result;//顺序存储
		Num/=16;
	}

	for(i-=1;i>=0;i--)
	{ 
		if(NumSpace[i]>=10)
		{
			LCD_WriteData(NumSpace[i]+'A'-10);//逆序输出
		}
		else
		{
			LCD_WriteData(NumSpace[i]+'0');//逆序输出
		}
	}
}
