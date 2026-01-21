#include "timer.h"
#include "ch32v00x.h"

static volatile uint32_t sys_ticks = 0;
static void (*timer_callback)(void) = 0;

/*
 * Timer: TIM2
 * Clock: 24 MHz
 * Tick: 1 ms
 */

void timer_init(uint32_t tick_hz)
{
    /* Enable TIM2 clock */
    RCC->APB1PCENR |= RCC_APB1Periph_TIM2;

    /* Prescaler for 1 ms tick */
    TIM2->PSC = (24000000 / tick_hz) - 1;

    /* Auto reload = 1 tick */
    TIM2->ATRLR = 1 - 1;

    /* Enable update interrupt */
    TIM2->DMAINTENR |= TIM_UIE;

    /* Enable TIM2 interrupt */
    NVIC_EnableIRQ(TIM2_IRQn);

    /* Start timer */
    TIM2->CTLR1 |= TIM_CEN;
}

void timer_delay_ms(uint32_t ms)
{
    uint32_t start = sys_ticks;
    while ((sys_ticks - start) < ms);
}

void timer_start_periodic(uint32_t period_ms, void (*callback)(void))
{
    timer_callback = callback;

    TIM2->ATRLR = period_ms - 1;
    TIM2->CNT = 0;

    TIM2->CTLR1 |= TIM_CEN;
}


uint32_t timer_get_ticks(void)
{
    return sys_ticks;
}


void timer_stop(void)
{
    TIM2->CTLR1 &= ~TIM_CEN;
}

/* TIM2 Interrupt Handler */
void TIM2_IRQHandler(void) __attribute__((interrupt));
void TIM2_IRQHandler(void)
{
    if (TIM2->INTFR & TIM_UIF)
    {
        TIM2->INTFR &= ~TIM_UIF;

        sys_ticks++;

        if (timer_callback)
        {
            timer_callback();
        }
    }
}

