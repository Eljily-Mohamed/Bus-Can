/*
 * drv_uart.h
 *
 *  Created on: 31 mars 2016
 *      Author: kerhoas
 */

#ifndef INC_DRV_UART_H_
#define INC_DRV_UART_H_

#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

void uart2_Init(void);
void uart3_Init(void);

void term_printf(const char* fmt, ...);
void sendFrame(unsigned char* s, int size);

UART_HandleTypeDef Uart2Handle;
UART_HandleTypeDef UartDxlHandle;

#endif /* INC_DRV_UART_H_ */
