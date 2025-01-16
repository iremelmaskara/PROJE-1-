#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"    // Sistemle ilgili kütüphaneler
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"   // GPIO_PIN_x tanýmlamalarý için
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "lcd.h"                 // LCD baþlýk dosyasý



int main()
{
    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    LCDilkayarlar();
    LCDfonksiyonayarla(0, 1, 0); // 4-bit mod, 2 satýr, 5x8 karakter
    LCDtemizle();

    // Ýlk satýra 'A' karakteri yazdýrma
    LCDgit(0, 0); // 1. Satýr, 1. Sütun
    LCDkarakteryaz('b');
//    LCDgit(0, 1); // 1. Satýr, 1. Sütun
//    LCDkarakteryaz('x');
//    // Ýkinci satýra 'B' karakteri yazdýrma
//    LCDgit(1, 0); // 2. Satýr, 1. Sütun
//    LCDkarakteryaz('B');

    while (1) {} // Sonsuz döngü
}

