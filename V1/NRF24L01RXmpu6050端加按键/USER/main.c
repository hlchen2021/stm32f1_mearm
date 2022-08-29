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
  float mpudata[3]={0};     //���ڴ洢mpu6050����
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();	    	 			//��ʱ������ʼ��	  
	uart_init(500000);	 			//���ڳ�ʼ��Ϊ9600
	usmart_dev.init(72);			//��ʼ��USMART
	LED_Init();		  					//��ʼ����LED���ӵ�Ӳ���ӿ�
	KEY_Init();								//��ʼ������
	OLED12864_Init();     		//��ʼ��OLED
	Servo_Init();							//�����ʼ��
	OLED12864_TurnBias(0x7f);	//OLED��������
	nRF24L01_Setup(RxAddr);		//nrfģ���ʼ��
	SetRxMode();							//��������ͨ��ģ��Ϊ����
	WaitingRX();							//��������
	

	OLED12864_DisStr(0,10,0,"link1 :");
	OLED12864_DisStr(0,20,0,"link2 :");
	OLED12864_DisStr(0,30,0,"base	 :");
	
	while(1)
	{
		if(GetIRQStatus()==2)		//�ж��Ƿ������ݵ���
		{
			ClearIRQ();						//����ж�
			nRF24L01_RxDat(RXData,13);
			WaitingRX();
		}
		
		turn_charinto_float(RXData,mpudata);
		OLED12864_Format4(40,10,0,mpudata[0]);
		OLED12864_Format4(40,20,0,mpudata[1]);
		OLED12864_Format4(40,30,0,mpudata[2]);
		
		Servo_SetAngle1(mpudata[2]);
		Servo_SetAngle2(mpudata[0]);
		Servo_SetAngle3(mpudata[1]);
		
		if(RXData[0] == 'a')
		{
			Servo_SetAngle4(60);
		}
		
		if(RXData[0] == 'b')
		{
			Servo_SetAngle4(0);
		}		
		
	}
}

