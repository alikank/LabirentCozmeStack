// src/main.cpp
#include <stack>

#include <iostream>
#include "Labirent.h"

using namespace std;
int main() {
	// labirent baþlangýç ve bitiþ noktalarýnýn oluþturulmasý
	Konum baslangic,bitis;
	baslangic.satir = 0; baslangic.sutun = 19; //baslangýc
	bitis.satir = 19; bitis.sutun = 11; //bitis
	
	//labirentin oluþturulmasý
	
    Labirent* labirent = new Labirent();
    labirent->baslangic = baslangic;
    labirent->bitis = bitis;
    
    
    // labirentte gezen ünlem (mevcut konum) oluþturulmasý
    Konum * mevcutKonum = new Konum;
    mevcutKonum->deger = '!';
    mevcutKonum->satir = baslangic.satir;
    mevcutKonum->sutun = baslangic.sutun;
    labirent->harita[baslangic.satir][baslangic.sutun].deger = mevcutKonum->deger; // baþlangýç konumunu ata
    
    // Birden fazla ihtimallerin olduðu yerler için stack oluþturulmasý
    stack<Konum>* yol = new stack<Konum>();
          
    while(!labirent->cikisaUlasildiMi(mevcutKonum)){
    	labirent->hareketEt(mevcutKonum, *yol);
	}

    return 0;
}

