#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

/* Initialize hardware timer */
void timer_init(uint32_t tick_hz);

/* Blocking delay in milliseconds */
void timer_delay_ms(uint32_t ms);

/* Register a periodic callback (optional advanced) */
void timer_start_periodic(uint32_t period_ms, void (*callback)(void));

/* Stop periodic timer */
void timer_stop(void);
uint32_t timer_get_ticks(void);

#endif

