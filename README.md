# PROJE-1- 
Bu proje, Tiva C serisi mikrodenetleyici kullanarak LCD ekran kontrolü için yazılmış bir uygulamadır. Projede kullanılan kod, LCD'nin 4-bit modunda çalıştırılmasını, temel LCD ayarlarının yapılmasını ve metin yazdırılmasını sağlar.

Gereksinimler: Bu kodun çalışması için aşağıdaki donanım ve yazılım bileşenleri gereklidir:
Donanım:
Tiva C Series LaunchPad (TM4C123 veya TM4C129 serisi)
LCD ekran
Bağlantı kabloları
Breadboard (opsiyonel)

Yazılım:
Code Composer Studio (CCS)

Ana Dosyalar:
main.c: Programın ana başlangıç dosyasıdır.
LCD'ye karakterler yazmak için temel işlemleri içerir.

lcd.h:
LCD'yi kontrol etmek için kullanılan fonksiyonların prototiplerini içerir.
LCD bağlantıları ve pin tanımlamaları burada yapılmalıdır.

Kullanılan Fonksiyonlar:
otuzhexgonder()
LCD'ye 0x30 (ilk kurulum komutu) göndermek için kullanılır.
Bu komut, LCD'nin başlangıç ayarlarını yapar ve 3 kez tekrarlanır.

LCDkomut(unsigned char c)
LCD'ye komut göndermek için kullanılan bir fonksiyondur.
Gelen komut verisi, 4-bit modunda LCD'ye iki parça halinde gönderilir (üst 4 bit ve alt 4 bit).

LCDilkayarlar()
LCD'nin başlangıç ayarlarını yapar.
Port ve pin ayarlarını tanımlar.
LCD'yi çalıştırmak için gerekli olan temel komutları gönderir.

LCDfonksiyonayarla(unsigned char DL, unsigned char N, unsigned char F)
LCD'nin çalışma modunu ayarlar.

LCDkarakteryaz(unsigned char c)
LCD'ye bir karakter yazdırır.
Karakter verisini 4-bit modunda LCD'ye gönderir.

LCDtemizle()
LCD ekranını temizlemek için kullanılır.
Ekrandaki tüm verileri siler ve imleci başlangıç pozisyonuna getirir.

LCDgit(unsigned char k, unsigned char m)
LCD imlecini belirli bir satır ve sütuna taşır.
