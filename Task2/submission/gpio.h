#ifndef GPIO_H
#define GPIO_H

#include "ch32v00x.h"

/* GPIO definition based strictly on datasheet */
#define USER_GPIO_PORT   GPIOD
#define USER_GPIO_PIN    GPIO_Pin_4   // PD4

void gpio_init(void);
void gpio_set(void);
void gpio_clear(void);
void gpio_toggle(void);

#endif
