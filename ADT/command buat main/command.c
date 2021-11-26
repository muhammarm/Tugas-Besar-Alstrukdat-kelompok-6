/*File:command.c*/
/*deskripsi:implementasi dari command.h*/

#include "command.h"
#include "adtplayer.h"
#include "skill.h"
#include "arraypeta.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>

void command(TabPeta *Peta,Pemain *P,Stack *Stack,int PlayerTurn,boolean *EndGame, boolean *EndRonde, int *SumRonde)
{
    /*Kamus*/
    int inp;
    char CommandInput[100];
    boolean flag;
    flag = false;
    /*Algoritma*/
    printf("Masukkan Command : ");
    /*membaca command dari user*/
    while (!flag){
        scanf("%s", &CommandInput); 
        printf("\n");
        if (CommandInput == "SKILL"){
            inp = 1;
            flag = true;
        }
        else if (CommandInput == "BUFF"){
            inp = 2;
            flag = true;
        }
        else if (CommandInput == "MAP"){
            inp = 3;
            flag = true;
        }
        else if (CommandInput == "INSPECT"){
            inp = 4;
            flag = true;
        }
        else if (CommandInput == "ROLL"){
            inp = 5;
            flag = true;
        }
        else if (CommandInput == "UNDO"){
            inp = 6;
            flag = true;
        }
        else if (CommandInput == "ENDTURN"){
            inp = 7;
            flag = true;
        }
        else if (CommandInput == "SAVE"){
            inp = 8;
            flag = true;
        }
        else{
            printf("Input Anda salah!\n");
            printf("Silahkan ulangi dengan benar!\n");
            printf("Masukkan Command : ");
        }
    }
    
    switch(inp){
        case 1: 
        /* Berisi command skill*/
            int use, buang;
            boolean flag;
            flag = false;
            while(!flag){
                printf("\n");
                if (isEmpty(Skills(*P)[PlayerTurn])){
                    printf("Skillmu kosong untuk saat ini");
                    flag = true;
                }
                else{
                    printAll(P, PlayerTurn);
                }
                printf("\n");
                printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill");
                printf("\n");
                printf("Pilih skill yang ingin digunakan: ");
                scanf("%d", &use);
                printf("\n");
                buang = (-1) * use;
                if (use == 0){
                    flag = true;
                }
                else{
                    if (use > 0 && use <= NbElmt(Skills(*P)[PlayerTurn])){
                        if (ids(search(&P->Skills[PlayerTurn], use)) == 2){
                            if (P->IsMirror[PlayerTurn] == false){
                                printf("%s memakai skill ", NamaPemain(*P)[PlayerTurn]);
                                printOne(&Skills(*P)[PlayerTurn], use);
                                useSkill(P, &Skills(*P)[PlayerTurn], use, PlayerTurn);
                                flag = true;
                            }
                            else{
                                printf("Kamu sudah pernah memakai skill ini. \n");
                                flag = true;
                            }
                        }
                        else if (ids(search(&P->Skills[PlayerTurn], use)) == 3 || ids(search(&P->Skills[PlayerTurn], use)) == 4){
                            if (P->IsSenterPembesar[PlayerTurn] == false && P->IsSenterPengecil[PlayerTurn] == false){
                                printf("%s memakai skill ", NamaPemain(*P)[PlayerTurn]);
                                printOne(&Skills(*P)[PlayerTurn], use);
                                useSkill(P, &Skills(*P)[PlayerTurn], use, PlayerTurn);
                                flag = true;
                            }
                            else{
                                printf("Kamu sudah pernah memakai skill ini. \n");
                                flag = true;
                            }
                        }
                        else{
                            printf("%s memakai ", NamaPemain(*P)[PlayerTurn]);
                            printOne(&Skills(*P)[PlayerTurn], use);
                            useSkill(P, &Skills(*P)[PlayerTurn], use, PlayerTurn);
                            flag = true;
                        }
                    }
                    else if (use < 0 && buang <= NbElmt(Skills(*P)[PlayerTurn])){
                        printf("%s membuang skill ", NamaPemain(*P)[PlayerTurn]);
                        printOne(&Skills(*P)[PlayerTurn], use);
                        delSkill(&Skills(*P)[PlayerTurn], buang);
                        flag = true;
                    }
                    else{
                        printf("Input tidak valid!\n");
                        flag = true;
                    }
                }
            }
        

        case 2:
        /*Berisi command Buff*/
            for (int ib = 1; ib <= (*P).Neff; ib++){
                printf("%s memiliki buff: \n", (*P).NamaPemain[ib]);
                boolean activated = false;
                if ((*P).IsImmune[ib]) {
                    printf("- Imunitas Teleport\n") ;
                    activated = true ;
                }
                if ((*P).IsMirror[ib]) {
                    printf("- Cermin Pengganda\n") ;
                    activated = true ;
                }
                if ((*P).IsSenterPembesar[ib]) {
                    printf("- Senter Pembesar Hoki\n") ;
                    activated = true ;
                }
                if ((*P).IsSenterPengecil[ib]) {
                    printf("- Senter Pengecil Hoki\n") ;
                    activated = true ;
                }
                if (!activated) {
                    printf("-\n") ;
                }
                printf("\n") ;
            }

        case 3: 
        /*Berisi command Map*/


        case 4:
        /*Berisi command Buff*/


        case 5:
        /*Berisi command Roll*/


        case 6:
        /*Berisi command Undo */

        case 7:
        /*Berisi command Endturn */

        case 8:

    }


    


}