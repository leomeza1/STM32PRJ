#include "Project.hpp"
#include "GpioPin.hpp"


// A GPIO output configuration
static GPIO_Config_t gpio_cfg = {
		GPIOC, 6, GPIO_MODER_OUTPUT, AHB_PCLOCK_IOPC, GPIO_OUTPUT_TYPE_PP, GPIO_OUTPUT_SPEED_LOW, GPIO_PUPD_NONE
};


#ifdef __cplusplus
extern "C"
{
#endif

void ProjectLoop()
{
    // Create a GPIO object configured for ouput
	GpioPin led = GpioPin(&gpio_cfg);

	// Loop forever...
    while(1)
    {
        for(int i = 0; i < 500000; i++);

        led.Toggle();
    }
}

#ifdef __cplusplus
}
#endif
