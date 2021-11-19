
/* File: mesinkata.c */
/* Implementasi Mesin Kata */

#include <stdio.h>
#include "mesin_kata.h"
#include "mesin_kar.h"


boolean EndKata;
Kata CKata;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
   /*algoritma*/
   while (CC==BLANK)
    {
     ADV();
    }
}

void SalinKata(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    /*Kamus Lokal */
    int i;
    /*Algoritma*/
    i=1;
    while((CC!=MARK) && (CC != BLANK))

    {
        CKata.TabKata[i]=CC;
        ADV();
        i++;
    }
    CKata.Length = i-1;
}

void STARTKATA(){
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
          /*algoritma*/
          START();
          IgnoreBlank();
          if (CC==MARK) {
            EndKata=true;
          }
          else /*CC!=MARK*/{
            EndKata=false;
            SalinKata();
          }
}

void ADVKATA(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
   /*algoritma*/
   IgnoreBlank();
   if (CC==MARK) {
    EndKata=true;
   }
    else {
        SalinKata();
    }
}




