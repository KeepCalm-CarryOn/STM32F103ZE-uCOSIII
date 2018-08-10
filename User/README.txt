1、 第一次编译 bsp.h 报错。把 #include "stm32f10x_lib.h" 删掉了 lib 三个字符
                                      应该是 stm32f10x_conf.h
									  
									  
									  
2       RCC_PREDIV1Config(RCC_PREDIV1_Source_PLL2, RCC_PREDIV1_Div5);
..\?cosIII\BSP\bsp.c(198): warning:  #223-D: function "RCC_PLL1Config" declared implicitly
      RCC_PLL1Config(RCC_PLL1Source_PREDIV1, RCC_PLL1Mul_9);      /* PLL1 = Fprediv1 * 9 = 72Mhz.                         */
..\?cosIII\BSP\bsp.c(198): error:  #20: identifier "RCC_PLL1Source_PREDIV1" is undefined

在bsp.h 中加入了 #include "stm32f10x_rcc.h"         不管用，删除掉  
出错的地方在 bsp.c 的 bsp_Init() 函数中，把这个注释掉   

bsp_ser .h  中报错 ，把这个 .c文件暂时去除掉

编译成功了


1、文件夹路径全部修改成了中文，因为在查找变量的定义的时候打不开路径，不知道和这个有没有关系
   的确是有关系的
