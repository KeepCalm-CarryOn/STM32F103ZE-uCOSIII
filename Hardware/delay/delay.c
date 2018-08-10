#include "delay.h"
static u16 fac_ms=0;
static u16 fac_us=0;


void delay_init()
{
 
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	//选择外部时钟  HCLK/8
	fac_us=SystemCoreClock/8000000;	//为系统时钟的1/8  
	fac_ms=(u16)fac_us*1000;//代表每个ms需要的systick时钟数   


}


void delay_ms(u16 nms)
{ 
	
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;//时间加载(SysTick->LOAD为24bit)
	SysTick->VAL =0x00;           //清空计数器
	SysTick->CTRL|=0x01;          //开始倒数  
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//等待时间到达   
	SysTick->CTRL&=0x00;       //关闭计数器
	SysTick->VAL =0X00;       //清空计数器	 



}
void delay_us(u32 nus)
{
	u32 temp=0;
  SysTick->LOAD = nus*fac_us;    //24位重装值，  实际值应小于 2^24/fac_us  
  SysTick->VAL = 0x00;
  SysTick->CTRL|=0x01;
	do
	{
  temp=SysTick->CTRL;
  }
	while((temp&0x01)&&!(temp&(1<<16)));
  SysTick->CTRL&=0x00;
  SysTick->VAL = 0x00;
	
	


}
