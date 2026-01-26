#include "timer.h"
#include "ch32v00x.h"

volatile uint32_t system_ticks = 0;

void TIM2_IRQHandler(void) __attribute__((interrupt));
void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        system_ticks++;
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}

void timer_init(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM_TimeBaseInitTypeDef tim;
    tim.TIM_Prescaler = (SystemCoreClock / 1000) - 1; // 1ms
    tim.TIM_CounterMode = TIM_CounterMode_Up;
    tim.TIM_Period = 1;
    tim.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInit(TIM2, &tim);

    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM2, ENABLE);

    NVIC_EnableIRQ(TIM2_IRQn);
}

uint32_t millis(void)
{
    return system_ticks;
}

