/* File arraypeta.c*/
/* Implementasi arraypeta.h */

#include <stdio.h>
#include <stdlib.h>
#include "arraypeta.h"

/* Konstruktor */
void MakeEmptyMap (TabPeta *P)
/* I.S. : P Sembarang
   F.S. : Terbentuk TabPeta P kosong dengan Neff = 0 
          dan setiap petak diset '?' serta tanpa teleporter */
{
    /* ALGORITMA */
    (*P).Neff = 0;
    for (int i = 0;i <= IdxMaxPetak;i++)
    {
        (*P).Peta[i].Petak = '?';
        (*P).Peta[i].TP = NoTP;
    }
}

/* Pengisian TabPeta */
void ReadMap (TabPeta *P, char Filepath[255])
/* I.S. : P Sembarang
   F.S. : Terbentuk TabPeta P sesuai dengan data peta 
          dan teleporter pada file konfigurasi */
{
    /* KAMUS LOKAL */
    int nbtele, Elmtpetak;
    /* ALGORITMA */
    MakeEmptyMap(&(*P));
    STARTKATA(Filepath);
    (*P).Neff = KataToInt(CKata);
    ADVKATA();
    for (int i = 1;i <= (*P).Neff;i++){
        (*P).Peta[i].Petak = CKata.TabKata[i];
    }
    ADVKATA();
    ADVKATA();
    nbtele = KataToInt(CKata);
    for (int i = 1;i <= nbtele;i++){
        ADVKATA();
        Elmtpetak = KataToInt(CKata);
        ADVKATA();
        (*P).Peta[Elmtpetak].TP = KataToInt(CKata);
    }
}

/* Operasi Lainnya */
void PosisiPemain (TabPeta P, int PosisiPemain) 
/* I.S. : P dan PosisiPemain Terdefinisi
   F.S. : Posisi pemain pada peta ditampilkan ke layar dengan tanda '*'
          serta menampilkan PosisiPemain */
{
    /* ALGORITMA */
    for(int i = 1;i <= P.Neff;i++){
        if (i == PosisiPemain){
            printf("%c",'*');
        }
        else{
            printf("%c",P.Peta[i].Petak);
        }
    }
    printf(" %d", PosisiPemain);
}

int GetPetakTP (TabPeta P, int ElmtPetak)
/* Mengembalikan integer indeks tujuan teleport
   dari petak berindeks ElmtPetak pada TabPeta P */
{
    return (P.Peta[ElmtPetak].TP);
}

char GetPetakInfo (TabPeta P, int ElmtPetak)
/* Mengembalikan char petak ('.' atau '#')
   dari petak berindeks ElmtPetak pada TabPeta P */
{
    return (P.Peta[ElmtPetak].Petak);
}

