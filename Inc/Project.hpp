#ifndef PROJECT_HPP_
#define PROJECT_HPP_


typedef enum {

	STM32PRJ_HELLO_GPIO           = 0,
	STM32PRJ_HELLO_PUSH_BUTTON    = 1,
	STM32PRJ_HELLO_LATCHED_BUTTON = 2,

	STM32PRJ_COUNT                = 3

}STM32PRJ_t;


#ifdef __cplusplus
extern "C"
{
#endif


void ProjectLoop(STM32PRJ_t stm32_prj);

#ifdef __cplusplus
}
#endif

#endif /* PROJECT_HPP_ */
