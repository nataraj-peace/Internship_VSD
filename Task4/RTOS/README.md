# Project-8: Mini-RTOS (Cooperative Scheduler) on VSDSquadron Mini

## Project Description
This project implements a simple Mini Real-Time Operating System (RTOS) using a cooperative, tick-based scheduler on the VSDSquadron Mini (CH32V003) board. The system demonstrates multitasking without blocking delays, where multiple application tasks run deterministically based on a hardware timer. The project uses GPIO for LED control and button input, UART for system status output, and a timer interrupt as the system tick source.

---

## Drivers Used
- **GPIO**: LED output and button input  
- **UART**: System status and debug messages  
- **Timer (TIM2)**: 1 ms system tick  

---

## API Summary

### Scheduler APIs
- void scheduler_add(void (*func)(void), uint32_t period_ms);
- void scheduler_run(void);
### Timer APIs
- void timer_init(void);
- uint32_t millis(void);
### GPIO APIs
- void gpio_init(void);
- void gpio_toggle(void);
- uint8_t gpio_read_button(void);
### UART APIs
- void USART1_Init(void);
- void USART1_SendString(const char *s);

---

## Build and Flash Steps
- pio run
- pio run -t upload

## UART Settings
- Baud rate: 115200
- Data bits: 8
- Parity: None
- Stop bits: 1
- Port: USART1 (PD5 TX)

## How to Demo
- Power the VSDSquadron Mini board.
- Observe LED blinking every 500 ms.
- Open UART terminal at 115200 baud.
- Observe status messages:
  *STATUS: Button = RELEASED
- Press the onboard button.
- Observe:
  *EVENT: Button Pressed
  *STATUS: Button = PRESSED
- Release button:
  *EVENT: Button Released
### This demonstrates cooperative multitasking with deterministic scheduling.
