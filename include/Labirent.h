// include/Labirent.h

#ifndef LABIRENT_H
#define LABIRENT_H

#include <stack>
#define YUKSEKLIK 20
#define GENISLIK 50

class Konum {
public:
    char deger;
    int satir;
    int sutun;
    bool gezildiMi;

    Konum();
};

class Labirent {
public:
    Konum harita[YUKSEKLIK][GENISLIK];
    Konum baslangic;
    Konum bitis;

    Labirent();

    bool hareketMumkunMu(int yeniSatir, int yeniSutun);

    void hareketEt(Konum* mevcut, std::stack<Konum>& yol);

    bool cikisaUlasildiMi(Konum* mevcut);

    void yazdir();
};

#endif // LABIRENT_H
