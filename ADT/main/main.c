/* File : main.c*/
/* berisi program utama untuk menjalankan permainan*/

#include "mesin_kar.h"
#include "mesin_kata.h"
#include "arraypeta.h"
#include "roll.h"
#include "adtplayer.h" /*untuk adt player*/
#include "listdp.h" /*untuk adt skill*/
#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    /*Kamus*/
    int JumlahPemain, maxroll;
    Pemain P; /*dari adt player*/
    TabPeta Peta;/*dari arraypeta*/
    Stack S;
    char filepath[] = "../../config/";
    char filename[100];


    /*START GAME*/
    /*meminta jumlah pemain*/
    boolean JumlahInvalid = false ;
    while(!JumlahInvalid)
    {
        printf("Masukkan jumlah pemain game: ") ;
        scanf("%d", &JumlahPemain) ;
        if (JumlahPemain < 2 || JumlahPemain > 4)
        {
            printf("Jumlah pemain game tidak sesuai dengan ketentuan. Silahkan masukkan kembali jumlah pemain game.\n");
        }
        else
        {
            JumlahInvalid=true;
        }
    }
    printf("\n");
    
    /*Membuat list player kosong*/
    CreateEmptyPemainList(&P);
    /*membuat list pemain sebanyak "JumlahPemain"*/
    AddPemain(&P,JumlahPemain);
    printf("\n");

    /*Program Membaca Map dari File konfigurasi*/
    scanf("%s", &filename);
    strncat(filepath, filename, 100);
    ReadMap (&P,filepath);
    maxroll = ReadMaxroll(filepath);

    /*Membuat Stack kosong*/
    CreateEmpty(&S);
    

}