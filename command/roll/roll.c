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

int roll(Pemain *P,TabPeta M, int minroll, int maxroll, int turn){         // memutar dadu dan mendapatkan nilai tertentu di antara 1 dan MaxRoll.
    int dice=getNomor(minroll, maxroll);                                    // Lalu, menanyakan pemain untuk memilih antara maju dan mundur.
    printf("%s mendapatkan angka %d\n", (*P).NamaPemain[turn], dice); 
    if (M.Peta[(*P).Pos[turn]+dice].Petak=='.' && M.Peta[(*P).Pos[turn]-dice].Petak=='.'){
        int kemana;  // pilihan untuk maju atau mundur
        printf("%s dapat maju dan mundur.\n",(*P).NamaPemain[turn]);
        printf("Ke mana %s mau bergerak:\n",(*P).NamaPemain[turn]);
        printf("  1.%d\n  2.%d\n",(*P).Pos[turn]-dice ,(*P).Pos[turn]+dice);
        scanf("%d",&kemana);
        if (kemana==1){
            langkahPemain(P,(*P).Pos[turn]-dice, turn);
            printf("%s mundur %d langkah.\n",(*P).NamaPemain[turn], dice);
        }else if(kemana==2){
            langkahPemain(P,(*P).Pos[turn]+dice, turn);
            printf("%s maju %d langkah.\n",(*P).NamaPemain[turn], dice);
        }else{
            printf("Input salah! ulangi Roll\n");
        }
    }else if(M.Peta[(*P).Pos[turn]+dice].Petak=='.'){
        printf("%s dapat maju.\n",(*P).NamaPemain[turn]);
        printf("%s maju %d langkah.\n",(*P).NamaPemain[turn], dice);
        langkahPemain(P,(*P).Pos[turn]+dice, turn);
    }else if(M.Peta[(*P).Pos[turn]-dice].Petak=='.'){
        printf("%s dapat mundur.\n",(*P).NamaPemain[turn]);
        printf("%s mundur %d langkah.\n",(*P).NamaPemain[turn], dice);
        langkahPemain(P,(*P).Pos[turn]-dice, turn);
    }else{
        printf("%s tidak dapat bergerak.\n",(*P).NamaPemain[turn]);
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


