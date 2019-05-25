//-----------------------------------------------------------------
//  MUC与FPGA之间SPI通信协议头文件
// 头文件名: SPI_FPGA.h
// 作    者: 凌智电子
// 编写日期: 2014-02-15
// 修改日期: 2014-02-17
//-----------------------------------------------------------------

#ifndef _SPI_FPGA_H
#define _SPI_FPGA_H

//-----------------------------------------------------------------
// 宏定义
//-----------------------------------------------------------------
#define		SPI_DATA_WIDTH  32									// 定义发送数据的宽度
#define		SPI_CMD_WIDTH   8   								// 地址位宽度

//-----------------------------------------------------------------
// I/O口定义:端口/引脚/时钟
//-----------------------------------------------------------------

// 数据线:单片机输入,FPGA输出(spi_sdo)
#define SPI_FPGA_MISO 		(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)) 

// 时钟线,FPGA(spi_scl)
#define SPI_FPGA_SCL_Set 	(GPIO_SetBits(GPIOB,GPIO_Pin_12))   				
#define SPI_FPGA_SCL_Clr	(GPIO_ResetBits(GPIOB,GPIO_Pin_12))

// 片选命令,FPGA(spi_cs_cmd)
#define CS_CMD_Set 				(GPIO_SetBits(GPIOB,GPIO_Pin_13))    	 			
#define CS_CMD_Clr 				(GPIO_ResetBits(GPIOB,GPIO_Pin_13))

// 片选数据cs_data
#define CS_DATA_Set 			(GPIO_SetBits(GPIOB,GPIO_Pin_14)) 		 			
#define CS_DATA_Clr 			(GPIO_ResetBits(GPIOB,GPIO_Pin_14))

// 数据线:单片机输出,FPGA输入(spi_sdi)
#define SPI_FPGA_MOSI_Set (GPIO_SetBits(GPIOB,GPIO_Pin_15))  					
#define SPI_FPGA_MOSI_Clr (GPIO_ResetBits(GPIOB,GPIO_Pin_15))

//-----------------------------------------------------------------
// 函数声明
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
