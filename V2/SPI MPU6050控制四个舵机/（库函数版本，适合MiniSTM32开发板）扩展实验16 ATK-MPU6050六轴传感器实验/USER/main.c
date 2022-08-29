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
#include "AD.h"

float AD0;

int main(void)
 {
	float pitch,roll,yaw; 												//ŷ����
	short aacx,aacy,aacz;													//���ٶȴ�����ԭʼ����
	short gyrox,gyroy,gyroz;											//������ԭʼ����
	short temp;																		//�¶�	   
	float base,link1,link2;
	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
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
	AD_Init();
	 
	while(mpu_dmp_init())
 	{
		OLED12864_Format1(0,20,0,mpu_dmp_init());
	}
	OLED12864_DisStr(0,10,0,"pitch:");
	OLED12864_DisStr(0,20,0,"roll :");
	OLED12864_DisStr(0,30,0,"yaw  :");
	OLED12864_DisStr(0,40,0,"claw :");
 	while(1)
	{
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		{ 
			temp=MPU_Get_Temperature();								//�õ��¶�ֵ
			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
		}
		base=yaw+90.0;
		link1=roll+90.0;
		link2=pitch+90.0;
		
		AD0 = AD_GetValue(ADC_Channel_0)*0.019;
		
		Servo1_SetAngle(base);								//���ö��1ת����pitch��Ӧ�Ƕ�
		Servo2_SetAngle(link1);								//���ö��2ת����roll ��Ӧ�Ƕ�
		Servo3_SetAngle(link2);								//���ö��3ת����yaw  ��Ӧ�Ƕ�
		Servo4_SetAngle(AD0);
		
		OLED12864_Format4(40,10,0,base);					//��ʾ������pitch����
		OLED12864_Format4(40,20,0,link1);					//��ʾ������roll ����
		OLED12864_Format4(40,30,0,link2);						//��ʾ������yaw  ����
		OLED12864_Format4(40,40,0,AD0);
	}
}

