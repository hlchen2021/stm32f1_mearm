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

unsigned char RxAddr[]={0x0a,0xbc,0xad,0xce,0x2a};//���͵�ַ
unsigned char RXData[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char TranFlag;

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();	    	 			//��ʱ������ʼ��	  
	uart_init(500000);	 			//���ڳ�ʼ��Ϊ9600
	Servo_Init();							//�����ʼ��
	while(1)
	{
		Servo_SetAngle1(90);
		Servo_SetAngle2(90);
		Servo_SetAngle3(90);
		
	}
}

