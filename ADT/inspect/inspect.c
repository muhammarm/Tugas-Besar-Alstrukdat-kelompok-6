/* File :inspect.c */
/* Deskripsi : Command ini akan meminta suatu petak X, lalu melihat apakah ada teleporter di suatu petak X.*/

#include "inspect.h"
#include <stdio.h>
#include <stdlib.h>

void inspect(TabPeta *P)
/* Peta dari file config terbaca*/
/* meminta suatu petak X, lalu melihat apakah ada teleporter di suatu petak X*/
/*KAMUS LOKAL */
int petak;
/*ALGORITMA*/
{
    printf("Masukkan petak: ");
    scanf("%d", &petak);
    if ( IsPetakForbidden (*P,petak))
    {
        printf("Petak %d merupakan petak terlarang.\n",petak);
    }
    else if (IsPetakEmpty(*P,petak))
    {
        printf("Petak %d merupakan petak kosong.\n",petak);
    }
    else /* fungsi teleporter*/
    {   
       printf("Petak %d memiliki teleporter menuju %d.\n",petak); /* perlu petak teleporter*/
    }

}

