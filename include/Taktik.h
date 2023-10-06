/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* Taktik.h dosyası
* </p>
*/
#ifndef TAKTIK_H
#define TAKTIK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct TAKTIK
{
   
    void(*savas)();
    void(*yokEt)(struct TAKTIK*);
 

};
typedef struct TAKTIK* Taktik;

Taktik TaktikOlustur();
void TaktikYokEt(const Taktik);





#endif