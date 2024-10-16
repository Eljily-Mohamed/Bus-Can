/*
 * lps22hb.h
 *
 *  Created on: Jan 29, 2021
 *      Author: kerhoas
 */

#ifndef LPS22HB_H_
#define LPS22HB_H_

#include "drv_i2c.h"

uint8_t lps22hb_whoAmI();
void lps22hb_setup();
int lps22hb_getPressure(float*);
int lps22hb_getTemperature(float*);

#endif /* LPS22HB_H_ */
