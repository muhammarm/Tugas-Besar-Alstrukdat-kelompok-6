/*File : adtplayer.h*/
/* ADT player untuk menyimpan informasi-informasi terkait player */

#ifndef ADTPLAYER_H
#define ADTPLAYER_H

#include "boolean.h"
#include <stdlib.h>

#define Nil NULL
#define IdxMax 4
#define IdxMin 1
#define IdxUndef -999

/* Definisi Type Data LinkedList */
typedef struct ListSkillNode *address;
typedef struct ListSkillNode {
    address NextSkill;
    char NamaSkill[30];  /* deklarasi string sepanjang 30 karakter */
} SkillNode;
typedef struct {
    address FirstSkill;
}Skill;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

/*notasi akses*/
#define FIRSTSKILL(p) (p).FirstSkill
#define NEXTSKILL(p) (p)->NextSkill
#define NAMASKILL(p) (p)->NamaSkill

/*player menggunakan implementasi array*/
typedef int ElType;

typedef struct {
    int Neff;
    
}





