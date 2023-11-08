#include "GpioPin.hpp"


// A GPIO output configuration, for the LED
static GPIO_InitTypeDef led_cfg = {
    GPIO_PIN_6,
	GPIO_MODE_OUTPUT_PP,
	GPIO_NOPULL,
	GPIO_SPEED_FREQ_LOW,
	0
};


void Hello_GPIO(void)
{
	// Create a GPIO object configured for output
	GpioPin led = GpioPin(GPIOC, &led_cfg);

	// Loop forever...
    while(1)
    {
        for(int i = 0; i < 500000; i++);

        led.Toggle();
    }
}
