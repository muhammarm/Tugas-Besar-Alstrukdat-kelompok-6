#ifndef skill_H
#define skill_H

#include "../Boolean/boolean.h"
#include "../player/adtplayer.h"
#include <time.h>


boolean isEmpty(LSkill skill);
//mereturn true apabila skill = Nil

AddrSkill createSkillNode();
//mereturn AddrSkill hasil alokasi skill

void createEmpty(LSkill *skill);
//I.S.: *skill = sembarang
//F.S.: *skill = Nil

int NbElmt(LSkill skill);
//mereturn jumlah skill yang ada di dalam skill

void insSkill(LSkill *skill, AddrSkill S);
//menambahkan skill dengan AddrSkill S ke LSkill

AddrSkill search(LSkill *skill, int urutan);
//Mencari apakah ada elemen list yang sama dengan urutan pada skill
//apabila ada, mengirimkan AddrSkill elemen tersebut
//apabila tidak, mengirimkan nilai Nil

int percentage(int x);
//mereturn sebuah nilai hasil dari random

int random(int x);
//mengembalikan ids sesuai hasil dari percentage

void getSkill(Pemain *P, int curr, int num);
//menambahkan 1 skill secara random pada LSkill Pemain yang sedang bermain

void delSkill(LSkill *skill, int urutan);
//membuang skill sesuai urutan pada sebuah Pemain

void useSkill(Pemain *P, LSkill *skill, int urutan, int curr);
//menggunakan buff dari sebuah skill yang dipilih

void printOne(LSkill *skill, int urutan);
//menampilkan skill sesuai urutan

void printAll (Pemain *P, int curr);
//menampilkan semua skill yang dimiliki Pemain

void pintuGakManaMana(Pemain *P, int curr);
//Pemain mendapatkan buff immune

void mirror(Pemain *P, int curr);
//Pemain mendapat 2 skill random 

void senterPembesar(Pemain *P, int curr);
//Roll akan menghasilkan angka antara floor(maxroll/2) dan maxroll

void senterPengecil(Pemain *P, int curr);
//Roll akan menghasilkan angka antara 1 dan floor(maxroll/2)

void mesinPenukar(Pemain *P, int curr);
//Pemain dapat menukar posisi dengan target Pemain yang dipilih

void makeSkill(AddrSkill S, int idx);
//Mengisi atribut dari skill sesuai ids yang diinput

void copy(LSkill awal, LSkill *copy);
//

#endif