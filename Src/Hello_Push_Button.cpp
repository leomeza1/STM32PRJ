#include "GpioPin.hpp"


// A GPIO output configuration, for the LED
static GPIO_InitTypeDef led_cfg = {
    GPIO_PIN_6,
	GPIO_MODE_OUTPUT_PP,
	GPIO_NOPULL,
	GPIO_SPEED_FREQ_LOW,
	0
};

// A GPIO input configuration, for the push button
static GPIO_InitTypeDef button_cfg = {
    GPIO_PIN_1,
    GPIO_MODE_INPUT,
    GPIO_NOPULL,
	0,
	0
};


void Hello_Push_Button(void)
{
	// Create a GPIO object configured for output
	GpioPin led = GpioPin(GPIOC, &led_cfg);

	// Create a GPIO object configured for input
	GpioPin button = GpioPin(GPIOB, &button_cfg);

	// Loop forever...
    while(1)
    {
    	// Is the push button being pressed?
        if(button.Read() == GPIO_PIN_SET)
        {
        	// Yes, turn on the LED
        	led.Set();
        }
        else
        {
        	// No, turn off the LED
        	led.Clear();
        }
    }
}
