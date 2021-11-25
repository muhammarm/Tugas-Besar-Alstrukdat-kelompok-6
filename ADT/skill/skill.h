#ifndef skill_H
#define skill_H

#include "boolean.h"
#include "adtplayer.h"

#define Nil NULL

boolean isEmpty(LSkill skill);

address createSkillNode();

void createEmpty(LSkill *skill);

int NbElmt(LSkill skill);

void insSkill(LSkill *skill, address S);

address search(LSkill *skill, int urutan);

int percentage(int x);

int random(int x);

void getSkill(Pemain *P, int curr, int num);

void delSkill(LSkill *skill, int urutan);

void useSkill(Pemain *P, LSkill *skill, int urutan, int curr);

void printOne(LSkill *skill, int urutan);

void printAll (Pemain *P, int curr);

void pintuGakManaMana(Pemain *P, int curr);

void mirror(Pemain *P, int curr);

void senterPembesar(Pemain *P, int curr);

void senterPengecil(Pemain *P, int curr);

void mesinPenukar(Pemain *P, int curr);

void makeSkill(address S, int idx);

void copy(LSkill awal, LSkill *copy);

#endif