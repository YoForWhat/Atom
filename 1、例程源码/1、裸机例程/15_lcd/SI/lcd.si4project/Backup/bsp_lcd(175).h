#ifndef _BSP_LCD_H
#define _BSP_LCD_H
#include "imx6ul.h"
/*
 * IMX6UL LCD驱动文件
 * 作者:左忠凯
 */

//颜色
#define LCD_BLUE		  0x000000FF
#define LCD_GREEN		  0x0000FF00
#define LCD_RED 		  0x00FF0000
#define LCD_CYAN		  0x0000FFFF
#define LCD_MAGENTA 	  0x00FF00FF
#define LCD_YELLOW		  0x00FFFF00
#define LCD_LIGHTBLUE	  0x008080FF
#define LCD_LIGHTGREEN	  0x0080FF80
#define LCD_LIGHTRED	  0x00FF8080
#define LCD_LIGHTCYAN	  0x0080FFFF
#define LCD_LIGHTMAGENTA  0x00FF80FF
#define LCD_LIGHTYELLOW   0x00FFFF80
#define LCD_DARKBLUE	  0x00000080
#define LCD_DARKGREEN	  0x00008000
#define LCD_DARKRED 	  0x00800000
#define LCD_DARKCYAN	  0x00008080
#define LCD_DARKMAGENTA   0x00800080
#define LCD_DARKYELLOW	  0x00808000
#define LCD_WHITE		  0x00FFFFFF
#define LCD_LIGHTGRAY	  0x00D3D3D3
#define LCD_GRAY		  0x00808080
#define LCD_DARKGRAY	  0x00404040
#define LCD_BLACK		  0x00000000
#define LCD_BROWN		  0x00A52A2A
#define LCD_ORANGE		  0x00FFA500
#define LCD_TRANSPARENT   0x00000000

//LCD显存地址
#define LCD_FRAMEBUF_ADDR	(0x89000000)

//LCD控制参数结构体
struct tftlcd_typedef{
	unsigned short height;	/* LCD屏幕高度 */
	unsigned short width;	/* LCD屏幕宽度 */
	unsigned char pixsize;	/* LCD每个像素所占字节大小 */
	unsigned short vspw;
	unsigned short vbpd;
	unsigned short vfpd;
	unsigned short hspw;
	unsigned short hbpd;
	unsigned short hfpd;
	unsigned int framebuffer; 	/* LCD显存首地址   	  */
	unsigned int forecolor;		/* 前景色 */
	unsigned int backcolor;		/* 背景色 */
};

extern struct tftlcd_typedef tftlcd_dev;


//函数声明
void lcd_init(void);
void lcdgpio_init(void);
void lcdclk_init(void);
void lcd_reset(void);
void lcd_noreset(void);
void lcd_enable(void);
void video_pllinit(unsigned char loopdivi, unsigned char postdivi);

inline void lcd_drawpoint(unsigned short x,unsigned short y,unsigned int color);
inline unsigned int lcd_readpoint(unsigned short x,unsigned short y);
void lcd_clear(unsigned int color);
void lcd_fill(unsigned    short x0, unsigned short y0, unsigned short x1, unsigned short y1, unsigned int color);
void lcd_drawline(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2);
void lcd_draw_rectangle( unsigned short x1, unsigned short y1, unsigned short x2,  unsigned short y2);
void lcd_draw_Circle(unsigned short x0,unsigned short y0,unsigned char r);
void lcd_showchar(unsigned     short x,unsigned short y,unsigned char num,unsigned char size);
unsigned int lcd_pow(unsigned char m,unsigned char n);
unsigned int lcd_pow(unsigned char m,unsigned char n);
void lcd_shownum(unsigned     short x,unsigned short y,unsigned int num,unsigned char len,unsigned char size);
void lcd_show_string(unsigned       short x,unsigned short y,unsigned short width,unsigned short height,unsigned char size,char *p);









#endif
