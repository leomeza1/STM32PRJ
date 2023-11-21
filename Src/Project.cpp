#include "Project.hpp"
#include "GpioPin.hpp"


void Hello_GPIO(void);
void Hello_Push_Button(void);
void Hello_Latched_Button(void);


#ifdef __cplusplus
extern "C"
{
#endif

void ProjectLoop(STM32PRJ_t stm32_prj)
{
	switch(stm32_prj)
	{
	case STM32PRJ_HELLO_GPIO:
		Hello_GPIO();
		break;

	case STM32PRJ_HELLO_PUSH_BUTTON:
		Hello_Push_Button();
		break;

	case STM32PRJ_HELLO_LATCHED_BUTTON:
		Hello_Latched_Button();
		break;

	default:
		break;
	}
}

#ifdef __cplusplus
}
#endif
