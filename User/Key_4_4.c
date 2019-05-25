//-----------------------------------------------------------------
// ��������:
//     4*4�������, ��תɨ�跨
// ��    ��: ���ǵ���
// ��ʼ����: 2014-01-30
// �������: 2014-02-1
// �޸�����: 2014-04-1
// ��ǰ�汾: V1.0.2
// ��ʷ�汾:
//    -V1.0: (2014-02-1)4x4����ɨ�裬��ִ�м�ֵת��
//	-V1.0.1: (2014-02-16)ͷ�ļ��в���������ͷ�ļ�
//  -V1.0.2: (2014-04-01)����Ӳ���޸�,��Ӧ����
// ���Թ���: ����STM32+FPGA����ϵͳ��ƿ����塢1602Һ������LZE_ST_LINK2
// ˵    ��:
//
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// ͷ�ļ�����
//-----------------------------------------------------------------
#include <stm32f10x.h>
#include "Delay.h"
#include "key_4_4.h"

//-----------------------------------------------------------------
// ȫ�ֱ�������
//-----------------------------------------------------------------
u8 IOToggle = 0x00 ;												// IO�������״̬�л�����

//-----------------------------------------------------------------
// void GPIO_Keyboard_Configuration(void)
//-----------------------------------------------------------------
//
// ��������: ����IO������
// ��ڲ���: ��
// ���ز���: �� 
// ȫ�ֱ���: ��
// ����ģ��: ��
// ע������: ע��IO״̬�л�
// ���̼�IO�ڷ���:
//							PE3 PE2 PE1 	PE0
// 			PC13		-1-	-2-	-3-		-+-
// 			PE6			-4-	-5-	-6-		---
// 			PE5			-7-	-8-	-9-		-*-
//			PE4		-Brk-	-0-	-ok-	-/-			
//-----------------------------------------------------------------
void GPIO_Keyboard_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	// ��PE,PC��ʱ��
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC |
													RCC_APB2Periph_GPIOE ,ENABLE);
	// ����PE4-PE6,PC13Ϊ������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 |
																GPIO_Pin_6 ;	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	if(!IOToggle)
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 			 
	else
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 			 
	GPIO_Init(GPIOE, &GPIO_InitStructure);		
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	if(!IOToggle)
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 			 
	else
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 			 
	GPIO_Init(GPIOC, &GPIO_InitStructure);		
	// ����PE0-PE3Ϊ�����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1|
																GPIO_Pin_2 | GPIO_Pin_3;	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 	
	if(!IOToggle)// �������
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	else
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 			 
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

//-----------------------------------------------------------------
// unsigned char Key_scan (void)
//-----------------------------------------------------------------
//
// ��������: ����ɨ��
// ��ڲ���: ��
// ���ز���: ��⵽������ 
// ȫ�ֱ���: ��
// ����ģ��: 
// ע������: �޼����·���0xff
// ���̼�IO�ڷ���:			
//							PE4 PE5 PE6 	PC13
// 			PE0		  -1-	-2-	-3-		-+-
// 			PE1			-4-	-5-	-6-		---
// 			PE2			-7-	-8-	-9-		-*-
//			PE3		-Brk-	-0-	-ok-	-/-
//			
//-----------------------------------------------------------------
u8 Key_scan (void)
{
	u8 Date_h=0;
	u8 Date_l=0;
	u16 State=0;
	u8 BitState=0;

	State = GPIO_ReadInputData(GPIOE);				// ��ȡPE״̬
	BitState = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);
	// ��PE0-PE3����,��PE4-PE6����			
	GPIO_Write(GPIOE,(State & 0xfff0 )| 0x0070);
	GPIO_Write(GPIOC,BitState | 0X2000);			// ��PC13����
	Delay_1ms(2);	
	
	State = GPIO_ReadInputData(GPIOE);				// ��ȡPE4-PE6״̬
	// ��ȡPC13״̬
	BitState = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);
	State &= 0x0070;
	// ��ֵ��ȫ��Ϊ0
	if((State!=0x0070)||(BitState != 0x01))		// �м�����
	{
		Delay_5ms (4);	 												// ��ʱ20mS����
		State = GPIO_ReadInputData(GPIOE);			// ��ȡPE4-PE6״̬
		// ��ȡPC13״̬
		BitState = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);
		State &= 0x0070;
		if((State!=0x0070)||(BitState != 0x01))	// ȷʵ�м�����
		{
			if(BitState)													// ����PC13����
			{
				State = GPIO_ReadInputData(GPIOE);	// ��ȡPE4-PE6״̬
				State &= 0x0070;										// ������
				Date_h = State;
				GPIO_Write(GPIOE,Date_h|0x000f);
			}
			else
			{	// ��PC13����,��ʱPE4-PE6��Ϊ1,��Date_h=0x70
				Date_h = 0x70;											
				GPIO_ResetBits(GPIOC,GPIO_Pin_13);	// ��PC13����
				GPIO_Write(GPIOE,0X000F);						// ��PE0-PE3����
			}
			IOToggle = 1;					
			// PE0-PE3������ĳ����룬PE4-PE6������ĳ����
			GPIO_Keyboard_Configuration();
			State = GPIO_ReadInputData(GPIOE);		// ��ȡPE4-PE6״̬
			Date_l = State&0x000f;
			while((State &0x000f)!=0x000f)				// �ȴ������ͷ�
				State = GPIO_ReadInputData(GPIOE);	// ��ȡPE4-PE6״̬
			IOToggle = 0;													// IO����ԭ��״̬
			GPIO_Keyboard_Configuration();
			return (Date_h+Date_l);								// ��������ɨ��ֵ	
		}
		else
			return 0xff;
	}
	else
			return 0xff;
}	

//-----------------------------------------------------------------
// u8	KeyTransfer (void)
//-----------------------------------------------------------------
// ��������: ������ֵ����
// ��ڲ���: ��
// ���ز���: ������������� 
// ȫ�ֱ���: ��
// ע�����
//	���̱��벼�֣�
//		 	1					2				3 				12(+)
//			4					5				6					13(-)
//			7					8				9					14(*)
//			10(ȡ��)	0				11(ȷ��)	15(/)
//
//--------------------------------------------------------------
u8	KeyTransfer (void)
{
  switch (Key_scan ())
  {
	  // ������Ӧ�ļ���ʾ���Ӧ����ֵ
	  case 0x77 :	return 15;	break;					// /
	  case 0x7b	:	return 14;	break;					// *
	  case 0x7d	:	return 13;	break;					// -
	  case 0x7e	:	return 12;	break;					// +
	  case 0x37	:	return 11;	break;					// OK
	  case 0x3b	:	return 9;		break;					// 9
	  case 0x3d	:	return 6;		break;					// 6
	  case 0x3e	:	return 3;		break;					// 3
	  case 0x57	:	return 0;		break;					// 0
	  case 0x5b	:	return 8;		break;					// 8
	  case 0x5d	:	return 5;		break;					// 5
	  case 0x5e	:	return 2;		break;					// 2
	  case 0x67	:	return 10;	break;					// ȡ��
	  case 0x6b	:	return 7;		break;					// 7
	  case 0x6d	:	return 4;		break;					// ȷ��
	  case 0x6e	:	return 1;		break;					// 1
	  default	  : return 0xff;	
  }
}

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
