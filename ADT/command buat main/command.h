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
#include "inspect.h"

/*prosedur commandd*/
void command(TabPeta *Peta,Pemain *P,Stack *Stack,int PlayerTurn,boolean *EndGame, boolean *EndRonde, int *SumRonde, int maxroll); /* SumRonde==Jumlah Ronde */
#endif