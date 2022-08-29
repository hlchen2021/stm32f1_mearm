#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h"   
#include "OLED.h"
#include "key.h"   
#include "usmart.h"   
#include "floatturn.h"
#include "nRF24L01.h"
#include "receieveturn.h"
#include "Servo.h"

unsigned char RxAddr[]={0xaa,0xbb,0xcc,0xdd,0xee};//���͵�ַ
unsigned char RXData[17]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char TranFlag;
float mpudata[4]={0};     //���ڴ洢mpu6050����

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();	    	 			//��ʱ������ʼ��	  
	uart_init(500000);	 			//���ڳ�ʼ��Ϊ9600
	usmart_dev.init(72);			//��ʼ��USMART
	LED_Init();		  					//��ʼ����LED���ӵ�Ӳ���ӿ�
	KEY_Init();								//��ʼ������
	OLED_Init();     		//��ʼ��OLED
	Servo_Init();							//�����ʼ��
	nRF24L01_Setup(RxAddr);		//nrfģ���ʼ��
	SetRxMode();							//��������ͨ��ģ��Ϊ����
	WaitingRX();							//��������
	
	OLED_ShowString(1,1,"base:");
	OLED_ShowString(2,1,"link1:");
	OLED_ShowString(3,1,"link2:");
	OLED_ShowString(4,1,"claw:");
	
	while(1)
	{
		if(GetIRQStatus()==2)		//�ж��Ƿ������ݵ���
		{
			ClearIRQ();						//����ж�
			nRF24L01_RxDat(RXData,17);
			WaitingRX();
		}
		
		turn_charinto_float(RXData,mpudata);
		OLED_Showfloat(1,8,mpudata[2]);
		OLED_Showfloat(2,8,mpudata[0]);
		OLED_Showfloat(3,8,mpudata[1]);
		OLED_Showfloat(4,8,mpudata[3]);
		
		Servo_SetAngle1(mpudata[0]);
		Servo_SetAngle2(mpudata[1]);
		Servo_SetAngle3(mpudata[2]);
		Servo_SetAngle4(mpudata[3]);
	}
}

