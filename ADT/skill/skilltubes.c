#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "listdp.h"

int percentage(int x){
    if ((x >= 1) && (x <= 10)){
        return 0;
    }
    else if((x >= 11) && (x <= 20)){
        return 1;
    }
    else if((x >= 21) && (x <= 30)){
        return 2;
    }
    else if((x >= 31) && (x <= 36)){
        return 3;
    }
    else if((x >= 37) && (x <= 51)){
        return 4;
    }
    else if((x >= 52) && (x <= 66)){
        return 5;
    }
    else if((x >= 67) && (x <= 70)){
        return 6;
    }
    else{
        return Nil;
    }
}

void randomSkill(List *skill){
    int x;
    srand(time(0));
    x = percentage(rand() % 100 + 1);
    if (x != Nil){
        InsVLast(skill, x);
    }
}

void printSkill(List skill){
    address p;
    int count = 1;
    char listSkill[][25] = {
        "Pintu Ga Ke Mana Mana",
        "Mesin Waktu",
        "Baling Baling Jambu",
        "Cermin Pengganda",
        "Senter Pembesar Hoki",
        "Senter Pengecil Hoki",
        "Mesin Penukar Posisi"
    };

    p = First(skill);
    printf("Kamu memiliki skill: \n");
    while(p != Nil){
        printf("%d. %s\n", count, listSkill[Info(p)]);
        count += 1;
        p = Next(p);
    }  
}
