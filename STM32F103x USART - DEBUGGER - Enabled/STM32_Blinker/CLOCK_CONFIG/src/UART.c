/*
 * UART.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Ali
 */


#include <UART.h>




void UART1_IO_CONFIG(void)
{
		// Enable PortA CLK
		RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN);
		RCC->APB2ENR |= (RCC_APB2ENR_AFIOEN); //Enable Alternate Function

		GPIOA->CRH &= ~(GPIO_CRH_CNF9);   // Setting GPIOA 9 - 10 As TXD - RXD
	    GPIOA->CRH |= (GPIO_CRH_CNF9_1);
	    GPIOA->CRH &= ~(GPIO_CRH_CNF10);
	    GPIOA->CRH |= (GPIO_CRH_CNF10_0);
	    GPIOA->CRH &= ~(GPIO_CRH_MODE9);
	    GPIOA->CRH &= ~(GPIO_CRH_MODE10);
	    GPIOA->CRH |= (GPIO_CRH_MODE9_0);   // Setting IO mode for TX and RX
	    AFIO->MAPR &= ~(AFIO_MAPR_USART1_REMAP); // Making Sure Register in Not MAPPED to PB6 PB7

}




void UART_MAIN_CONFIG (void)
{
	//Enable UART Clock
	RCC->APB2ENR |= (RCC_APB2ENR_USART1EN);
	USART1->CR1 |= (USART_CR1_TE);
	USART1->CR1 &= ~(USART_CR1_PCE); // Disabling Parity Control ???
	USART1->CR1 &= ~(USART_CR1_PS); // Setting parity to Even
	USART1->CR1 &= ~(USART_CR1_M); // Setting 8bit data transfer
	USART1->CR2 &= ~(USART_CR2_STOP); // Setting Stop bit to 1
	 //Disable Hardware flow control (RTS, CTS)
	USART1->CR3 &= ~(USART_CR3_CTSE);
 	USART1->CR3 &= ~(USART_CR3_RTSE);

 	//Setting Baud Rate to 115200
	 USART1->BRR = 0;
	 USART1->BRR |= (39UL << 4);
	 USART1->BRR |= (1UL << 0);
	  //Clear LINEN and CLKEN in CR2
     USART1->CR2 &= ~(USART_CR2_LINEN | USART_CR2_CLKEN);
	    //Clear SCEN, HDSEL and IREN in CR3
     USART1->CR3 &= ~(USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN);
  	 USART1->CR1 |= (USART_CR1_UE); // Enabled UART


}



/**
 * @brief UART1 transmit
 */
bool UART1_TRANSMIT(uint8_t *data, uint8_t len, uint32_t timeout)
{
  //Wait on TXE to start transmit
  //Write to DR as TXE flag is HIGH (Tx buffer Empty)
  uint8_t dataIdx = 0;
  uint32_t startTick = RCC_GET_MSTICKS();
  while(dataIdx<len)
  {
    if(USART1->SR & USART_SR_TXE) //Tx buffer empty
    {
      USART1->DR = data[dataIdx];
      dataIdx++;
    }
    else //Manage timeout
    {
      if((RCC_GET_MSTICKS() - startTick)>= timeout) return false;
    }
  }
  //Wait for busy flag
  while(USART1->SR & USART_SR_TC)
  {
    if((RCC_GET_MSTICKS() - startTick)>= timeout) return false;
  }
  return true;
}



