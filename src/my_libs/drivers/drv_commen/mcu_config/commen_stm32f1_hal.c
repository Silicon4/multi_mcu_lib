//基本函数的stm32f1hal相关实现
#include "commen_config.h"

#define us_tim htim6 //用于us延时的定时器

#ifdef mcu_stm32f1_hal

void my_delayms(uint64_t ms)
{
    HAL_Delay(ms);
}

void my_delayus(uint64_t us) //如果不用systic,需要开一个定时器用于us级别延时
{
    uint16_t differ = 0xffff - us - 5;
    __HAL_TIM_SET_COUNTER(&us_tim, differ);
    HAL_TIM_Base_Start(&us_tim);
    while (differ < 0xffff - 6)
    {
        differ = __HAL_TIM_GET_COUNTER(&us_tim);
    }
    HAL_TIM_Base_Stop(&us_tim);
}

uint64_t my_getms(void)
{
    uint32_t getms = HAL_Gettick();
    return getms;
}

void my_commonInit(void)
{
    #if 1 //gnu编译的串口重定向
    int _write (int fd, char *pBuffer, int size)  
    {  
        for (int i = 0; i < size; i++)  
        {  
            while((USART1->SR&0X40)==0);//等待上一次串口数据发送完成  
            USART1->DR = (u8) pBuffer;       //写DR,串口1将发送数据
        }  
        return size;  
    }
    #endif
}

void my_print(const char *)
{
    pirntf(char);
}


#endif
