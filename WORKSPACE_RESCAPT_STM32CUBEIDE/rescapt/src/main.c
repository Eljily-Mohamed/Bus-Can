#include "main.h"
#include "MadgwickAHRS.h"

//###################################################################
#define VL6180X_PRESS_HUM_TEMP	1
#define MPU9250	0
#define DYN_ANEMO 0
//###################################################################

//====================================================================
//			CAN ACCEPTANCE FILTER
//====================================================================
#define USE_FILTER	1
// Can accept until 4 Standard IDs
#define ID_1	0x01 //VL6180X_PRESS_HUM_TEMP
#define ID_2	0x02 //MPU9250
#define ID_3	0x03 //DYN_ANEMO
#define ID_4	0x04 // PC

//====================================================================
extern void systemClock_Config(void);
void (*rxCompleteCallback) (void);
void can_callback(void);

CAN_Message      rxMsg;
CAN_Message      txMsg;
long int        counter = 0;

//=============== DYN_ANEMO vars
static int vitesse;
static int motor_on;
static int mode_auto;
static int mode_auto_on = 0;
//=============== end

uint8_t* aTxBuffer[2];

extern float magCalibration[3];

void VL6180x_Init(void);
void VL6180x_Step(void);
void rangeLuxTempHum_Callback(void);
void accelerometre_Callback(void);
void anymo_Callback();

//============== card 2
uint8_t bascule_mode;
uint8_t lsb = 0;
uint8_t msb = 0;
uint8_t lsb2 = 0;
uint8_t msb2 = 0;
int id;
int status;
int new_switch_state;
int switch_state = -1;

//========== end

//==================== card 3
int16_t acc[3];
int16_t gyr[3];
float acc_x, acc_y, acc_z, gyr_x, gyr_y, gyr_z;
float angles[3] = {0.0f, 0.0f, 0.0f};

//====================================================================
// >>>>>>>>>>>>>>>>>>>>>>>>>> MAIN <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//====================================================================
int main(void)
{
	HAL_Init();
	systemClock_Config();
    SysTick_Config(HAL_RCC_GetHCLKFreq() / 1000); //SysTick end of count event each 1ms
	uart2_Init();
	uart1_Init();
	i2c1_Init();

#if DYN_ANEMO
    // Initialisation du moteur anémomètre
	dxl_LED(1, LED_ON);
	HAL_Delay(500);
	dxl_LED(1, LED_OFF);
	HAL_Delay(500);
	dxl_torque(1, TORQUE_OFF);
	dxl_setOperatingMode(1, VELOCITY_MODE);
	dxl_torque(1, TORQUE_ON);
    anemo_Timer1Init();
#endif

	HAL_Delay(1000); // Attente

#if VL6180X_PRESS_HUM_TEMP
    VL6180x_Init();
    id = lps22hb_whoAmI();
	lps22hb_setup();
	hts221_activate();
	id = hts221_whoAmI();
	hts221_storeCalibration();
#endif

#if MPU9250
    mpu9250_InitMPU9250();
    mpu9250_CalibrateMPU9250();
    uint8_t response=0;
	response =  mpu9250_WhoAmI();
	term_printf("%d",response);
#endif

    can_Init();
    can_SetFreq(CAN_BAUDRATE); // CAN BAUDRATE : 500 MHz
#if USE_FILTER
    can_Filter_list((ID_1<<21)|(ID_2<<5), (ID_3<<21)|(ID_4<<5), CANStandard, 0);
#else
    can_Filter_disable();
#endif

    can_IrqInit();
    can_IrqSet(&can_callback);
    tickTimer_Init(200);

    while (1) {
#if DYN_ANEMO
        if (motor_on || mode_auto_on)
            dxl_setGoalVelocity(1, vitesse);
        else
            dxl_setGoalVelocity(1, 0);
#endif
#if VL6180X_PRESS_HUM_TEMP
    VL6180x_Step();
#endif
    }
    return 0;
}

//====================================================================
//			CAN CALLBACK RECEPT
//====================================================================

#if DYN_ANEMO
void anymo_Callback(){
    int counter = anemo_GetCount();
    int anemoSpeed = (counter * 5) / 4;
    if(mode_auto){
    	if(anemoSpeed > 10)
    		mode_auto_on = 1;
    	else {
    		mode_auto_on = 0;
    	}
    }
    anemo_ResetCount();


    txMsg.id = 0x55;
    txMsg.data[0] = (uint8_t)(anemoSpeed & 0xFF);
    txMsg.data[1] = (uint8_t)((anemoSpeed >> 8) & 0xFF);
    txMsg.len = 2;
    txMsg.format = CANStandard;
    txMsg.type = CANData;
    can_Write(txMsg);
}
#endif

#if VL6180X_PRESS_HUM_TEMP
void rangeLuxTempHum_Callback(void) {
    static float pres_value, temp_value, humi_value;
    uint8_t i = lps22hb_getPressure(&pres_value);
    if (i) {
        term_printf("Erreur lors de l'acquisition de la pression\n\r");
        return;
    }
    i = hts221_getTemperature(&temp_value);
    if (i) {
        term_printf("Erreur lors de l'acquisition de la température\n\r");
        return;
    }
    i = hts221_getHumidity(&humi_value);
    if (i) {
        term_printf("Erreur lors de l'acquisition de l'humidité\n\r");
        return;
    }

    txMsg.id = 0x56;

    uint16_t pres_int = (uint16_t)(pres_value * 10.0f);
    uint16_t temp_int = (uint16_t)(temp_value * 100.0f);
    uint16_t humi_int = (uint16_t)(humi_value);

    if (bascule_mode) {
        txMsg.data[0] = Als.lux & 0xFF;
        txMsg.data[1] = (Als.lux >> 8) & 0xFF;
        txMsg.data[2] = (Als.lux >> 16) & 0xFF;
    } else {
        txMsg.data[0] = range & 0xFF;
        txMsg.data[1] = (range >> 8) & 0xFF;
        txMsg.data[2] = 0x00;
    }

//    term_printf("Pressure: %d hPa\n\r", pres_int);
//    term_printf("Temperature: %d °C\n\r", temp_int);
//    term_printf("Humidity: %d %%\n\r", humi_int);

    txMsg.data[3] = pres_int & 0xFF;
    txMsg.data[4] = (pres_int >> 8) & 0xFF;
    txMsg.data[5] = temp_int & 0xFF;
    txMsg.data[6] = (temp_int >> 8) & 0xFF;
    txMsg.data[7] = (uint8_t)humi_int;

    txMsg.len = 8;
    txMsg.format = CANStandard;
    txMsg.type = CANData;

    can_Write(txMsg);
}
#endif



#if MPU9250
void accelerometre_Callback(void) {
    // Lecture des données de l'accéléromètre et du gyroscope
    mpu9250_ReadAccelData(acc);
    mpu9250_ReadGyroData(gyr);

    acc_x = acc[0] * (4.0f / 32768.0f);
    acc_y = acc[1] * (4.0f / 32768.0f);
    acc_z = acc[2] * (4.0f / 32768.0f);

    gyr_x = gyr[0] * ((1000.0f / 32768.0f) * (M_PI / 180.0f));
    gyr_y = gyr[1] * ((1000.0f / 32768.0f) * (M_PI / 180.0f));
    gyr_z = gyr[2] * ((1000.0f / 32768.0f) * (M_PI / 180.0f));

    //deplace vers main dans while() pour optemise code
    // Mise à jour de l'algorithme de fusion de capteurs
    MadgwickAHRSupdateIMU(gyr_x, gyr_y, gyr_z, acc_x, acc_y, acc_z);

    double R12=2*(q1*q2+q0*q3);
    double R22=q0*q0+q1*q1-q2*q2-q3*q3;
    double R31=2*(q0*q1+q2*q3);
    double R32=2*(q1*q3-q0*q2);
    double R33=q0*q0-q1*q1-q2*q2+q3*q3;

    angles[0] = atan2(R31,R33);
    angles[1] = -asin(R32);
    angles[2] = atan2(R12,R22);


    int16_t angle_phi = (int16_t)(angles[0] * 100.0f);
    int16_t angle_theta = (int16_t)(angles[1] * 100.0f);
    int16_t angle_psi = (int16_t)(angles[2] * 100.0f);


    //term_printf("angles sont = %f,%f,%f \n\r",angles[0],angles[1],angles[2]);

    txMsg.id = 0x57;

    uint8_t msb = (angle_phi & 0xFF00) >> 8;
    uint8_t lsb = (angle_phi & 0x00FF);

    txMsg.data[0] = lsb;
    txMsg.data[1] = msb;

    msb = (angle_theta & 0xFF00) >> 8;
    lsb = (angle_theta & 0x00FF);

   txMsg.data[2] = lsb;
   txMsg.data[3] = msb;

    msb = (angle_psi & 0xFF00) >> 8;
    lsb = (angle_psi & 0x00FF);

    txMsg.data[4] = lsb;
    txMsg.data[5] = msb;


    txMsg.len = 6;
    txMsg.format = CANStandard;
    txMsg.type = CANData;
    can_Write(txMsg);
}
#endif

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
#if DYN_ANEMO
	//anymo_Callback();
#endif
}

void can_callback(void)
{
    CAN_Message msg_rcv;
    can_Read(&msg_rcv);

    if (msg_rcv.id == ID_1) {

#if VL6180X_PRESS_HUM_TEMP
     if(msg_rcv.data[0] == 0x10) {
    		bascule_mode = 1;
      } else if(msg_rcv.data[0] == 0x20) {
    		bascule_mode = 0;
      }
      rangeLuxTempHum_Callback();
#endif

    }
    else if (msg_rcv.id == ID_2) {
#if MPU9250
        accelerometre_Callback();
#endif
    }
    else if (msg_rcv.id == ID_3) {
#if DYN_ANEMO
        if (msg_rcv.data[0] == 0x10) {
            motor_on = !motor_on;
        } else if (msg_rcv.data[0] == 0x20) {
            vitesse = msg_rcv.data[1];
        }else if(msg_rcv.data[0] == 0x30){
        	mode_auto = !mode_auto;
        	if(!mode_auto)
        		mode_auto_on = 0;
        }
        anymo_Callback();
#endif
    }
    else if (msg_rcv.id == ID_4) {
        //
    }
}


//====================================================================

#if VL6180X_PRESS_HUM_TEMP
void VL6180x_Init(void)
{
	uint8_t id;
	State.mode = 1;

    XNUCLEO6180XA1_Init();
    HAL_Delay(500); // Wait
    // RESET
    XNUCLEO6180XA1_Reset(0);
    HAL_Delay(10);
    XNUCLEO6180XA1_Reset(1);
    HAL_Delay(1);

    HAL_Delay(10);
    VL6180x_WaitDeviceBooted(theVL6180xDev);
    id=VL6180x_Identification(theVL6180xDev);
    term_printf("id=%d, should be 180 (0xB4) \n\r", id);
    VL6180x_InitData(theVL6180xDev);

    State.InitScale=VL6180x_UpscaleGetScaling(theVL6180xDev);
    State.FilterEn=VL6180x_FilterGetState(theVL6180xDev);

     // Enable Dmax calculation only if value is displayed (to save computation power)
    VL6180x_DMaxSetState(theVL6180xDev, DMaxDispTime>0);

    switch_state=-1 ; // force what read from switch to set new working mode
    State.mode = AlrmStart;
}
//====================================================================
void VL6180x_Step(void)
{
    DISP_ExecLoopBody();
	#ifndef bascule_mode
		new_switch_state = XNUCLEO6180XA1_GetSwitch();
	#endif
	new_switch_state = bascule_mode;
    if (new_switch_state != switch_state) {
        switch_state=new_switch_state;
        status = VL6180x_Prepare(theVL6180xDev);
        // Increase convergence time to the max (this is because proximity config of API is used)
        VL6180x_RangeSetMaxConvergenceTime(theVL6180xDev, 63);
        if (status) {
            AbortErr("ErIn");
        }
        else{
            if (switch_state == SWITCH_VAL_RANGING) {
                VL6180x_SetupGPIO1(theVL6180xDev, GPIOx_SELECT_GPIO_INTERRUPT_OUTPUT, INTR_POL_HIGH);
                VL6180x_ClearAllInterrupt(theVL6180xDev);
                State.ScaleSwapCnt=0;
                DoScalingSwap( State.InitScale);
            } else {
                 State.mode = RunAlsPoll;
                 InitAlsMode();
            }
        }
    }

    switch (State.mode) {
    case RunRangePoll:
        RangeState();
        break;

    case RunAlsPoll:
        AlsState();
        break;

    case InitErr:
        TimeStarted = g_TickCnt;
        State.mode = WaitForReset;
        break;

    case AlrmStart:
       GoToAlaramState();
       break;

    case AlrmRun:
        AlarmState();
        break;

    case FromSwitch:
        // force reading swicth as re-init selected mode
        switch_state=!XNUCLEO6180XA1_GetSwitch();
        break;

    case ScaleSwap:

        if (g_TickCnt - TimeStarted >= ScaleDispTime) {
            State.mode = RunRangePoll;
            TimeStarted=g_TickCnt; /* reset as used for --- to er display */
        }
        else
        {
        	DISP_ExecLoopBody();
        }
        break;

    default: {
    	 DISP_ExecLoopBody();
          if (g_TickCnt - TimeStarted >= 5000) {
              NVIC_SystemReset();
          }
    }
    }
}
//====================================================================
#endif

