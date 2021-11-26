/*file : command.h*/
/* deskripsi: file berisi gabungan command untuk file main*/

#ifndef COMMAND_H
#define COMMAND_H

#include "arraypeta.h"
#include "adtplayer.h"
#include "stack.h"
#include "roll.h"
#include "skill.h"
#include "mesin_kar.h"
#include "mesin_kata.h"

/* deklarasi dan inisialisasi string*/
char skill[] = "SKILL";
char buff[] = "BUFF";     
char map[] = "MAP";                         
char inspect[] ="INSPECT";
char roll[] = "ROLL";
char save[] = "SAVE";
char endturn[] ="ENDTURN";
char undo[] = "UNDO";

/*deklarasi Tab Command */
char TabCommand[10];

/*prosedur command*/
void command(TabPeta *Peta,Pemain *P,Stack *Stack,int PlayerTurn,boolean *EndGame, boolean *EndRonde, int *SumRonde); /* SumRonde==Jumlah Ronde */
