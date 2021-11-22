/* File :inspect.h  header*/
/* for inspect.c*/

#ifndef INSPECT_H
#define INSPECT_H
#include "boolean.h"
#include "arraypeta.h"


boolean IsPetakEmpty (TabPeta P,int CekPetak); 
/* Mengirimkan true jika petak kosong("."), mengirimkan false jika tidak */


boolean IsPetakForbidden(TabPeta P,int CekPetak); 
/* Mengirimkan true jika petak terlarang ('#'),mengirimkan false jika tidak*/


void inspect(TabPeta *P);
/* Peta dari file config terbaca*/
/* meminta suatu petak X, lalu melihat apakah ada teleporter di suatu petak X*/
    

#endif


