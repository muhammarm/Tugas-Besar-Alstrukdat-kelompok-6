/* File arraypeta.h*/
/* ADT Array Peta yang digunakan pada permainan, 
   merupakan modifikasi dari ADT Array pada array.h */

#ifndef ARRAYPETA_H
#define ARRAYPETA_H

#include "../Boolean/boolean.h"
#include "../Mesin_Karakter/mesin_kar.h"
#include "../Mesin_Kata/mesin_kata.h"

#define IdxMinPetak 1
#define IdxMaxPetak 100
#define NoTP -1


/* Peta pada permainan terdiri dari petak-petak yang digambarkan dengan char '.' yang menunjukkan petak kosong 
   dan '#' yang menunjukkan petak terlarang.*/
/* Pemain hanya dapat berada di posisi petak kosong, tidak bisa di petak terlarang,
   Petak pertama dan terakhir dijamin petak kosong */
/* Informasi peta dan petak di dalamnya dibaca dari file konfigurasi */

/* Struct Petak */
typedef struct {
        char Petak; /* Jenis petak, bisa petak kosong (.) atau petak terlarang (#) */
        int TP; /* Indeks tujuan teleporter dari Petak, apabila tidak ada teleporter bernilai NoTP */
} InfoPetak;

/* Struct Peta */
typedef struct {
        InfoPetak Peta[IdxMaxPetak-IdxMinPetak+1+1]; /* Tempat penyimpanan petak, Peta adalah array of InfoPetak */
        int Neff; /* Banyaknya elemen array Peta yang dipakai, atau banyaknya petak pada peta */
} TabPeta;


/* Konstruktor */
void MakeEmptyMap (TabPeta *P);
/* I.S. : P Sembarang
   F.S. : Terbentuk TabPeta P kosong dengan Neff = 0 
          dan setiap petak diset '?' serta tanpa teleporter */

/* Pengisian TabPeta */
void ReadMap (TabPeta *P, char Filepath[255]);
/* I.S. : P Sembarang
   F.S. : Terbentuk TabPeta P sesuai dengan data peta 
          dan teleporter pada file konfigurasi */

/* Operasi Lainnya */
void PosisiPemain(TabPeta P, int PosisiPemain);
/* I.S. : P dan PosisiPemain Terdefinisi
   F.S. : Posisi pemain pada peta ditampilkan ke layar dengan tanda '*'
          serta menampilkan PosisiPemain */

int GetPetakTP (TabPeta P, int ElmtPetak);
/* Mengembalikan integer indeks tujuan teleport
   dari petak berindeks ElmtPetak pada TabPeta P */

char GetPetakInfo (TabPeta P, int ElmtPetak);
/* Mengembalikan char petak ('.' atau '#')
   dari petak berindeks ElmtPetak pada TabPeta P */

#endif