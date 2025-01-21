

/**
* @file Bitki.c
* @description Bitki sýnýfý yazildi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/
#include "Bitki.h"

Bitki new_Bitki(int deger) {
    Bitki this;

    this = (Bitki)malloc(sizeof(struct BITKI));
    if (this == NULL) {
        printf("Bellek ayrýlamadý!\n");
        return NULL;
    }

    this->super = new_Canli('B', deger);
    this->super->delete = &delete_Canli;
    
    return this;
}

void delete_Bitki(Bitki this) {
    if (this == NULL) return;

    free(this);
}
