/**
 ****************************************************************************************
 *
 * \file SSD1322_HW_Driver.c
 *
 * \brief Hardware dependent functions for SSD1322 OLED display.
 *
 * This file contains functions that rely on hardware of used MCU. In this example functions
 * are filled with STM32F411RE hardware implementation. To use this library on any other MCU
 * you just have to provide its hardware implementations of functions from this file and higher
 * level functions should work without modification.
 *
 * Rewritten for RP2040 by Adam Schabtach.
 * 
 * Copyright (C) 2025 Adam Schabtach
 * MIT license:
 * https://github.com/wjklimek1/SSD1322_OLED_library
 *
 ****************************************************************************************
 */

//=================== Include hardware libraries =====================//
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "SSD1322_RP2040.h"
#include "../SSD1322_OLED_lib/SSD1322_HW_Driver.h"

//====================== CS pin low ========================//
/**
 *  @brief Drives CS (Chip Select) pin of SPI interface low.
 *
 *  CS pin may be also signed as "SS" or "NSS"
 */
void SSD1322_HW_drive_CS_low()
{
    gpio_put(PIN_CS, 0);
}

//====================== CS pin high ========================//
/**
 *  @brief Drives CS (Chip Select) pin of SPI interface high.
 *
 *  CS pin may be also signed as "SS" or "NSS"
 */
void SSD1322_HW_drive_CS_high()
{
    gpio_put(PIN_CS, 1);
}

//====================== DC pin low ========================//
/**
 *  @brief Drives DC (Data/Command) pin of OLED driver low.
 *
 *  High state is for data and low state is for command.
 */
void SSD1322_HW_drive_DC_low()
{
    gpio_put(PIN_DC, 0);
}

//====================== DC pin high ========================//
/**
 *  @brief Drives DC (Data/Command) pin of of OLED driver high.
 *
 *  High state is for data and low state is for command.
 */
void SSD1322_HW_drive_DC_high()
{
    gpio_put(PIN_DC, 1);
}

//====================== RESET pin low ========================//
/**
 *  @brief Drives RESET pin of of OLED driver low.
 *
 *  Logic low on RESET resets OLED driver.
 */
void SSD1322_HW_drive_RESET_low()
{
    gpio_put(PIN_RESET, 0);
}

//====================== RESET pin high ========================//
/**
 *  @brief Drives RESET pin of of OLED driver high.
 *
 *  Logic low on RESET resets OLED driver.
 */
void SSD1322_HW_drive_RESET_high()
{
    gpio_put(PIN_RESET, 1);
}

//====================== Send single SPI byte ========================//
/**
 *  @brief Transmits single byte through SPI interface.
 *
 *  @param[in] byte_to_transmit byte that will be transmitted through SPI interface
 */
void SSD1322_HW_SPI_send_byte(uint8_t byte_to_transmit)
{
	spi_write_blocking(SPI_PORT, &byte_to_transmit, 1);
}

//====================== Send array of SPI bytes ========================//
/**
 *  @brief Transmits array of bytes through SPI interface.
 *
 *  @param[in] array_to_transmit array of bytes that will be transmitted through SPI interface
 *  @param[in] array_size amount of bytes to transmit
 */
void SSD1322_HW_SPI_send_array(uint8_t *array_to_transmit, uint32_t array_size)
{
	spi_write_blocking(SPI_PORT, array_to_transmit, array_size);
}

//====================== Milliseconds delay ========================//
/**
 *  @brief Wait for x milliseconds.
 *
 *  NOTE: This function is only used in initialization sequence to pull reset down and high
 *  and later to wait for Vdd stabilization. It takes time ONLY on startup (around 200ms)
 *  and is NOT USED during normal operation.
 *
 *  @param[in] milliseconds time to wait
 */
void SSD1322_HW_msDelay(uint32_t milliseconds)
{
	sleep_ms(milliseconds);
}
