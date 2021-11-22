/* File :inspect.c */
/* Deskripsi : Command ini akan meminta suatu petak X, lalu melihat apakah ada teleporter di suatu petak X.*/

#include "inspect.h"
#include <stdio.h>
#include <stdlib.h>


boolean IsPetakEmpty (TabPeta P, int CekPetak) 
/* Mengirimkan true/mengecek jika petak kosong("."), mengirimkan false jika tidak */
/*pemain hanya dapet berdiri di petak kosong*/
/*ALGORITMA*/
{
   return (P.Peta[CekPetak].Petak == '.');
}

boolean IsPetakForbidden (TabPeta P, int CekPetak) 
/* Mengirimkan true/mengecek jika petak terlarang ('#'),mengirimkan false jika tidak*/
/*ALGORITMA*/
{
    return (P.Peta[CekPetak].Petak == '#');
}

void inspect(TabPeta *P)
/* Peta dari file config terbaca*/
/* meminta suatu petak X, lalu melihat apakah ada teleporter di suatu petak X*/
/*KAMUS LOKAL */
int PetakX;
/*ALGORITMA*/
{
    printf("Masukkan petak: ");
    scanf("%d", &PetakX);
    if ( IsPetakForbidden (*P,PetakX))
    {
        printf("Petak %d merupakan petak terlarang.\n",PetakX);
    }
    else if (IsPetakEmpty(*P,PetakX))
    {
        printf("Petak %d merupakan petak kosong.\n",PetakX);
    }
    else /* fungsi teleporter*/
    {   
       printf("Petak %d memiliki teleporter menuju %d.\n",PetakX,(*P).Peta[PetakX].TP); /*TP indeks tujuan teleporter*/
    }

}

