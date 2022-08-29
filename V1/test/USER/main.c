#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h"   
#include "SPI_OLED.h"
#include "key.h"   
#include "usmart.h"   
#include "floatturn.h"
#include "nRF24L01.h"
#include "receieveturn.h"
#include "Servo.h"

unsigned char RxAddr[]={0x0a,0xbc,0xad,0xce,0x2a};//发送地址
unsigned char RXData[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char TranFlag;

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();	    	 			//延时函数初始化	  
	uart_init(500000);	 			//串口初始化为9600
	Servo_Init();							//舵机初始化
	while(1)
	{
		Servo_SetAngle1(90);
		Servo_SetAngle2(90);
		Servo_SetAngle3(90);
		
	}
}

