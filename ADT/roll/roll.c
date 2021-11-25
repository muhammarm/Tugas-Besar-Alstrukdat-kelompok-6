#include<stdio.h>
#include<stdlib.h>
#include "roll.h"

Player CreatePlayer (Player *P){
    scanf("%s", &Nama(*P));
    Posisi(*P)=0;
}
/* I.S. P sembarang   */
/* F.S. Terbentuk player. Lihat definisi di atas. */

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
void langkahMaju(Player *P,int dice){                   // menambahkan nilai pada posisi player sesuai roll dadu
    printf("%s maju %d langkah.\n",Nama(*P), dice);
    Posisi(*P) = Posisi(*P)+dice;
    printf("%s berada di petak %d.\n",Nama(*P), Posisi(*P)+1);
}
void langkahMundur(Player *P,int dice){                 // mengurangkan nilai pada posisi player sesuai roll dadu
    printf("%s mundur %d langkah.\n",Nama(*P), dice);
    Posisi(*P) = Posisi(*P)-dice;
    printf("%s berada di petak %d.\n",Nama(*P), Posisi(*P)+1);
}
int roll(Player *P,char map[100], int minroll, int maxroll){         // memutar dadu dan mendapatkan nilai tertentu di antara 1 dan MaxRoll.
    int dice=getNomor(minroll, maxroll);                            // Lalu, menanyakan pemain untuk memilih antara maju dan mundur.
    printf("%s mendapatkan angka %d\n", Nama(*P), dice); 
    if (map[(Posisi(*P)+dice)]=='.' && map[(Posisi(*P)-dice)]=='.'){
        int kemana;  // pilihan untuk maju atau mundur
        printf("%s dapat maju dan mundur.\n",Nama(*P));
        printf("Ke mana %s mau bergerak:\n",Nama(*P));
        printf("  1.%d\n  2.%d\n", Posisi(*P)-dice+1, Posisi(*P)+dice+1);
        scanf("%d",&kemana);
        if (kemana==1){
            langkahMundur(P,dice);
        }else if(kemana==2){
            langkahMaju(P,dice);
        }else{
            printf("Input salah! ulangi Roll\n");
        }
    }else if(map[(Posisi(*P)+dice)]=='.'){
        printf("%s dapat maju.\n",Nama(*P));
        langkahMaju(P,dice);
    }else if(map[(Posisi(*P)-dice)]=='.'){
        printf("%s dapat mundur.\n",Nama(*P));
        langkahMundur(P,dice);
    }else{
        printf("%s tidak dapat bergerak.\n",Nama(*P));
    }
    return 0;
}

