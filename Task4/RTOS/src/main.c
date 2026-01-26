#include "scheduler.h"
#include "gpio.h"
#include "uart.h"
#include "timer.h"
#include "tasks.h"

/* task prototypes */
void taskA_led(void);
void taskB_uart(void);
void taskC_button(void);

int main(void)
{
    gpio_init();
    USART1_Init();
    timer_init();

    /* Register tasks */
    scheduler_add(taskA_led,   500);   // 500 ms
    scheduler_add(taskB_uart, 1000);   // 1 second
    scheduler_add(taskC_button, 50);   // 50 ms polling

    while(1)
    {
        scheduler_run();
    }
}

