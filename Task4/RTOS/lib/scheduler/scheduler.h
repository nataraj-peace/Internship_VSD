#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

#define MAX_TASKS  5

typedef struct
{
    void (*task_func)(void);
    uint32_t period_ms;
    uint32_t last_run;
} task_t;

void scheduler_add(void (*func)(void), uint32_t period);
void scheduler_run(void);

#endif

