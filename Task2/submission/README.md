# Task-2: GPIO & UART Validation – VSDSquadron Mini

## Overview
This project demonstrates successful board bring-up, UART validation,
and GPIO control on the VSDSquadron Mini board using clean firmware architecture.

## GPIO Selection
- Physical Pin: PD4 (silkscreen on board)
- MCU Mapping: GPIOD, GPIO_Pin_4 (as per CH32V003 datasheet)
- Function: Output toggle (LED/probe observable)

## UART Output
- Startup banner after reset
- Board name and firmware version
- Continuous counter output (10+ lines)
- UART visible on /dev/ttyACM0
