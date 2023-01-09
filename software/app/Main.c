#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include <stdint.h>
#include "unistd.h"

int main()
{
	// Define variable to hold state of LED chenillard
	uint16_t led_state = 0x0001;
	// Define variable to keep track of direction of LED chenillard
	int8_t direction = 1;
	
	while (1)
	{
		// Read state of switches 0-9 to determine speed of LED chenillard
		uint16_t speed = IORD_ALTERA_AVALON_PIO_DATA(PIO_0_BASE); 
		// Delay based on determined speed
		usleep(1000*speed);
		
		// Update LED chenillard state
		if (direction == 1)
		{
			if (led_state & 0x0080)
			{
				// If the rightmost LED is lit, change direction and shift left
				direction = -1;
				led_state = (led_state>>1);
			}
			else
			{
				// Otherwise, just shift the current state of the LEDs right by one position
				led_state = (led_state<<1) + 0x1;
			}
		}
		else
		{
			if (led_state & 0x0001)
			{
				// If the leftmost LED is lit, change direction and shift right
				direction = 1;
				led_state = (led_state<<1);
			}
			else
			{
				// Otherwise, just shift the current state of the LEDs left by one position
				led_state = (led_state>>1) + 0x0080;
			}
		}
		
		// Update LEDs with current state of LED chenillard
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_1_BASE, led_state);
	}
	
	return 0;
}