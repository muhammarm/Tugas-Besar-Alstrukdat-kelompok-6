/* File : roll.h */
/* for roll.c*/
#ifndef roll_H
#define roll_H

#include "boolean.h"
int nomor(int maxroll);  
//fungsi untuk mendapatkan nomor random sebagai nomor dadu
void langkahMaju(char nama[255],int *posisi,int dice);  
// menambahkan nilai pada posisi player sesuai roll dadu
void langkahMundur(char nama[255],int *posisi,int dice); 
// mengurangkan nilai pada posisi player sesuai roll dadu
int roll(char nama[255],char map[100], int *posisi, int maxroll); 
// fungsi untuk memutar dadu dan mendapatkan nilai tertentu di antara 1 dan MaxRoll.
// Lalu, menanyakan pemain untuk memilih antara maju dan mundur.
#endif