/**
* @file sayi.h
* @description  sayi sinifini,sayiyi temsil eden basamak bagli listesini ve mainde kullanilan bazi fonksiyonlari icerir.
* @course 2.öğretim A grubu
* @assignment 1.Ödev
* @date 25 KASIM 2023
* @author Ayşe Verda Gülcemal ayseeverda@gmail.com
*/


#ifndef SAYI_H
#define SAYI_H

#include "basamak.h"

class Sayi {
public:
    Basamak* baslangic;

    Sayi(int sayi);
    void sayiGoster();
    void basamaklariGoster();
};

#endif
