/*
 * printf_redirect.c
 *
 *  Created on: 9 Oct 2020
 *      Author: Dell
 */

#include "UART.h"

int __io_putchar(int ch);
int _write(int file,char *ptr, int len);

int __io_putchar(int ch) {
	UART1_TRANSMIT((uint8_t *)&ch, 1, 100);
 return ch;
}

int _write(int file,char *ptr, int len) {
 int DataIdx;
 for(DataIdx= 0; DataIdx< len; DataIdx++) {
  __io_putchar(*ptr++);
 }
 return len;
}
