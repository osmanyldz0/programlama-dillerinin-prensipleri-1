
/**
* @file Pire.c
* @description Pire sýnýfý yazildi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/

#include "Pire.h"

Pire new_Pire(int deger) {
	Pire this;

	this = (Pire)malloc(sizeof(struct PIRE));
	this->super = new_Bocek(  deger);

	this->super-> yoket = &delete_Bocek;
	this->super->super->harf = 'P';


	return this;


}
void delete_Pire(const Pire this) {

	if (this == NULL) return

		free(this);


}


