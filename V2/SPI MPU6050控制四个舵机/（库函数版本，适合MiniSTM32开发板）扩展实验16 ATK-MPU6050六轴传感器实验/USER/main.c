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
	float pitch,roll,yaw; 												//欧拉角
	short aacx,aacy,aacz;													//加速度传感器原始数据
	short gyrox,gyroy,gyroz;											//陀螺仪原始数据
	short temp;																		//温度	   
	float base,link1,link2;
	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();	    	 													//延时函数初始化	  
	uart_init(500000);	 													//串口初始化为9600
	usmart_dev.init(72);													//初始化USMART
	LED_Init();		  															//初始化与LED连接的硬件接口
	KEY_Init();																		//初始化按键
	OLED12864_Init();     												//初始化OLED
	OLED12864_TurnBias(0x7f);											//OLED亮度设置
	OLED12864_DisStr(30,0,12,"MPU6050");
	MPU_Init();																		//初始化MPU6050
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
			temp=MPU_Get_Temperature();								//得到温度值
			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		}
		base=yaw+90.0;
		link1=roll+90.0;
		link2=pitch+90.0;
		
		AD0 = AD_GetValue(ADC_Channel_0)*0.019;
		
		Servo1_SetAngle(base);								//设置舵机1转动到pitch相应角度
		Servo2_SetAngle(link1);								//设置舵机2转动到roll 相应角度
		Servo3_SetAngle(link2);								//设置舵机3转动到yaw  相应角度
		Servo4_SetAngle(AD0);
		
		OLED12864_Format4(40,10,0,base);					//显示陀螺仪pitch数据
		OLED12864_Format4(40,20,0,link1);					//显示陀螺仪roll 数据
		OLED12864_Format4(40,30,0,link2);						//显示陀螺仪yaw  数据
		OLED12864_Format4(40,40,0,AD0);
	}
}

