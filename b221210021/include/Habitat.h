

/**
* @file Habitat.h
* @description Habitat sınıfının baslik dosyasi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/
#pragma once

#include "Canli.h"

struct HABITAT {
    Canli** matris;
    int satir_sayisi;
    int sutun_sayisi;
};

typedef struct HABITAT* Habitat;

Habitat new_Habitat( char* dosyaAdi);
void delete_Habitat(Habitat habitat);
void habitatEkle(Habitat habitat, Canli canli, int satir, int sutun);
void habitatHarfleriYazdir(Habitat habitat);
Canli canliOlustur(int deger,  char* dosyaAdi);
void yeme(Habitat habitat);
