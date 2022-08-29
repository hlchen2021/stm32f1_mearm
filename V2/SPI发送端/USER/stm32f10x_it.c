#include "stm32f10x_it.h"
#include "Key.h"
/********************************************************************
*��    ��:NVIC_Configration(void)
*��    ��:�жϷ��麯��������TIM1~4��USART1
*��ڲ���:��
*���ڲ���:��
*˵    ��:��
*���÷���:��
********************************************************************/
void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��1���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��2���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;				//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��3���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;				//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��4���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;				//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��5���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;				//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��6���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;				//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��7���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;				//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 7;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��8���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM8_UP_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
}
/*******************************************************************************
���ƣ�void TIM1_IRQHandler(void)
���ܣ���ʱ��1���жϷ�����
��ڲ�������
���ڲ�������
˵������
***********************************************************************************/
// unsigned short Timer1Counter;//��ʱ��1��ִ�м�����
// extern unsigned char Beep;//����Ч���ı���
// extern unsigned short SoundCounter;//��������ʱ������

// void TIM1_UP_IRQHandler(void)
// {
// 	Timer1Counter++;
// 	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);					//����жϱ�־
// 	
// 	BuzzerOut();
// 	
// 	
// 	if(Timer1Counter == 100) //100*10ms=1s
// 	{
// 		LED2Reverse();
// 		Timer1Counter=0;
// 	}
// }
/*******************************************************************************
���ƣ�void TIM2_IRQHandler(void)
���ܣ���ʱ��2���жϷ�����
��ڲ�������
���ڲ�������
˵������
************************************************************************************/

unsigned short Timer2Counter=0;
unsigned char TranFlag=0;
extern unsigned char TXData[17];
void TIM2_IRQHandler(void)
{
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);					//����жϱ�־
	Timer2Counter++;
// 	switch(GetKeyStatus())
// 	{
// 		case 1: Beep=5;break;
// 		case 2: Beep=6;break;
// 		case 3: Beep=3;break;
// 		case 4: Beep=4;break;
// 		default:break;
// 	}
	if(Timer2Counter==1)
	{
		Timer2Counter=0;
		TranFlag=1;
	}		
}
// /*******************************************************************************
// ���ƣ�void TIM3_IRQHandler(void)
// ���ܣ���ʱ��3���жϷ�����
// ��ڲ�������
// ���ڲ�������
// ˵������
// ***********************************************************************************
// void TIM3_IRQHandler(void)
// {
// 	TIM_ClearITPendingBit(TIM3, TIM_IT_Update);					//����жϱ�־
// 	LED1Reverse();
// }*/
// /*******************************************************************************
// ���ƣ�void TIM4_IRQHandler(void)
// ���ܣ���ʱ��4���жϷ�����
// ��ڲ�������
// ���ڲ�������
// ˵������
// ***********************************************************************************
// void TIM4_IRQHandler(void)
// {
// 	TIM_ClearITPendingBit(TIM4, TIM_IT_Update);					//����жϱ�־
// 	LED4Reverse();
// }*/
// /*******************************************************************************
// ���ƣ�void TIM5_IRQHandler(void)
// ���ܣ���ʱ��5���жϷ�����
// ��ڲ�������
// ���ڲ�������
// ˵������
// ***********************************************************************************
// void TIM5_IRQHandler(void)
// {
// 	TIM_ClearITPendingBit(TIM5, TIM_IT_Update);					//����жϱ�־
// 	LED4Reverse();
// }*/
// /*******************************************************************************
// ���ƣ�void TIM6_IRQHandler(void)
// ���ܣ���ʱ��6���жϷ�����
// ��ڲ�������
// ���ڲ�������
// ˵������
// ***********************************************************************************
// void TIM6_IRQHandler(void)
// {
// 	TIM_ClearITPendingBit(TIM6, TIM_IT_Update);					//����жϱ�־
// 	LED4Reverse();
// }*/
// /*******************************************************************************
// ���ƣ�void TIM7_IRQHandler(void)
// ���ܣ���ʱ��7���жϷ�����
// ��ڲ�������
// ���ڲ�������
// ˵������
// ***********************************************************************************/
// void TIM7_IRQHandler(void)
// {
// 	TIM_ClearITPendingBit(TIM7, TIM_IT_Update);					//����жϱ�־
// 	LED4Reverse();
// }*/
// /*******************************************************************************
// ���ƣ�void TIM8_IRQHandler(void)
// ���ܣ���ʱ��8���жϷ�����
// ��ڲ�������
// ���ڲ�������
// ˵������
// **********************************************************************************/
// void TIM8_UP_IRQHandler(void)
// {
// 	TIM_ClearITPendingBit(TIM8, TIM_IT_Update);					//����жϱ�־
// 	LED4Reverse();
// }*/
// /*******************************************************************************
// ���ƣ�void EXTI15_10_IRQHandler(void)
// ���ܣ��ⲿ�ж�10-15���жϷ�����
// ��ڲ�������
// ���ڲ�������
// ˵������
// ***********************************************************************************/
// void EXTI15_10_IRQHandler(void)
// {
// 	if(EXTI_GetFlagStatus(EXTI_Line11))
// 	{
// 		EXTI_ClearITPendingBit(EXTI_Line11);							//���EXTI11 ��־
// 		LED4Reverse();
// 	}
// }
// */


/*******************************************************************************
���ƣ�void USART1_IRQHandler(void)
���ܣ�����һ���жϷ�����
��ڲ�������
���ڲ�������
˵������
***********************************************************************************/

// unsigned char Usart1Data=0;
// unsigned char Usart1Status=0;
// unsigned char ShiWei=0;
// unsigned char GeWei=0;
// unsigned char ShiFenWei=0;
// float Temprature=0.0;
// void AdjustASCII(unsigned char ASCII_dat)
// {
// 	if((ASCII_dat<'0')||(ASCII_dat>0x7f))
// 		ASCII_dat='0';
// }

// void USART1_IRQHandler(void)
// {

// 	
// 	if(USART_GetITStatus(USART1,USART_IT_RXNE))			//�ж��ն���Դ�Ƿ�Ϊ�����ж�
// 	{
// 		USART_ClearITPendingBit(USART1,USART_IT_RXNE);//����жϱ�ʶλ
// 		Usart1Data=USART_ReceiveData(USART1);			//��ȡ����һ���յ�������
// 		//USART_SendData(USART1,Usart1Data);					//�����յ������ݷ���
// 		//while(USART_GetFlagStatus(USART1,USART_FLAG_TC) == RESET);//�ȴ����ݷ������
// 		switch(Usart1Status)
// 		{
// 			case 0:
// 				if(Usart1Data=='T')
// 				Usart1Status=1;
// 			break;
// 			case 1:
// 				AdjustASCII(Usart1Data);
// 				ShiWei=Usart1Data-'0';
// 				Usart1Status=2;
// 			break;
// 			case 2:
// 				AdjustASCII(Usart1Data);
// 				GeWei=Usart1Data-'0';
// 				Usart1Status=3;
// 			break;
// 			case 3:
// 				AdjustASCII(Usart1Data);
// 			if(Usart1Data=='.')
// 				Usart1Status=4;
// 			else
// 				Usart1Status=0;
// 			break;
// 			case 4:
// 				AdjustASCII(Usart1Data);
// 				ShiFenWei=Usart1Data-'0';
// 				Usart1Status=0;
// 			Temprature=ShiWei*10+GeWei+ShiFenWei*0.1;
// 			break;
// 			default:break;
// 		}
// 	}
// }






























































































































/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
