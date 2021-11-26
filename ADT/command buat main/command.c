/*File:command.c*/
/*deskripsi:implementasi dari command.h*/

#include "command.h"
#include <stdio.h>
#include <string.h>

void command(TabPeta *Peta,Pemain *P,Stack *Stack,int PlayerTurn,boolean *EndGame, boolean *EndRonde, int *SumRonde)
{
    /*Kamus*/
    int x;
    int HasilCommand;
    boolean endturn=false;
    char command[100];

    /*Algoritma*/
    
    /*while loop*/
     while (!endturn)
     {
         HasilCommand=0;
         printf("Masukkan Command : ");
         scanf("%d",&command);
         for(int i=0;i<8;i++){
             if(command==TabCommand[i]){
                 HasilCommand=i;
             }
         }
         
     }
    


}