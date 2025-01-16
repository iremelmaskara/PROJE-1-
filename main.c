#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"    // Sistemle ilgili k�t�phaneler
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"   // GPIO_PIN_x tan�mlamalar� i�in
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "lcd.h"                 // LCD ba�l�k dosyas�



int main()
{
    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    LCDilkayarlar();
    LCDfonksiyonayarla(0, 1, 0); // 4-bit mod, 2 sat�r, 5x8 karakter
    LCDtemizle();

    // �lk sat�ra 'A' karakteri yazd�rma
    LCDgit(0, 0); // 1. Sat�r, 1. S�tun
    LCDkarakteryaz('b');
//    LCDgit(0, 1); // 1. Sat�r, 1. S�tun
//    LCDkarakteryaz('x');
//    // �kinci sat�ra 'B' karakteri yazd�rma
//    LCDgit(1, 0); // 2. Sat�r, 1. S�tun
//    LCDkarakteryaz('B');

    while (1) {} // Sonsuz d�ng�
}

