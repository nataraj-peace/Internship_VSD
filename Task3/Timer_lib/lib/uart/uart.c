#include "uart.h"

/* crude delay */
void delay_ms(uint32_t ms)
{
    for(uint32_t i = 0; i < ms * 8000; i++)
        __NOP();
}

/* USART1 Init for CH32V003 */
void USART1_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD |
                           RCC_APB2Periph_USART1, ENABLE);

    GPIO_InitTypeDef gpio;

    /* PD5 -> USART1_TX */
    gpio.GPIO_Pin   = GPIO_Pin_5;
    gpio.GPIO_Mode  = GPIO_Mode_AF_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &gpio);

    /* PD6 -> USART1_RX (optional) */
    gpio.GPIO_Pin  = GPIO_Pin_6;
    gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOD, &gpio);

    USART_InitTypeDef usart;
    usart.USART_BaudRate            = 115200;
    usart.USART_WordLength          = USART_WordLength_8b;
    usart.USART_StopBits            = USART_StopBits_1;
    usart.USART_Parity              = USART_Parity_No;
    usart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    usart.USART_Mode                = USART_Mode_Tx;

    USART_Init(USART1, &usart);
    USART_Cmd(USART1, ENABLE);
}

/* Send single char */
void USART1_SendChar(char c)
{
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    USART_SendData(USART1, c);
}

/* Send string */
void USART1_SendString(const char *s)
{
    while(*s)
        USART1_SendChar(*s++);
}

/* Print integer */
void print_number(uint32_t n)
{
    char buf[10];
    int i = 0;

    if(n == 0)
    {
        USART1_SendChar('0');
        return;
    }

    while(n > 0)
    {
        buf[i++] = (n % 10) + '0';
        n /= 10;
    }

    while(i--)
        USART1_SendChar(buf[i]);
}
