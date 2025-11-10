#include <stdio.h>
#include <math.h>
#include "pico/rand.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "SSD1322_RP2040.h"
#include "../SSD1322_OLED_lib/SSD1322_HW_Driver.h"
#include "../SSD1322_OLED_lib/SSD1322_API.h"
#include "../SSD1322_OLED_lib/SSD1322_GFX.h"

#include "../SSD1322_OLED_lib/Fonts/FreeMono12pt7b.h"
#include "../SSD1322_OLED_lib/Fonts/FreeSansOblique9pt7b.h"
//====================== Initialize ========================//
/**
 *  @brief Initialize GPIO and SPI for use with the SDD1322.
 * 
 *	Call this before any other SDD1322 functions.
 */
// TODO parameterize the SPI assignment, speed, and pins.
void SSD1322_RP2040_init(void)
{
//	stdio_init_all();

	// SPI initialisation. This example will use SPI at 1MHz.
	// TODO this could go as high as 10MHz
	spi_init(SPI_PORT, 1000*1000);
	gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
	gpio_set_function(PIN_SCK,  GPIO_FUNC_SPI);
	gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);
   
	gpio_init(PIN_CS);
	gpio_init(PIN_DC);
	gpio_init(PIN_RESET);   
	gpio_set_dir(PIN_CS, GPIO_OUT);
	gpio_set_dir(PIN_DC, GPIO_OUT);
	gpio_set_dir(PIN_RESET, GPIO_OUT);
}
