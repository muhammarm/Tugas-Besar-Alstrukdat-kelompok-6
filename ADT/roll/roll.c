#include<stdio.h>
#include<stdlib.h>
#include "roll.h"

int nomor(int maxroll)  //fungsi untuk mendapatkan nomor random sebagai nomor dadu
{
	int nomor;
	A:nomor=rand()%(maxroll+1);
	if(nomor==0)
		goto A;
	else
		return nomor;
}
void langkahMaju(char nama[255],int *posisi,int dice){   // menambahkan nilai pada posisi player sesuai roll dadu
    printf("%s maju %d langkah.\n",nama, dice);
    *posisi = *posisi+dice;
    printf("%s berada di petak %d.\n",nama, *posisi);
}
void langkahMundur(char nama[255],int *posisi,int dice){   // mengurangkan nilai pada posisi player sesuai roll dadu
    printf("%s mundur %d langkah.\n",nama, dice);
    *posisi = *posisi-dice;
    printf("%s berada di petak %d.\n",nama, *posisi);
}
int roll(char nama[255],char map[100], int *posisi, int maxroll){   // memutar dadu dan mendapatkan nilai tertentu di antara 1 dan MaxRoll.
    int dice=nomor(maxroll);                                         // Lalu, menanyakan pemain untuk memilih antara maju dan mundur.
    printf("%s mendapatkan angka %d\n", nama, dice); 
    if (map[(*posisi+dice)]=='.' && map[(*posisi-dice)]=='.'){
        int kemana;  // pilihan untuk maju atau mundur
        printf("%s dapat maju dan mundur.\n",nama);
        printf("Ke mana %s mau bergerak:\n",nama);
        printf("  1.%d\n  2.%d\n", *posisi-dice, *posisi+dice);
        scanf("%d",&kemana);
        if (kemana==1){
            langkahMundur(nama,posisi,dice);
        }else if(kemana==2){
            langkahMaju(nama,posisi,dice);
        }else{
            printf("Input salah! ulangi Roll\n");
        }
    }else if(map[(*posisi+dice)]=='.'){
        printf("%s dapat maju.\n",nama);
        langkahMaju(nama,posisi,dice);
    }else if(map[(*posisi-dice)]=='.'){
        printf("%s dapat mundur.\n",nama);
        langkahMundur(nama,posisi,dice);
    }else{
        printf("%s tidak dapat bergerak.\n",nama);
    }
    return 0;
}

