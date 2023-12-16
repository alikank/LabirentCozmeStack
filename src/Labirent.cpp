// src/Labirent.cpp

#include "Labirent.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <windows.h>

#define YUKSEKLIK 20
#define GENISLIK 50

Konum::Konum() {
    gezildiMi = false;
}

Labirent::Labirent() {
    std::ifstream dosyaOku("AnaHarita.txt");

    if (dosyaOku.is_open()) {
        for (int i = 0; i < YUKSEKLIK; ++i) {
            for (int j = 0; j < GENISLIK; ++j) {
                dosyaOku.get(harita[i][j].deger);
                harita[i][j].satir = i;
                harita[i][j].sutun = j;
            }
            dosyaOku.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        dosyaOku.close();
    } else {
        std::cerr << "Dosya a��lamad�!" << std::endl;
    }
}

bool Labirent::hareketMumkunMu(int yeniSatir, int yeniSutun) {
    if (yeniSatir >= 0 && yeniSatir < YUKSEKLIK &&
        yeniSutun >= 0 && yeniSutun < GENISLIK &&
        harita[yeniSatir][yeniSutun].deger != '#' &&
        harita[yeniSatir][yeniSutun].gezildiMi == false) {
        return true;
    }

    return false;
}

void Labirent::hareketEt(Konum* mevcut, std::stack<Konum>& yol) {
    int hareketEdebilecegiYon, satir, sutun, islem;
    hareketEdebilecegiYon = 0; // ka� adet y�ne hareket edebilece�ini tutar, birden fazlaysa stacke atar.
    islem = 0;
    satir = mevcut->satir; sutun = mevcut->sutun;

    // a�a�� y�ne gidi�
    if (hareketMumkunMu(satir + 1, sutun)) {
        hareketEdebilecegiYon++;
        islem = 1;
    }

    // sa� y�ne gidi�
    if (hareketMumkunMu(satir, sutun + 1)) {
        hareketEdebilecegiYon++;
        if (islem == 0)
            islem = 2; // daha �nce hareket edilecek y�n belirlenmediyse i�lemi belirle.
    }

    // sol y�ne gidi�
    if (hareketMumkunMu(satir, sutun - 1)) {
        hareketEdebilecegiYon++;
        if (islem == 0)
            islem = 3;
    }

    // yukar� y�ne gidi�
    if (hareketMumkunMu(satir - 1, sutun)) {
        hareketEdebilecegiYon++;
        if (islem == 0)
            islem = 4;
    }

    if (hareketEdebilecegiYon > 1) yol.push(*mevcut); // birden fazla se�enek varsa o yolu kaydet

    // hareket i�lemlerini ger�ekle�tirmeye ba�la
    switch (islem) {
        case 1: // a�a��
            harita[satir][sutun].gezildiMi = true;
            harita[satir][sutun].deger = ' '; // eski konumu bo�alt�yoruz (!)'i kald�r�yoruz.
            mevcut->satir = satir + 1;
            harita[mevcut->satir][mevcut->sutun].deger = mevcut->deger;
            yazdir();
            break;

        case 2: // sa�
            harita[satir][sutun].gezildiMi = true;
            harita[satir][sutun].deger = ' '; // eski konumu bo�alt�yoruz (!)'i kald�r�yoruz.
            mevcut->sutun = sutun + 1;
            harita[mevcut->satir][mevcut->sutun].deger = mevcut->deger;
            yazdir();
            break;

        case 3: // sol
            harita[satir][sutun].gezildiMi = true;
            harita[satir][sutun].deger = ' '; // eski konumu bo�alt�yoruz (!)'i kald�r�yoruz.
            mevcut->sutun = sutun - 1;
            harita[mevcut->satir][mevcut->sutun].deger = mevcut->deger;
            yazdir();
            break;

        case 4: // yukar�
            harita[satir][sutun].gezildiMi = true;
            harita[satir][sutun].deger = ' '; // eski konumu bo�alt�yoruz (!)'i kald�r�yoruz.
            mevcut->satir = satir - 1;
            harita[mevcut->satir][mevcut->sutun].deger = mevcut->deger;
            yazdir();
            break;

        case 0:
            if (!yol.empty()) {
                harita[satir][sutun].gezildiMi = true;
                harita[satir][sutun].deger = ' ';
                system("color a");
                std::cout << "BU YOL BASARISIZ, STACKTEKI ESKI KONUMA GERI DONULUYOR : " << yol.top().satir << ", " << yol.top().sutun << std::endl;
                mevcut->satir = yol.top().satir; mevcut->sutun = yol.top().sutun;
                yol.pop();
                Sleep(900);
                system("color 7");
                yazdir();
                break;
            } else {
                std::cout << "STACK BOS, COZUM YOK\n";
                exit(0);
            }

            break;
    }
}

bool Labirent::cikisaUlasildiMi(Konum* mevcut) {
    if (bitis.satir == mevcut->satir && bitis.sutun == mevcut->sutun) {
        harita[mevcut->satir][mevcut->sutun].deger = 'E'; // Biti�e ula��ld���nda E ata
        yazdir();
        std::cout << "CIKISA ULASTIN BRAVO"; return true;
    } else return false;
}

void Labirent::yazdir() {
    Sleep(400);
    system("cls");
    for (int i = 0; i < YUKSEKLIK; ++i) {
        for (int j = 0; j < GENISLIK; ++j) {
            std::cout << harita[i][j].deger;
        }
        std::cout << std::endl;
    }
}

