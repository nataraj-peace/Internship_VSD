# Task-3: Timer Peripheral Driver Library + Demo Application

## 1. Implemented Library
**Timer Driver Library**

The timer library provides a clean and reusable abstraction over the hardware timer of the **VSDSquadron Mini (CH32V003)** board.  
All timer-related hardware register access is isolated inside the library.  
The application interacts with the timer strictly through well-defined APIs.

---

## 2. Timer Library APIs

| API | Description |
|----|------------|
| `void timer_init(uint32_t tick_hz)` | Initializes the hardware timer with the given tick frequency (Hz). |
| `void timer_delay_ms(uint32_t ms)` | Provides a blocking delay in milliseconds using the timer tick. |
| `void timer_start_periodic(uint32_t period_ms, void (*callback)(void))` | Starts a periodic timer that invokes a callback at the specified interval. |
| `void timer_stop(void)` | Stops the running timer. |
| `uint32_t timer_get_ticks(void)` | Returns the system tick count (used for timestamps/logging). |

---

## 3. Demo Application Description

The demo application showcases the usage of the timer library by:

- Initializing the UART, GPIO, and Timer libraries
- Configuring a 1 ms system tick using the timer library
- Starting a periodic timer with a 1-second interval
- Toggling an LED every 1 second
- Printing timestamped log messages over UART

The application **does not access any hardware registers directly**.  
All hardware interaction is performed via library APIs only.

---

## 4. Clean, Build and Flash Instructions

- pio run -t clean
- pio run
- pio run -t upload

## 5. UART Configuration

- UART Port: UART1
- Baud Rate: 115200
- Data Format: 8 data bits, No parity, 1 stop bit (8N1)
- UART output displays timestamped logs confirming correct timer operation.

