


/**
* @file Bocek.c
* @description Bocek sýnýfý yazildi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/

#include "Bocek.h"

Bocek new_Bocek( int deger) {
	Bocek this;

	this = (Bocek)malloc(sizeof(struct BOCEK));
	this->super = new_Canli('C', deger);
	

	this->super->delete = &delete_Canli;



	return this;


}
void delete_Bocek( Bocek this) {
	if (this == NULL) return;

	free(this);


}