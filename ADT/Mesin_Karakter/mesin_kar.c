/* File mesin_kar.c */
/* Implementasi Mesin Karakter yang telah dimodifikasi */

#include <stdio.h>
#include <stdlib.h>
#include "mesin_kar.h"

char CC;
boolean EOP;

static FILE * pita;

void START(char Filepath[255])
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : Filepath terdefinisi
   F.S. : File pada Filepath tersalin ke pita untuk dibaca. 
          CC adalah karakter pertama pada pita. */
{
   /* ALGORITMA */
    pita = fopen(Filepath,"r");
    ADV();
}

void ADV()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != EOF
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = EOF.
          Jika CC = EOF maka EOP akan menyala (true) */
{
   /* ALGORITMA */
    CC = getc(pita);
    EOP = (CC == EOF);
    if (EOP) {
       fclose(pita);
    }
}

boolean CheckIfFileExists(const char* Filepath)
/* Mengembalikan true ketika Filepath ada di komputer */
{
    struct stat buffer;
    int exist = stat(Filepath, &buffer);
    if (exist == 0)
        return true;
    else  
        return false;
}
