/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* BTaktik.h dosyası
* </p>
*/
#ifndef BTAKTIK_H
#define BTAKTIK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Taktik.h"
#include "Koloni.h"

struct BTAKTIK
{
    Taktik super;
    void(*yokEt)(struct BTAKTIK*);
 

};
typedef struct BTAKTIK* BTaktik;

BTaktik BTaktikOlustur();
void savas(const BTaktik,Koloni);
void BTaktikYokEt(const BTaktik);





#endif