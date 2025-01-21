 
/**
* @file Pire.h
* @description Pire sýnýfýnýn baslik dosyasi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/
#pragma once
#include "Bocek.h"

struct PIRE {

	Bocek  super;
	void (*yoket)(struct PIRE*);





};
typedef struct PIRE* Pire;

Pire new_Pire(int );
void delete_Pire( Pire);

 