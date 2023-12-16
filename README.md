
# C++ Maze Solver

Bu C++ projesi, yükseklik ve genişlik bilgileri ile başlangıç ve bitiş koordinatları verilen bir labirentin çözüm adımlarını yığıt (stack) yardımıyla bulmayı amaçlar.
 
```http
  İlgili proje, Sakarya Uygulamalı Bilimler Üniversitesi
  Veri Yapıları ve Algoritmalar dersi ödevidir.
```

## Kullanılan Algoritma

Bu projede, labirenti çözmek için derinlik öncelikli bir arama algoritması kullanılmıştır. Ancak, geleneksel derinlik öncelikli arama algoritmalarından farklı olarak, bu projede her adımı stack'e atmak yerine labirent üzerinde birden fazla yola gidiş imkanı bulunan koordinatlar stack'e atılmıştır.






## Algoritma Genel Bilgi

Proje Konum ve Labirent olmak üzere iki farklı sınıftan oluşmaktadır.

#### Konum Sınıfı

| Değişken             | Değişken Açıklaması                                                               |
| ----------------- | ------------------------------------------------------------------ |
| char deger | koordinatın değerini tutar örn: ' ' veya '#'|
| int satir | koordinat satır değerini tutar |
| int sutun | koordinat sütun değerini tutar |
| bool gezildiMi | koordinatın üzerinden geçilme bilgisini tutar |

#### Labirent Sınıfı
| Değişken             | Değişken Açıklaması                                                               |
| ----------------- | ------------------------------------------------------------------ |
| Konum harita[YUKSEKLIK][GENISLIK] | labirent ana yapısı|
| Konum baslangic | labirent başlangıç koordinatlarını tutar |
| Konum bitis | labirent bitiş koordinatlarını tutar |


  
## Algoritma Adımları

- Labirent sınıfı, TXT dosyasını okuyarak labirenti oluşturur. Dosyada her satır bir labirent satırını temsil eder.
- Konum sınıfı, her bir hücrenin özelliklerini (değer, satır, sütun, gezildiMi) içerir. Başlangıçta bir hücrede gezildiMi değeri false olarak ayarlanır.
- Konum sınıfından ek bir değişken üretilir, bu değişken mevcut konumun bilgisini tutar ve ilk değeri labirentin başlangıç noktasına eşit olur.
- Labirent sınıfının hareketMumkunMu fonksiyonu, verilen konumda hareketin mümkün olup olmadığını kontrol eder. Bu fonksiyon : gidilecek yeni satır ve sütun değerinin 0'dan büyük olması, labirent genişlik/yükseklik değerini aşmaması, gidilecek yeni koordinatın duvar olmaması, gidilecek yeni satırın daha önce gidilmemiş olması gibi kontrolleri içerir.
- Labirent sınıfının hareketEt fonksiyonu, mevcut konumdan hareket edilebilecek yönlere bakar.
- Birden fazla yöne gidilebilecekse, o konumu bir stack'e ekler. Ardından bir yöne (öncelik sıralaması = AŞAĞI,SAĞ,SOL,YUKARI) hareket eder ve labirenti yazdir fonksiyonu ile günceller.
- Eğer bir çıkışa ulaşılamazsa, en son kaydedilen konumu (stack'ten çıkartılan) kullanarak geri döner. Stackin boş durumda olması daha fazla gidilecek yol bulunmadığını gösterir bu da labirentin çıkışı olmadığını gösterir.
- Labirent sınıfının cikisaUlasildiMi fonksiyonu, mevcut konumun bitiş konumuna eşit olup olmadığını kontrol eder. Bu fonksiyon sayesinde labirent çıkış noktasına ulaşıldığında main fonksiyondaki döngü sonlandırılır.

  
## Harita Bilgi

Örnek haritalar projenin ana dizininde paylaşılmıştır, haritaların yükseklik ve genişlik gibi bilgileri `HARİTALAR HAKKINDA BİLGİ.txt` dosyasında bulunmaktadır.


  
## Yardım

Projelenin klasörlere ayrışması ve mingw make file yardımıyla çalıştırılması için CHATGPT (yapay zekadan) destek alınmıştır.

  
## Bilgisayarınızda Çalıştırın

Proje dizininden CMD açın

```bash
  mingw32-make derle
```

Derleme işlemi sonrası programı çalıştırın

```bash
  mingw32-make calistir
```




  
## Alikan Köse
alikan.com.tr


  
