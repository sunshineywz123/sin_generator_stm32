// 
///*预定义汉字点阵数据文件*/
//
///*------------------------------------------------------------------------------
// ------------------  汉字字模的数据结构定义 ------------------------ //
struct  typFNT_GB16                        // 汉字字模数据结构 
{
    unsigned char  Index[2];               // 汉字内码索引	
    unsigned char   Msk[32];               // 点阵码数据 
};

/////////////////////////////////////////////////////////////////////////
// 汉字字模表                                                          //
// 取模软件：   纵向取模 -> PCtoLCD2002完美版：逐行式						  //
/////////////////////////////////////////////////////////////////////////
struct  typFNT_GB16 codeGB_16[100] =          // 数据表 
{

"校", 0x10, 0x40, 0x10, 0x20, 0x10, 0x20, 0x11, 0xFE, 0xFC, 0x00, 0x10, 0x88, 0x31, 0x04, 0x3A, 0x02,
0x54, 0x88, 0x50, 0x88, 0x90, 0x50, 0x10, 0x50, 0x10, 0x20, 0x10, 0x50, 0x10, 0x88, 0x13, 0x06,/*"校",0*/

"准", 0x01, 0x40, 0x41, 0x20, 0x21, 0x20, 0x23, 0xFE, 0x02, 0x20, 0x16, 0x20, 0x1B, 0xFC, 0x12, 0x20,
0x22, 0x20, 0x23, 0xFC, 0xE2, 0x20, 0x22, 0x20, 0x22, 0x20, 0x23, 0xFE, 0x22, 0x00, 0x02, 0x00,/*"准",1*/

"幅", 0x10, 0x00, 0x11, 0xFE, 0x10, 0x00, 0x7C, 0xF8, 0x54, 0x88, 0x54, 0x88, 0x54, 0xF8, 0x54, 0x00,
0x55, 0xFC, 0x55, 0x24, 0x55, 0x24, 0x5D, 0xFC, 0x11, 0x24, 0x11, 0x24, 0x11, 0xFC, 0x11, 0x04,/*"幅",0*/

"值", 0x08, 0x40, 0x08, 0x40, 0x0F, 0xFC, 0x10, 0x40, 0x10, 0x40, 0x33, 0xF8, 0x32, 0x08, 0x53, 0xF8,
0x92, 0x08, 0x13, 0xF8, 0x12, 0x08, 0x13, 0xF8, 0x12, 0x08, 0x12, 0x08, 0x1F, 0xFE, 0x10, 0x00,/*"值",1*/

"占", 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0xFE, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
0x3F, 0xF8, 0x20, 0x08, 0x20, 0x08, 0x20, 0x08, 0x20, 0x08, 0x20, 0x08, 0x3F, 0xF8, 0x20, 0x08,/*"占",2*/

"空", 0x02, 0x00, 0x01, 0x00, 0x7F, 0xFE, 0x40, 0x02, 0x88, 0x24, 0x10, 0x10, 0x20, 0x08, 0x00, 0x00,
0x1F, 0xF0, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x7F, 0xFC, 0x00, 0x00,/*"空",3*/

"比", 0x00, 0x80, 0x20, 0x80, 0x20, 0x80, 0x20, 0x84, 0x20, 0x88, 0x20, 0x90, 0x3E, 0xA0, 0x20, 0xC0,
0x20, 0x80, 0x20, 0x80, 0x20, 0x80, 0x20, 0x82, 0x26, 0x82, 0x38, 0x82, 0x20, 0x7E, 0x00, 0x00,/*"比",4*/

"频", 0x10, 0x00, 0x11, 0xFE, 0x50, 0x20, 0x5C, 0x40, 0x51, 0xFC, 0x51, 0x04, 0xFF, 0x24, 0x01, 0x24,
0x11, 0x24, 0x55, 0x24, 0x55, 0x24, 0x55, 0x44, 0x84, 0x50, 0x08, 0x88, 0x31, 0x04, 0xC2, 0x02,/*"频",5*/

"率", 0x02, 0x00, 0x01, 0x00, 0x7F, 0xFC, 0x02, 0x00, 0x44, 0x44, 0x2F, 0x88, 0x11, 0x10, 0x22, 0x48,
0x4F, 0xE4, 0x00, 0x20, 0x01, 0x00, 0xFF, 0xFE, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,/*"率",6*/

"凌", 0x00, 0x40, 0x40, 0x40, 0x23, 0xF8, 0x20, 0x40, 0x00, 0x40, 0x07, 0xFE, 0x11, 0x10, 0x12, 0x88,
0x24, 0x84, 0xE1, 0xF0, 0x23, 0x10, 0x24, 0xA0, 0x20, 0x40, 0x20, 0xA0, 0x23, 0x10, 0x0C, 0x0C,/*"凌",0*/

"智", 0x20, 0x00, 0x3E, 0x7C, 0x48, 0x44, 0x08, 0x44, 0xFF, 0x44, 0x14, 0x44, 0x22, 0x7C, 0x40, 0x00,
0x1F, 0xF0, 0x10, 0x10, 0x10, 0x10, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x10, 0x1F, 0xF0, 0x10, 0x10,/*"智",1*/

"电", 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x3F, 0xF8, 0x21, 0x08, 0x21, 0x08, 0x21, 0x08, 0x3F, 0xF8,
0x21, 0x08, 0x21, 0x08, 0x21, 0x08, 0x3F, 0xF8, 0x21, 0x0A, 0x01, 0x02, 0x01, 0x02, 0x00, 0xFE,/*"电",2*/

"子", 0x00, 0x00, 0x7F, 0xF8, 0x00, 0x10, 0x00, 0x20, 0x00, 0x40, 0x01, 0x80, 0x01, 0x00, 0xFF, 0xFE,
0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x05, 0x00, 0x02, 0x00,/*"子",3*/

"载",0x08, 0x20, 0x08, 0x28, 0x7F, 0x24, 0x08, 0x20, 0xFF, 0xFE, 0x10, 0x20, 0x10, 0x24, 0xFF, 0x24, 0x20, 
0x24, 0x48, 0x28, 0x7F, 0x28, 0x08, 0x10, 0x0F, 0x12, 0xF8, 0x2A, 0x08, 0x46, 0x08, 0x82,/*"?",0*/

"波",0x00, 0x20, 0x20, 0x20, 0x10, 0x20, 0x13, 0xFE, 0x82, 0x22, 0x42, 0x24, 0x4A, 0x20, 0x0B, 0xFC, 0x12,
0x84, 0x12, 0x88, 0xE2, 0x48, 0x22, 0x50, 0x22, 0x20, 0x24, 0x50, 0x24, 0x88, 0x09, 0x06,/*"?",1*/

"序",0x01, 0x00, 0x00, 0x80, 0x3F, 0xFE, 0x20, 0x00, 0x23, 0xF8, 0x20, 0x10, 0x20, 0xA0, 0x20, 0x40, 0x2F,
0xFE, 0x20, 0x42, 0x20, 0x44, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x81, 0x40, 0x00, 0x80,/*"?",2*/

"列",0x00, 0x04, 0x7F, 0x84, 0x08, 0x04, 0x08, 0x24, 0x1F, 0x24, 0x11, 0x24, 0x21, 0x24, 0x21, 0x24, 0x52,
0x24, 0x8A, 0x24, 0x04, 0x24, 0x04, 0x24, 0x08, 0x04, 0x10, 0x04, 0x20, 0x14, 0x40, 0x08,/*"?",3*/

"形",0x00, 0x00, 0x7F, 0x84, 0x12, 0x04, 0x12, 0x08, 0x12, 0x10, 0x12, 0x22, 0x12, 0x02, 0xFF, 0xC4, 0x12, 
0x08, 0x12, 0x10, 0x12, 0x22, 0x12, 0x02, 0x22, 0x04, 0x22, 0x08, 0x42, 0x10, 0x82, 0x60,/*"?",4*/

"模",0x11, 0x10, 0x11, 0x10, 0x17, 0xFC, 0x11, 0x10, 0xFC, 0x00, 0x13, 0xF8, 0x32, 0x08, 0x3B, 0xF8, 0x56,
0x08, 0x53, 0xF8, 0x90, 0x40, 0x17, 0xFC, 0x10, 0xA0, 0x11, 0x10, 0x12, 0x08, 0x14, 0x06,/*"?",5*/

"式",0x00, 0x48, 0x00, 0x44, 0x00, 0x44, 0x00, 0x40, 0xFF, 0xFE, 0x00, 0x40, 0x00, 0x40, 0x3E, 0x40, 0x08, 
0x40, 0x08, 0x40, 0x08, 0x20, 0x08, 0x22, 0x0F, 0x12, 0x78, 0x0A, 0x20, 0x06, 0x00, 0x02,/*"?",6*/

"最",0x1F, 0xF0, 0x10, 0x10, 0x1F, 0xF0, 0x10, 0x10, 0x1F, 0xF0, 0x00, 0x00, 0xFF, 0xFE, 0x22, 0x00, 0x3E, 
0xF8, 0x22, 0x88, 0x3E, 0x90, 0x22, 0x50, 0x2F, 0x20, 0xF2, 0x50, 0x42, 0x88, 0x03, 0x06,/*"?",7*/

"大",0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0xFF, 0xFE, 0x01, 0x00, 0x01, 0x00, 0x02,
0x80, 0x02, 0x80, 0x04, 0x40, 0x04, 0x40, 0x08, 0x20, 0x10, 0x10, 0x20, 0x08, 0xC0, 0x06,/*"?",8*/

"操",0x23, 0xF8, 0x22, 0x08, 0x22, 0x08, 0x23, 0xF8, 0xF8, 0x00, 0x27, 0xBC, 0x24, 0xA4, 0x2C, 0xA4, 0x37,
0xBC, 0xE0, 0x40, 0x2F, 0xFE, 0x21, 0x60, 0x22, 0x50, 0x24, 0x48, 0xB8, 0x46, 0x40, 0x40,/*"?",9*/

"作",0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x11, 0xFE, 0x12, 0x80, 0x32, 0x80, 0x34, 0x80, 0x50, 0xF8, 0x90, 
0x80, 0x10, 0x80, 0x10, 0x80, 0x10, 0xFC, 0x10, 0x80, 0x10, 0x80, 0x10, 0x80, 0x10, 0x80,/*"?",10*/

"偏",0x10, 0x80, 0x10, 0x40, 0x17, 0xFC, 0x24, 0x04, 0x24, 0x04, 0x67, 0xFC, 0x64, 0x00, 0xA4, 0x00, 0x27,
0xFC, 0x26, 0xA4, 0x2A, 0xA4, 0x2B, 0xFC, 0x2A, 0xA4, 0x2A, 0xA4, 0x32, 0xA4, 0x22, 0x0C,/*"?",11*/

"调",0x00, 0x00, 0x47, 0xFC, 0x24, 0x44, 0x24, 0x44, 0x05, 0xF4, 0x04, 0x44, 0xE4, 0x44, 0x27, 0xFC, 0x24,
0x04, 0x25, 0xF4, 0x25, 0x14, 0x2D, 0x14, 0x35, 0xF4, 0x24, 0x04, 0x04, 0x14, 0x08, 0x08,/*"?",0*/

"制",0x04, 0x04, 0x24, 0x04, 0x24, 0x04, 0x3F, 0xA4, 0x44, 0x24, 0x04, 0x24, 0xFF, 0xE4, 0x04, 0x24, 0x04,
0x24, 0x3F, 0xA4, 0x24, 0xA4, 0x24, 0xA4, 0x26, 0x84, 0x25, 0x04, 0x04, 0x14, 0x04, 0x08,/*"?",1*/

"设",0x00, 0x00, 0x21, 0xF0, 0x11, 0x10, 0x11, 0x10, 0x01, 0x10, 0x02, 0x0E, 0xF4, 0x00, 0x13, 0xF8, 0x11,
0x08, 0x11, 0x10, 0x10, 0x90, 0x14, 0xA0, 0x18, 0x40, 0x10, 0xA0, 0x03, 0x18, 0x0C, 0x06,/*"?",2*/

"置",0x7F, 0xFC, 0x44, 0x44, 0x7F, 0xFC, 0x01, 0x00, 0x7F, 0xFC, 0x01, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x1F,
0xF0, 0x10, 0x10, 0x1F, 0xF0, 0x10, 0x10, 0x1F, 0xF0, 0x10, 0x10, 0xFF, 0xFE, 0x00, 0x00,/*"?",3*/

"正",0x00, 0x00, 0x7F, 0xFC, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x11, 0x00, 0x11, 0xF8, 0x11,
0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00, 0xFF, 0xFE, 0x00, 0x00,/*"?",0*/

"弦",0x00, 0x40, 0xF8, 0x20, 0x08, 0x20, 0x0B, 0xFE, 0x08, 0x40, 0x78, 0x40, 0x40, 0x88, 0x41, 0x08, 0x43,
0xF0, 0x78, 0x20, 0x08, 0x40, 0x08, 0x88, 0x09, 0x04, 0x0B, 0xFC, 0x51, 0x04, 0x20, 0x00,/*"?",1*/
"基",0x08, 0x20, 0x08, 0x20, 0x7F, 0xFC, 0x08, 0x20, 0x0F, 0xE0, 0x08, 0x20, 0x0F, 0xE0, 0x08, 0x20, 0xFF, 
0xFE, 0x08, 0x20, 0x11, 0x10, 0x21, 0x08, 0xCF, 0xE6, 0x01, 0x00, 0x01, 0x00, 0x3F, 0xF8,/*"?",0*/
"带",0x09, 0x20, 0x09, 0x20, 0x7F, 0xFC, 0x09, 0x20, 0x09, 0x20, 0x00, 0x00, 0x7F, 0xFE, 0x41, 0x02, 0x81,
0x04, 0x1F, 0xF0, 0x11, 0x10, 0x11, 0x10, 0x11, 0x50, 0x11, 0x20, 0x01, 0x00, 0x01, 0x00,/*"?",1*/
"度",0x01, 0x00, 0x00, 0x80, 0x3F, 0xFE, 0x22, 0x20, 0x22, 0x20, 0x3F, 0xFC, 0x22, 0x20, 0x22, 0x20, 0x23, 
0xE0, 0x20, 0x00, 0x2F, 0xF0, 0x24, 0x10, 0x42, 0x20, 0x41, 0xC0, 0x86, 0x30, 0x38, 0x0E,/*"?",0*/

"按",0x10, 0x40, 0x10, 0x20, 0x10, 0x20, 0x13, 0xFE, 0xFA, 0x02, 0x14, 0x44, 0x10, 0x40, 0x1B, 0xFE, 0x30, 
0x88, 0xD0, 0x88, 0x11, 0x08, 0x10, 0xD0, 0x10, 0x20, 0x10, 0x50, 0x50, 0x88, 0x23, 0x04,/*"?",0*/
"键",0x20, 0x10, 0x20, 0x10, 0x3B, 0x7C, 0x21, 0x14, 0x41, 0xFE, 0x7A, 0x14, 0xA2, 0x7C, 0x27, 0x10, 0xF9,
0x7C, 0x25, 0x10, 0x25, 0xFE, 0x22, 0x10, 0x2A, 0x10, 0x35, 0x00, 0x28, 0xFE, 0x00, 0x00,/*"?",1*/
"提",0x10, 0x00, 0x11, 0xFC, 0x11, 0x04, 0x11, 0x04, 0xFD, 0xFC, 0x11, 0x04, 0x11, 0x04, 0x15, 0xFC, 0x18,
0x00, 0x33, 0xFE, 0xD0, 0x20, 0x11, 0x20, 0x11, 0x3C, 0x11, 0x20, 0x52, 0xA0, 0x24, 0x7E,/*"?",2*/
"示",0x00, 0x00, 0x3F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE, 0x01, 0x00, 0x01,
0x00, 0x11, 0x10, 0x11, 0x08, 0x21, 0x04, 0x41, 0x02, 0x81, 0x02, 0x05, 0x00, 0x02, 0x00,/*"?",3*/

"确",0x00, 0x40, 0x00, 0x40, 0xFC, 0x7C, 0x10, 0x84, 0x11, 0x08, 0x22, 0xFE, 0x3C, 0x92, 0x64, 0x92, 0x64, 
0xFE, 0xA4, 0x92, 0x24, 0x92, 0x24, 0xFE, 0x3C, 0x92, 0x25, 0x12, 0x21, 0x0A, 0x02, 0x04,/*"?",0*/
"认",0x00, 0x40, 0x20, 0x40, 0x10, 0x40, 0x10, 0x40, 0x00, 0x40, 0x00, 0x40, 0xF0, 0x40, 0x10, 0x40, 0x10,
0xA0, 0x10, 0xA0, 0x10, 0xA0, 0x15, 0x10, 0x19, 0x10, 0x12, 0x08, 0x04, 0x04, 0x08, 0x02,/*"?",1*/
"选",0x00, 0x40, 0x22, 0x40, 0x12, 0x40, 0x13, 0xF8, 0x04, 0x40, 0x00, 0x40, 0xF7, 0xFC, 0x11, 0x20, 0x11,
0x20, 0x11, 0x20, 0x12, 0x24, 0x12, 0x24, 0x14, 0x1C, 0x28, 0x00, 0x47, 0xFE, 0x00, 0x00,/*"?",2*/
"择",0x20, 0x00, 0x27, 0xF8, 0x22, 0x08, 0x21, 0x10, 0xF0, 0xA0, 0x20, 0x40, 0x21, 0xB0, 0x26, 0x4E, 0x30, 
0x40, 0xE3, 0xF8, 0x20, 0x40, 0x20, 0x40, 0x27, 0xFC, 0x20, 0x40, 0xA0, 0x40, 0x40, 0x40,/*"?",3*/
"信",0x08, 0x40, 0x08, 0x20, 0x0B, 0xFE, 0x10, 0x00, 0x10, 0x00, 0x31, 0xFC, 0x30, 0x00, 0x50, 0x00, 0x91,
0xFC, 0x10, 0x00, 0x10, 0x00, 0x11, 0xFC, 0x11, 0x04, 0x11, 0x04, 0x11, 0xFC, 0x11, 0x04,/*"?",4*/
"号",0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F, 0xF0, 0x00, 0x00, 0xFF, 0xFE, 0x08,
0x00, 0x10, 0x00, 0x1F, 0xF0, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0xA0, 0x00, 0x40,/*"?",5*/
"发",0x01, 0x00, 0x11, 0x10, 0x11, 0x08, 0x22, 0x00, 0x3F, 0xFC, 0x02, 0x00, 0x04, 0x00, 0x07, 0xF8, 0x0A, 
0x08, 0x09, 0x08, 0x11, 0x10, 0x10, 0xA0, 0x20, 0x40, 0x40, 0xA0, 0x03, 0x18, 0x1C, 0x06,/*"?",6*/
"生",0x01, 0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00, 0x3F, 0xFC, 0x21, 0x00, 0x41, 0x00, 0x81, 0x00, 0x01,
0x00, 0x3F, 0xF8, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0xFF, 0xFE, 0x00, 0x00,/*"?",7*/
"器",0x00, 0x00, 0x3E, 0x7C, 0x22, 0x44, 0x22, 0x44, 0x3E, 0x7C, 0x01, 0x20, 0x01, 0x10, 0xFF, 0xFE, 0x02,
0x80, 0x0C, 0x60, 0x30, 0x18, 0xC0, 0x06, 0x3E, 0x7C, 0x22, 0x44, 0x22, 0x44, 0x3E, 0x7C,/*"?",8*/

"返",0x00, 0x08, 0x20, 0x3C, 0x13, 0xC0, 0x12, 0x00, 0x02, 0x00, 0x03, 0xFC, 0xF2, 0x04, 0x12, 0x88, 0x12, 
0x50, 0x12, 0x20, 0x12, 0x50, 0x14, 0x88, 0x15, 0x04, 0x28, 0x00, 0x47, 0xFE, 0x00, 0x00,/*"?",0*/

"回",0x00, 0x00, 0x3F, 0xF8, 0x20, 0x08, 0x20, 0x08, 0x27, 0xC8, 0x24, 0x48, 0x24, 0x48, 0x24, 0x48, 0x24, 
0x48, 0x24, 0x48, 0x27, 0xC8, 0x20, 0x08, 0x20, 0x08, 0x3F, 0xF8, 0x20, 0x08, 0x00, 0x00,/*"?",1*/



};
