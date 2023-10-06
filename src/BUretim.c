/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* BUretim.c dosyası
* </p>
*/
#include"BUretim.h"

BUretim BUretimOlustur(){
    BUretim this;
    this = (BUretim)malloc(sizeof(struct BURETIM));
    this->super = uretimOlustur();

    this->super->uret=&uret;
    this->yokEt=&BUretimYokEt;
    return this;
}

void uret(const BUretim this, Koloni koloni){
    int uretilen = rand() % 10 + 1;
    int yeniStok=atoi(koloni->yemekStogu)+uretilen;
    sprintf(koloni->yemekStogu,"%d",yeniStok);
    
}

void BUretimYokEt(const BUretim this){
    if(this==NULL) return;
    this->super->yokEt(this->super);
    free(this);
}