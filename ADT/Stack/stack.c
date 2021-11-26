/*
    File : stack.c
    Deskripsi : implementasi dari stack.h
*/
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


void CreateEmpty (Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
    Top(*S) = Nil;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return (Top(S) == Nil);
}
boolean IsFullStack (Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (Top(S) == MaxEl);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, Pemain *P){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    if (IsEmptyStack(*S)){
        Top(*S) = 1;
    }
    else {
        Top(*S)++;
    }
    InfoTop(*S) = *P;
    for (int x = 1; x <= (*P).Neff; x++){
        (*S).P[Top(*S)].Skills[x] = Nil;
        copy((*P).Skills[x], &(*S).P[Top(*S)].Skills[x]);
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, Pemain *P, boolean *UndoSukses){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    if(IsEmptyStack(*S)){
        printf("Tidak dapat melakukan undo!\n");
        *UndoSukses = false;
    }
    else{
        *P = InfoTop(*S);
        Top(*S)--;
        *UndoSukses = true;
    }
}
