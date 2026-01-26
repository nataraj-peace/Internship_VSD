#include "gpio.h"
#include "uart.h"
#include "timer.h"

/* shared state */
volatile uint8_t button_state = 0;

/* Task A: LED blink */
void taskA_led(void)
{
    gpio_toggle();
}

/* Task B: UART status */
void taskB_uart(void)
{
    if(button_state)
        USART1_SendString("STATUS: Button = PRESSED\r\n");
    else
        USART1_SendString("STATUS: Button = RELEASED\r\n");
}

/* Task C: Button read */
void taskC_button(void)
{
    static uint8_t last = 0;
    uint8_t now = gpio_read_button();

    if(now != last)
    {
        last = now;
        button_state = now;

        if(now)
            USART1_SendString("EVENT: Button Pressed\r\n");
        else
            USART1_SendString("EVENT: Button Released\r\n");
    }
}

