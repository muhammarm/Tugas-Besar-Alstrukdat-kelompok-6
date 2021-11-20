/* *** ABSTRACT DATA TYPE ARRAYPETA *** */

#include "arraypeta.h"
#include <stdio.h>
#include <stdlib.h>

void MakeEmptyMap (TabPeta *P)
/* Menghasilkan tabel peta P kosong dengan kapasitas (IdxMaxPetak-IdxMinPetak+1+1) */
/*Tabel Peta di set dengan default char '?'*/
{
    for (int i=0;i<=IdxMaxPetak;i++)
    {
        *P.Peta[i]='?'
    }
}

void PosisiPemain(TabPeta P, int PosisiPemain, int PanjangPeta) 
/*LengthPeta merupakan panjang peta dibaca melalui file konfigurasi*/
/*menampilkan state peta dan posisi pemain pada peta*/
/* posisi pemain digambarkan menggunakan '*' (bintang)*/
{
    for(int i=1;i<=PanjangPeta;i++)
    {
        if(i==PosisiPemain)
        {
            printf("%c",'*');
        }else /*menulis petak selanjutnya*/
        {
            printf("%c",P.Peta[i]);
        }
    }
    printf("%d",PosisiPemain);
}

boolean IsPetakEmpty (TabPeta P,int CekPetak) 
/* Mengirimkan true/mengecek jika petak kosong("."), mengirimkan false jika tidak */
/*pemain hanya dapet berdiri di petak kosong*/
{
   return(P.Peta[CekPetak]=='.');
}

boolean IsPetakForbidden(TabPeta P,int CekPetak) 
/* Mengirimkan true/mengecek jika petak terlarang ('#'),mengirimkan false jika tidak*/
{
    return(P.Peta[CekPetak]=='#');
}