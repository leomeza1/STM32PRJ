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


void Hello_Latched_Button(void)
{
	// Create a GPIO object configured for output
	GpioPin led = GpioPin(GPIOC, &led_cfg);

	// Create a GPIO object configured for input
	GpioPin button = GpioPin(GPIOB, &button_cfg);

	// Button state (pressed = 1, released = 0)
	volatile char buttonState = 0;

	// Button Pressed confidence level
	volatile int buttonPressedConfidenceLevel = 0;

	// Button Released confidence level
	volatile int buttonReleasedConfidenceLevel = 0;

	// Button state confidence threshold
	volatile int confidenceThreshold = 500;

	// Loop forever...
    while(1)
    {
    	// Note: This code debounces the signal from the mechanical
    	//       push button using a 'confidence threshold' method.
    	//       That is, the signal is sampled continuously while
    	//       counting the number of consecutive 1's (or 0's).
    	//       As the number of consecutive 1's (or 0's) increases,
    	//       so too does the confidence in the actual state of
    	//       the push button (pressed or not pressed). If the
    	//       sampled values are alternating between 1's and 0's
    	//       then the confidence in the actual state of the push
    	//       button is low, we don't know if it's pressed or not.

    	// Is the button in the pressed state?
        if(button.Read() == GPIO_PIN_SET)
        {
        	// Yes, the button is in the pressed state.

        	// Was the button in the released state the previous iteration?
        	if(buttonState == 0)
        	{
        		// Yes,the button was in the released state the previous iteration

        		// Is the Button Pressed Confidence level has passed the threshold
        		if(buttonPressedConfidenceLevel > confidenceThreshold)
        		{
        			// Toggle the LED
        			led.Toggle();

        			// Update the Button State variable to 1 (pressed)
        			buttonState = 1;
        		}
        		else
        		{
        			// Increase the Button Pressed Confidence Level
        			buttonPressedConfidenceLevel += 1;
        			buttonReleasedConfidenceLevel = 0;
        		}
        	}
        }
        else
        {
        	if(buttonState == 1)
        	{
        		// Once the button Release Confidence Level has been reached
        		if(buttonReleasedConfidenceLevel > confidenceThreshold)
        		{
        			// Update the Button State variable to 0 (released)
        			buttonState = 0;
        		}
        		else
        		{
        			// Increase the Button Released Confidence level
        			buttonReleasedConfidenceLevel += 1;
        			buttonPressedConfidenceLevel = 0;
        		}
        	}
        }
    }
}
