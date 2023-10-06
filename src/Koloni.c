/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* Koloni.c dosyası
* </p>
*/
#include"Koloni.h"

Koloni koloniOlustur(char sembol,char* populasyon, char* yemekStogu,char* kazanma,char* kaybetme){//kişi structının kurucusu.
    Koloni this;
    this = (Koloni)malloc(sizeof(struct KOLONI));
    this->savasDegeri=0;
    this->sembol=sembol;
    this->populasyon=populasyon;
    this->yemekStogu=yemekStogu;
    this->kazanma=kazanma;
    this->kaybetme=kaybetme;
    
    this->turSonu=&turSonu;
    this->populasyonAzalt=&populasyonAzalt;
    this->yemekStoguArttir=&yemekStoguArttir;
    this->yemekStoguAzalt=&yemekStoguAzalt;
    this->kazan=&kazan;
    this->kaybet=&kaybet;
    this->yokEt=&KoloniYokEt;

    return this;
}

void turSonu(const Koloni this){//populasyon arttı, yemek stoğu azaldı.
    sprintf(this->yemekStogu,"%d",atoi(this->yemekStogu)-atoi(this->populasyon)*2);
    sprintf(this->populasyon,"%d",atoi(this->populasyon)+atoi(this->populasyon)*20/100);
}
void populasyonAzalt(const Koloni this,int oran){
    int azalma=atof(this->populasyon)-atof(this->populasyon)*oran/100;
    sprintf(this->populasyon,"%d",azalma);
}
void yemekStoguAzalt(const Koloni this,int oran){
    int azalma=atof(this->yemekStogu)-atof(this->yemekStogu)*oran/100;
    sprintf(this->yemekStogu,"%d",azalma);
}
void yemekStoguArttir(const Koloni this,int yagmalanan){
    sprintf(this->yemekStogu,"%d",atoi(this->yemekStogu)+yagmalanan);
}
void kazan(const Koloni this){
    sprintf(this->kazanma,"%d",atoi(this->kazanma)+1);
}
void kaybet(const Koloni this){
    sprintf(this->kaybetme,"%d",atoi(this->kaybetme)+1);
}
void KoloniYokEt(const Koloni this){
    if(this!=NULL) free(this);
}