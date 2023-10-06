/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* Test.c dosyası
* </p>
*/
#include <stdio.h>
#include <stdlib.h>
#include "Koloni.h"
#include "AUretim.h"
#include "BUretim.h"
#include "ATaktik.h"
#include "BTaktik.h"
#include "Oyun.h"

#define MevcutKapasite 1
#define BuyumeCarpani 2

int main() {
    Koloni *koloniler = NULL;
    int kapasite = MevcutKapasite;
    int koloniSayisi = 0;
    int sayi;
    char girdi;
    Oyun oyun = oyunOlustur();
    koloniler = (Koloni *) malloc(kapasite * sizeof(Koloni));

    if (koloniler == NULL) {
        printf("Bellek hatasi.\n");
        return 0;
    }
    
    printf("Sayilari girin:\n");
    
 
   
    while (1) {
        if (koloniSayisi == kapasite) {//Dizi dolarsa kapasitesi arttırılır.
            kapasite *= BuyumeCarpani;
            koloniler = (Koloni *) realloc(koloniler, kapasite * sizeof(Koloni));
            
            if (koloniler == NULL) {
                printf("Bellek hatasi.\n");
                return 0;
            }
        }
        girdi = getchar();
        if (girdi == '\n') {
            break;
        }
        ungetc(girdi, stdin);
        scanf("%d", &sayi);
        
        char *str1;
        char str2[50];
        char str3[10];
        char str4[10];
        sprintf(str1, "%d", sayi);
        sprintf(str2, "%d", sayi*sayi);
        sprintf(str3, "%d", 0);
        sprintf(str4, "%d", 0);
        char *populasyon = malloc(strlen(str1) + 1);
        char *yemekStok = malloc(strlen(str2) + 1);
        char *kazanma = malloc(strlen(str3) + 1);
        char *kaybetme = malloc(strlen(str4) + 1);
        strcpy(populasyon, str1);
        strcpy(yemekStok, str2);
        strcpy(kazanma, str3);
        strcpy(kaybetme, str4);

        //Random bir karakter ve ekran girdileri ile koloniler oluşturulup dinamik diziye eklenir.
        koloniler[koloniSayisi++] = koloniOlustur(rand()%255,populasyon,yemekStok,kazanma,kaybetme);
        
    }
    oyun->basla(oyun,koloniSayisi,koloniler);
    oyun->yokEt(oyun);
    for (sayi = 0; sayi < koloniSayisi; sayi++)
    {
        koloniler[sayi]->yokEt(koloniler[sayi]);
    }
    
    free(koloniler);
    
    return 0;
}
