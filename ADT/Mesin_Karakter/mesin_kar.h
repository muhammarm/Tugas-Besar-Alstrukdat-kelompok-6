/* File mesin_kar.h */
/* Definisi Mesin Karakter yang telah dimodifiksi */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../Boolean/boolean.h"
#include <sys/stat.h>

/* State Mesin */
extern char CC;
extern boolean EOP;

void START(char Filepath[255]);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : Filepath terdefinisi
   F.S. : File pada Filepath tersalin ke pita untuk dibaca. 
          CC adalah karakter pertama pada pita. */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != EOF
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = EOF.
          Jika CC = EOF maka EOP akan menyala (true) */

boolean CheckIfFileExists(const char* Filepath);
/* Mengembalikan true ketika Filepath ada di komputer */

#endif
