#include<stdio.h>
#include<stdlib.h>
#include "roll.h"
#include "arraypeta.h"
#include "adtplayer.h"


int getNomor(int minroll, int maxroll)  //fungsi untuk mendapatkan nomor random sebagai nomor dadu
{
	int nomor;
    srand(time(0));
	A:nomor = minroll + rand() / (RAND_MAX / (maxroll - minroll + 1) + 1);
	if(nomor==0)
		goto A;
	else
		return nomor;
}
void langkahPemain(Pemain *P,int dice, int turn){                   // menambahkan nilai pada posisi player sesuai roll dadu
    (*P).Pos[turn] = dice;
    printf("%s berada di petak %d.\n",(*P).NamaPemain[turn], (*P).Pos[turn]);
}

int roll(Pemain *P,TabPeta M, int maxroll, int turn){         // memutar dadu dan mendapatkan nilai tertentu di antara 1 dan MaxRoll.
    int dice;
    boolean move = false;
    if((*P).IsSenterPembesar[turn]){
        dice = getNomor(floor(maxroll/2),maxroll);
    }else if((*P).IsSenterPengecil[turn]){
        dice = getNomor(1,floor(maxroll/2));
    }else{
        dice = getNomor(1,maxroll);
    }                                
    printf("%s mendapatkan angka %d\n", (*P).NamaPemain[turn], dice); 
    if (M.Peta[(*P).Pos[turn]+dice].Petak=='.' && M.Peta[(*P).Pos[turn]-dice].Petak=='.'){
        int kemana;  // pilihan untuk maju atau mundur
        printf("%s dapat maju dan mundur.\n",(*P).NamaPemain[turn]);
        printf("Ke mana %s mau bergerak:\n",(*P).NamaPemain[turn]);
        printf("  1.%d\n  2.%d\n",(*P).Pos[turn]-dice ,(*P).Pos[turn]+dice);
        scanf("%d",&kemana);
        if (kemana==1){
            printf("%s mundur %d langkah.\n",(*P).NamaPemain[turn], dice);
            langkahPemain(P,(*P).Pos[turn]-dice, turn);
            move = true;
        }else if(kemana==2){
            printf("%s maju %d langkah.\n",(*P).NamaPemain[turn], dice);
            langkahPemain(P,(*P).Pos[turn]+dice, turn);
            move= true;
        }else{
            printf("Input salah! ulangi Roll\n");
        }
    }else if(M.Peta[(*P).Pos[turn]+dice].Petak=='.'){
        printf("%s dapat maju.\n",(*P).NamaPemain[turn]);
        printf("%s maju %d langkah.\n",(*P).NamaPemain[turn], dice);
        langkahPemain(P,(*P).Pos[turn]+dice, turn);
        move = true;
    }else if(M.Peta[(*P).Pos[turn]-dice].Petak=='.'){
        printf("%s dapat mundur.\n",(*P).NamaPemain[turn]);
        printf("%s mundur %d langkah.\n",(*P).NamaPemain[turn], dice);
        langkahPemain(P,(*P).Pos[turn]-dice, turn);
        move = true;
    }else{
        printf("%s tidak dapat bergerak.\n",(*P).NamaPemain[turn]);
    }
    if (move){
        if (M.Peta[(*P).Pos[turn]].TP == -1) {
            printf("%s tidak menemukan teleporter.\n", (*P).NamaPemain[turn]);
        }else{
            printf("%s menemukan teleporter.\n", (*P).NamaPemain[turn]);
            if ((*P).IsImmune[turn]){
                printf("%s memiliki imunitas teleport.\n", (*P).NamaPemain[turn]);
                printf("Apakah %s ingin teleport (Y/N)? ", (*P).NamaPemain[turn]);
                boolean televalid = false;
                char asktele;
                while (!televalid) {
                    scanf("%c", &asktele);
                    if (asktele == 'Y') {
                        (*P).Pos[turn] = M.Peta[(*P).Pos[turn]].TP;
                        printf("%s teleport ke petak %d.\n", (*P).NamaPemain[turn], (*P).Pos[turn]);
                        televalid = true ;
                    }else if (asktele == 'N') {
                        printf("%s tidak teleport.\n", (*P).NamaPemain[turn]);
                        (*P).IsImmune[turn] = false ;
                        printf("Buff imunitas teleport hilang.\n") ;
                        televalid = true ;
                    }else {
                        printf("Input Salah! Masukkan Y/N.\n") ;
                    }
                }
            }else{
                printf("%s tidak memiliki imunitas teleport.\n", (*P).NamaPemain[turn]) ;
                (*P).Pos[turn] = M.Peta[(*P).Pos[turn]].TP;
                printf("%s teleport ke petak %d.\n", (*P).NamaPemain[turn], (*P).Pos[turn]) ;
            }
        }
        (*P).IsDoneRoll[turn] = true ;
        printf("\n") ;
    }else{
        printf("Tidak dapat melakukan roll 2 kali dalam 1 turn.\n\n");
    }
    return 0;
}
int ReadMaxroll (char Filepath[255]){          // Mengembalikan integer MaxRoll pada file config 
    int maxroll;
    STARTKATA(Filepath);
    ADVKATA();
    ADVKATA();
    maxroll = KataToInt(CKata);
    return maxroll;
}


