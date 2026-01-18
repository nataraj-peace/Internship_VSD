
#include "gpio.h"
#include "uart.h"


int main(void)
{
    uint32_t counter = 0;

    gpio_init();

    USART1_Init();   // from previous UART task

    USART1_SendString("\r\nTask-2 GPIO + UART Demo\r\n");
    USART1_SendString("GPIO : PD4 (GPIOD, GPIO_Pin_4)\r\n");

    while (1)
    {
        gpio_toggle();

        USART1_SendString("GPIO TOGGLE, Count = ");
        print_number(counter++);
        USART1_SendString("\r\n");

        delay_ms(500);
    }
}
