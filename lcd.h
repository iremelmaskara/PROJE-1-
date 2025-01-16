/*
 * lcd.h
 *
 *  Created on: 2 Kas 2024
 *      Author: ireme
 */
#ifndef LCD_H_
#define LCD_H_

#define LCDPORT             GPIO_PORTB_BASE
#define LCDPORTENABLE       SYSCTL_PERIPh_GPIOB
#define RS                  GPIO_PIN_0
#define E                   GPIO_PIN_1
#define D4                  GPIO_PIN_4
#define D5                  GPIO_PIN_5
#define D6                  GPIO_PIN_6
#define D7                  GPIO_PIN_7

void LCDkomut(unsigned char);  //0 la 255 arasýnda veri
// rs=0
//d4-d7 arasýnda veri yaz
//ve en ac kapa

void LCDilkayarlar();
//giriþ kipini seç
//ekran ac/kapa
//kursör kaydýr

void LCDkarakteryaz(unsigned char);
// rs=1
//d4-d7 arasýnda veri yaz
//ve en ac kapa

void LCDfonksiyonayarla(unsigned char DL, unsigned char N, unsigned char F);  //dl,N,F
//dl=0 1
//N =0 1
//F =0 1

void LCDtemizle();
// rs=0
//d4-d7 arasýnda veri yaz
//ve en ac kapa

void LCDgit(unsigned char,unsigned char);
//1,5
//85

//2,7
//c7

#endif /* LCD_H_ */


