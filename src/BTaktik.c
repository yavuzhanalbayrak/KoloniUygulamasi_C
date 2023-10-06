/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* BTaktik.c dosyası
* </p>
*/
#include"BTaktik.h"

BTaktik BTaktikOlustur(){
    BTaktik this;
    this = (BTaktik)malloc(sizeof(struct BTAKTIK));
    this->super = TaktikOlustur();

    this->super->savas=&savas;
    this->yokEt=&BTaktikYokEt;
    return this;
}

void savas(const BTaktik this, Koloni koloni){
    int uretilen = rand() % 1000;
    koloni->savasDegeri=uretilen;
    
}

void BTaktikYokEt(const BTaktik this){
    if(this==NULL) return;
    this->super->yokEt(this->super);
    free(this);
}