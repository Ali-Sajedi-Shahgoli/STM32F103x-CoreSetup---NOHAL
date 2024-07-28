
#ifndef INC_RCC_H_
#define INC_RCC_H_

#include <main.h>
#include <stm32f103xb.h>


void RCC_HSE_CLOCK(void);
void RCC_SYSTICK_CONFIG(uint32_t RELOAD_VALUE);
void RCC_MSTICKS_INC(void);
uint32_t RCC_GET_MSTICKS(void);
void RCC_DELAY(uint32_t ms);



#endif /* INC_RCC_H_ */

