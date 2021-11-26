#include "skill.h"
#include <stdlib.h>
#include <stdio.h>

boolean isEmpty(LSkill skill){
    return (skill == Nil);
}

address createSkillNode(){
    address S = (address)malloc(sizeof(SkillNode));
    if (S != Nil){
        ids(S) = 0;
        NextSkill(S) = Nil;
        return S;
    }
    else{
        return Nil;
    }
}

void createEmpty(LSkill *skill){
    *skill = Nil;
}

int NbElmt(LSkill skill){
    if (isEmpty(skill)){
        return 0;
    }
    else{
        int ct = 0;
        address P = skill;
        while (P != Nil){
            ct = ct + 1;
            P = NextSkill(P);
        }
        return ct;
    }
}

void insSkill(LSkill *skill, address S){
    address last;
    if (*skill == Nil){
        *skill = S;
    }
    else{
        last = *skill;
        while(NextSkill(last) != Nil){
            last = NextSkill(last);
        }
        NextSkill(last) = S;
    }
}

address search(LSkill *skill, int urutan){
    boolean flag;
    flag = false;
    address P = *skill;
    int temp = 1;
    while ((!flag) && (P != Nil)){
        if (temp == urutan){
            flag = true;
        }
        else{
            P = NextSkill(P);
            temp = temp + 1;
        }
    }
    return P;
}

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
        return 6;
    }
}

int random(int x){
    srand(time(NULL));
    int arr[2];
    arr[0] = rand() % 100;
    arr[1] = rand() % 100;

    return arr[x];
}

void getSkill(Pemain *P, int curr, int num){
    address S;
    S = createSkillNode();
    int idx = percentage(random(num));
    ids(S) = idx;
    makeSkill(S, ids(S));
    insSkill(&Skills(*P)[curr], S);
}

void delSkill(LSkill *skill, int urutan){
    int temp = 1;
    address S = *skill;
    if (urutan == 1){
        if (NextSkill(S) == Nil){
            *skill = Nil;
        }
        else{
            *skill = NextSkill(S);
        }
    }
    else{
        address prec = *skill;
        S = search(skill, urutan);
        while (NextSkill(prec) != S){
            prec = NextSkill(prec);
        }
        NextSkill(prec) = NextSkill(S);
    }
}

void useSkill(Pemain *P, LSkill *skill, int urutan, int curr){
    int temp = 1;
    address S = *skill;
    while(temp < urutan){
        S = NextSkill(S);
        temp = temp + 1;
    }
    if (buff(S) != Nil){
        buff(S)(P, curr);
    }
    delSkill(skill, urutan);
}


void printOne(LSkill *skill, int urutan){
    address S = *skill;
    int temp = 1;
    while (temp < urutan){
        S = NextSkill(S);
        temp = temp + 1;
    }
    if (ids(S) == 1){
        printf("Pintu ga Kemana-mana\n");
    } 
    else if (ids(S) == 2){
        printf("Cermin Pengganda\n");
    } 
    else if (ids(S) == 3){
        printf("Senter Pembesar Hoki\n");
    }  
    else if (ids(S) == 4){
        printf("Senter Pengecil Hoki\n");
    }  
    else if (ids(S) == 5){
        printf("Mesin Penukar Posisi\n");
    }  
    else if (ids(S) == 6){
        printf("Teknologi Gagal\n");
    }
}

void printAll(Pemain *P, int curr){
    address S = P->Skills[curr];
    int temp = 1;
    while (S != Nil){
        if (ids(S) == 1){
            printf("Pintu ga Kemana-mana\n");
        } 
        else if (ids(S) == 2){
            printf("Cermin Pengganda\n");
        } 
        else if (ids(S) == 3){
            printf("Senter Pembesar Hoki\n");
        }  
        else if (ids(S) == 4){
            printf("Senter Pengecil Hoki\n");
        }  
        else if (ids(S) == 5){
            printf("Mesin Penukar Posisi\n");
        }  
        else if (ids(S) == 6){
            printf("Teknologi Gagal\n");
        }
        temp = temp + 1;
        S = NextSkill(S);
    }
}

void pintuGakManaMana(Pemain *P, int curr){
    if (IsImmune(*P)[curr] == false){
        IsImmune(*P)[curr] = true;
    }
}

void mirror(Pemain *P, int curr){
    if (!IsMirror(*P)[curr]){
        getSkill(P, curr, 0);
        getSkill(P, curr, 1);

        P->IsMirror[curr] = true;
    }
}

void senterPembesar(Pemain *P, int curr){
    P->IsSenterPembesar[curr] = true;
}

void senterPengecil(Pemain *P, int curr){
    P->IsSenterPengecil[curr] = true;
}

void mesinPenukar(Pemain *P, int curr){
    ElType temp;
    int target;
    printf("Masukkan nomor player yang ingin ditarget: ");
    scanf("%d", &target);
    temp = Pos(*P)[target];
    Pos(*P)[target] = Pos(*P)[curr];
    Pos(*P)[curr] = temp;
}

void makeSkill(address S, int idx){
    switch (idx){
        case 1:
            ids(S) = 1;
            buff(S) = pintuGakManaMana;
            break;
        case 2:
            ids(S) = 2;
            buff(S) = mirror;
            break;
        case 3:
            ids(S) = 3;
            buff(S) = senterPembesar;
            break;
        case 4:
            ids(S) = 4;
            buff(S) = senterPengecil;
            break;
        case 5:
            ids(S) = 5;
            buff(S) = mesinPenukar;
            break;
        default:
            break;   
    }
}

void copy(LSkill awal, LSkill *copy){
    LSkill A = awal;
    while (A != Nil){
        address S;
        S = createSkillNode();
        makeSkill(S, ids(A));
        insSkill(copy, S);
        A = NextSkill(A);
    }
}