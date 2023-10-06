/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* BUretim.h dosyası
* </p>
*/
#ifndef BURETIM_H
#define BURETIM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Uretim.h"
#include "Koloni.h"

struct BURETIM
{
    Uretim super;
    void(*yokEt)(struct BURETIM*);
 

};
typedef struct BURETIM* BUretim;

BUretim BUretimOlustur();
void uret(const BUretim,Koloni);
void BUretimYokEt(const BUretim);





#endif