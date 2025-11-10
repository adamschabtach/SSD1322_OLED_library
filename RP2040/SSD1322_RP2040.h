/**
 ****************************************************************************************
 *
 * \file RP2040.h
 *
 * \brief Hardware dependent constants for connecting RP2040 to SSD1322 OLED display.
 *
 *  This file defines constants for the RP2040 microcontroller to interface with the SSD1322 OLED display.
 * It specifies the SPI port and GPIO pins used for communication and are used in SSD1322_HW_Driver.c.
 * 
 * Copyright (C) 2025 Adam Schabtach
 * MIT license:
 * https://github.com/wjklimek1/SSD1322_OLED_library
 *
 ****************************************************************************************
 */
#ifndef SSD1322_OLED_RP2040_H
#define SSD1322_OLED_RP2040_H

#ifdef __cplusplus
extern "C" {
#endif

// SPI Defines
// We are going to use SPI 0, and allocate it to the following GPIO pins
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define SPI_PORT spi0
// TODO we don't use MISO.
#define PIN_MISO 16
#define PIN_CS   17
#define PIN_SCK  18
#define PIN_MOSI 19

#define PIN_DC    20  // Data/Command pin
#define PIN_RESET 21  // Reset pin

void SSD1322_RP2040_init(void);

#ifdef __cplusplus
}
#endif

#endif // RP2040_H
