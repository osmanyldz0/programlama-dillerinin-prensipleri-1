

/**
* @file Test.c
* @description main fonskiyonu yazildi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/

#include "Habitat.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	 
	 
	Habitat habitat = new_Habitat("Veri.txt");

	 
	habitatHarfleriYazdir(habitat);
 
	yeme(habitat);

	delete_Habitat(habitat);
 
	return 0;



}
