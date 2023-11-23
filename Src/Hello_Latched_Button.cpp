#include "GpioPin.hpp"
#include "PushButton.hpp"


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


void Hello_Latched_Button(void)
{
	// Create a GPIO object configured for output
	GpioPin led = GpioPin(GPIOC, &led_cfg);

	// Create a GPIO object configured for input
	GpioPin button = GpioPin(GPIOB, &button_cfg);

	// Create a PushButton object
	PushButton *push_button = new PushButton();

	// Create a variable to keep track of the previous push button state
	GPIO_PinState previous_state = GPIO_PIN_RESET;

	// Loop forever...
    while(1)
    {
    	// Update the push button state by reading the value of the GPIO input pin
    	push_button->Update(button.Read());

    	// Is the push button in the 'pressed' state?
    	if(push_button->IsPressed())
    	{
    		// Yes, set previous_state so we can detect when the push button is released
    		previous_state = GPIO_PIN_SET;
    	}
    	else // The push button is in the 'released' state
    	{
    		// Was the push button in the 'pressed' state the previous iteration?
    		if(previous_state == GPIO_PIN_SET)
    		{
    			// Yes, toggle the LED
    			led.Toggle();
    		}

    		// Reset previous_state set the push button is in the 'released' state
    		previous_state = GPIO_PIN_RESET;
    	}
    }
}
