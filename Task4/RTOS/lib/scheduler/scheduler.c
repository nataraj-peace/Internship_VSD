#include "scheduler.h"
#include "timer.h"

static task_t tasks[MAX_TASKS];
static uint8_t task_count = 0;

void scheduler_add(void (*func)(void), uint32_t period)
{
    if(task_count < MAX_TASKS)
    {
        tasks[task_count].task_func = func;
        tasks[task_count].period_ms = period;
        tasks[task_count].last_run = millis();
        task_count++;
    }
}

void scheduler_run(void)
{
    uint32_t now = millis();

    for(uint8_t i = 0; i < task_count; i++)
    {
        if(now - tasks[i].last_run >= tasks[i].period_ms)
        {
            tasks[i].last_run = now;
            tasks[i].task_func();
        }
    }
}

