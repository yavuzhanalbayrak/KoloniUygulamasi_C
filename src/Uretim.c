/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* Uretim.c dosyası
* </p>
*/
#include"Uretim.h"

Uretim uretimOlustur(){
    Uretim this;
    this = (Uretim)malloc(sizeof(struct URETIM));
    srand(time(NULL));
    
    this->yokEt=&UretimYokEt;
    
    return this;
}

void UretimYokEt(const Uretim this){
    if(this!=NULL) free(this);
}