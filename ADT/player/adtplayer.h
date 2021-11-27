/*File : adtplayer.h*/
/* ADT player untuk menyimpan informasi-informasi terkait player */

#ifndef ADTPLAYER_H
#define ADTPLAYER_H

#include "../Boolean/boolean.h"
#include <stdlib.h>

/*Kamus Umum*/
#define Nil NULL
#define IdxMax 5
#define IdxMin 1
#define IdxUndef -999

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
    boolean IsDoneRoll[IdxMax-IdxMin+1]; /*Player sudah melakukan roll*/
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
#define IsDoneRoll(P) (P).IsDoneRoll
#define Skills(P) (P).Skills

/* Definisi Type Data LinkedList */
typedef struct ListSkillNode *address;
typedef address LSkill;/* List Skill*/
typedef struct ListSkillNode {
    address NextSkill;
    char NamaSkill[25];  /* deklarasi string sepanjang 25 karakter */
    int ids;
    void (*buff)(Pemain *, int);
} SkillNode;

/*notasi akses(linked list)*/
#define ids(P) (P)->ids
#define NextSkill(P) (P)->NextSkill
#define NamaSkill(P) (P)->NamaSkill
#define buff(P) (P)->buff

void CreateEmptyPemainList(Pemain *P);
/* Membuat List Player yang kosong*/
/* I.S. P terdefinisi
   F.S Sebuah list P berisi pemain terbentuk
*/

void AddPemain (Pemain *P, int n);
/* Prosedur untuk membuat list pemain sebanyak n pemain */
/* I.S array Pemain.NamaPemain, Pemain.Pos, Pemain.IsTeleporter, Pemain.IsImmune, dan Neff berisi 0
   F.S array Pemain.NamaPemain, Pemain.Pos, Pemain.IsTeleporter, Pemain.IsImmune, dan Neff terisi sebanyak n buah
*/

int GetIdxPemain(Pemain P, char *Nama);
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



