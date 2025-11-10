
#include <stdint.h>
#include <math.h>
#include "pico/rand.h"
#include "pico/stdlib.h"
#include "SSD1322_RP2040.h"
#include "../SSD1322_OLED_lib/SSD1322_API.h"
#include "../SSD1322_OLED_lib/SSD1322_GFX.h"

//#include "../SSD1322_OLED_lib/Fonts/FreeMono12pt7b.h"
//#include "../SSD1322_OLED_lib/Fonts/FreeSansOblique9pt7b.h"



int main()
{
  	// Declare bytes array for a frame buffer.
	// Dimensions are divided by 2 because one byte contains two 4-bit grayscale pixels
	uint8_t tx_buf[256 * 64 / 2];
	bool ledState = false;	
	int px[256], py[256], pl[256];
	int pxCount = 22;
	
	for (int i = 0; i < pxCount; i++) {
		px[i] = get_rand_32() % 256;
		py[i] = get_rand_32() % 64;
		pl[i] = get_rand_32() % 16;
	}

    stdio_init_all();
	// Initialize RP2040 hardware to communicate with SSD1322
	SSD1322_RP2040_init();
	//Call initialization seqence for SSD1322
	SSD1322_API_init();
	set_buffer_size(256, 64);
    fill_buffer(tx_buf, 0);

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
        gpio_put(PICO_DEFAULT_LED_PIN, 1);

    while (true) {
		fill_buffer(tx_buf, 0);
		for (int i = 0; i < pxCount; i++) {
			draw_pixel(tx_buf, px[i], py[i], pl[i]);
			pl[i]--;
			px[i]++;
			if (pl[i] < 0 || px[i] >= 256) {
				px[i] = get_rand_32() % 256;
				py[i] = get_rand_32() % 64;
				pl[i] = get_rand_32() % 16;
			}
		}
		// send a frame buffer to the display
		send_buffer_to_OLED(tx_buf, 0, 0);
  //      gpio_put(PICO_DEFAULT_LED_PIN, ledState);
		ledState = !ledState;
//		sleep_ms(100 + (get_rand_32() % 2000));
	//	printf("tick\n");
    }
}