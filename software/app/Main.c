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
	int i=0;
	while (1)
	{
		// Read state of switches 0-9 to determine speed of LED chenillard
		uint16_t speed = IORD_ALTERA_AVALON_PIO_DATA(PIO_0_BASE); 
		// Delay based on determined speed
		
		
		// Update LED chenillard state
		for (i=0;i<7;i++){
                IOWR_ALTERA_AVALON_PIO_DATA(PIO_1_BASE,1<<i);
                usleep(1000*speed);
            }
            	for (i=7;i>0;i--){
                   IOWR_ALTERA_AVALON_PIO_DATA(PIO_1_BASE,1<<i);
                   usleep(1000*speed);
                }
	}
	
	return 0;
}