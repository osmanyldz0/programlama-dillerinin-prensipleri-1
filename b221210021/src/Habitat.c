
/**
* @file Habitat.c
* @description habitat s�n�f� yazildi
* @course 1-C
* @assignment 2
* @date 11.05.2024 son duzenlenme tarihi
* @author osman yildiz osman.yildiz2@ogr.sakarya.edu.tr
*/



#include "Habitat.h"
#include <stdio.h>
#include "Bitki.h"
#include "Sinek.h"
#include "Bocek.h"
#include "Pire.h"
#include <stdlib.h>

Habitat new_Habitat(char* dosyaAdi) {
    FILE* dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya a��lamad�.\n");
        return NULL;
    }

    // Dosyan�n ka� sat�r ve ka� s�tun oldu�unu bulma
    int satirSayisi = 0;
    int sutunSayisi = 0;
    int sayi;

    while (fscanf(dosya, "%d", &sayi) == 1) {
        sutunSayisi++;
        char c = getc(dosya);
        if (c == '\n') {
            satirSayisi++;
        }
    }

    // Dosyay� tekrar ba�a al
    fseek(dosya, 0, SEEK_SET);

    // Habitat olu�turma
    Habitat this = (Habitat)malloc(sizeof(struct HABITAT));
    this->satir_sayisi = satirSayisi + 1;
    this->sutun_sayisi = sutunSayisi / satirSayisi - 1;

    // Matris olu�turma
    this->matris = (Canli**)malloc(this->satir_sayisi * sizeof(Canli*));
    for (int i = 0; i < this->satir_sayisi; ++i) {
        this->matris[i] = (Canli*)malloc(this->sutun_sayisi * sizeof(Canli));
    }

    // Verileri okuyarak habitat� doldurma
    int satir = 0;
    int sutun = 0;

    while (fscanf(dosya, "%d", &sayi) == 1) {
        if (satir < this->satir_sayisi && sutun < this->sutun_sayisi) {
            Canli yeni_canli = canliOlustur(sayi, dosyaAdi);
            habitatEkle(this, yeni_canli, satir, sutun);
        }

        sutun++;
        if (sutun == this->sutun_sayisi) {
            sutun = 0;
            satir++;
        }
    }

    fclose(dosya);

    return this;
}

void delete_Habitat(Habitat habitat) {
    if (habitat == NULL) return;

    // Matrisi silme
    for (int i = 0; i < habitat->satir_sayisi; ++i) {
        free(habitat->matris[i]);
    }
    free(habitat->matris);

    free(habitat);
}

void habitatEkle(Habitat habitat, Canli canli, int satir, int sutun) {
    if (habitat == NULL || satir < 0 || satir >= habitat->satir_sayisi || sutun < 0 || sutun >= habitat->sutun_sayisi) {
        printf("Ge�ersiz konum!\n");
        return;
    }

    habitat->matris[satir][sutun] = canli;
}

//harleri ekrana yaz
void habitatHarfleriYazdir(Habitat habitat) {
    if (habitat == NULL) {
        printf("Habitat bulunamad�.\n");
        return;
    }

    printf(" \n");
    for (int i = 0; i < habitat->satir_sayisi; ++i) {
        for (int j = 0; j < habitat->sutun_sayisi; ++j) {
            Canli canli = habitat->matris[i][j];
            if (canli != NULL) {
                printf(" %c", canli->harf);
            }
            else {
                printf("[ ]");
            }
        }
        printf("\n");
    }
}

//canli olu�turma
Canli canliOlustur(int deger, char* dosyaAdi) {
    if (deger >= 1 && deger <= 9) {
        Bitki b;
        b = new_Bitki(deger);
        return  b->super;
    }
    else if (deger >= 10 && deger <= 20) {
        Bocek c;
        c = new_Bocek(deger);
        return c->super;
    }
    else if (deger >= 21 && deger <= 50) {
        Sinek s;
        s = new_Sinek(deger);
        return s->super->super;
    }
    else if (deger >= 51 && deger <= 99) {
        Pire p;
        p = new_Pire(deger);
        return p->super->super;
    }
    else {
        printf("Ge�ersiz veri: %d\n", deger);
        return NULL;
    }
}

//yeme fonksiyonu
void yeme(Habitat habitat) {
    int satir_sayisi = habitat->satir_sayisi;
    int sutun_sayisi = habitat->sutun_sayisi;

    Canli kazanan;
    kazanan = habitat->matris[0][0];
    int konumX = 0;
    int konumY = 0;

    // Yeme i�lemleri

    printf("\nislemi baslatmak icin bir tusa basiniz...");
    getchar();

    for (int i = 0; i < satir_sayisi; ++i) {
        for (int j = 0; j < sutun_sayisi; ++j) {
            if (i == 0 && j == 0)
                continue;
            if (habitat->matris[i][j] != NULL) {
                if (habitat->matris[i][j]->harf == 'C') {
                    if (kazanan->harf == 'P' || kazanan->harf == 'B') {
                        kazanan->harf = 'X';
                        kazanan->delete;
                        kazanan = habitat->matris[i][j];
                        konumX = i;
                        konumY = j;
                        habitatHarfleriYazdir(habitat);
                        system("cls");
                        printf("\n");
                        continue;
                    }
                    else if (kazanan->harf == 'S') {
                        habitat->matris[i][j]->harf = 'X';
                        habitat->matris[i][j]->delete;
                        habitatHarfleriYazdir(habitat);
                        system("cls");
                        printf("\n");
                        continue;
                    }
                    else if (kazanan->harf == 'C') {
                        if (kazanan->deger > habitat->matris[i][j]->deger) {
                            habitat->matris[i][j]->harf = 'X';
                            habitat->matris[i][j]->delete;
                            habitatHarfleriYazdir(habitat);
                            system("cls");
                            printf("\n");
                            continue;
                        }
                        else if (kazanan->deger == habitat->matris[i][j]->deger) {
                            kazanan->harf = 'X';
                            kazanan->delete;
                            kazanan = habitat->matris[i][j];
                            konumX = i;
                            konumY = j;
                            habitatHarfleriYazdir(habitat);
                            system("cls");
                            printf("\n");
                            continue;
                        }
                        else if (kazanan->deger < habitat->matris[i][j]->deger) {
                            kazanan->harf = 'X';
                            kazanan->delete;
                            kazanan = habitat->matris[i][j];
                            konumX = i;
                            konumY = j;
                            habitatHarfleriYazdir(habitat);
                            system("cls");
                            printf("\n");
                            continue;
                        }
                    }
                }
                else if (habitat->matris[i][j]->harf == 'S') {
                    if (kazanan->harf == 'P' || kazanan->harf == 'C') {
                        kazanan->harf = 'X';
                        kazanan->delete;
                        kazanan = habitat->matris[i][j];
                        konumX = i;
                        konumY = j;
                        habitatHarfleriYazdir(habitat);
                        system("cls");
                        printf("\n");
                        continue;
                    }
                    else if (kazanan->harf == 'B') {
                        habitat->matris[i][j]->harf = 'X';
                        habitat->matris[i][j]->delete;
                        habitatHarfleriYazdir(habitat);
                        system("cls");
                        printf("\n");
                        continue;
                    }
                    if (kazanan->harf == 'S') {
                        system("cls");
                        if (kazanan->deger > habitat->matris[i][j]->deger) {
                            kazanan->harf = 'X';
                            kazanan->delete;
                            kazanan = habitat->matris[i][j];
                            konumX = i;
                            konumY = j;
                            habitatHarfleriYazdir(habitat);
                            system("cls");
                            printf("\n");
                            continue;
                        }
                        else if (kazanan->deger < habitat->matris[i][j]->deger) {
                            kazanan->harf = 'X';
                            kazanan->delete;
                            kazanan = habitat->matris[i][j];
                            konumX = i;
                            konumY = j;
                            habitatHarfleriYazdir(habitat);
                            system("cls");
                            printf("\n");
                            continue;
                        }
                        else if (kazanan->deger == habitat->matris[i][j]->deger) {
                            kazanan->harf = 'X';
                            kazanan->delete;
                            kazanan = habitat->matris[i][j];
                            konumX = i;
                            konumY = j;
                            habitatHarfleriYazdir(habitat);
                            system("cls");
                            printf("\n");
                            continue;
                        }
                    }
                }
                else if (habitat->matris[i][j]->harf == 'B') {
                    if (kazanan->harf == 'P' || kazanan->harf == 'S') {
                        kazanan->harf = 'X';
                        kazanan->delete;
                        kazanan = habitat->matris[i][j];
                        konumX = i;
                        konumY = j;
                        habitatHarfleriYazdir(habitat);
                        system("cls");
                        printf("\n");
                        continue;
                    }
                    else if (kazanan->harf == 'C') {
                        habitat->matris[i][j]->harf = 'X';
                        habitat->matris[i][j]->delete;
                        habitatHarfleriYazdir(habitat);
                        system("cls");
                        printf("\n");
                        continue;
                    }
                    else if (kazanan->harf == 'B') {
                        if (kazanan->deger > habitat->matris[i][j]->deger) {
                            habitat->matris[i][j]->harf = 'X';
                            habitat->matris[i][j]->delete;
                            habitatHarfleriYazdir(habitat);
                            system("cls");
                            printf("\n");
                            continue;
                        }
                        else if (kazanan->deger < habitat->matris[i][j]->deger) {
                            kazanan->harf = 'X';
                            kazanan->delete;
                            kazanan = habitat->matris[i][j];
                            konumX = i;
                            konumY = j;
                            habitatHarfleriYazdir(habitat);
                            system("cls");
                            printf("\n");
                            continue;
                        }
                        else if (kazanan->deger == habitat->matris[i][j]->deger) {
                            kazanan->harf = 'X';
                            kazanan->delete;
                            kazanan = habitat->matris[i][j];
                            konumX = i;
                            konumY = j;
                            habitatHarfleriYazdir(habitat);
                            system("cls");
                            printf("\n");
                            continue;
                        }
                    }
                }
                else if (habitat->matris[i][j]->harf == 'P') {
                    if (kazanan->harf == 'C' || kazanan->harf == 'B' || kazanan->harf == 'S') {
                        habitat->matris[i][j]->harf = 'X';
                        habitat->matris[i][j]->delete;
                        habitatHarfleriYazdir(habitat);
                        system("cls");
                        printf("\n");
                        continue;
                    }
                    else if (kazanan->harf == 'P') {
                        if (kazanan->deger > habitat->matris[i][j]->deger) {
                            habitat->matris[i][j]->harf = 'X';
                            habitat->matris[i][j]->delete;
                            habitatHarfleriYazdir(habitat);
                            system("cls");
                            printf("\n");
                            continue;
                        }
                        else if (kazanan->deger == habitat->matris[i][j]->deger) {
                            kazanan->harf = 'X';
                            kazanan->delete;
                            kazanan = habitat->matris[i][j];
                            konumX = i;
                            konumY = j;
                            habitatHarfleriYazdir(habitat);
                            system("cls");
                            printf("\n");
                            continue;
                        }
                        else if (kazanan->deger < habitat->matris[i][j]->deger) {
                            kazanan->harf = 'X';
                            kazanan->delete;
                            kazanan = habitat->matris[i][j];
                            konumX = i;
                            konumY = j;
                            habitatHarfleriYazdir(habitat);
                            system("cls");
                            printf("\n");
                            continue;
                        }
                    }
                }
            }
        }
    }
    habitatHarfleriYazdir(habitat);
    printf("\n Kazanan: %c : (%d,%d)\n\n", kazanan->harf, konumX, konumY);
    delete_Habitat(habitat);
}
