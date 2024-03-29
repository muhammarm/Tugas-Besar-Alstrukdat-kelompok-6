/*File:command.c*/
/*deskripsi:implementasi dari command.h*/

#include "command.h"
#include <stdio.h>
#include <string.h>

void command(TabPeta *Peta,Pemain *P,Stack *Stack,int PlayerTurn,boolean *EndGame, boolean *EndRonde, int *SumRonde, int maxroll)
{
    /*Kamus*/
    int inp;
    char CommandInput[100];
    boolean endturn;
    endturn = false;
    /*Algoritma*/
    /*membaca command dari user*/
    while (!endturn){
        printf("Masukkan Command : ");
        scanf("%s", &CommandInput); 
        printf("\n");
        if (strcmp(CommandInput, "SKILL") == 0){
            inp = 1;
        }
        else if (strcmp(CommandInput, "BUFF") == 0){
            inp = 2;
        }
        else if (strcmp(CommandInput, "MAP") == 0){
            inp = 3;
        }
        else if (strcmp(CommandInput, "INSPECT") == 0){
            inp = 4;
        }
        else if (strcmp(CommandInput, "ROLL") == 0){
            inp = 5;
        }
        else if (strcmp(CommandInput, "UNDO") == 0){
            inp = 6;
        }
        else if (strcmp(CommandInput, "ENDTURN") == 0){
            inp = 7;
        }
        else{
            printf("Input Anda salah!\n");
            inp = 0;
        }
    
        switch(inp){
            int use, buang;
            boolean flag;
            case 1: 
            /* Berisi command skill*/
                flag = false;
                if (!(*P).IsDoneRoll[PlayerTurn]){
                    while(!flag){
                        printf("\n");
                        if (isEmpty(Skills(*P)[PlayerTurn])){
                            printf("Skillmu kosong untuk saat ini\n");
                            printf("\n");
                            flag = true;
                        }
                        else{
                            printAll(P, PlayerTurn);
                            printf("\n");
                            printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill");
                            printf("\n");
                            printf("Pilih skill yang ingin digunakan: ");
                            scanf("%d", &use);
                            printf("\n");
                        }
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
                }
                else{
                    printf("Anda sudah melakukan roll, tidak bisa melakukan command SKILL\n");
                }
                break;
            

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
                break;


            case 3: 
            /*Berisi command Map*/
                for (int j = 1;j <= Neff(*P);j++){
                    printf("%s", NamaPemain(*P)[j]);
                    int lenNama = strlen(NamaPemain(*P)[j]);
                    while (lenNama < 10){
                        printf(" ");
                        lenNama++;
                    }
                    printf(": ");
                    PosisiPemain(*Peta, Pos(*P)[j]);
                    printf("\n");
                }
                printf("\n");
                break;


            case 4:
            /*Berisi command Inspect*/
                inspect(*Peta);
                break;


            case 5:
            /*Berisi command Roll*/
                if(!(*P).IsDoneRoll[PlayerTurn]){
                    roll(P,Peta,maxroll,PlayerTurn);
                    (*P).IsDoneRoll[PlayerTurn] = true ;
                    printf("\n") ;
                }else{
                    printf("Pemain tidak dapat melakukan roll 2 kali.\n") ;
                }

                if ((*P).Pos[PlayerTurn] == (*Peta).Neff) {
                    endturn = true ;
                    printf("%s telah mencapai ujung.\n", (*P).NamaPemain[PlayerTurn]) ;
                    printf("Pemenang game ini adalah %s.\n", (*P).NamaPemain[PlayerTurn]) ;
                    *EndGame = true ;
                    *EndRonde = true ;
                }
                break;


            case 6:
            /*Berisi command Undo */
                endturn = true;
                *EndRonde = true;
                boolean bisaUndo = false;
                boolean UndoSukses;
                char Undo;
                (*SumRonde)--;
                Pop(Stack, P, &UndoSukses);
                if (!UndoSukses){
                    printf("Tidak dapat melakukan undo!\n");
                }
                else{
                    printf("Undo berhasil dilakukan!\n");
                    if(*SumRonde != 0){
                        printf("State permainan akan kembali ke akhir ronde %d.\n", *SumRonde);
                    }
                    else{
                        printf("State permainan akan kembali ke awal permainan!\n");
                        UndoSukses = false;
                    }
                }
                 while (!bisaUndo && UndoSukses) {
                    printf("Apakah kamu ingin melakukan undo lagi? (Y/N): ") ;
                    scanf(" %c", &Undo) ;
                    if (Undo == 'Y') {
                        Pop(Stack, P, &UndoSukses) ;
                        if (!UndoSukses) {
                            printf("Undo gagal dilakukan!\n\n");
                        }
                        else {
                            (*SumRonde)-- ;
                            printf("Undo berhasil dilakukan.\n") ;
                            if (*SumRonde != 0) {
                                printf("State permainan akan kembali ke akhir ronde %d.\n\n", *SumRonde) ;
                            }
                            else {
                                printf("State permainan akan kembali ke awal permainan.\n\n") ;
                            }
                        }
                    }
                    else if (Undo == 'N') {
                        bisaUndo = true ;
                        printf("\n") ;
                    }
                    else {
                        printf("Kamu harus memasukkan Y atau N.\n\n") ;
                    }
                }
                break;


            case 7:
            /*Berisi command Endturn */
                if (NbElmt(Skills(*P)[PlayerTurn]) > 10){
                    int jumlahSkill = NbElmt(Skills(*P)[PlayerTurn]);
                    for (int x = 0; x < jumlahSkill; x++){
                        int urutan;
                        printAll(P, PlayerTurn);
                        printf("Skill yang kamu miliki mencapai batas maksimal. Pilih skill yang ingin kamu buang: ");
                        delSkill(&Skills(*P)[PlayerTurn], urutan);
                    }
                }
                if((*P).IsDoneRoll[PlayerTurn]){
                    endturn = true;
                    (*P).IsSenterPembesar[PlayerTurn] = false;
                    (*P).IsSenterPengecil[PlayerTurn] = false;
                    (*P).IsMirror[PlayerTurn] = false;
                    printf("\n");
                }
                else{
                    printf("Kamu belum bisa melakukan endturn\n");
                    printf("Lakukan Roll terlebih dahulu!\n");
                }
                break;

            // INPUT SALAH
            default:
                printf("Silahkan ulangi dengan benar!\n");
                printf("\n");
        }
    }
}