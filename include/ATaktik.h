/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* ATaktik.h dosyası
* </p>
*/
#ifndef ATAKTIK_H
#define ATAKTIK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Taktik.h"
#include "Koloni.h"

struct ATAKTIK
{
    Taktik super;
    void(*yokEt)(struct ATAKTIK*);
 

};
typedef struct ATAKTIK* ATaktik;

ATaktik ATaktikOlustur();
void Savas(const ATaktik,Koloni);
void ATaktikYokEt(const ATaktik);





#endif