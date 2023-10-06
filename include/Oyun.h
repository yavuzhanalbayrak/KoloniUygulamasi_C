/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* Oyun.h dosyası
* </p>
*/
#ifndef OYUN_H
#define OYUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Koloni.h"
struct OYUN
{
    int turSayisi;
    int aktifKoloniSayisi;
    
    void(*basla)(struct OYUN*,int,Koloni []);
    void(*kontrol)(struct OYUN*,int,Koloni []);
    void(*kazanan)(struct OYUN*,Koloni [],int,int);
    void(*yazdir)(struct OYUN*,int,Koloni []);
    void(*yokEt)(struct OYUN*);

};
typedef struct OYUN* Oyun;

Oyun oyunOlustur();
void basla(const Oyun,int,Koloni []);
void kontrol(const Oyun,int,Koloni []);
void kazanan(const Oyun,Koloni [],int,int);
void yazdir(const Oyun,int,Koloni []);
void OyunYokEt(const Oyun);





#endif