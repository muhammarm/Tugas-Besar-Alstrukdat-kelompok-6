/*file : command.h*/
/* deskripsi: file berisi gabungan command untuk file main*/

#ifndef COMMAND_H
#define COMMAND_H

#include "../../ADT/Boolean/boolean.h"
#include "../../ADT/Map/arraypeta.h"
#include "../../ADT/player/adtplayer.h"
#include "../../ADT/Stack/stack.h"
#include "../../ADT/skill/skill.h"
#include "../../ADT/Mesin_Karakter/mesin_kar.h"
#include "../../ADT/Mesin_Kata/mesin_kata.h"
#include "../roll/roll.h"
#include "../inspect/inspect.h"

/*prosedur command*/
void command(TabPeta *Peta,Pemain *P,Stack *Stack,int PlayerTurn,boolean *EndGame, boolean *EndRonde, int *SumRonde, int maxroll); /* SumRonde==Jumlah Ronde */

#endif