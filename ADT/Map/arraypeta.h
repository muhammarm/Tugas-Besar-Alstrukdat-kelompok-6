/*arraypeta merupakan modifikasi dari array.h */
/*File:arraypeta.h*/
#ifndef ARRAYPETA_H
#define ARRAYPETA_H

#include "boolean.h"
#include "mesin_kar.h"
#include "mesin_kata.h"

#define IdxMinPetak 1
#define IdxMaxPetak 100
#define NoTP -1


/*Peta pada permainan ini terdiri dari petak-petak yang digambarkan dengan character “.” (titik, menunjukkan petak kosong) dan “#” (tagar, menunjukkan petak terlarang).*/
/* Pemain hanya dapat berdiri di petak kosong. Petak pertama dan petak terakhir dijamin berupa petak kosong.Peta dibaca melalui file konfigurasi.*/

typedef struct {
        char Petak; /* Jenis petak, bisa petak kosong (.) atau petak terlarang (#) */
        int TP; /* Indeks tujuan teleporter dari Petak, apabila tidak ada teleporter bernilai NoTP */
} InfoPetak;

typedef struct {
        InfoPetak Peta[IdxMaxPetak-IdxMinPetak+1+1]; /* memori tempat penyimpan elemen pada peta(container), peta merupakan array of character */
        int Neff; /* Banyaknya elemen array Petak yang dipakai */
} TabPeta;

void MakeEmptyMap (TabPeta *P);
/* Menghasilkan tabel peta P kosong dengan kapasitas (IdxMaxPetak-IdxMinPetak+1) */

void ReadMap (TabPeta *P);
/* Menghasilkan tabel peta P sesuai dengan peta pada file konfigurasi */

void PosisiPemain(TabPeta P, int PosisiPemain, int PanjangPeta);
/*menampilkan posisi pemain pada peta*/

boolean IsPetakEmpty (TabPeta P,int CekPetak); 
/* Mengirimkan true jika petak kosong("."), mengirimkan false jika tidak */

boolean IsPetakForbidden(TabPeta P,int CekPetak); 
/* Mengirimkan true jika petak terlarang ('#'),mengirimkan false jika tidak*/

#endif