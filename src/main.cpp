// src/main.cpp
#include <stack>

#include <iostream>
#include "Labirent.h"

using namespace std;
int main() {
	// labirent ba�lang�� ve biti� noktalar�n�n olu�turulmas�
	Konum baslangic,bitis;
	baslangic.satir = 0; baslangic.sutun = 19; //baslang�c
	bitis.satir = 19; bitis.sutun = 11; //bitis
	
	//labirentin olu�turulmas�
	
    Labirent* labirent = new Labirent();
    labirent->baslangic = baslangic;
    labirent->bitis = bitis;
    
    
    // labirentte gezen �nlem (mevcut konum) olu�turulmas�
    Konum * mevcutKonum = new Konum;
    mevcutKonum->deger = '!';
    mevcutKonum->satir = baslangic.satir;
    mevcutKonum->sutun = baslangic.sutun;
    labirent->harita[baslangic.satir][baslangic.sutun].deger = mevcutKonum->deger; // ba�lang�� konumunu ata
    
    // Birden fazla ihtimallerin oldu�u yerler i�in stack olu�turulmas�
    stack<Konum>* yol = new stack<Konum>();
          
    while(!labirent->cikisaUlasildiMi(mevcutKonum)){
    	labirent->hareketEt(mevcutKonum, *yol);
	}

    return 0;
}

