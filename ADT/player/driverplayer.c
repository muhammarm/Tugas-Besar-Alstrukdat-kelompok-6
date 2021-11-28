#include <stdio.h>
#include "adtplayer.h"

int main(){
    /*deklarasi*/
    Pemain P;
    int n;

    createEmptyPemainList(&P);
    printf("Masukkan Jumlah Pemain : ");
    scanf("%d", &n);
    printf("\nmasukkan salah satu username untuk mengecek\n");
    AddPemain(&P, n); /*  Username "Will" untuk tes */
    printf("index pemain : %d\n", GetIdxPemain(P, "Will"));
    printf("Apakah pemain teleported ? : %d\n", IsPemainTeleported(P, "Will"));
    printf("Apakah pemain memiliki senter pengecil ? : %d\n", IsPemainSenterPengecil(P, "Will"));
    printf("Apakah pemain memiliki senter pembesar? : %d\n", IsPemainSenterPembesar(P, "Will"));
    printf("Apakah pemain memiliki cermin pengganda? : %d\n", IsPemainCerminPengganda(P, "Will"));
    printf("Apakah pemain sedang imun? : %d\n", IsPemainImmune(P, "Will"));
    printf("pemain ada di posisi berapa ? : %d\n", GetPosisiPemain(P, "Will"));
    printf("\nPeringkat Pemain : \n");
    PeringkatPemain(&P);
}

