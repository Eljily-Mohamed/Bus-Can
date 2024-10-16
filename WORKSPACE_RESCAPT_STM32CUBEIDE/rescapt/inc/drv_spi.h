/*
 * drv_spi.h
 *
 *  Created on: 29 févr. 2016
 *      Author: kerhoas
 */

#ifndef INC_DRV_SPI_H_
#define INC_DRV_SPI_H_


#include "main.h"

void spi1_Init(void);
uint8_t spi1_Transfer(uint8_t out);
void spi1_CS_low();
void spi1_CS_high();

//=========================================================================



#endif /* INC_DRV_SPI_H_ */
