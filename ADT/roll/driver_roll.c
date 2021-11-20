#include<stdio.h>
#include<stdlib.h>
#include "roll.c"

int main(){
    Player p1,p2;
    int pilihan, maxroll, besarMap;
    char map[besarMap];
    printf("Masukkan nama Player 1: ");
    CreatePlayer(&p1);
    printf("Masukkan nama Player 2: ");
    CreatePlayer(&p2);
    scanf("%d",&besarMap); 
    scanf("%s",map);
    scanf("%d",&maxroll);
    while(Posisi(p1)<besarMap-1 && Posisi(p2)<besarMap-1){
        printf("Pilih instruksi:\n 1. Roll Player 1\n 2. Roll Player 2\n 3. Keluar\n");
        scanf("%d",&pilihan);
        switch(pilihan){
            case 1:
                roll(&p1,map,maxroll);
                break;
            case 2:
                roll(&p2,map,maxroll);
                break;
            case 3:exit(0); break;
            default:printf("Input salah! mohon ulangi.\n");
        }
    }
    return 0;
}
