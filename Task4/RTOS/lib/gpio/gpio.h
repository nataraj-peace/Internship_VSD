#ifndef GPIO_H
#define GPIO_H

#include "ch32v00x.h"

/* GPIO definition based strictly on datasheet */
#define USER_GPIO_PORT   GPIOD
#define USER_GPIO_PIN    GPIO_Pin_4   // PD4

#define USER_BTN_PORT GPIOC
#define USER_BTN_PIN  GPIO_Pin_1   // if this doesn't work, try Pin_0 or Pin_2

uint8_t gpio_read_button(void);

void gpio_init(void);
void gpio_set(void);
void gpio_clear(void);
void gpio_toggle(void);

#endif
