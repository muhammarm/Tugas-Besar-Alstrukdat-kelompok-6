/*modifikasi dari array.h */
#ifndef ARRAYPETA_H
#define ARRAYPETA_H

#include "boolean.h"
#include "mesin_kar.h"
#include "mesin_kata.h"

#define IdxMinPetak 1
#define IdxMaxPetak 100


/*Peta pada permainan ini terdiri dari petak-petak yang digambarkan dengan character “.” (titik, menunjukkan petak kosong) dan “#” (tagar, menunjukkan petak terlarang).*/
/* Pemain hanya dapat berdiri di petak kosong. Petak pertama dan petak terakhir dijamin berupa petak kosong.Peta dibaca melalui file konfigurasi.*/

typedef char Petak; /*Petak merupakan character*/

typedef struct {
        Petak Peta[IdxMaxPetak-IdxMinPetak+1+1]; /* memori tempat penyimpan elemen pada peta(container), peta meurpakan array of character */
} TabPeta;

void MakeEmptyMap (TabPeta *P);
/* Menghasilkan tabel peta P kosong dengan kapasitas (IdxMaxPetak-IdxMinPetak+1) */

void PosisiPemain(TabPeta P, int PosisiPemain, int PanjangPeta);
/*menampilkan posisi pemain pada peta*/

boolean IsPetakEmpty (TabPeta P,int MarkPetak); /* mark petak == petak yang ditandai */
/* Mengirimkan true jika petak kosong("."), mengirimkan false jika tidak */

boolean IsPetakForbidden(TabPeta P,int MarkPetak); /* mark petak == petak yang ditandai */
/* Mengirimkan true jika petak terlarang ('#'),mengirimkan false jika tidak*/

#endif