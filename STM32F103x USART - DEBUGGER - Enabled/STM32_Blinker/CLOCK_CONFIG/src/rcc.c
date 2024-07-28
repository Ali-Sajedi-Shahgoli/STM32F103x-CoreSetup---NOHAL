
#include <rcc.h>



static __IO MSTICKS = 0;


void RCC_HSE_CLOCK(void)
{


  RCC->CFGR &= ~(RCC_CFGR_PLLMULL); // Clear BitFields
  RCC->CFGR |= (RCC_CFGR_PLLMULL9); //SET PLL to 9X

  RCC->CFGR &= ~(RCC_CFGR_USBPRE); // USB PRESCALER = 1.5
  SET_BIT(RCC->CR,RCC_CR_HSEON); // TURN ON THE HSE

  while((RCC->CR & RCC_CR_HSERDY) == 0); // Wait for HSE to boot

  RCC->CFGR |= (0x1 >> RCC_CFGR_PLLSRC_Pos); // Select HSE for the PLL MUX
  SET_BIT(RCC->CR,RCC_CR_PLLON); // Turn On the PLL

  while((RCC->CR & RCC_CR_PLLRDY) == 0); // Wait for the PLL to turn On

  FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY_1; //clear latency fields


  RCC->CFGR &= ~(RCC_CFGR_SW); // Clear Bit fields or system Clock
  SET_BIT(RCC->CFGR,RCC_CFGR_SW_1); // Set System Clock MUXto PLL input

  while(( RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1);
  RCC->CFGR &= ~(RCC_CFGR_HPRE);
  RCC->CFGR &= ~(RCC_CFGR_PPRE1);
  RCC->CFGR |= (RCC_CFGR_PPRE1_2);
  RCC->CFGR &= ~(RCC_CFGR_PPRE2);


  RCC->CFGR &= ~(RCC_CFGR_ADCPRE);
  RCC->CFGR |= (RCC_CFGR_ADCPRE_1);


 // For more Info Refer to COLCK TREE and Reference Manual

}

void RCC_SYSTICK_CONFIG(uint32_t RELOAD_VALUE)
{

  SysTick->CTRL = 0;
  SysTick->LOAD = RELOAD_VALUE-1;
  NVIC_SetPriority(SysTick_IRQn,0);
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
  SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;


}


void RCC_MSTICKS_INC(void)
{
	MSTICKS++;
}

uint32_t RCC_GET_MSTICKS(void)
{
  return MSTICKS;
}


void SysTick_Handler(void)
{
  NVIC_ClearPendingIRQ(SysTick_IRQn);
  RCC_MSTICKS_INC();
}

void RCC_DELAY(uint32_t MILI_SECONDS)
{
  uint32_t StartTicks = RCC_GET_MSTICKS();

  while(RCC_GET_MSTICKS() - StartTicks < MILI_SECONDS );

}
