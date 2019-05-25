//-----------------------------------------------------------------
// 程序描述:
//     4*4矩阵键盘, 反转扫描法
// 作    者: 凌智电子
// 开始日期: 2014-01-30
// 完成日期: 2014-02-1
// 修改日期: 2014-04-1
// 当前版本: V1.0.2
// 历史版本:
//    -V1.0: (2014-02-1)4x4键盘扫描，并执行键值转换
//	-V1.0.1: (2014-02-16)头文件中不包含其他头文件
//  -V1.0.2: (2014-04-01)键盘硬件修改,相应程序
// 调试工具: 凌智STM32+FPGA电子系统设计开发板、1602液晶屏、LZE_ST_LINK2
// 说    明:
//
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// 头文件包含
//-----------------------------------------------------------------
#include <stm32f10x.h>
#include "Delay.h"
#include "key_4_4.h"

//-----------------------------------------------------------------
// 全局变量定义
//-----------------------------------------------------------------
u8 IOToggle = 0x00 ;												// IO输入输出状态切换变量

//-----------------------------------------------------------------
// void GPIO_Keyboard_Configuration(void)
//-----------------------------------------------------------------
//
// 函数功能: 按键IO口配置
// 入口参数: 无
// 返回参数: 无 
// 全局变量: 无
// 调用模块: 无
// 注意事项: 注意IO状态切换
// 键盘及IO口分配:
//							PE3 PE2 PE1 	PE0
// 			PC13		-1-	-2-	-3-		-+-
// 			PE6			-4-	-5-	-6-		---
// 			PE5			-7-	-8-	-9-		-*-
//			PE4		-Brk-	-0-	-ok-	-/-			
//-----------------------------------------------------------------
void GPIO_Keyboard_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	// 打开PE,PC口时钟
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC |
													RCC_APB2Periph_GPIOE ,ENABLE);
	// 配置PE4-PE6,PC13为列输入
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
	// 配置PE0-PE3为行输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1|
																GPIO_Pin_2 | GPIO_Pin_3;	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 	
	if(!IOToggle)// 推挽输出
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	else
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 			 
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

//-----------------------------------------------------------------
// unsigned char Key_scan (void)
//-----------------------------------------------------------------
//
// 函数功能: 按键扫描
// 入口参数: 无
// 返回参数: 检测到的数据 
// 全局变量: 无
// 调用模块: 
// 注意事项: 无键按下返回0xff
// 键盘及IO口分配:			
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

	State = GPIO_ReadInputData(GPIOE);				// 读取PE状态
	BitState = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);
	// 把PE0-PE3清零,把PE4-PE6拉高			
	GPIO_Write(GPIOE,(State & 0xfff0 )| 0x0070);
	GPIO_Write(GPIOC,BitState | 0X2000);			// 把PC13拉高
	Delay_1ms(2);	
	
	State = GPIO_ReadInputData(GPIOE);				// 读取PE4-PE6状态
	// 读取PC13状态
	BitState = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);
	State &= 0x0070;
	// 列值不全部为0
	if((State!=0x0070)||(BitState != 0x01))		// 有键按下
	{
		Delay_5ms (4);	 												// 延时20mS消抖
		State = GPIO_ReadInputData(GPIOE);			// 读取PE4-PE6状态
		// 读取PC13状态
		BitState = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);
		State &= 0x0070;
		if((State!=0x0070)||(BitState != 0x01))	// 确实有键按下
		{
			if(BitState)													// 不是PC13按下
			{
				State = GPIO_ReadInputData(GPIOE);	// 读取PE4-PE6状态
				State &= 0x0070;										// 开放行
				Date_h = State;
				GPIO_Write(GPIOE,Date_h|0x000f);
			}
			else
			{	// 是PC13按下,此时PE4-PE6都为1,故Date_h=0x70
				Date_h = 0x70;											
				GPIO_ResetBits(GPIOC,GPIO_Pin_13);	// 把PC13拉低
				GPIO_Write(GPIOE,0X000F);						// 把PE0-PE3拉高
			}
			IOToggle = 1;					
			// PE0-PE3由输出改成输入，PE4-PE6由输入改成输出
			GPIO_Keyboard_Configuration();
			State = GPIO_ReadInputData(GPIOE);		// 读取PE4-PE6状态
			Date_l = State&0x000f;
			while((State &0x000f)!=0x000f)				// 等待按键释放
				State = GPIO_ReadInputData(GPIOE);	// 读取PE4-PE6状态
			IOToggle = 0;													// IO返回原来状态
			GPIO_Keyboard_Configuration();
			return (Date_h+Date_l);								// 返回两次扫描值	
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
// 函数功能: 按键数值处理
// 入口参数: 无
// 返回参数: 按键处理的数据 
// 全局变量: 无
// 注意事项：
//	键盘编码布局：
//		 	1					2				3 				12(+)
//			4					5				6					13(-)
//			7					8				9					14(*)
//			10(取消)	0				11(确认)	15(/)
//
//--------------------------------------------------------------
u8	KeyTransfer (void)
{
  switch (Key_scan ())
  {
	  // 按下相应的键显示相对应的码值
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
	  case 0x67	:	return 10;	break;					// 取消
	  case 0x6b	:	return 7;		break;					// 7
	  case 0x6d	:	return 4;		break;					// 确认
	  case 0x6e	:	return 1;		break;					// 1
	  default	  : return 0xff;	
  }
}

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
