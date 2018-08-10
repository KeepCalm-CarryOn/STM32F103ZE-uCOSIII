#ifndef _DELAY_H_
#define _DELAY_H_
#include "stm32f10x.h"
void delay_init(void);
void delay_ms(u16 ms);
void delay_us(u32 us);

#endif

