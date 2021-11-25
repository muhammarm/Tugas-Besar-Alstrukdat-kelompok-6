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
typedef address LSkill;/* List Skill*/
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
    LSkill Skills[IdxMax-IdxMin+1]; /*List Skill*/
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
#define Skills(P) (P).Skills


void CreateEmptyPlayerList(Pemain *P);
/* Membuat List Player yang kosong*/
/* I.S. P terdefinisi
   F.S Sebuah list P berisi pemain terbentuk
*/

void addPlayer (Pemain *P, int n);
/* Prosedur untuk membuat list pemain sebanyak n pemain */
/* I.S array Pemain.NamaPemain, Pemain.Pos, Pemain.IsTeleporter, Pemain.IsImmune, dan Neff berisi 0
   F.S array Pemain.NamaPemain, Pemain.Pos, Pemain.IsTeleporter, Pemain.IsImmune, dan Neff terisi sebanyak n buah
*/

int GetPemainIdx(Pemain P, char *SearchNama);
/* Mereturn index pemain dalam array NamaPemain sebagai parameter input.
   Apabila input tidak terdapat di dalam list NamaPemain, maka akan mereturn IdxUndef
*/

int GetPosisiPemain(Pemain P, char *NamaPemain);
/*
 mendapatkan informasi mengenai  mengenai posisi pemain berdasarkan parameter NamaPemain
*/

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



#endif



