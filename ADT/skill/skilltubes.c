#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "listdp.h"
#include "roll.h"

int percentage(int x){
    if ((x >= 1) && (x <= 20)){
        return 1;
    }
    else if((x >= 21) && (x <= 30)){
        return 2;
    }
    else if((x >= 30) && (x <= 45)){
        return 3;
    }
    else if((x >= 46) && (x <= 60)){
        return 4;
    }
    else if((x >= 61) && (x <= 70)){
        return 5;
    }
    else{
        return 0;
    }
}

void randomSkill(List *skill){
    int x;
    time_t t;
    srand((unsigned) time(&t));
    x = percentage(rand() % 100 + 1);
    if (x != 0){
        if (NbElmt(*skill) <= 9){
            if (x == 1){
                InsVLast(skill, x);
                printf("Skill Pintu Ga Ke Mana Mana berhasil didapatkan \n");
            }
            else if (x == 2){
                InsVLast(skill, x);
                printf("Skill Cermin Pengganda berhasil didapatkan \n");
            }
            else if (x == 3){
                InsVLast(skill, x);
                printf("Skill Senter Pembesar Hoki berhasil didapatkan \n");
            }
            else if (x == 4){
                InsVLast(skill, x);
                printf("Skill Senter Pengecil Hoki berhasil didapatkan \n");
            }
            else if (x == 5){
                InsVLast(skill, x);
                printf("Skill Mesin Penukar Posisi berhasil didapatkan \n");
            }
        }
        else {
            printf("Maaf, skill Anda sudah penuh");
        }
    }
    else{
        printf("Maaf, Anda gagal mendapatkan skill");
    }
}

void printSkill(List skill){
    address p;
    int count = 1;
    char listSkill[][25] = {
        "Pintu Ga Ke Mana Mana",
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

void deleteSkill (List *skill, int count){

}

void cerminPengganda(List *skill){
    randomSkill(&(*skill));
    randomSkill(&(*skill));
}

void senterPembesar(List skill){
    getNomor(maxroll/2, maxroll);
}

void senterPengecil(List skill){
    getNomor(0, maxroll/2);
}

