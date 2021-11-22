/*File : adtplayer.h*/
/* ADT player untuk menyimpan informasi-informasi terkait player */

#ifndef ADTPLAYER_H
#define ADTPLAYER_H

#include "boolean.h"
#include <stdlib.h>

/*Kamus Umum*/
#define Nil NULL
#define IdxMax 5
#define IdxMin 1
#define IdxUndef -999

/* Definisi Type Data LinkedList */
typedef struct ListSkillNode *address;
typedef struct ListSkillNode {
    address NextSkill;
    char NamaSkill[25];  /* deklarasi string sepanjang 25 karakter */
} SkillNode;
typedef struct {
    address FirstSkill;
}Skill;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

/*notasi akses(linked list)*/
#define FIRSTSKILL(P) (P).FirstSkill
#define NEXTSKILL(P) (P)->NextSkill
#define NAMASKILL(P) (P)->NamaSkill

/*Data player menggunakan implementasi array*/
typedef int ElType;

typedef struct 
{
    int Neff;
    char NamaPemain[IdxMax-IdxMin+1][16];
    ElType Pos[IdxMax - IdxMin +1];
    boolean IsTeleporter[IdxMax - IdxMin +1];
    boolean IsImmune[IdxMax - IdxMin +1];
    boolean IsMirror[IdxMax - IdxMin +1];
    boolean IsSenterPengecil[IdxMax - IdxMin+1];
    boolean IsSenterPembesar[IdxMax - IdxMin +1];
    boolean IsMesinPenukarPos[IdxMax-IdxMin+1];
    boolean IsTeknologiFail[IdxMax-IdxMin+1];
} Pemain;

/*Selektor(array)*/
#define Neff(P) (P).Neff
#define NamaPemain(P) (P).NamaPemain
#define Pos(P) (P).Pos
#define IsTeleporter(P) (P).IsTeleporter
#define IsImmune(P) (P).IsImmune
#define IsMirror(P) (P).IsMirror
#define IsSenterPengecil(P) (P).IsSenterPengecil
#define IsSenterPembesar(P) (P).IsSenterPembesar
#define IsMesinPenukarPos(P) (P).IsMesinPenukarPos
#define IsTeknologiFail(P) (P).IsTeknologiFail



void CreateEmptyPlayerList(Pemain *P);
/* Membuat List Player yang kosong*/

boolean IsPemainTeleported(Pemain P, char *NamaPemain);
/* Menghasilkan True jika pemain dengan parameter NamaPemain terkena portal atau sebaliknya*/

boolean IsPemainImmune(Pemain P, char *NamaPemain);
/*Menghasilkan True jika pemain dengan parameter NamaPemain sedang imun(buff) atau sebaliknya*/

boolean IsPemainSenterPengecil(Pemain P,char *NamaPemain);
/* Menghasilkan True jika pemain dengan parameter NamaPemain memakai senter pengecil atau sebaliknya*/

boolean IsPemainSenterPembesar(Pemain P, char *NamaPemain);
/*Menghasilkan True jika pemain dengan parameter NamaPemain memakai senter pembesar atau sebaliknya*/

boolean IsPemainCerminPengganda(Pemain P,char *NamaPemain);
/*Menghasilkan True jika pemain dengan parameter NamaPemain memakai cermin pengganda atau sebaliknya*/


 




