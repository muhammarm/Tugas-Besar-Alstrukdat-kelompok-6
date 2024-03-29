/* File : roll.h */
/* for roll.c*/
#ifndef ROLL_H
#define ROLL_H

#include "../../ADT/Map/arraypeta.h"
#include "../../ADT/player/adtplayer.h"
#include <time.h>
#include <math.h>

/****************** PRIMITIF BERDASARKAN NILAI ******************/

void langkahPemain(Pemain *P,int dice, int turn); 
/* I.S. P terdefinisi
   F.S. mengurangkan/menambahkan nilai pada posisi player dengan roll dadu agar player menjadi mundur pada map
*/
/****************** PROSES SEMUA ELEMEN PLAYER ******************/
int roll(Pemain *P,TabPeta *M, int maxroll, int turn); 
// fungsi untuk memutar dadu dan mendapatkan nilai tertentu di antara 1 dan MaxRoll.
// Lalu, menanyakan pemain untuk memilih antara maju dan mundur.
int ReadMaxroll (char Filepath[255]);
/* I.S. : Sembarang
   F.S. : Mengembalikan integer MaxRoll pada file config */

#endif