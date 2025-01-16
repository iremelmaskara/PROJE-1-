#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/gpio.c"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.c"
#include "lcd.h"



void otuzhexgonder()
{
    SysCtlDelay(10000000);

    //rs=0
    GPIOPinWrite(LCDPORT, RS, 0);
    //ayar yaz�ld�
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, 0x30);   //30h g�ndermi� olduk yani
    //en ac kapa
    GPIOPinWrite(LCDPORT, E, 2);  //P�N1  2 �LE ACILIYORDU
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E, 0);
    //3 kez 30h gonder
}
void LCDkomut(unsigned char c)   //0x07 g�ndermek istersek
{

    GPIOPinWrite(LCDPORT, RS, 0);      //O DI DE���T�RD�M
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, (c & 0xf0));
    GPIOPinWrite(LCDPORT, E, 2);  //P�N1  2 �LE ACILIYORDU
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E, 0);

    SysCtlDelay(1000);

    GPIOPinWrite(LCDPORT, RS,0 );
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, (c & 0x0f)<<4);
    GPIOPinWrite(LCDPORT, E, 2);  //P�N1  2 �LE ACILIYORDU
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E, 0);

    SysCtlDelay(1000);
}

void LCDilkayarlar()
{
    //portB_base_enable
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, 0xFF);
    //portb de kitli pin yok

    otuzhexgonder();
    otuzhexgonder();
    otuzhexgonder();

    LCDkomut(0x02);

    //ayarlar devamm

    //lcd komut kullan
}

void LCDfonksiyonayarla(unsigned char DL ,unsigned char N,unsigned char F)
{
//    if DL
//    if N
//    if F
    unsigned char cmd = 0x20; // Fonksiyon set komutu ba�lang�c�

    if (DL) cmd |= 0x10; // DL: Data Length (0 = 4-bit, 1 = 8-bit)
    if (N) cmd |= 0x08;  // N: Display lines (0 = 1 sat�r, 1 = 2 sat�r)
    if (F) cmd |= 0x04;  // F: Font (0 = 5x8, 1 = 5x10)

    LCDkomut(cmd); // Fonksiyon set komutunu g�nder

}

void LCDkarakteryaz(unsigned char c)  //
{
    GPIOPinWrite(LCDPORT, RS, RS); // Veri modu

    // �st 4 bit g�nder
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, (c & 0xf0));
    GPIOPinWrite(LCDPORT, E, 2); // Enable pinini y�ksek yap
    SysCtlDelay(1000); // Gecikme
    GPIOPinWrite(LCDPORT, E, 0); // Enable pinini s�f�rla

    SysCtlDelay(1000); // Gecikme

    // Alt 4 bit g�nder
    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, (c & 0x0f) << 4);
    GPIOPinWrite(LCDPORT, E, 2); // Enable pinini y�ksek yap
    SysCtlDelay(1000); // Gecikme
    GPIOPinWrite(LCDPORT, E, 0); // Enable pinini s�f�rla

    SysCtlDelay(1000); // Gecikme
}

void LCDtemizle()
{
    LCDkomut(0x01);
    SysCtlDelay(1000);
}

void LCDgit(unsigned char k,unsigned char m)
{
    unsigned char address;

    if (k == 0) address = 0x80 + m; // 1. Sat�r
    else if (k == 1) address = 0xC0 + m; // 2. Sat�r

    LCDkomut(address);

}
