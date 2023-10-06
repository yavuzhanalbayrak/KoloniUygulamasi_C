/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* ATaktik.c dosyası
* </p>
*/
#include"ATaktik.h"

ATaktik ATaktikOlustur(){
    ATaktik this;
    this = (ATaktik)malloc(sizeof(struct ATAKTIK));
    this->super = TaktikOlustur();

    this->super->savas=&Savas;
    this->yokEt=&ATaktikYokEt;
    return this;
}

void Savas(const ATaktik this, Koloni koloni){
    int uretilen = rand() % 1000;
    koloni->savasDegeri=uretilen;
    
}

void ATaktikYokEt(const ATaktik this){
    if(this==NULL) return;
    this->super->yokEt(this->super);
    free(this);
}