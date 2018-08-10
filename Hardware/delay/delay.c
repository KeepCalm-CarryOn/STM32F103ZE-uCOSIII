#include "delay.h"
static u16 fac_ms=0;
static u16 fac_us=0;


void delay_init()
{
 
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	//ѡ���ⲿʱ��  HCLK/8
	fac_us=SystemCoreClock/8000000;	//Ϊϵͳʱ�ӵ�1/8  
	fac_ms=(u16)fac_us*1000;//����ÿ��ms��Ҫ��systickʱ����   


}


void delay_ms(u16 nms)
{ 
	
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;//ʱ�����(SysTick->LOADΪ24bit)
	SysTick->VAL =0x00;           //��ռ�����
	SysTick->CTRL|=0x01;          //��ʼ����  
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=0x00;       //�رռ�����
	SysTick->VAL =0X00;       //��ռ�����	 



}
void delay_us(u32 nus)
{
	u32 temp=0;
  SysTick->LOAD = nus*fac_us;    //24λ��װֵ��  ʵ��ֵӦС�� 2^24/fac_us  
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
