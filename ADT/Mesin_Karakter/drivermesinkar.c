/* File drivermesinkar.c */
/* File driver untuk implementasi Mesin Karakter */

#include <stdio.h>
#include <stdlib.h>
#include "mesin_kar.h"
#include "mesin_kar.c"


int main(){
    char filename[100];

    printf("Masukkan nama file : ");
    scanf("%s", &filename);
    while (!CheckIfFileExists(filename)){
        printf("File %s tidak ada, mohon ulangi.\n", filename);
        printf("Masukkan nama file : ");
        scanf("%s", &filename);
    }

    START(filename);
    int i = 1;
    while(!EOP){
        printf("Karakter ke-%d : %c\n", i, CC);
        ADV();
        i++;
    }
    return 0;
}