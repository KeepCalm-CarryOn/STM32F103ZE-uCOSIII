1�� ��һ�α��� bsp.h ������ #include "stm32f10x_lib.h" ɾ���� lib �����ַ�
                                      Ӧ���� stm32f10x_conf.h
									  
									  
									  
2       RCC_PREDIV1Config(RCC_PREDIV1_Source_PLL2, RCC_PREDIV1_Div5);
..\?cosIII\BSP\bsp.c(198): warning:  #223-D: function "RCC_PLL1Config" declared implicitly
      RCC_PLL1Config(RCC_PLL1Source_PREDIV1, RCC_PLL1Mul_9);      /* PLL1 = Fprediv1 * 9 = 72Mhz.                         */
..\?cosIII\BSP\bsp.c(198): error:  #20: identifier "RCC_PLL1Source_PREDIV1" is undefined

��bsp.h �м����� #include "stm32f10x_rcc.h"         �����ã�ɾ����  
����ĵط��� bsp.c �� bsp_Init() �����У������ע�͵�   

bsp_ser .h  �б��� ������� .c�ļ���ʱȥ����

����ɹ���


1���ļ���·��ȫ���޸ĳ������ģ���Ϊ�ڲ��ұ����Ķ����ʱ��򲻿�·������֪���������û�й�ϵ
   ��ȷ���й�ϵ��
