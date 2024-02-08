/**
* @file main.cpp
* @description bir dosyadan okunan sayıları bir bağlı liste ile bağlayarak çeşitli işlemleri gerçekleştiren bir menü tabanlı bir program.
* @course 2.öğretim A grubu
* @assignment 1.Ödev
* @date 25 KASIM 2023
* @author Ayşe Verda Gülcemal ayseeverda@gmail.com
*/


#include "sayi.h"
#include <fstream>
#include <iostream>
#include <limits> 

using namespace std;

class Dugum {
public:
    Sayi* sayi;
    Dugum* sonraki;

    Dugum(Sayi* sayi);
};

Dugum::Dugum(Sayi* sayi) : sayi(sayi), sonraki(nullptr) {}

class SayilarListesi {
public:
    Dugum* baslangic;

    SayilarListesi();
    void sayiEkle(Sayi* sayi);
    void sayilariGoster();
    void menuGoster();
	void tekBasamaklilariBasAl();
	void basamaklariTersCevir();
	void enBuyuguCikar();
};

SayilarListesi::SayilarListesi() : baslangic(nullptr) {}

void SayilarListesi::enBuyuguCikar() {
    if (!baslangic) {
        cout << "Liste bos, en buyuk sayi cikarilamaz." << endl;
        return;
    }

    Dugum* current = baslangic;
    Dugum* enBuyukDugum = nullptr;
    
    
    int enBuyukSayi = std::numeric_limits<int>::min(); 

    while (current) {
        Sayi* sayi = current->sayi;
        Basamak* currentBasamak = sayi->baslangic;
        int currentSayi = 0;

        while (currentBasamak) {
            currentSayi = currentSayi * 10 + currentBasamak->deger;
            currentBasamak = currentBasamak->sonraki;
        }

        if (currentSayi > enBuyukSayi) {
            enBuyukSayi = currentSayi;
            enBuyukDugum = current;
        }

        current = current->sonraki;
    }

    if (enBuyukDugum) {
        
        if (enBuyukDugum == baslangic) {
            baslangic = enBuyukDugum->sonraki;
        } else {
            Dugum* prev = baslangic;
            while (prev->sonraki != enBuyukDugum) {
                prev = prev->sonraki;
            }
            prev->sonraki = enBuyukDugum->sonraki;
        }

        delete enBuyukDugum->sayi;
        delete enBuyukDugum;
        cout << endl<< "	EN BUYUK SAYI CIKARILDI: " << enBuyukSayi << endl<<endl;
    } else {
        cout << "		Hata: En buyuk sayi bulunamadi." << endl<<endl;
    }
}

void SayilarListesi::basamaklariTersCevir() {
    Dugum* current = baslangic;

    while (current) {
        Sayi* sayi = current->sayi;

        Basamak* prev = nullptr;
        Basamak* currentBasamak = sayi->baslangic;

        while (currentBasamak) {
            Basamak* nextBasamak = currentBasamak->sonraki;
            currentBasamak->sonraki = prev;
            prev = currentBasamak;
            currentBasamak = nextBasamak;
        }

        sayi->baslangic = prev;

        current = current->sonraki;
    }
}


   void SayilarListesi::tekBasamaklilariBasAl() {
    Dugum* current = baslangic;

    while (current) {
        Sayi* sayi = current->sayi;

       
        Basamak* tekBasamak = nullptr;
        Basamak* ciftBasamak = nullptr;

        Basamak* currentBasamak = sayi->baslangic;
        Basamak* nextBasamak = nullptr;

        while (currentBasamak) {
            nextBasamak = currentBasamak->sonraki;

            // Tek basamaklı
            if (currentBasamak->deger % 2 == 1) {
                currentBasamak->sonraki = tekBasamak;
                tekBasamak = currentBasamak;
            }
            // Çift basamaklı
            else {
                currentBasamak->sonraki = ciftBasamak;
                ciftBasamak = currentBasamak;
            }

            currentBasamak = nextBasamak;
        }

       
        if (tekBasamak) {
            sayi->baslangic = tekBasamak;

            Basamak* sonTekBasamak = tekBasamak;
            while (sonTekBasamak->sonraki) {
                sonTekBasamak = sonTekBasamak->sonraki;
            }

            if (ciftBasamak) {
                sonTekBasamak->sonraki = ciftBasamak;
            }
        } else {
            sayi->baslangic = ciftBasamak;
        }

        current = current->sonraki;
    }
}

              

       
void SayilarListesi::sayiEkle(Sayi* sayi) {
    Dugum* yeniDugum = new Dugum(sayi);

    if (!baslangic) {
        baslangic = yeniDugum;
    } else {
        Dugum* current = baslangic;
        while (current->sonraki) {
            current = current->sonraki;
        }
        current->sonraki = yeniDugum;
    }
}

void SayilarListesi::sayilariGoster() {
    Dugum* current = baslangic;
    while (current) {
        current->sayi->sayiGoster();
        current->sayi->basamaklariGoster();
        cout << " ************************************" << endl;
        current = current->sonraki;
    }
}

void SayilarListesi::menuGoster() {
    cout << "		--- MENU ---" << endl;
    cout << "	1. SAYILARI GOSTER" << endl;
    cout << "	2. TEK RAKAMLARI BASA AL" << endl;
	cout << "	3. BASAMAKLARI TERSLE" << endl;
	cout << "	4. EN BUYUGU CIKAR" << endl;
	cout << "	5. Cikis" << endl;
}

int main() {
    SayilarListesi sayilarListesi;

    ifstream dosya("sayilar.txt");
    int sayi;

    while (dosya >> sayi) {
        sayilarListesi.sayiEkle(new Sayi(sayi));
    }

    while (true) {
        sayilarListesi.menuGoster();
        int secim;
        cout << "	Seciminizi yapin: ";
        cin >> secim;

        switch (secim) {
            case 1:
                sayilarListesi.sayilariGoster();
                break;
  
            case 2:
			cout<<endl<<"		TEK SAYILAR BASA ALINDI"<<endl<<endl;
			sayilarListesi.tekBasamaklilariBasAl();
			break;
			case 3:
			cout<<endl<<"		BASAMAKLAR TERSLENDI"<<endl<<endl;
			sayilarListesi.basamaklariTersCevir();
			break;
			case 4: 
             sayilarListesi.enBuyuguCikar();
				break;
			case 5:
                cout << endl<<"			CIKIS YAPILIYOR..." <<endl<< endl;
                return 0;
            default:
                cout << endl<<"			Gecersiz bir secim yaptiniz. Tekrar deneyin." <<endl<< endl;
                break;
        }
    }

    return 0;
}
