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
    char CommandInput[100];
    /*Algoritma*/
    printf("Masukkan Command : ");
    /*membaca command dari user*/
    scanf("%s", &CommandInput); 
    printf("\n");


    switch(CommandInput){
        case "SKILL": 
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
                    printOne(P, PlayerTurn);
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
                        else if (ids(search(&P->Skills[PlayerTurn], use)) == 3) || (ids(search(&P->Skills[PlayerTurn], use)) == 4){
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
        

        case "BUFF" :
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

        case "MAP" : 
        /*Berisi command Map*/


        case "INSPECT" :
        /*Berisi command Buff*/


        case "ROLL" :
        /*Berisi command Roll*/


        case "UNDO" :
        /*Berisi command Undo */

        case "ENDTURN" :
        /*Berisi command Endturn */

        case "SAVE" :

    }


    


}