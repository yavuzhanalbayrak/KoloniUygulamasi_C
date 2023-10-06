/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* Koloni.h dosyası
* </p>
*/
#ifndef KOLONI_H
#define KOLONI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct KOLONI
{
    int savasDegeri;
    char sembol;
    char* populasyon;
    char* yemekStogu;
    char* kazanma;
    char* kaybetme;
    void(*populasyonAzalt)(struct KOLONI*,int);
    void(*turSonu)(struct KOLONI*);
    void(*yemekStoguAzalt)(struct KOLONI*,int);
    void(*yemekStoguArttir)(struct KOLONI*,int);
    void(*kazan)(struct KOLONI*);
    void(*kaybet)(struct KOLONI*);
    void(*yokEt)(struct KOLONI*);

};
typedef struct KOLONI* Koloni;

Koloni koloniOlustur(char,char*,char*,char*,char*);
void populasyonAzalt(const Koloni,int);
void turSonu(const Koloni);
void yemekStoguAzalt(const Koloni,int);
void yemekStoguArttir(const Koloni,int);
void kazan(const Koloni);
void kaybet(const Koloni);
void KoloniYokEt(const Koloni);





#endif