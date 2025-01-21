

/**
* @file Bitki.h
* @description Bitki sýnýfýnýn baslik dosyasi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/

#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI {
    Canli super;
    void (*yoket)(struct BITKI*);
};

typedef struct BITKI* Bitki;

Bitki new_Bitki(int);
void delete_Bitki(Bitki);

#endif
