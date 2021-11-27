/*file : command.h*/
/* deskripsi: file berisi gabungan command untuk file main*/

#ifndef COMMAND_H
#define COMMAND_H

#include "../Map/arraypeta.h"
#include "../player/adtplayer.h"
#include "../Stack/stack.h"
#include "../../command/roll/roll.h"
#include "../skill/skill.h"
#include "../Mesin_Karakter/mesin_kar.h"
#include "../Mesin_Kata/mesin_kata.h"
#include "../../command/inspect/inspect.h"

/*prosedur command*/
void command(TabPeta *Peta,Pemain *P,Stack *Stack,int PlayerTurn,boolean *EndGame, boolean *EndRonde, int *SumRonde, int maxroll); /* SumRonde==Jumlah Ronde */

#endif