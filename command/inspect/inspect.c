/* File :inspect.c */
/* Deskripsi : Command ini akan meminta suatu petak X, lalu melihat apakah ada teleporter di suatu petak X.*/

#include "inspect.h"
#include <stdio.h>
#include <stdlib.h>


boolean IsPetakEmpty (TabPeta P, int CekPetak) 
/* Mengirimkan true/mengecek jika petak kosong("."), mengirimkan false jika tidak */
/* pemain hanya dapet berdiri di petak kosong */
{
    /* ALGORITMA */
    return (GetPetakInfo(P, CekPetak) == '.');
}

boolean IsPetakForbidden (TabPeta P, int CekPetak) 
/* Mengirimkan true/mengecek jika petak terlarang ('#'), mengirimkan false jika tidak */
{
    /* ALGORITMA */
    return (GetPetakInfo(P, CekPetak) == '#');
}

void inspect (TabPeta P)
/* Peta dari file config terbaca */
/* meminta suatu petak X, lalu melihat apakah ada teleporter di suatu petak X */
{
    /* KAMUS LOKAL */
    int PetakX;
    /* ALGORITMA */
    printf("Masukkan petak: ");
    scanf("%d", &PetakX);
    if (IsPetakEmpty(P, PetakX))
    {
        if (GetPetakTP(P, PetakX) == NoTP)
        {
            printf("Petak %d merupakan petak kosong.\n", PetakX);
        }
        else
        {
            printf("Petak %d memiliki teleporter menuju %d.\n", PetakX, GetPetakTP(P, PetakX));
        }
    }
    else
    {
        printf("Petak %d merupakan petak terlarang.\n", PetakX);
    }
    printf("\n");
}


