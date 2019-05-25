//-----------------------------------------------------------------
//  MUC��FPGA֮��SPIͨ��Э��ͷ�ļ�
// ͷ�ļ���: SPI_FPGA.h
// ��    ��: ���ǵ���
// ��д����: 2014-02-15
// �޸�����: 2014-02-17
//-----------------------------------------------------------------

#ifndef _SPI_FPGA_H
#define _SPI_FPGA_H

//-----------------------------------------------------------------
// �궨��
//-----------------------------------------------------------------
#define		SPI_DATA_WIDTH  32									// ���巢�����ݵĿ��
#define		SPI_CMD_WIDTH   8   								// ��ַλ���

//-----------------------------------------------------------------
// I/O�ڶ���:�˿�/����/ʱ��
//-----------------------------------------------------------------

// ������:��Ƭ������,FPGA���(spi_sdo)
#define SPI_FPGA_MISO 		(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)) 

// ʱ����,FPGA(spi_scl)
#define SPI_FPGA_SCL_Set 	(GPIO_SetBits(GPIOB,GPIO_Pin_12))   				
#define SPI_FPGA_SCL_Clr	(GPIO_ResetBits(GPIOB,GPIO_Pin_12))

// Ƭѡ����,FPGA(spi_cs_cmd)
#define CS_CMD_Set 				(GPIO_SetBits(GPIOB,GPIO_Pin_13))    	 			
#define CS_CMD_Clr 				(GPIO_ResetBits(GPIOB,GPIO_Pin_13))

// Ƭѡ����cs_data
#define CS_DATA_Set 			(GPIO_SetBits(GPIOB,GPIO_Pin_14)) 		 			
#define CS_DATA_Clr 			(GPIO_ResetBits(GPIOB,GPIO_Pin_14))

// ������:��Ƭ�����,FPGA����(spi_sdi)
#define SPI_FPGA_MOSI_Set (GPIO_SetBits(GPIOB,GPIO_Pin_15))  					
#define SPI_FPGA_MOSI_Clr (GPIO_ResetBits(GPIOB,GPIO_Pin_15))

//-----------------------------------------------------------------
// ��������
//-----------------------------------------------------------------
extern void SPI_FPGA_Init(void);						
void GPIO_SPI_FPGA_Configuration(void);
void spi_send_cmd(u8 send_data);
void spi_send_data(u32 send_data);
u32	spi_rece_data(void);
extern void spi_send_cmd_data(u8 cmd,u32 send_data);  
extern u32	spi_rece_cmd_data(u8 cmd);

#endif

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
