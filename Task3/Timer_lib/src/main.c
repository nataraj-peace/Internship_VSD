
#include "gpio.h"
#include "uart.h"
#include "timer.h"

void led_task(void)
{
    uint32_t t = timer_get_ticks();
    gpio_toggle();
    USART1_SendString("[");
    print_number(t);
    USART1_SendString("  Sec] LED toggled\r\n");
}


int main(void)
{

    gpio_init();

    USART1_Init();   // from previous UART task
    timer_init(1000);   // 1 ms tick

    USART1_SendString("Timer Library demo started \r\n ");

    timer_start_periodic(1000, led_task); // 1 second

    while (1)
    {
    }
}
