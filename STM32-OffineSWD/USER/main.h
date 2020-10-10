#ifndef _MAIN_H_
#define _MAIN_H_

/***********************ͷ�ļ�����************************/
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "w25qxx.h"
#include "hw_config.h" 
#include "usb_lib.h"
#include "usb_pwr.h"
#include "SWD_host.h"
#include "SWD_flash.h"
#include "SWD_opt.h"
#include "oled.h"
#include "key.h"
#include "String.h"
#include "hex2bin.h"
#include "ff.h" 
#include "DAPA_config.h"
#include "led.h"

/****************************************Logo************************************/
unsigned char USBLogo[]={
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF0,0xF0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF8,0xFC,
  0xFE,0xFF,0xFF,0xFF,0xFF,0xFB,0xF1,0xE1,0xC3,0xC7,0xEE,0x7F,0x3B,0x1F,0x0E,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x3E,0x7F,0xFF,0xFF,0xFF,0xDF,
  0xDB,0xF6,0xF7,0xFF,0xFE,0xF6,0xFF,0xFF,0x7F,0x3F,0x1F,0x0F,0x07,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3F,0x3F,0x0F,
  0x03,0x07,0x0F,0x1F,0x0F,0x0F,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

unsigned char FlashLogo[]={
  0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0x70,0x38,0x38,0x1C,0x1C,0x0C,0x0C,0x0E,0x0E,
  0x0E,0x0E,0x8E,0xCC,0xEC,0xEC,0xEC,0xF8,0xF8,0xF8,0x7C,0xFE,0x8F,0x07,0x03,0x00,
  0x00,0x00,0xC0,0xFC,0xFF,0x0F,0x03,0x80,0x80,0xC0,0xC0,0xE0,0xF0,0xF8,0xF8,0xFC,
  0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xBF,0x8F,0x87,0x81,0x80,0x03,0x07,0x7F,0xFC,
  0xC0,0x00,0x00,0x07,0x7F,0xFF,0xE0,0x80,0x03,0x03,0xC3,0xE3,0xF3,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0x7F,0x7F,0x3F,0x1F,0x0F,0x0F,0x07,0x03,0x03,0x80,0xC0,0xFC,
  0x7F,0x0F,0x00,0x00,0x00,0x00,0xC1,0xE3,0xF7,0x7C,0x7F,0x3F,0x1F,0x6F,0x6F,0x6F,
  0x67,0xE3,0xC3,0xC1,0xC0,0xE0,0xE0,0x60,0x60,0x70,0x38,0x38,0x1C,0x0E,0x0F,0x03,
  0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,
};

unsigned char DebugLogo[]={
	0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0x60,0x70,0x38,0xB8,0xB8,0xBC,0xFC,0xFC,
	0xFC,0xFC,0xFC,0xF8,0xF8,0xF8,0xF0,0xE0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xE0,0xFC,0xFE,0xFF,0xF1,0xFC,0xFE,0xF3,0xFB,0x39,0x1D,0x0F,0xC7,0xC7,
	0xC7,0xC7,0x0F,0x1F,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFC,0xE0,0x00,0x00,
	0x00,0x00,0x07,0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xF8,0xF0,0xE3,0xE3,
	0xE3,0xE3,0xF0,0x38,0x9C,0xCF,0xFF,0x7F,0x1F,0xFF,0xFF,0x7F,0x3F,0x07,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x07,0x0F,0x1F,0x1F,0x1F,0x3F,0x3F,0x3F,
	0x3F,0x3F,0x3F,0x1B,0x1B,0x19,0x0C,0x06,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,
};
	

/***********************��������************************/
uint32_t Flash_Page_Size = 1024;

/***********************��������************************/
void Init_device(void);
void Draw_Logo(void);
void Draw_Menu(void);
void Draw_Main(void);
u8 FLASH_SWD(u8 *File);
u8 FLASH_SWD_HEX(u8 *File);
u8 Scan_Key(void);

#endif /*_MAIN_H_*/

