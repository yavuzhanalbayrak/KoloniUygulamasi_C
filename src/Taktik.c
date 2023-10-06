/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* Taktik.c dosyası
* </p>
*/
#include"Taktik.h"

Taktik TaktikOlustur(){
    Taktik this;
    this = (Taktik)malloc(sizeof(struct TAKTIK));
    srand(time(NULL));
    
    this->yokEt=&TaktikYokEt;
    
    return this;
}

void TaktikYokEt(const Taktik this){
    if(this!=NULL) free(this);
}