

/**
* @file Canli.h
* @description Canli sýnýfýnýn baslik dosyasi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/

#pragma once
#include "stdio.h"
#include "stdlib.h"

struct CANLI
{
    char harf;
    int deger;
    char* (*gorunum)(struct CANLI*);
    void (*delete)(struct CANLI*);
};
typedef struct CANLI* Canli;

Canli new_Canli(char, int);
char turuAl(Canli);
int degeriAl(Canli);
char* gorunum(Canli);
void delete_Canli( Canli);