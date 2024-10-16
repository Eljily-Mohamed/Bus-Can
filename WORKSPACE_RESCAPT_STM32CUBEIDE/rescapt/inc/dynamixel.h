/*
 * dxlamixel.h
 *
 *  Created on: Oct 10, 2019
 *      Author: kerhoas
 */

#include "main.h"

#ifndef INC_dxlAMIXEL_H_
#define INC_dxlAMIXEL_H_

#define TORQUE_ON 	1
#define TORQUE_OFF 	0
#define LED_ON 		1
#define LED_OFF		0

#define VELOCITY_MODE 	1
#define POSITION_MODE	3
#define EXT_POS_MODE	4
#define PWM_MODE		16

void dxl_LED(int id, char val );
unsigned short dxl_updateCRC(unsigned short crc_accum, unsigned char *data_blk_ptr, unsigned short data_blk_size);
int dxl_sendPacketWrite(int id, int Address, int value);
int dxl_sendPacket(int id, int instruction, int parameter_data_size, ...);
void dxl_torque(int id, char val);
void dxl_setGoalVelocity(int id, int val);
void dxl_setGoalPosition(int id, int val);
void dxl_setOperatingMode(int id, char val);
int dxl_readPacket();
uint8_t dxl_getBaudRate(int id);
uint32_t dxl_getPresentPosition(int id);
uint8_t dxl_getFirmwareVersion(int id);
uint8_t dxl_getModelNumber(int id);
void dxl_rcv_cb(uint8_t car);
void dxl_setBaudrate(int id, char val);
void dxl_factoryReset(int id);

#endif /* INC_dxlAMIXEL_H_ */
