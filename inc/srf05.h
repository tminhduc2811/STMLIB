#include "stm32f4xx.h"
#include "stm32f411_RCCEnable.h"
#include "stm32f4xx_delay.h"
/* Driver using STM32F411 to communicate with Srf05 (Ultra sonic sensor) */
/* ------------- How to use the driver ------------------*/
/* ------------------------------------------------------*/
/***** Followwing these steps to config the sensor ******/
/*
***     (+) Step 1:
Config trigger pin by calling function: Srf05_TriggerPinConfig()
***			(+) Step 2:
Config peripherals to control device then call function: Srf05_Initial()
***			(+) Step 3: By using IC interrupt for each device, call the interrupt function handler that match with the TIMx


*/	
/* ------------ Device parameters	--------------------------*/
#define					Srf05_Const											(double)29.412

typedef enum{
	SAI = 0,
	DUNG,
}LOGIC;

typedef struct Srf05_InitTypeDef{
	GPIO_TypeDef			*Srf05_GPIO;
	TIM_TypeDef				*Srf05_ICTIM;
	uint16_t					Srf05_Echo_Pin;
	uint16_t					Srf05_TIM_IT_CC;
	uint16_t					Srf05_IC_Channel;
	uint8_t						Srf05_PreemptionPriority;
	uint8_t						Srf05_SubPriority;
}Srf05_InitTypeDef;

typedef struct Srf05_Data{
	uint32_t 					PulseWidth;
	double						Distance;
}Srf05_Data;

/* Export function */
void			Srf05_TriggerPinConfig(GPIO_TypeDef *GPIOx, uint16_t TriggerPin);
void			Srf05_Initial(Srf05_InitTypeDef *psrf05);
void			Srf05_StartDevice(void);
void			Srf05_ResetCounter(TIM_TypeDef *TIMx);



