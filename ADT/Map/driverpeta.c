/* File driverpeta.c  */
/* File driver untuk testing implementasi arraypeta.h  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../Boolean/boolean.h"
#include "arraypeta.h"

TabPeta Map;
int posisi;

int main(){
    char configpath[] = "..\\..\\config\\";
    char filename[100];
    char filepath[255];

    strcpy(filepath, configpath);
    printf("Masukkan nama file konfigurasi : ");
    scanf("%s", &filename);
    strncat(filepath, filename, 100);
    while (!CheckIfFileExists(filepath)){
        printf("File %s tidak ada, mohon ulangi.\n", filename);
        strcpy(filepath, configpath);
        printf("Masukkan nama file konfigurasi : ");
        scanf("%s", &filename);
        strncat(filepath, filename, 100);
    }
    ReadMap(&Map, filepath);

    for (int i = 1;i <= Map.Neff;i++){
        printf("Petak ke-%d\n", i);
        printf("Info Petak  : %c\n", GetPetakInfo(Map, i));
        printf("Teleport Ke : %d\n", GetPetakTP(Map, i));
        printf("\n");
    }

    scanf("%d", &posisi);
    PosisiPemain(Map, posisi);

    return 0;
}
