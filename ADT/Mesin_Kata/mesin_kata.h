/* File mesin_kata.h */
/* Definisi Mesin Kata yang telah dimodifikasi */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../Boolean/boolean.h"
#include "../Mesin_Karakter/mesin_kar.h"

#define NMax 50
#define BLANK ' '
#define EOL '\n'

typedef struct {
  char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlankEOL();
/* Mengabaikan satu atau beberapa BLANK dan EOL
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK dan CC ≠ EOL */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK, CC = EOL, atau EOP;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi. */

void STARTKATA(char Filepath[255]);
/* I.S. : CC sembarang, Filepath terdefinisi
   F.S. : CC = MARK, CC = EOL, atau EOP
          CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

int KataToInt(Kata kata);
/* Mengembalikan nilai integer hasil konversi dari string */

#endif
