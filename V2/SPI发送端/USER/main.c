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
#include "key.h"
#include "AD.h"

uint16_t AD0, AD1, AD2;														//用于存储ADC值
float servo[4];																		//用于将AD值转换成对应的角度信息
float storage[4];																	//

unsigned char TxAddr[]={0xaa,0xbb,0xcc,0xdd,0xee};//发送地址
unsigned char TXData[17]={0};
extern unsigned char TranFlag;										//通过中断来实现定时发送数据

int main(void)
 {
	float pitch,roll,yaw; 												//欧拉角
	short aacx,aacy,aacz;													//加速度传感器原始数据
	short gyrox,gyroy,gyroz;											//陀螺仪原始数据
	short temp;																		//温度	   
//	float base,link1,link2;
	 
	RCC_HSE_Configuration();											//系统时钟设置为72M
	NVIC_Configuration();
	delay_init();	    	 													//延时函数初始化	  
	uart_init(500000);	 													//串口初始化为9600
	usmart_dev.init(72);													//初始化USMART
	LED_Init();		  															//初始化与LED连接的硬件接口
	Key_Init();
	OLED12864_Init();     												//初始化OLED
	OLED12864_TurnBias(0x7f);											//OLED亮度设置
	OLED12864_DisStr(0,0,0,"TXData:");
	MPU_Init();																		//初始化MPU6050
	Servo_Init();
	TimerConfiguration();
	nRF24L01_Setup(TxAddr);												//nrf模块初始化
	AD_Init();
	
	while(mpu_dmp_init())
 	{}
	OLED12864_DisStr(0,10,0,"link1:");
	OLED12864_DisStr(0,20,0,"Link2:");
	OLED12864_DisStr(0,30,0,"base:");
	OLED12864_DisStr(0,40,0,"claw: ");

 	while(1)
	{
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		{ 
			temp=MPU_Get_Temperature();								//得到温度值
			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		}
		servo[0]=pitch;
		servo[1]=roll;
		servo[2]=yaw;
		servo[3]=AD_GetValue(ADC_Channel_0)*0.019;
		floatturn(servo,TXData,storage);  					//将servo的float类型的数据转换成unsigned char类型的数据存入TXData中	
		OLED12864_Format4(40,10,0,storage[0]);			//显示陀螺仪pitch数据
		OLED12864_Format4(40,20,0,storage[1]);			//显示陀螺仪roll 数据
		OLED12864_Format4(40,30,0,storage[2]);			//显示陀螺仪yaw  数据
		OLED12864_Format4(40,40,0,storage[3]);			//显示陀螺仪claw 数据
		if(TranFlag)
			{
				nRF24L01_TxDat(TXData,17);
				TranFlag=0;			
			}
	}
}

