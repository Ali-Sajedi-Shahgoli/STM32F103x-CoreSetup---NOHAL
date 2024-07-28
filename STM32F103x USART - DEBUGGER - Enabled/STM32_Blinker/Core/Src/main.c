#include "main.h"
#include "uart.h"




int main(void)
{
  //HSE Configuration

	RCC_HSE_CLOCK();
	RCC_SYSTICK_CONFIG(72000);
  //UART Configuration
	UART1_IO_CONFIG();
	UART_MAIN_CONFIG();
  //LED Configuration
	printf("HELLO ?\n");

  while(1)
  {
	  printf("HELLLOOOO\n");
	  RCC_DELAY(1000);
	  printf("KIA \n");
	  RCC_DELAY(1000);

  }
}


