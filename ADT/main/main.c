/* File : main.c*/
/* berisi program utama untuk menjalankan permainan ular tangga*/

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
    int JumlahPemain;
    Pemain P; /*dari adt player*/
    TabPeta PetaGame;/*dari arraypeta*/


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
    
    /*Membuat list pemain kosong*/
    CreateEmptyPemainList(&P);
    /*membuat list pemain sebanyak "JumlahPemain"*/
    AddPemain(&P,JumlahPemain);
    printf("\n");

    /*Program Membaca Map dari File konfigurasi*/
    int maxroll;
    char configpath[] =  "..\\..\\config\\";
    char filename[100];
    char filepath[255];

    strcpy(filepath, configpath);
    printf("Masukkan nama file konfigurasi : ");
    scanf("%s", &filename);
    strncat(filepath, filename, 100);
    while (!CheckIfFileExists(filepath))
    {
        printf("File %s tidak ada, mohon ulangi.\n", filename);
        strcpy(filepath, configpath);
        printf("Masukkan nama file konfigurasi : ");
        scanf("%s", &filename);
        strncat(filepath, filename, 100);
    }
    ReadMap(&PetaGame, filepath);
    maxroll = ReadMaxroll(filepath);

    /*Membuat Stack kosong*/
    Stack S;
    CreateEmpty(&S);
    

    /*Game akan terus looping hingga ada pemain yang menang*/
    boolean GameBerakhir=false;
    boolean EndRonde=false;
    int JumlahRonde = 1;

    Push(&S,&P);
    while (!GameBerakhir)
    {
        int x =1;
        EndRonde=false;
        printf("-- Ronde ke-%d --\n\n", JumlahRonde);

        /*Setiap pemain mendapatkan turn pada sebuah ronde*/
        while (!EndRonde && x <= JumlahPemain)
        {
            printf("-- Giliran %s --\n\n", (P).NamaPemain[x]) ;
            draw(&P,x,0);

            /*Menuliskan Peta di awal giliran*/
            for(int TulisPemain=1;TulisPemain<=(P).Neff;TulisPemain++)
            {/*loop untuk menuliskan nama pemain*/
                printf("%s\t", (P).NamaPemain[TulisPemain]) ;
                printf(" : ");
                for(int TulisPetak=1 ; TulisPetak<=PetaGame.Neff;TulisPetak++)
                {/*loop untuk menampilkan state peta dengan posisi pemain digambarkan dengan "*" */
                    if((P).Pos[TulisPemain]==TulisPetak)
                    {
                        printf("*");
                    }
                    else
                    {
                        printf("%c", (PetaGame).Peta[TulisPetak].Petak);
                    }
                }
                printf(" %d", P.Pos[TulisPemain]) ; /*->Pada akhir setiap baris ditampilkan petak pemain tersebut*/
            }
            printf("\n");
            
        /*Prosedur command akan meminta user untuk memasukkan command yang tersedia lalu akan menjalankan fitur command sesuai input user */
            command(&PetaGame, &P, &S, x, &GameBerakhir, &EndRonde, &JumlahRonde) ;
            x++;
        }
        for (x=1;x<=P.Neff;x++)
        {
            P.IsDoneRoll[x]=false;
        }
        JumlahRonde++;
        printf("\n");
        Push(&S,&P);
    }
}