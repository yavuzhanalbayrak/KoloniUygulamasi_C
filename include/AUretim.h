/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* AUretim.h dosyası
* </p>
*/
#ifndef AURETIM_H
#define AURETIM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Uretim.h"
#include "Koloni.h"

struct AURETIM
{
    Uretim super;
    void(*yokEt)(struct AURETIM*);
 

};
typedef struct AURETIM* AUretim;

AUretim AUretimOlustur();
void Uret(const AUretim,Koloni);
void AUretimYokEt(const AUretim);





#endif