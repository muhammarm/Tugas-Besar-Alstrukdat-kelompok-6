/* File driverpeta.c  */
/* File driver untuk testing implementasi arraypeta.h  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Boolean/boolean.h"
#include "arraypeta.h"

TabPeta Map;
char filename[100];
int posisi;

int main(){
    char filepath[] = "../../config/";
    scanf("%s", &filename);
    strncat(filepath, filename, 100);

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
