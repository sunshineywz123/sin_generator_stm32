//-----------------------------------------------------------------
// ��������: 
//		 ���FPGA������Ҳ��κ͸��ֵ��Ʋ����
// ��    ��: ���ǵ���
// ��ʼ����: 2014-02-17
// �������: 2014-02-18
// �޸�����:
// ��    ��: V1.0
//   - V1.0: MCU��FPGA����Ƶ�ʿ����ֺ͵��Ʋ���ѡ��
// ���Թ���: ����STM32+FPGA����ϵͳ��ƿ����塢LZE_ST LINK2
//						2.8��Һ��
// ˵    ��:
//    - ����ʹ�õ�ϵͳʱ��Ƶ��Fsysclk=72MHz��
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// ͷ�ļ�����
//-----------------------------------------------------------------
#include <stm32f10x.h>
#include "PeripheralInit.h"
#include "SPI.h"
#include "key_4_4.h"
#include "Delay.h"
#include "Wave.h"
#include "SPFD5408.h"
//-----------------------------------------------------------------
// ������
//-----------------------------------------------------------------

u32 Date[7];																// ��Ÿ�ģ������ֵ

int main(void)
{
  u32 Num_date=0;
	u32 Key_num_2;
	
	PeripheralInit();													// �����ʼ��							
	LCD_Print_Box (0, 0, 239, 2, RED);				// ��������
	LCD_Print_Box (0, 65, 239, 67, RED);
	LCD_Print_Box (0, 0, 2, 319, RED);
	LCD_Print_Box (237, 0, 239, 319, RED);
	LCD_Print_Box (0, 317, 239, 319, RED);
	SPFD5408_Fill (3, 3, 237, 66, GREEN);			// ��ɫ
	LCD_HLine 	  (0, 254,239, RED);
	SPFD5408_Fill (3, 255, 237, 330, GREEN);	// ��ɫ
	// ��ʾ������ʾ
	LCD_WriteChinese24x24string(36,21,BLACK,GREEN,"�����źŷ�����");
	LCD_WriteString(10,80,BLUE,WHITE,"����ģʽ:");
	LCD_WriteString(10,110,BLUE,WHITE,"����Ƶ��:");
	LCD_WriteString(10,140,BLUE,WHITE,"�ز�Ƶ��:");
	LCD_WriteString(10,170,BLUE,WHITE,"�ز�����:");
	LCD_WriteString(10,200,BLUE,WHITE,"���Ƶƫ:");
	LCD_WriteString(10,230,BLUE,WHITE,"      MA:");
	LCD_WriteString(10,260,BLUE,GREEN,"������ʾ:");
	LCD_WriteString(10,280,BLUE,GREEN,"1���Ҳ�  2AM    3FM   4ASK");
	LCD_WriteString(10,300,BLUE,GREEN,"5PSK  +ȷ��  *ѡ��  -���� ");
	while(1)
	{
		Key_num_2=KeyTransfer();								// ������ֵ
		if(Key_num_2==14)												// ����ϵͳ��ġ�*����
		{
			if(Num_mode<5)		
			{
				Num_mode=Num_mode+1;
			}
			else
			{
				Num_mode=0;													// �ܹ�7��ģʽ
			}
		    switch(Num_mode)				 						// ģʽѡ��
			{
			case 0:	  	
					// ����ѡ��
			    LCD_WriteString(10,230,BLUE,WHITE,"      MA:");
					// ѡ�У��ֱ��
					LCD_WriteString(10, 80,RED,WHITE,"����ģʽ:");	
					// ����ʾ��ͷ
					LCD_WriteString(220,80,RED,WHITE,"<=");	
					// ����ϴμ�ͷ
					LCD_WriteString(220,230,WHITE,WHITE,"<=");	   
					break;
			case 1:
				  // ����Ƶ��
					LCD_WriteString(10, 80,BLUE,WHITE,"����ģʽ:");
					LCD_WriteString(10,110,RED,WHITE,"����Ƶ��:");
					LCD_WriteString(220,110,RED,WHITE,"<=");
					LCD_WriteString(220,80,WHITE,WHITE,"<=");
					break;
			case 2:
					// �ز�Ƶ��
					LCD_WriteString(10,110,BLUE,WHITE,"����Ƶ��:");
					LCD_WriteString(10,140,RED,WHITE,"�ز�Ƶ��:");
					LCD_WriteString(220,140,RED,WHITE,"<=");
					LCD_WriteString(220,110,WHITE,WHITE,"<=");
					break;
			case 3:
					// �ز�����
					LCD_WriteString(10,140,BLUE,WHITE,"�ز�Ƶ��:");
					LCD_WriteString(10,170,RED,WHITE,"�ز�����:");
					LCD_WriteString(220,170,RED,WHITE,"<=");
					LCD_WriteString(220,140,WHITE,WHITE,"<=");
					break;
			case 4:
					// ���Ƶƫ
					LCD_WriteString(10,170,BLUE,WHITE,"�ز�����:");	
					LCD_WriteString(10,200,RED,WHITE,"���Ƶƫ:");
					LCD_WriteString(220,200,RED,WHITE,"<=");
					LCD_WriteString(220,170,WHITE,WHITE,"<=");
					break;
			case 5:
					// MA���ƶ�
					LCD_WriteString(10,200,BLUE,WHITE,"���Ƶƫ:");
					LCD_WriteString(10,230,RED,WHITE,"      MA:");
					LCD_WriteString(220,230,RED,WHITE,"<=");
					LCD_WriteString(220,200,WHITE,WHITE,"<=");
					break;
			default:break;
			}
		}
		else if(Key_num_2==12)									// ����ϵͳ��ġ�+����
		{
			Num_date=Key_ldate();
		}
    if(Num_date!=0x00)											//ȷʵ�а�������
		{			
			switch(Num_mode)
			{
			  case  0:											  		//����ģʽ
			  	   		Date[4] = Num_date;						   
			    		switch(Num_date)
			  			{
			   				case  1:  LCD_WriteString(110,80,BLUE,WHITE,"���Ҳ�");break;
								case  2:  LCD_WriteString(110,80,BLUE,WHITE,"  AM  ");break;
			   				case  3:  LCD_WriteString(110,80,BLUE,WHITE,"  FM  ");break;
								case  4:  LCD_WriteString(110,80,BLUE,WHITE,"  ASK ");break;
								case  5:  LCD_WriteString(110,80,BLUE,WHITE,"  PSK ");break;
								default:  break;
			   			}
			    		Num_date=0;	break;
			  case  1:														// ����Ƶ��
			  			Date[3] = Num_date;
							LCD_WriteNumLong(100,110,BLUE,WHITE,Num_date);
							LCD_WriteString(188,110,BLUE,WHITE,"Hz");
							Num_date=0;break;
			  case  2:														// �ز�Ƶ��
			  			Date[0] = Num_date;
			   			LCD_WriteNumLong(100,140,BLUE,WHITE,Num_date);
			   			LCD_WriteString(188,140,BLUE,WHITE,"Hz");
			   			Num_date=0;break;
			  case  3:														// �ز�����
			  			Date[1]=Num_date;
			   			LCD_WriteNumLong(100,170,BLUE,WHITE,Num_date);	
			   			Num_date=0;break;
			  case  4:												 		// ���Ƶƫ
			  			Date[6]=Num_date;
			   			LCD_WriteNumLong(100,200,BLUE,WHITE,Num_date);
			   			Num_date=0;break;
			  case  5:											   		//	MAֵ
			  			Date[5]=Num_date;
			   			LCD_WriteNumLong(100,230,BLUE,WHITE,Num_date);
			   			Num_date=0;break;
			  default:  break;	
			}		
			 SPI2_Send_Cmd_Data(1+128,Date[0]);    // ���͵�FPGA
			 SPI2_Send_Cmd_Data(3+128,Date[1]);
			 SPI2_Send_Cmd_Data(8+128,Date[2]);
			 SPI2_Send_Cmd_Data(5+128,Date[3]*26.88);
			 SPI2_Send_Cmd_Data(4+128,Date[4]-1); 
			 SPI2_Send_Cmd_Data(2+128,Date[5]);
			 SPI2_Send_Cmd_Data(0+128,Date[6]);
		}
// 		else 
// 		{
// 		switch(Num_mode)										//��ֵû�иı�ʱ����дһ��
// 			{
// 			  case  0:											  //����ģʽ						   
// 			    		switch(Date5)
// 			  			{
// 			   				case  1:  LCD_WriteString(110,80,BLUE,WHITE,"���Ҳ�");break;
// 							case  2:  LCD_WriteString(110,80,BLUE,WHITE,"  AM  ");break;
// 			   				case  3:  LCD_WriteString(110,80,BLUE,WHITE,"  FM  ");break;
// 							case  4:  LCD_WriteString(110,80,BLUE,WHITE,"  ASK ");break;
// 							case  5:  LCD_WriteString(110,80,BLUE,WHITE,"  PSK ");break;
// 							default:  break;
// 			   			}
// 			  case  1:												//����Ƶ��
// // 						LCD_WriteNumLong(158,110,BLUE,WHITE,Date4);
// 						Num_date=0;break;
// 			  case  2:												//�ز�Ƶ��
// // 			   			LCD_WriteNumLong(158,140,BLUE,WHITE,Date1);
// 			   			Num_date=0;break;
// 			  case  3:												//�ز�����
// // 			   			LCD_WriteNumLong(158,170,BLUE,WHITE,Date2);	
// 			   			Num_date=0;break;
// 			  case  4:												 //���Ƶƫ
// // 			   			LCD_WriteNumLong(158,200,BLUE,WHITE,Date7);
// 			   			Num_date=0;break;
// 			  case  5:											   //MAֵ
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
