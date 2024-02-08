/**
* @file basamak.h
* @description  basamak sinifinin nesnelerini birbirine baglar ve sonraki basamagi da gösteriren isaretciyi olusturur.
* @course 2.öğretim A grubu
* @assignment 1.Ödev
* @date 25 KASIM 2023
* @author Ayşe Verda Gülcemal ayseeverda@gmail.com
*/



#ifndef BASAMAK_H
#define BASAMAK_H

class Basamak {
public:
    int deger;
    Basamak* sonraki;

    Basamak(int deger);
};

#endif
