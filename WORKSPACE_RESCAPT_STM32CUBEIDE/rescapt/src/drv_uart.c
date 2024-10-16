/*
 * drv_uart.c
 *
 *  Created on: 31 mars 2016
 *      Author: kerhoas
 */

#include "drv_uart.h"
#include "math.h"
#include "util.h"
#include "dynamixel.h"

uint8_t rec_buf[2];
uint8_t rec_buf6[2]="";
int put_char(int);

extern void dyn_rcv_cb(uint8_t car);

//=================================================================
//	UART 2 INIT (STLINK UART)
//=================================================================

void uart2_Init()
{
	  Uart2Handle.Instance        = USART2;
	  Uart2Handle.Init.BaudRate   = UART_BAUDRATE;
	  Uart2Handle.Init.WordLength = UART_WORDLENGTH_8B;
	  Uart2Handle.Init.StopBits   = UART_STOPBITS_1;
	  Uart2Handle.Init.Parity     = UART_PARITY_NONE;
	  Uart2Handle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	  Uart2Handle.Init.Mode       = UART_MODE_TX_RX;
	  Uart2Handle.Init.OverSampling = UART_OVERSAMPLING_16;

	  HAL_UART_Init(&Uart2Handle);

	  HAL_UART_Receive_IT(&Uart2Handle, (uint8_t *)rec_buf, 1);
}

void uart3_Init()
{
	  UartDxlHandle.Instance          = USART3;

	  UartDxlHandle.Init.BaudRate     =57600;//1000000;//57600;
	  UartDxlHandle.Init.WordLength   = UART_WORDLENGTH_8B;
	  UartDxlHandle.Init.StopBits     = UART_STOPBITS_1;
	  UartDxlHandle.Init.Parity       = UART_PARITY_NONE;
	  UartDxlHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
	  UartDxlHandle.Init.Mode         = UART_MODE_TX_RX;
	  UartDxlHandle.Init.OverSampling = UART_OVERSAMPLING_16;

	  HAL_UART_Init(&UartDxlHandle);

	  HAL_UART_Receive_IT(&UartDxlHandle, (uint8_t *)rec_buf6, 1);
}


void uart1_Init()
{
	  UartDxlHandle.Instance          = USART1;

	  UartDxlHandle.Init.BaudRate     =57600;//1000000;//57600;
	  UartDxlHandle.Init.WordLength   = UART_WORDLENGTH_8B;
	  UartDxlHandle.Init.StopBits     = UART_STOPBITS_1;
	  UartDxlHandle.Init.Parity       = UART_PARITY_NONE;
	  UartDxlHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
	  UartDxlHandle.Init.Mode         = UART_MODE_TX_RX;
	  UartDxlHandle.Init.OverSampling = UART_OVERSAMPLING_16;

	  HAL_UART_Init(&UartDxlHandle);

	  HAL_UART_Receive_IT(&UartDxlHandle, (uint8_t *)rec_buf6, 1);
}


void sendFrame(unsigned char* s, int size)
{
	HAL_UART_Transmit(&UartDxlHandle, s, size, 0xFFFF);
}

//=================================================================
//	UART WRITE
//=================================================================

void uart_Write(char* toprint, int size)
{
	HAL_UART_Transmit(&Uart2Handle, (uint8_t *)toprint, size, 0xFFFF);
}

//=================================================================
//	PUCHAR PROTOTYPE (USED BY PRINTF FUNCTIONS)
//=================================================================
int put_char(int ch)
{
	HAL_UART_Transmit(&Uart2Handle, (uint8_t *)&ch, 1, 0xFFFF);
	return 0;
}

//=================================================================
//	UART RECEIVE CALLBACK5
//=================================================================
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{


		if (UartHandle -> Instance == USART3)
		{
			HAL_UART_Receive_IT(&UartDxlHandle, (uint8_t *)rec_buf6, 1);
			dxl_rcv_cb(rec_buf6[0]);
		}
		else
		{

			 HAL_UART_Receive_IT(&Uart2Handle, (uint8_t *)rec_buf, 1);
		}
}

//================================================================
//				PUT STRING
//================================================================
void put_string(char* s)
{
	while(*s != '\0')
	{
		put_char(*s);
		s++;
	}
}



//================================================================
//				TERM_PRINTF
//================================================================
void term_printf(const char* fmt, ...)
{
	__gnuc_va_list         ap;
	char          *p;
	char           ch;
	unsigned int u;
	unsigned long  ul;
	unsigned long long ull;
	unsigned long long tmp;
	unsigned long  size;
	unsigned int   sp;
	char           s[60];
	int first=0;

	va_start(ap, fmt);

	while (*fmt != '\0') {
		if (*fmt =='%') {
			size=0; sp=1;
			if (*++fmt=='0') {fmt++; sp=0;}	// parse %04d --> sp=0
			ch=*fmt;
			if ((ch>'0') && (ch<='9')) {	// parse %4d --> size=4
				char tmp[10];
				int i=0;
				while ((ch>='0') && (ch<='9')) {
					tmp[i++]=ch;
					ch=*++fmt;
				}
				tmp[i]='\0';
				size=str2num(tmp,10);
			}
			switch (ch) {
				case '%':
					put_char('%');
					break;
				case 'c':
					ch = va_arg(ap, int);
					put_char(ch);
					break;
				case 's':
					p = va_arg(ap, char *);
					put_string(p);
					break;
				case 'd':
					ul = va_arg(ap, long);
					if ((long)ul < 0) {
						put_char('-');
						ul = -(long)ul;
						//size--;
					}
					num2str(s, ul, 10, size, sp);
					put_string(s);
					break;
				case 'u':
					ul = va_arg(ap, unsigned int);
					num2str(s, ul, 10, size, sp);
					put_string(s);
					break;
				case 'o':
					ul = va_arg(ap, unsigned int);
					num2str(s, ul, 8, size, sp);
					put_string(s);
					break;
				case 'p':
					put_char('0');
					put_char('x');
					ul = va_arg(ap, unsigned int);
					num2str(s, ul, 16, size, sp);
					put_string(s);
					break;
				case 'x':
					ul = va_arg(ap, unsigned int);
					num2str(s, ul, 16, size, sp);
					put_string(s);
					break;
				case 'f':
					//if(first==0){ ull = va_arg(ap, long long unsigned int); first = 1;}
					ull = va_arg(ap, long long unsigned int);
					tmp = ull >> 63;
					int sign = tmp & 0x1 ;
					tmp = (ull & 0x000FFFFFFFFFFFFF) ;
					double mf = (double)tmp ;
					mf = mf / pow(2.0,52.0);
					mf = mf + 1.0;
					tmp = ( ull & 0x7FF0000000000000 ) >> 52;
					tmp = tmp - 1023;
					float f = mf*myPow(2.0,tmp);
					if(sign==1){ put_char('-'); }
					float2str((char*)s, f, 5);
					put_string((char*)s);
					break;

				default:
					put_char(*fmt);
			}
		} else put_char(*fmt);
		fmt++;
	}
	va_end(ap);
}
//================================================================

