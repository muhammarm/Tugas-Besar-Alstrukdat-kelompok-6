#include "stack.h"
int main()
{
    /* Membuat sebuah stack kosong */
    Stack S;
    CreateEmpty(&S);

    Pemain P;
    P.IsDoneRoll[1] = true;
    P.IsImmune[1] = false;
    P.IsMirror[1] = false;
    P.IsSenterPembesar[1] = false;
    P.IsSenterPengecil[1] = false;
    P.Neff = 1;
    P.Pos[1] = 1;

    /*  Mengecek apakah stack kosong atau penuh. Jika stack kosong, maka akan dipush */
    if(!IsEmptyStack){
        printf("Stack penuh");
    }
    else{
        /* push data ke dalam stack */
        Push(&S, &P);
        printf("Jumlah pemain saat ini: %d\n", S.P[Top(S)].Neff);
        printf("Posisi pemain saat ini: %d\n\n", S.P[Top(S)].Pos[1]);


        /* pop data yang telah dimasukkan ke dalam pemain 2*/
        boolean UndoSukses;
        Pemain P2;
        Pop(&S, &P2, &UndoSukses);
        printf("Jumlah pemain saat ini: %d\n", P2.Neff);
        printf("Posisi pemain saat ini: %d\n", P2.Pos[1]);
    }
}
