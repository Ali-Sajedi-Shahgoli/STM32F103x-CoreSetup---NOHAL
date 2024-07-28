/*
 * UART.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Ali
 */

#ifndef INC_UART_H_
#define INC_UART_H_
#include <main.h>

void UART1_IO_CONFIG(void);
void UART_MAIN_CONFIG(void);
bool UART1_TRANSMIT(uint8_t *data, uint8_t len, uint32_t timeout);


#endif /* INC_UART_H_ */
