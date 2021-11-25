/* File : roll.h */
/* for roll.c*/
#ifndef roll_H
#define roll_H

#include "boolean.h"

/* Definisi Type Data */
typedef struct {
     /* memori tempat penyimpan elemen pada player, player berisi nama dengan array of character dan bilangan posisi pada map */
    char Nama[255];
    int Posisi;
} Player;

/* Definisi player : */
/* Awal player : Posisi(P) = 0 dan mempunyai Nama(P) dari input user */

/* Notasi Akses */
#define Nama(P) ((P).Nama)
#define Posisi(P) ((P).Posisi)

/****************** PEMBUATAN PLAYER ******************/
Player CreatePlayer (Player *P);
/* I.S. P sembarang   */
/* F.S. Terbentuk player. Lihat definisi di atas. */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
int getNomor(int minroll, int maxroll);  
//fungsi untuk mendapatkan nomor random sebagai nomor dadu
void langkahMaju(Player *P,int dice);  
/* I.S. P terdefinisi
   F.S. menambahkan nilai pada posisi player dengan roll dadu agar player menjadi maju pada map
*/
void langkahMundur(Player *P,int dice); 
/* I.S. P terdefinisi
   F.S. mengurangkan nilai pada posisi player dengan roll dadu agar player menjadi mundur pada map
*/

/****************** PROSES SEMUA ELEMEN PLAYER ******************/
int roll(Player *P,char map[100], int minroll, int maxroll); 
// fungsi untuk memutar dadu dan mendapatkan nilai tertentu di antara 1 dan MaxRoll.
// Lalu, menanyakan pemain untuk memilih antara maju dan mundur.
#endif