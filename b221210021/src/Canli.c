

/**
* @file Canli.c
* @description Canli sýnýfý yazildi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/
#include "Canli.h"

Canli new_Canli(char harf, int deger) {
    Canli this = (Canli)malloc(sizeof(struct CANLI));
    if (this == NULL) {
        printf("Bellek ayrýlamadý!\n");
        return NULL;
    }
    this->deger = deger;
    this->harf = harf;
    this->gorunum = &gorunum;
    this->delete = &delete_Canli;
    return this;
}

char* gorunum(Canli canli) {

    char* str = (char*)malloc(sizeof(char) * 2);
    str[0] = canli->harf;
    str[1] = '\0';
    return str;
    
}

char turuAl( Canli this) {
    return this->harf;
}

int degeriAl( Canli this) {
    return this->deger;
}

void delete_Canli( Canli this) {
    if (this == NULL) return;
    free(this);
}
