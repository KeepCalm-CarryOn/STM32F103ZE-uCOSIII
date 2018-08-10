/*******include files*****/
#include "delay.h"
#include <app_cfg.h>
#include <bsp.h>
#include <os.h>
/*******local global variables***/
static OS_TCB   AppTaskStartTCB; 
static OS_TCB   AppTask1TCB; 
static OS_TCB   AppTask2TCB;
static OS_TCB   AppTask3TCB;
static CPU_STK  AppTaskStartStk[APP_TASK_START_STK_SIZE];
static CPU_STK  AppTask1Stk[128];
static CPU_STK  AppTask2Stk[128];
static CPU_STK  AppTask3Stk[128];
/*******Function Prototypes**********/
static void AppTaskStart(void *p_arg);
static void AppTask1(void *p_arg);
static void AppTask2(void *p_arg);
static void AppTask3_ui(void *p_arg);
int main(void)
{
  /*运行状态错误码*/ 
	OS_ERR err;
	/*关中断*/

  /*初始化操作系统*/	
	OSInit(&err);
	/*检查状态*/
	if(err!=OS_ERR_NONE)
	{
	  /*OSInit 初始化系统失败*/
	}
	/*创建一个任务*/
  		OSTaskCreate(
	             (OS_TCB     *) &AppTaskStartTCB,
	             (CPU_CHAR   *) "App Task Start",
	             (OS_TASK_PTR ) AppTaskStart,
	             (void       *) 0,
							 (OS_PRIO     ) APP_TASK_START_PRIO,
							 (CPU_STK    *) &AppTaskStartStk[0],
							 (CPU_STK_SIZE) APP_TASK_START_STK_SIZE/10,
               (CPU_STK_SIZE) APP_TASK_START_STK_SIZE,
               (OS_MSG_QTY  ) 0,
               (OS_TICK     ) 0,
               (void       *) 0,
               (OS_OPT      ) (OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR),
               (OS_ERR     *) &err 							
	            );
  if(err!=OS_ERR_NONE)
	{
	  /*任务创建失败*/
	}
	OSStart(&err);
	  if(err!=OS_ERR_NONE)
	{
	  /* your code is never supposed to come back to this point*/
	}

}

static void AppTaskStart(void *p_arg)
{
	OS_ERR err;
	CPU_INT32U cpu_clk_freq,cnts;
	
	p_arg = p_arg; //因为参数没有用到，所以加上这一句，防止编译器警告 
	CPU_Init();
	
	cpu_clk_freq = BSP_CPU_ClkFreq();
	cnts = cpu_clk_freq / (CPU_INT32U)OSCfg_TickRate_Hz;
  OS_CPU_SysTickInit(cnts);
	OSTaskCreate(
	             (OS_TCB     *) &AppTask1TCB,
	             (CPU_CHAR   *) "App Task1",
	             (OS_TASK_PTR ) AppTask1,
	             (void       *) 0,
							 (OS_PRIO     ) 5,
							 (CPU_STK    *) &AppTask1Stk[0],
							 (CPU_STK_SIZE) 0,
               (CPU_STK_SIZE) 128,
               (OS_MSG_QTY  ) 0,
               (OS_TICK     ) 0,
               (void       *) 0,
               (OS_OPT      ) (OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR),
               (OS_ERR     *) &err 							
	            );
	OSTaskCreate(
	             (OS_TCB     *) &AppTask2TCB,
	             (CPU_CHAR   *) "App Task2",
	             (OS_TASK_PTR ) AppTask2,
	             (void       *) 0,
							 (OS_PRIO     ) 6,
							 (CPU_STK    *) &AppTask2Stk[0],
							 (CPU_STK_SIZE) 0,
               (CPU_STK_SIZE) 128,
               (OS_MSG_QTY  ) 0,
               (OS_TICK     ) 0,
               (void       *) 0,
               (OS_OPT      ) (OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR),
               (OS_ERR     *) &err 							
	            );

	 BSP_Init ();
   OSTaskDel(&AppTaskStartTCB,&err);

}

static void AppTask1(void *p_arg)
{
	OS_ERR err;
	p_arg=p_arg;
	while(1)
	{ 
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		OSTimeDly(500,OS_OPT_TIME_DLY,&err);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		OSTimeDly(500,OS_OPT_TIME_DLY,&err);
	}

}



static void AppTask2(void *p_arg)
{
	OS_ERR       err;
	p_arg = p_arg;
  
	while(1)
	{ 
		GPIO_SetBits(GPIOE,GPIO_Pin_5);
		OSTimeDly(1000,OS_OPT_TIME_DLY,&err);
		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		OSTimeDly(1000,OS_OPT_TIME_DLY,&err);
	
	}


}
static void AppTask3(void *p_arg)
{








}