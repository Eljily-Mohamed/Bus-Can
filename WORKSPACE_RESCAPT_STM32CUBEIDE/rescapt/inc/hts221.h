/*
 * hts221.h
 *
 *  Created on: Nov 17, 2017
 *      Author: kerhoas
 */

#ifndef INC_HTS221_H_
#define INC_HTS221_H_

#include "main.h"


uint8_t hts221_whoAmI();
void hts221_activate();
void hts221_storeCalibration();
int hts221_getTemperature(float*);
int hts221_getHumidity(float*);


#endif /* INC_HTS221_H_ */
