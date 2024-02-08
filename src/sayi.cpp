/**
* @file sayi.cpp
* @description sayi sinifini ve bu sayinin basamaklari icin basamak sinifini icerir.sayiyi basamaklarini ve adreslerini yazdıran kodlari icerir
* @course 2.öğretim A grubu
* @assignment 1.Ödev
* @date 25 KASIM 2023
* @author Ayşe Verda Gülcemal ayseeverda@gmail.com
*/



#include "sayi.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdint>

using namespace std;

Sayi::Sayi(int sayi) : baslangic(nullptr) {
    string sayiStr = to_string(sayi);
    for (char basamakChar : sayiStr) {
        int basamak = basamakChar - '0';
        Basamak* yeniBasamak = new Basamak(basamak);

        if (!baslangic) {
            baslangic = yeniBasamak;
        } else {
            Basamak* current = baslangic;
            while (current->sonraki) {
                current = current->sonraki;
            }
            current->sonraki = yeniBasamak;
        }
    }
}

void Sayi::sayiGoster() {
	cout<< " ************************************"<<endl;
    cout<< " *           SAYIMIZ: ";
    Basamak* current = baslangic;
    while (current) {
        cout << current->deger;
        current = current->sonraki;
		
    } cout<<"      "<<endl;
	 cout<< " ************************************"<<endl;
    cout << " *         ADRES: " << this <<"         *" << endl;
	 cout<< " ************************************"<<endl;
	
}

void Sayi::basamaklariGoster() {
    Basamak* current = baslangic;
    while (current) {
        std::uintptr_t adres = reinterpret_cast<std::uintptr_t>(current);

        int sonUcRakam = adres % 1000;
        char sonUcHane[4];
        snprintf(sonUcHane, sizeof(sonUcHane), "%03d", sonUcRakam);

        cout << " *  Basamaklari: " << current->deger << "  *  Adres: " << sonUcHane << "   *" << endl;
        current = current->sonraki;
    }
}
