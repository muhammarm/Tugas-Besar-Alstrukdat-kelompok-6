#include "../Boolean/boolean.h"
#include "../Map/arraypeta.h"
#include "../player/adtplayer.h"
#include "../Stack/stack.h"
#include "../skill/skill.h"
#include "../Mesin_Karakter/mesin_kar.h"
#include "../Mesin_Kata/mesin_kata.h"
#include "../../command/roll/roll.h"
#include "../../command/inspect/inspect.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    //Menambahkan 2 player
    //player 1 bernama A, player 2 bernama B
    Pemain P;
    CreateEmptyPemainList(&P);
    AddPemain(&P, 2);

    //pengujian isEmpty
    if (isEmpty(Skills(P)[1])){
        printf("Anda tidak mempunyai skill\n");
    }
    else{
        printf("Anda mempunyai skill\n");
    }
    printf("\n");

    //Pengujian createSkillNode, random, percentage, makeSkill, insSkill
    LSkill skill;
    createEmpty(&skill);
    address S = createSkillNode();
    printf("%d\n", ids(S));
    int a = random(0);
    printf("%d\n", a);
    int b = percentage(a);
    printf("skill yang didapat %d\n", b);
    makeSkill(S, b);
    printf("skill yang tertera pada Skills S %d\n", ids(S));
    insSkill(&skill, S);
    printf("Skill yang terlah berhasil dimasukkan memiliki ids %d\n", ids(skill));
    printf("\n");

    //Pengujian NbElmt, getSkill, delSkill, printAll
    printf("Jumlah skill %d\n", NbElmt(Skills(P)[1]));
    getSkill(&P, 1, 0);
    getSkill(&P, 1, 1);
    printf("Jumlah skill setelah ditambah \n", NbElmt(Skills(P)[1]));
    printf("Skill - skill yang didapat\n");
    printAll(&P, 1);
    
    delSkill(&Skills(P)[1], 1);
    printf("Jumlah skill setelah dibuang %d\n", NbElmt(Skills(P)[1]));
    printAll(&P, 1);

    //Pengecekan skill tidak akan bertambah apabila > 10
    for (int i = 0; i < 15; i++){
        getSkill(&P, 1, i%2);
    }
    
    //Pengujian search
    printf("%d\n", search(&Skills(P)[1],2));
    printf("id yang dimiliki skill ini %d \n", ids(search(&Skills(P)[1],2)));

    //Pengujian buff dari skill
    printf("Cek Skill\n");
    CreateEmpty(&Skills(P)[1]);
    printf("Sebelum aktif (pintu gak kemana mana) %d\n", IsPemainImmune(P, "A"));
    pintuGakManaMana(&P, 1);
    printf("Setelah aktif (pintu gak kemana mana) %d\n", IsPemainImmune(P, "A"));
    printf("\n");

    printf("Sebelum aktif (senter pengecil) %d\n", IsPemainSenterPengecil(P, "A"));
    senterPengecil(&P, 1);
    printf("Setelah aktif (senter pengecil) %d\n", IsPemainSenterPengecil(P, "A"));
    printf("\n");

    printf("Sebelum aktif (senter pembesar) %d\n", IsPemainSenterPembesar(P, "A"));
    senterPembesar(&P, 1);
    printf("Setelah aktif (senter pembesar) %d\n", IsPemainSenterPembesar(P, "A"));
    printf("\n");

    printf("Sebelum aktif (cermin pengganda) %d\n", IsPemainCerminPengganda(P, "A"));
    mirror(&P, 1);
    printf("Setelah aktif (cermin pengganda) %d\n", IsPemainCerminPengganda(P, "A"));
    printf("\n");

    printf("Penukar posis\n");
    Pos(P)[1] = 10;
    Pos(P)[2] = 20;
    printf("Posisi para pemain sebelum ditukar %d %d\n", Pos(P)[1], Pos(P)[2]);
    mesinPenukar(&P, 1);
    printf("Posisi para pemain setelah ditukar %d %d\n", Pos(P)[1], Pos(P)[2]);
    printf("\n");

    //Pengujian copy
    printf("copy skill\n");
    printf("skill pemain 1\n");
    printAll(&P, 1);
    printf("skill pemain 2\n");
    printAll(&P, 2);
    copy(Skills(P)[1], &Skills(P)[2]);
    printf("setelah dicopy\n");
    printf("skill pemain 1\n");
    printAll(&P, 1);
    printf("skill pemain 2\n");
    printAll(&P, 2);

    //Pengujian useSkill
    printf("useSkill");
    int use;
    printf("Masukkan skill yang mau diaktifkan: ");
    scanf("%d", &use);
    useSkill(&P, &Skills(P)[1], use, 1);
}