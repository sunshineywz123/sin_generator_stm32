//-----------------------------------------------------------------
// 程序描述: 
//		 结合FPGA完成正弦波形和各种调制波输出
// 作    者: 凌智电子
// 开始日期: 2014-02-17
// 完成日期: 2014-02-18
// 修改日期:
// 版    本: V1.0
//   - V1.0: MCU给FPGA发送频率控制字和调制波形选择
// 调试工具: 凌智STM32+FPGA电子系统设计开发板、LZE_ST LINK2
//						2.8寸液晶
// 说    明:
//    - 调试使用的系统时钟频率Fsysclk=72MHz；
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// 头文件包含
//-----------------------------------------------------------------
#include <stm32f10x.h>
#include "PeripheralInit.h"
#include "SPI.h"
#include "key_4_4.h"
#include "Delay.h"
#include "Wave.h"
#include "SPFD5408.h"
//-----------------------------------------------------------------
// 主程序
//-----------------------------------------------------------------

u32 Date[7];																// 存放个模块设置值

int main(void)
{
  u32 Num_date=0;
	u32 Key_num_2;
	
	PeripheralInit();													// 外设初始化							
	LCD_Print_Box (0, 0, 239, 2, RED);				// 画背景框
	LCD_Print_Box (0, 65, 239, 67, RED);
	LCD_Print_Box (0, 0, 2, 319, RED);
	LCD_Print_Box (237, 0, 239, 319, RED);
	LCD_Print_Box (0, 317, 239, 319, RED);
	SPFD5408_Fill (3, 3, 237, 66, GREEN);			// 青色
	LCD_HLine 	  (0, 254,239, RED);
	SPFD5408_Fill (3, 255, 237, 330, GREEN);	// 青色
	// 显示界面显示
	LCD_WriteChinese24x24string(36,21,BLACK,GREEN,"正弦信号发生器");
	LCD_WriteString(10,80,BLUE,WHITE,"波形模式:");
	LCD_WriteString(10,110,BLUE,WHITE,"波形频率:");
	LCD_WriteString(10,140,BLUE,WHITE,"载波频率:");
	LCD_WriteString(10,170,BLUE,WHITE,"载波序列:");
	LCD_WriteString(10,200,BLUE,WHITE,"最大频偏:");
	LCD_WriteString(10,230,BLUE,WHITE,"      MA:");
	LCD_WriteString(10,260,BLUE,GREEN,"按键提示:");
	LCD_WriteString(10,280,BLUE,GREEN,"1正弦波  2AM    3FM   4ASK");
	LCD_WriteString(10,300,BLUE,GREEN,"5PSK  +确认  *选择  -返回 ");
	while(1)
	{
		Key_num_2=KeyTransfer();								// 读按键值
		if(Key_num_2==14)												// 按下系统板的‘*’键
		{
			if(Num_mode<5)		
			{
				Num_mode=Num_mode+1;
			}
			else
			{
				Num_mode=0;													// 总共7个模式
			}
		    switch(Num_mode)				 						// 模式选择
			{
			case 0:	  	
					// 波形选择
			    LCD_WriteString(10,230,BLUE,WHITE,"      MA:");
					// 选中，字变红
					LCD_WriteString(10, 80,RED,WHITE,"波形模式:");	
					// 画提示箭头
					LCD_WriteString(220,80,RED,WHITE,"<=");	
					// 清除上次箭头
					LCD_WriteString(220,230,WHITE,WHITE,"<=");	   
					break;
			case 1:
				  // 波形频率
					LCD_WriteString(10, 80,BLUE,WHITE,"波形模式:");
					LCD_WriteString(10,110,RED,WHITE,"波形频率:");
					LCD_WriteString(220,110,RED,WHITE,"<=");
					LCD_WriteString(220,80,WHITE,WHITE,"<=");
					break;
			case 2:
					// 载波频率
					LCD_WriteString(10,110,BLUE,WHITE,"波形频率:");
					LCD_WriteString(10,140,RED,WHITE,"载波频率:");
					LCD_WriteString(220,140,RED,WHITE,"<=");
					LCD_WriteString(220,110,WHITE,WHITE,"<=");
					break;
			case 3:
					// 载波序列
					LCD_WriteString(10,140,BLUE,WHITE,"载波频率:");
					LCD_WriteString(10,170,RED,WHITE,"载波序列:");
					LCD_WriteString(220,170,RED,WHITE,"<=");
					LCD_WriteString(220,140,WHITE,WHITE,"<=");
					break;
			case 4:
					// 最大频偏
					LCD_WriteString(10,170,BLUE,WHITE,"载波序列:");	
					LCD_WriteString(10,200,RED,WHITE,"最大频偏:");
					LCD_WriteString(220,200,RED,WHITE,"<=");
					LCD_WriteString(220,170,WHITE,WHITE,"<=");
					break;
			case 5:
					// MA调制度
					LCD_WriteString(10,200,BLUE,WHITE,"最大频偏:");
					LCD_WriteString(10,230,RED,WHITE,"      MA:");
					LCD_WriteString(220,230,RED,WHITE,"<=");
					LCD_WriteString(220,200,WHITE,WHITE,"<=");
					break;
			default:break;
			}
		}
		else if(Key_num_2==12)									// 按下系统板的‘+’键
		{
			Num_date=Key_ldate();
		}
    if(Num_date!=0x00)											//确实有按键按下
		{			
			switch(Num_mode)
			{
			  case  0:											  		//波形模式
			  	   		Date[4] = Num_date;						   
			    		switch(Num_date)
			  			{
			   				case  1:  LCD_WriteString(110,80,BLUE,WHITE,"正弦波");break;
								case  2:  LCD_WriteString(110,80,BLUE,WHITE,"  AM  ");break;
			   				case  3:  LCD_WriteString(110,80,BLUE,WHITE,"  FM  ");break;
								case  4:  LCD_WriteString(110,80,BLUE,WHITE,"  ASK ");break;
								case  5:  LCD_WriteString(110,80,BLUE,WHITE,"  PSK ");break;
								default:  break;
			   			}
			    		Num_date=0;	break;
			  case  1:														// 波形频率
			  			Date[3] = Num_date;
							LCD_WriteNumLong(100,110,BLUE,WHITE,Num_date);
							LCD_WriteString(188,110,BLUE,WHITE,"Hz");
							Num_date=0;break;
			  case  2:														// 载波频率
			  			Date[0] = Num_date;
			   			LCD_WriteNumLong(100,140,BLUE,WHITE,Num_date);
			   			LCD_WriteString(188,140,BLUE,WHITE,"Hz");
			   			Num_date=0;break;
			  case  3:														// 载波序列
			  			Date[1]=Num_date;
			   			LCD_WriteNumLong(100,170,BLUE,WHITE,Num_date);	
			   			Num_date=0;break;
			  case  4:												 		// 最大频偏
			  			Date[6]=Num_date;
			   			LCD_WriteNumLong(100,200,BLUE,WHITE,Num_date);
			   			Num_date=0;break;
			  case  5:											   		//	MA值
			  			Date[5]=Num_date;
			   			LCD_WriteNumLong(100,230,BLUE,WHITE,Num_date);
			   			Num_date=0;break;
			  default:  break;	
			}		
			 SPI2_Send_Cmd_Data(1+128,Date[0]);    // 发送到FPGA
			 SPI2_Send_Cmd_Data(3+128,Date[1]);
			 SPI2_Send_Cmd_Data(8+128,Date[2]);
			 SPI2_Send_Cmd_Data(5+128,Date[3]*26.88);
			 SPI2_Send_Cmd_Data(4+128,Date[4]-1); 
			 SPI2_Send_Cmd_Data(2+128,Date[5]);
			 SPI2_Send_Cmd_Data(0+128,Date[6]);
		}
// 		else 
// 		{
// 		switch(Num_mode)										//当值没有改变时再重写一遍
// 			{
// 			  case  0:											  //波形模式						   
// 			    		switch(Date5)
// 			  			{
// 			   				case  1:  LCD_WriteString(110,80,BLUE,WHITE,"正弦波");break;
// 							case  2:  LCD_WriteString(110,80,BLUE,WHITE,"  AM  ");break;
// 			   				case  3:  LCD_WriteString(110,80,BLUE,WHITE,"  FM  ");break;
// 							case  4:  LCD_WriteString(110,80,BLUE,WHITE,"  ASK ");break;
// 							case  5:  LCD_WriteString(110,80,BLUE,WHITE,"  PSK ");break;
// 							default:  break;
// 			   			}
// 			  case  1:												//波形频率
// // 						LCD_WriteNumLong(158,110,BLUE,WHITE,Date4);
// 						Num_date=0;break;
// 			  case  2:												//载波频率
// // 			   			LCD_WriteNumLong(158,140,BLUE,WHITE,Date1);
// 			   			Num_date=0;break;
// 			  case  3:												//载波序列
// // 			   			LCD_WriteNumLong(158,170,BLUE,WHITE,Date2);	
// 			   			Num_date=0;break;
// 			  case  4:												 //最大频偏
// // 			   			LCD_WriteNumLong(158,200,BLUE,WHITE,Date7);
// 			   			Num_date=0;break;
// 			  case  5:											   //MA值
// // 			   			LCD_WriteNumLong(158,230,BLUE,WHITE,Date6);
// 			   			Num_date=0;break;
// 			  default:  break;	
// 			}
// 		}	 
	}	
}

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
