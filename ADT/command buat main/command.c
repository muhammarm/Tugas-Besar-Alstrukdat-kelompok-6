/*File:command.c*/
/*deskripsi:implementasi dari command.h*/

#include "command.h"
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
    printf("\n")


    switch(CommandInput){
        case "SKILL": 
        /* Berisi command skill*/
        

        case "BUFF" :
        /*Berisi command Buff*/


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