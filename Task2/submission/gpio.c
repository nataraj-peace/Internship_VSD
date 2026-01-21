#include "gpio.h"

void gpio_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin   = USER_GPIO_PIN;
    gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(USER_GPIO_PORT, &gpio);

    GPIO_ResetBits(USER_GPIO_PORT, USER_GPIO_PIN);
}

void gpio_set(void)
{
    GPIO_SetBits(USER_GPIO_PORT, USER_GPIO_PIN);
}

void gpio_clear(void)
{
    GPIO_ResetBits(USER_GPIO_PORT, USER_GPIO_PIN);
}

void gpio_toggle(void)
{
    USER_GPIO_PORT->OUTDR ^= USER_GPIO_PIN;
}
