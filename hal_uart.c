#include "common.h"

static void UARTPutChar ( uint8_t ch)
{
	while((USIST1 & 0x80) == 0);
	USIDR = ch;
}


void UARTPuts( const void *str)
{
	uint8_t *s = (uint8_t *) str;

	while (*s)
	{
		UARTPutChar( *s++);
	}
}


void UARTPutDec16(uint16_t decnum)
{
	uint8_t c1=decnum%10;
	uint8_t c2=(decnum/10)%10;
	uint8_t c3=(decnum/100)%10;
	uint8_t c4=(decnum/1000)%10;
	uint8_t c5=(decnum/10000)%10;
	UARTPutChar( '0'+c5);
	UARTPutChar( '0'+c4);
	UARTPutChar( '0'+c3);
	UARTPutChar('0'+c2);
	UARTPutChar('0'+c1);
}

void UARTPutDec32(uint32_t decnum)
{
	uint8_t c1=decnum%10;
	uint8_t c2=(decnum/10)%10;
	uint8_t c3=(decnum/100)%10;
	uint8_t c4=(decnum/1000)%10;
	uint8_t c5=(decnum/10000)%10;
	uint8_t c6=(decnum/100000)%10;
	uint8_t c7=(decnum/1000000)%10;
	uint8_t c8=(decnum/10000000)%10;
	uint8_t c9=(decnum/100000000)%10;
	uint8_t c10=(decnum/1000000000)%10;
	UARTPutChar( '0'+c10);
	UARTPutChar( '0'+c9);
	UARTPutChar( '0'+c8);
	UARTPutChar('0'+c7);
	UARTPutChar('0'+c6);
	UARTPutChar('0'+c5);
	UARTPutChar('0'+c4);
	UARTPutChar('0'+c3);
	UARTPutChar('0'+c2);
	UARTPutChar('0'+c1);
}


volatile INT8U dbgXYl=0;
extern volatile INT8U gSysRunMode;
extern volatile INT8U gSysProtectStatus;
extern INT8U resultDuty;
extern INT8U currDuty;
extern INT8U sampleDuty;
extern SYSADC gSysAdc;
void dbgHandle()
{

	if(dbgXYl++ >=10)
		{
			dbgXYl = 0;
			DBG("\r\nsampleDuty:");DBD32(sampleDuty);
			DBG("\r\ncurrDuty:");DBD32(currDuty);
			DBG("\r\nresultDuty:");DBD32(resultDuty);
			DBG("\r\nSysRunMode:");DBD16(gSysRunMode);
			DBG("\r\nProtectStatus:");DBD16(gSysProtectStatus);
			DBG("\r\nmainCurr:");DBD16(gSysAdc.mainCurrAdc);
			DBG("\r\nviceCurr:");DBD16(gSysAdc.viceCurrAdc);
			DBG("\r\nvbusADC:");DBD16(gSysAdc.vbusAdc);
			DBG("\r\ntempAdc:");DBD16(gSysAdc.tempAdc);
		}
}
