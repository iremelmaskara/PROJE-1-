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
    //ayar yazýldý
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, 0x30);   //30h göndermiþ olduk yani
    //en ac kapa
    GPIOPinWrite(LCDPORT, E, 2);  //PÝN1  2 ÝLE ACILIYORDU
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E, 0);
    //3 kez 30h gonder
}
void LCDkomut(unsigned char c)   //0x07 göndermek istersek
{

    GPIOPinWrite(LCDPORT, RS, 0);      //O DI DEÐÝÞTÝRDÝM
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, (c & 0xf0));
    GPIOPinWrite(LCDPORT, E, 2);  //PÝN1  2 ÝLE ACILIYORDU
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E, 0);

    SysCtlDelay(1000);

    GPIOPinWrite(LCDPORT, RS,0 );
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, (c & 0x0f)<<4);
    GPIOPinWrite(LCDPORT, E, 2);  //PÝN1  2 ÝLE ACILIYORDU
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
    unsigned char cmd = 0x20; // Fonksiyon set komutu baþlangýcý

    if (DL) cmd |= 0x10; // DL: Data Length (0 = 4-bit, 1 = 8-bit)
    if (N) cmd |= 0x08;  // N: Display lines (0 = 1 satýr, 1 = 2 satýr)
    if (F) cmd |= 0x04;  // F: Font (0 = 5x8, 1 = 5x10)

    LCDkomut(cmd); // Fonksiyon set komutunu gönder

}

void LCDkarakteryaz(unsigned char c)  //
{
    GPIOPinWrite(LCDPORT, RS, RS); // Veri modu

    // Üst 4 bit gönder
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, (c & 0xf0));
    GPIOPinWrite(LCDPORT, E, 2); // Enable pinini yüksek yap
    SysCtlDelay(1000); // Gecikme
    GPIOPinWrite(LCDPORT, E, 0); // Enable pinini sýfýrla

    SysCtlDelay(1000); // Gecikme

    // Alt 4 bit gönder
    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, (c & 0x0f) << 4);
    GPIOPinWrite(LCDPORT, E, 2); // Enable pinini yüksek yap
    SysCtlDelay(1000); // Gecikme
    GPIOPinWrite(LCDPORT, E, 0); // Enable pinini sýfýrla

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

    if (k == 0) address = 0x80 + m; // 1. Satýr
    else if (k == 1) address = 0xC0 + m; // 2. Satýr

    LCDkomut(address);

}
