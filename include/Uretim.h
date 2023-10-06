/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* Uretim.h dosyası
* </p>
*/
#ifndef URETIM_H
#define URETIM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct URETIM
{
   
    void(*uret)();
    void(*yokEt)(struct URETIM*);
 

};
typedef struct URETIM* Uretim;

Uretim uretimOlustur();
void UretimYokEt(const Uretim);





#endif