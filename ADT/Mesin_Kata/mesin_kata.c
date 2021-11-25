/* File mesin_kata.c */
/* Implementasi Mesin Kata yang telah dimodifikasi */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mesin_kata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlankEOL()
/* Mengabaikan satu atau beberapa BLANK dan EOL
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK dan CC ≠ EOL */
{
   /* ALGORITMA */
    while ((CC==BLANK || CC==EOL) && !EOP){
       ADV();
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK, CC = EOL, atau EOP;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi. */
{
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 1;
    while((CC!=EOL) && (CC != BLANK) && !EOP){
       CKata.TabKata[i]=CC;
       ADV();
       i++;
    }
    CKata.Length = i-1;
}

void STARTKATA(char Filepath[255])
/* I.S. : CC sembarang, Filepath terdefinisi
   F.S. : CC = MARK, CC = EOL, atau EOP
          CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    /* ALGORITMA */
    START(Filepath);
    IgnoreBlankEOL();
    if (EOP){
       EndKata = true;
    }
    else{
       EndKata = false;
       SalinKata();
    }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
   /* ALGORITMA */
   IgnoreBlankEOL();
   if (EOP){
      EndKata = true;
   }
   else{
      SalinKata();
      IgnoreBlankEOL();
   }
}

int KataToInt(Kata kata)
/* Mengembalikan nilai integer hasil konversi dari string */
{
   /* ALGORITMA */
   int sum = 0;
   for (int i = 1;i <= kata.Length;i++){
      sum = sum + ((kata.TabKata[i]-48) * pow(10, (kata.Length-i)));
   }
   return sum;
}


