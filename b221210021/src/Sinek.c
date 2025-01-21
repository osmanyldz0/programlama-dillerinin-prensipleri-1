

/**
* @file Sinek.c
* @description Sinek sýnýfý yazildi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/

#include "Sinek.h"

Sinek new_Sinek(int deger)
{
	Sinek this;

	this = (Sinek)malloc(sizeof(struct SINEK));
	this->super = new_Bocek(  deger);

	this->super->yoket = &delete_Bocek;
	this->super->super->harf = 'S';


	return this;


}
void delete_Sinek( Sinek this) {

	if (this == NULL) return

		free(this);

}