#include "stm32f10x_it.h"
#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h"   
#include "SPI_OLED.h"
#include "key.h"   
#include "mpu6050.h"
#include "usmart.h"   
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include "MG955.h"
#include "nRF24L01.h"
#include "RCC.h"
#include "TIMX.h"
#include "floatturn.h"

uint16_t AD0, AD1, AD2;														//���ڴ洢ADCֵ
float servo[3];																		//���ڽ�ADֵת���ɶ�Ӧ�ĽǶ���Ϣ
float storage[3];																	//

unsigned char TxAddr[]={0x0a,0xbc,0xad,0xce,0x2a};//���͵�ַ
unsigned char TXData[13]={0};
extern unsigned char TranFlag;										//ͨ���ж���ʵ�ֶ�ʱ��������

int main(void)
 {
	float pitch,roll,yaw; 												//ŷ����
	short aacx,aacy,aacz;													//���ٶȴ�����ԭʼ����
	short gyrox,gyroy,gyroz;											//������ԭʼ����
	short temp;																		//�¶�	   
//	float base,link1,link2;
	 
	RCC_HSE_Configuration();											//ϵͳʱ������Ϊ72M
	NVIC_Configuration();
	delay_init();	    	 													//��ʱ������ʼ��	  
	uart_init(500000);	 													//���ڳ�ʼ��Ϊ9600
	usmart_dev.init(72);													//��ʼ��USMART
	LED_Init();		  															//��ʼ����LED���ӵ�Ӳ���ӿ�
	KEY_Init();																		//��ʼ������
	OLED12864_Init();     												//��ʼ��OLED
	OLED12864_TurnBias(0x7f);											//OLED��������
	OLED12864_DisStr(30,0,12,"MPU6050");
	MPU_Init();																		//��ʼ��MPU6050
	Servo_Init();
	TimerConfiguration();
	nRF24L01_Setup(TxAddr);												//nrfģ���ʼ��
	 
	while(mpu_dmp_init())
 	{
		OLED12864_Format1(0,20,0,mpu_dmp_init());
	}
	OLED12864_DisStr(0,10,0,"pitch:");
	OLED12864_DisStr(0,20,0,"roll :");
	OLED12864_DisStr(0,30,0,"yaw  :");
 	while(1)
	{
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		{ 
			temp=MPU_Get_Temperature();								//�õ��¶�ֵ
			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
		}
		servo[0]=pitch;
		servo[1]=roll;
		servo[2]=yaw;
		floatturn(servo,TXData,storage);  					//��servo��float���͵�����ת����unsigned char���͵����ݴ���TXData��	
		OLED12864_Format4(40,10,0,storage[0]);			//��ʾ������pitch����
		OLED12864_Format4(40,20,0,storage[1]);			//��ʾ������roll ����
		OLED12864_Format4(40,30,0,storage[2]);			//��ʾ������yaw  ����
		if(TranFlag)
		{
			nRF24L01_TxDat(TXData,13);
			TranFlag=0;			
		}
	}
}

