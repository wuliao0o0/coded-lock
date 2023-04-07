#include <REGX52.H>
void Timer0Init()		//@11.0592MHz 100us
{	
	TMOD &= 0xF0;		
	TMOD |= 0x01;		
	TL0 = 0x91;		
	TH0 = 0xff;		
	TF0 = 0;		
	TR0 = 1;
	ET0=1;
	EA=1;
	PT0=0;
}
//void Timer0_Routine() interrupt 1
//{
//	static uint T0count;
//	TL0 = 0x91;		
//	TH0 = 0xff;
//	T0count++;
//	if(T0count>=1000)
//	{
//		T0count=0;
//	}
//	
//}