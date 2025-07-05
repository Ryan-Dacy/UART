# 📡 Full UART Communication – Embedded Controllers (Spring 2024)

> 📌 Made this repo after graduation to save an important embedded communication project from college.

## Overview

This project implements a configurable **UART transmitter and receiver** on an **STM32** using **C**. It supports adjustable **baud rate** and **parity** settings.

Communication was tested and verified using an oscilloscope to observe live signal transmission.

## Features

- Configurable UART with adjustable baud rate and parity
- Full transmit and receive functionality
- Verified signals with oscilloscope
- Written in C for STM32 microcontrollers

## Hardware

- STM32 microcontroller ("Blue Pill")
- UART pins connected to oscilloscope for testing
- Powered directly from the STM32 board

## Files

- `uart.c`: UART driver implementation
- `README.md`: This file

## What I Learned

- Configuring UART on STM32
- Managing data transmission and reception in embedded C
- Using oscilloscope to verify communication signals
