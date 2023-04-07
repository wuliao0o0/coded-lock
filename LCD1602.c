#include <REGX52.H>
#include "delay.h"
sbit LCD_E=P2^7;
sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
#define uchar unsigned char
#define uint unsigned int
#define LCD_DataPort P0 //���ݿ�
///////////////////////////////////////////////////
void LCD_WriteCommand(uchar Command)
{
	LCD_RS=0; //�͵�ƽΪдָ��
	LCD_RW=0; //�͵�ƽΪд
	LCD_DataPort=Command;//���д��ָ��    ָ��ģ��
	LCD_E=1;//�Ƿ�����
	delay(1);
	LCD_E=0;
	delay(1);
}
///////////////////////////////////////////////////
void LCD_WriteData(uchar Data)
{
	LCD_RS=1; //�ߵ�ƽΪд����
	LCD_RW=0; //�͵�ƽΪд
	LCD_DataPort=Data;//���д������                 ����ģ��
	LCD_E=1;//�Ƿ�����
	delay(1);
	LCD_E=0;
	delay(1);
}
///////////////////////////////////////////////////
void LCD_SetAc(uchar Line,uchar Col)//����д�����ݵ�������Ϣ
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
void LCD_Init() //��ʼ��
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
   *@brief	��ʾ������ַ������ַ���
   *@param	Line 	�ַ�(��)���ڵ���λ��
   *@param 	Col		�ַ�(��)���ڵ���λ��  
	 *@retval	��
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
   *@brief ��ʾ���ַ�Χ��(-32768~32767)
   *@param Line ��ʾ�������ڵ���λ��
   *@param Col  ��ʾ�������ڵ���λ��
   *@param Num  ��ʾ������
   *@retval ��
   */
void LCD_ShowNum(uchar Line,uchar Col,int Num)
{
	int i;
	int result;
	uchar NumSpace[20];
	LCD_SetAc(Line,Col);
	if(Num==0)
		{LCD_WriteData(0+'0');}//��ʾ���������
	if(Num<0)
	{
		LCD_WriteData('-');
		Num=-Num;
	}
	for(i=0;Num>0;i++)
	{
		result=Num;
		result%=10;
		NumSpace[i]=result;//˳��洢
		Num/=10;
	}

	for(i-=1;i>=0;i--)
	{ 
		LCD_WriteData(NumSpace[i]+'0');//�������
	}
}
///////////////////////////////////////////////////
/**
   *@brief ��ʾʮ����������
   *@param Line&Col ��ʾ���ݵ�����λ��
   *@retval ��
   */
void LCD_ShowHex(uchar Line,uchar Col,uint Num)
{
	int i;
	int result;
	uchar NumSpace[20];
	LCD_SetAc(Line,Col);
	if(Num==0)
		{LCD_WriteData(0+'0');}//��ʾ���������
	for(i=0;Num>0;i++)
	{
		result=Num;
		result%=16;
		NumSpace[i]=result;//˳��洢
		Num/=16;
	}

	for(i-=1;i>=0;i--)
	{ 
		if(NumSpace[i]>=10)
		{
			LCD_WriteData(NumSpace[i]+'A'-10);//�������
		}
		else
		{
			LCD_WriteData(NumSpace[i]+'0');//�������
		}
	}
}
