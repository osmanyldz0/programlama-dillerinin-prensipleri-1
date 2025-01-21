 
/**
* @file Bocek.h
* @description Bocek sýnýfýnýn baslik dosyasi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/
#pragma once
#include "Canli.h"

struct BOCEK {

	Canli super;
	void (*yoket)(struct BOCEK*);





};
typedef struct BOCEK* Bocek;

Bocek new_Bocek(int );
void delete_Bocek( Bocek);

 
