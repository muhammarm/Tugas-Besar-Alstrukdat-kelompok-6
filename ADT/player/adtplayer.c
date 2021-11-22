/*File : adtplayer.c*/
/* ADT player untuk menyimpan informasi-informasi terkait player */
/*implementasi dari adtplayer.h*/

#include "adtplayer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Membuat List Pemain yang kosong */
void CreateEmptyPlayerList(Pemain *P)
{
    (*P).Neff = 0;

}

/* Membuat List Pemain sebanyak n pemain */
void addPlayer(Pemain *P, int n)
{
    for (int x = 1; x<=n; x++){
        printf("Masukan nama pemain %d: ", i);
        scanf("%s", &(NamaPemain(*P)[i]));
        int y = 1;
        while (y <= n){
            if(strcmp(NamaPemain(*P)[x], NamaPemain(*P)[y]) == 0 && y != x){
                printf("Nama %s sudah digunakan!\n", NamaPemain(*P)[x]);
                printf("Masukkan nama lain untuk pemain %d: ", i);
                scanf("%s", &(NamaPemain(*P)[x]))
            }
            else{
                y++;
            }
        }
        Pos(*P)[x] = 1;
        IsTeleporter(*P)[x] = false;
        IsImmune(*P)[x] = false;
        IsSenterPembesar(*P)[x] = false;
        IsSenterPengecil(*P)[x] = false;
        IsMirror(*P)[x] = false;
    }
    Neff(*P) = n;
}
/* Mendapatkan index pemain */
int getPemainIdx(Pemain *P, char *Nama)
{
    int x = IdxMin;
    int idxP = IdxUndef;
    while ( x <= IdxMax){
        if(strcmp(Nama, P.NamaPemain[x]) != 0){
            x++;
        }
        else {
            idxP = x;
            break;
        }
    }
    return idxP;
}

boolean IsPemainTeleported(Pemain P, char *NamaPemain);
/* Menghasilkan True jika pemain dengan parameter NamaPemain terkena portal atau sebaliknya */
{
    int idx = getPemainIdx(P, NamaPemain);
    if (idx != IdxUndef){
        return (IsTeleporter(P)[idx]);
    }
}

boolean IsPemainImmune(Pemain P, char *NamaPemain);
/*Menghasilkan True jika pemain dengan parameter NamaPemain sedang imun(buff) atau sebaliknya*/
{
    int idx = getPemainIdx(P, NamaPemain);
    if (idx != IdxUndef){
        return (IsImmune(P)[idx]);
    }
}

boolean IsPemainSenterPengecil(Pemain P,char *NamaPemain);
/* Menghasilkan True jika pemain dengan parameter NamaPemain memakai senter pengecil atau sebaliknya*/
{
    int idx = getPemainIdx(P, char *NamaPemain);
    if (idx != IdxUndef){
        return(IsSenterPengecil(P)[idx]);
    }
}

boolean IsPemainSenterPembesar(Pemain P, char *NamaPemain);
/*Menghasilkan True jika pemain dengan parameter NamaPemain memakai senter pembesar atau sebaliknya*/
{
    int idx = getPemainIdx(P, char *NamaPemain);
    if (idx != IdxUndef){
        return(IsSenterPembesar(P)[idx]);
    }
}

boolean IsPemainCerminPengganda(Pemain P,char *NamaPemain);
/*Menghasilkan True jika pemain dengan parameter NamaPemain memakai cermin pengganda atau sebaliknya*/
{
    int idx = getPemainIdx(P, char *NamaPemain);
    if (idx != IdxUndef){
        return(IsMirror(P)[idx]);
    }
}




