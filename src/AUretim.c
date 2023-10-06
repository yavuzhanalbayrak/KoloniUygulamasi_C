/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* AUretim.c dosyası
* </p>
*/
#include"AUretim.h"

AUretim AUretimOlustur(){
    AUretim this;
    this = (AUretim)malloc(sizeof(struct AURETIM));
    this->super = uretimOlustur();

    this->super->uret=&Uret;
    this->yokEt=&AUretimYokEt;
    return this;
}

void Uret(const AUretim this, Koloni koloni){
    int uretilen = rand() % 10 + 1;
    int yeniStok=atoi(koloni->yemekStogu)+uretilen;
    sprintf(koloni->yemekStogu,"%d",yeniStok);
    
}

void AUretimYokEt(const AUretim this){
    if(this==NULL) return;
    this->super->yokEt(this->super);
    free(this);
}