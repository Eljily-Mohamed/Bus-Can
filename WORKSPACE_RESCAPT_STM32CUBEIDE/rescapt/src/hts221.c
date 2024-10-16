/*
 * hts221.c
 *
 *  Created on: Nov 17, 2017
 *      Author: kerhoas
 */

// https://github.com/ameltech/sme-hts221-library

#include "hts221.h"
#include "drv_i2c.h"

//================================================================================
//              HUMIDITY AND TEMPERATURE SENSOR
//================================================================================

#define HTS221_I2C_ADDRESS      0xBE

#define TEMPERATURE_READY   0x1
#define HUMIDITY_READY      0x2
#define POWER_UP            0x80
#define BDU_SET             0x4
#define ODR0_SET            0x1 // setting sensor reading period 1Hz

//================================================================================
//              REGISTER ADDRESS MAP
//================================================================================

#define WHO_AM_I        0x0F
#define AV_CONF         0x10
#define CTRL_REG1       0x20
#define CTRL_REG2       0x21
#define CTRL_REG3       0x22
#define STATUS_REG      0x27
#define HUMIDITY_OUT_L  0x28
#define HUMIDITY_OUT_H  0x29
#define TEMP_OUT_L      0x2A
#define TEMP_OUT_H      0x2B

#define CALIB_0         0x30    //  H0_rH_x2
#define CALIB_1         0x31    //  H1_rH_x2
#define CALIB_2         0x32    //  T0_degC_x8
#define CALIB_3         0x33    //  T1_degC_x8
#define CALIB_4         0x34
#define CALIB_5         0x35    // T1/T0 msb
#define CALIB_6         0x36    // H0_T0_OUT
#define CALIB_7         0x37    // H0_T0_OUT
#define CALIB_8         0x38
#define CALIB_9         0x39
#define CALIB_A         0x3A    //  H1_T0_OUT
#define CALIB_B         0x3B    //  H1_T0_OUT
#define CALIB_C         0x3C    //  T0_OUT
#define CALIB_D         0x3D    //  T0_OUT
#define CALIB_E         0x3E    //  T1_OUT
#define CALIB_F         0x3F    //  T1_OUT

//================================================================================
//          CONF VARIABLES
//================================================================================

uint8_t _h0_rH, _h1_rH;
uint32_t  _T0_degC, _T1_degC;
uint32_t  _H0_T0, _H1_T0;
uint32_t  _T0_OUT, _T1_OUT;

//================================================================================
//          WHO AM I
//  defaut : 0xBC
//================================================================================
uint8_t hts221_whoAmI()
{
    uint8_t id=0;
    i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, WHO_AM_I,  &id, 1);
    return id;
}
//================================================================================
//          ACTIVATE
//================================================================================
void hts221_activate()
{
     uint8_t data;
    i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CTRL_REG1,  &data, 1);
    data |= POWER_UP;
    data |= ODR0_SET;
    i2c1_WriteRegBuffer(HTS221_I2C_ADDRESS, CTRL_REG1,  &data, 1);
}
//================================================================================
//          BDU ACTIVATE
//================================================================================
void hts221_bduActivate()
{
     uint8_t data;
    i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CTRL_REG1,  &data, 1);
    data |= BDU_SET;
    i2c1_WriteRegBuffer(HTS221_I2C_ADDRESS, CTRL_REG1,  &data, 1);
}



//================================================================================
//  Hum and Temp average Configuration
//  default : 0x1B  -   0b 00 - 011 - 011 // R-Temp-Hum
//================================================================================
void hts221_conf()
{
}
//================================================================================
//          STORE CALIBRATION
//================================================================================
void hts221_storeCalibration()
{
     uint8_t data;
     uint16_t tmp;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_0,  &data, 1);
     _h0_rH = data;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_1,  &data, 1);
     _h1_rH = data;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_2,  &data, 1);
     _T0_degC = data;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_3,  &data, 1);
     _T1_degC = data;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_5,  &data, 1);
     tmp = _T0_degC;
     _T0_degC = (data&0x3)<<8;
     _T0_degC |= tmp;
     tmp = _T1_degC;
     _T1_degC = ((data&0xC)>>2)<<8;
     _T1_degC |= tmp;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_6,  &data, 1);
     _H0_T0 = data;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_7,  &data, 1);
     _H0_T0 |= data<<8;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_A,  &data, 1);
     _H1_T0 = data;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_B,  &data, 1);
     _H1_T0 |= data<<8;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_C,  &data, 1);
     _T0_OUT = data;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_D,  &data, 1);
     _T0_OUT |= data << 8;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_E,  &data, 1);
     _T1_OUT = data;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, CALIB_F,  &data, 1);
     _T1_OUT |= data << 8;
}
//================================================================================
//          GET TEMPERATURE
//================================================================================
int hts221_getTemperature(float* tmp)
{
    uint8_t data = 0;
    int16_t t_out;
    uint8_t temp_lsb;
    uint8_t     temp_msb;
   static float _temperature = 0.0;

    float deg = 0.0 ;
    float t_temp = 0.0 ;

     i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, STATUS_REG,  &data, 1);
     if(data & TEMPERATURE_READY)
     {
         i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, TEMP_OUT_L,  &temp_lsb, 1);
         i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, TEMP_OUT_H,  &temp_msb , 1);

         t_out = ((int16_t)temp_msb << 8 ) | temp_lsb;

         // Decode Temperature
         deg    = (float)((int16_t)(_T1_degC) - (int16_t)(_T0_degC))/8.0; // remove x8 multiple

         // Calculate Temperature in decimal of grade centigrades i.e. 15.0 = 150.
         t_temp = (float)(((int16_t)t_out - (int16_t)_T0_OUT) * deg) /
                 (float)((int16_t)_T1_OUT - (int16_t)_T0_OUT);
         deg    = (float)((int16_t)_T0_degC) / 8.0;     // remove x8 multiple
         _temperature = deg + t_temp; // provide signed celsius measurement unit

         *tmp = _temperature;

         return 0;
     }


     else
     {
         return -1;
     }
}
//================================================================================
//          GET HUMIDITY
//================================================================================
int hts221_getHumidity(float *humid)
{
    uint8_t data   = 0;
    uint16_t h_out = 0;
    float h_temp  = 0.0;
    float hum     = 0.0;
    static float _humidity;

    i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS, STATUS_REG,  &data, 1);

    if (data & HUMIDITY_READY) {

        i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS,HUMIDITY_OUT_H,  &data, 1);
        h_out = data << 8;  // MSB
        i2c1_ReadRegBuffer(HTS221_I2C_ADDRESS,HUMIDITY_OUT_L,  &data, 1);
        h_out |= data;      // LSB

        // Decode Humidity
        hum = ((int16_t)(_h1_rH) - (int16_t)(_h0_rH))/2.0;  // remove x2 multiple

        // Calculate humidity in decimal of grade centigrades i.e. 15.0 = 150.
        h_temp = (float)(((int16_t)h_out - (int16_t)_H0_T0) * hum) /
             (float)((int16_t)_H1_T0 - (int16_t)_H0_T0);
        hum    = (float)((int16_t)_h0_rH) / 2.0; // remove x2 multiple
        _humidity = (hum + h_temp); // provide signed % measurement unit


        *humid = _humidity;
        return 0;

    }
    else
    {
        return -1;
    }


}
//================================================================================
