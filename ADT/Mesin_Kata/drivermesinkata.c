/* File drivermesinkata.c */
/* File driver untuk implementasi Mesin Kata */

#include <stdio.h>
#include <stdlib.h>
#include "mesin_kata.h"


void printKata(Kata kata);

int main(){
    char filename[100];

    printf("Masukkan nama file : ");
    scanf("%s", &filename);
    while (!CheckIfFileExists(filename)){
        printf("File %s tidak ada, mohon ulangi.\n", filename);
        printf("Masukkan nama file : ");
        scanf("%s", &filename);
    }

    STARTKATA(filename);
    int i = 1;
    while(!EndKata){
        printf("Kata ke-%d : ", i);
        printKata(CKata);
        ADVKATA();
        i++;
    }
    return 0;
}

void printKata(Kata kata){
  for(int i = 1; i <= kata.Length; i++){
    printf("%c", kata.TabKata[i]);
  }
  printf("\n");
}