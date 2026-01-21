#ifndef UART_H
#define UART_H
#include <stdint.h>
#include "ch32v00x.h"
void print_number(uint32_t n);
void USART1_SendString(const char *s);
void USART1_SendChar(char c);
void USART1_Init(void);  
void delay_ms(uint32_t ms); 

#endif