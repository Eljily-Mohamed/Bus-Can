#include "lps22hb.h"

//========================================================================
//          PRESSURE SENSOR
//========================================================================

#define lps22hb_I2C_ADDRESS     0xBA

//=======================================================
//          REGISTER ADDRESS MAP
//=======================================================

#define REF_P_XL        0x08
#define REF_P_L         0x09
#define REF_P_H         0x0A
#define WHO_AM_I        0x0F
#define RES_CONF        0x10
#define CTRL_REG1       0x20
#define CTRL_REG2       0x21
#define CTRL_REG3       0x22
#define CTRL_REG4       0x23
#define INTERRUPT_CFG   0x24
#define INT_SOURCE      0x25
#define STATUS_REG      0x27
#define PRESS_OUT_XL    0x28
#define PRESS_OUT_L     0x29
#define PRESS_OUT_H     0x2A
#define TEMP_OUT_L      0x2B
#define TEMP_OUT_H      0x2C
#define FIFO_CTRL       0x2E
#define FIFO_STATUS     0x2F
#define THS_P_L         0x30
#define THS_P_H         0x31
#define RPDS_L          0x39
#define RPDS_H          0x3A

//========================================================================
//          WHO AM I
//========================================================================
// Default : 0xBD
uint8_t lps22hb_whoAmI()
{
    uint8_t id;
    i2c1_ReadRegBuffer(lps22hb_I2C_ADDRESS, WHO_AM_I,  &id, 1);
    return id;
}
//========================================================================
//          SETUP
//========================================================================
void lps22hb_setup()
{
    uint8_t data;
    data = 0x10;    // Active mode, continuous update
    i2c1_WriteRegBuffer(lps22hb_I2C_ADDRESS, CTRL_REG1,  &data, 1);

    data=0x1A;  // resolution: temp=32, pressure=128
    i2c1_WriteRegBuffer(lps22hb_I2C_ADDRESS, RES_CONF,  &data, 1);
}
//========================================================================
//          GET PRESSURE
//========================================================================
int lps22hb_getPressure(float* pressure)
{
    uint8_t data_xl[1];
    uint8_t data_l[1];
    uint8_t data_h[1];
    static float press = 0.0;

    i2c1_ReadRegBuffer(lps22hb_I2C_ADDRESS, (PRESS_OUT_XL | 0x80),  data_xl, 1);
    i2c1_ReadRegBuffer(lps22hb_I2C_ADDRESS, (PRESS_OUT_L | 0x80),  data_l, 1);
    i2c1_ReadRegBuffer(lps22hb_I2C_ADDRESS, (PRESS_OUT_H | 0x80),  data_h, 1);
    //data_h[0]=0x10|data_h[0];
    press = ((data_h[0] * 65536) + ((data_l[0] * 256) + data_xl[0])) / 4096.0;

    *pressure = press;

    return 0;
}
//========================================================================
//          GET TEMPERATURE
//========================================================================
int lps22hb_getTemperature(float* tmp)
{
    uint8_t tempH, tempL;
    static float temperature = 0.0;

    //uint8_t  data = 0x1;  // For one-shot mode
    //i2c1_WriteRegBuffer(lps22hb_I2C_ADDRESS, CTRL_REG2,  &data, 1);
    i2c1_ReadRegBuffer(lps22hb_I2C_ADDRESS, TEMP_OUT_L,  &tempL, 1);
    i2c1_ReadRegBuffer(lps22hb_I2C_ADDRESS, TEMP_OUT_H,  &tempH, 1);

    int16_t val = ((int16_t)tempH) << 8 | (tempL & 0xff);
    temperature = (float)val/100.0;

    *tmp=temperature;

    return 0;
}
//========================================================================
