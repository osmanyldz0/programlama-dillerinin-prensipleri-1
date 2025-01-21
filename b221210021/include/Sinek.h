

/**
* @file Sinek.h
* @description Sinek sýnýfýnýn baslik dosyasi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/
#pragma once
#include "Bocek.h"

struct SINEK {

	Bocek  super;
	void (*yoket)(struct SINEK*);





};
typedef struct SINEK* Sinek;

Sinek new_Sinek(int );
void delete_Sinek( Sinek);

 
