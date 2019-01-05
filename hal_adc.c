#include "common.h"



SYSADC gSysAdc;

uint16_t get_adc(uint8_t ad_ch)
{
	uint16_t temp ;	

	ADCCRL = 0x80 |(ad_ch&0x0f);
	ADCCRL |=(1<<6);
	while((ADCCRL&0x10)==0);
	temp =((uint16_t)(ADCDRH ))&0x0003;// using 8bit

	temp = (temp << 8) + ADCDRL;
    return (temp);
}


void adcSampleHandle()
{
	gSysAdc.tempAdc = get_adc(ADC_CH_TEMP);
	gSysAdc.vbusAdc = get_adc(ADC_CH_VBUS);
	//gSysAdc.mainMotorAdc = get_adc(ADC_CH_V_MAIN_MOTOR);
	//gSysAdc.viceMotorAdc = get_adc(ADC_CH_V_VICE_MOTOR);
	//gSysAdc.mainCurrAdc = get_adc(ADC_CH_MAIN_CURR_DET);
	//gSysAdc.viceCurrAdc = get_adc(ADC_CH_VICE_CURR_DET);
}