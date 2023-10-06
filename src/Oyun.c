/**
*
* @author Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
* @since 11.05.2023
* <p>
* Oyun.c dosyası
* </p>
*/
#include "Oyun.h"
#include "AUretim.h"
#include "BUretim.h"
#include "ATaktik.h"
#include "BTaktik.h"
#include <Windows.h>

Oyun oyunOlustur(){//oyun structının kurucusu.
    Oyun this;
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->turSayisi=0;
    this->aktifKoloniSayisi=0;

    this->basla=&basla;
    this->kontrol=&kontrol;
    this->kazanan=&kazanan;
    this->yazdir=&yazdir;
    this->yokEt=&OyunYokEt;

    return this;
}

void basla(const Oyun this,int koloniSayisi,Koloni koloniler[]){
    AUretim Auretim = AUretimOlustur();
    BUretim Buretim = BUretimOlustur();
    ATaktik Ataktik = ATaktikOlustur();
    BTaktik Btaktik = BTaktikOlustur();
    this->aktifKoloniSayisi=koloniSayisi;
    yazdir(this,koloniSayisi,koloniler);
    while (1)
    {
        this->turSayisi++;
        //KONTROL
        kontrol(this,koloniSayisi,koloniler);
        //SAVAS
        for (int i = 0; i < koloniSayisi-1; i++)//iç içe for döngüsü ile tüm koloniler savaştırılır.
        {
            kontrol(this,koloniSayisi,koloniler);
            if (koloniler[i]->populasyon!="--")//Koloni hayatta mı kontrolü.
            {
                for (int j = i+1; j < koloniSayisi; j++)
                {
                    kontrol(this,koloniSayisi,koloniler);
                    if (koloniler[j]->populasyon!="--"&&koloniler[i]->populasyon!="--")
                    {
                        if(j%2==0)//taktiklerin rastgele seçilmesi.
                        {
                            Ataktik->super->savas(Ataktik,koloniler[i]);
                            Btaktik->super->savas(Btaktik,koloniler[j]);
                        }
                        else{
                            Ataktik->super->savas(Ataktik,koloniler[j]);
                            Btaktik->super->savas(Btaktik,koloniler[i]);
                        }
                        if(koloniler[i]->savasDegeri>koloniler[j]->savasDegeri)//Kimin puanı yüksekse kazanır. i
                        {
                            this->kazanan(this,koloniler,i,j);
                        }
                        else if(koloniler[i]->savasDegeri<koloniler[j]->savasDegeri) //j
                        {
                            this->kazanan(this,koloniler,j,i);
                        }
                        else if(koloniler[i]->savasDegeri==koloniler[j]->savasDegeri && atoi(koloniler[i]->populasyon)!=atoi(koloniler[j]->populasyon))//Berabere kalma durumunda popülasyona bakılır.
                        {
                            if(atoi(koloniler[i]->populasyon)>atoi(koloniler[j]->populasyon)){ //i
                                this->kazanan(this,koloniler,i,j);
                            }
                            else{ //j
                               this->kazanan(this,koloniler,j,i);
                            }
                        }
                        else//popülasyonlar da eşitse rastgele biri kazanır.
                        {
                            if(koloniler[i]->savasDegeri%2==0){ //i
                                this->kazanan(this,koloniler,i,j);
                            }
                            else{ //j
                                this->kazanan(this,koloniler,j,i);
                            }
                            
                        }
                    }
                }
            }
        }
        
        kontrol(this,koloniSayisi,koloniler);
        //URETİM
        for (int i = 0; i < koloniSayisi; i++)
        {
            if (koloniler[i]->populasyon!="--")
            {
                if(i%2==0){
                    Auretim->super->uret(Auretim,koloniler[i]);
                }
                else{
                    Buretim->super->uret(Buretim,koloniler[i]);
                }
                //TUR SONU
                koloniler[i]->turSonu(koloniler[i]);
            }
        }
        kontrol(this,koloniSayisi,koloniler);
        yazdir(this,koloniSayisi,koloniler);
        if(this->aktifKoloniSayisi<=1) break;
    } 
    Ataktik->yokEt(Ataktik);
    Btaktik->yokEt(Btaktik);
    Auretim->yokEt(Auretim);
    Buretim->yokEt(Buretim);
}

void kontrol(const Oyun this,int koloniSayisi,Koloni koloniler[])//koloninin popülasyonu veya yemek stoğu biterse oyun dışı kalır.
{
    for (int i = 0; i < koloniSayisi; i++)
    {
        if (koloniler[i]->populasyon!="--"){
            if(atoi(koloniler[i]->populasyon) <=0 || atoi(koloniler[i]->yemekStogu) <=0 ){
                koloniler[i]->populasyon="--";
                koloniler[i]->yemekStogu="--";
                koloniler[i]->kazanma="--";
                koloniler[i]->kaybetme="--";
                this->aktifKoloniSayisi--;
            }
        }
           
    }
    
}

void kazanan(const Oyun this,Koloni koloniler[],int i,int j){//Bu sıralamada i kazanan j kaybeden taraf.
    int oran = (koloniler[i]->savasDegeri-koloniler[j]->savasDegeri)/10;
    int yagmalananStok;
    koloniler[j]->populasyonAzalt(koloniler[j],oran);
    yagmalananStok = atoi(koloniler[j]->yemekStogu)*oran/100;
    koloniler[j]->yemekStoguAzalt(koloniler[j],oran);
    koloniler[i]->yemekStoguArttir(koloniler[i],yagmalananStok);
    koloniler[i]->kazan(koloniler[i]);
    koloniler[j]->kaybet(koloniler[j]);
}


void yazdir(const Oyun this,int koloniSayisi,Koloni koloniler[]){
    printf("---------------------------------------------------------------------------------------------\n");
    printf("Tur Sayisi: %d\n",this->turSayisi);
    printf("Sembol  Populasyon  Yemek Stogu  Kazanma  Kaybetme\n");
    for (int i = 0; i < koloniSayisi; i++)
    {
        printf("%3c %10s %12s %9s %8s \n",koloniler[i]->sembol,koloniler[i]->populasyon,koloniler[i]->yemekStogu,koloniler[i]->kazanma,koloniler[i]->kaybetme);
    }
    printf("---------------------------------------------------------------------------------------------\n");
    if(this->aktifKoloniSayisi>1){
        Sleep(100);
        system("cls");
    }
    
   
}



void OyunYokEt(const Oyun this){
    if(this!=NULL) free(this);
}