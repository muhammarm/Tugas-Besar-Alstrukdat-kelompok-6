#include<stdio.h>
#include<stdlib.h>
#include "roll.c"
#include "teleporter.c"

int main(){
    Player p1,p2;
    Tele l;
    int pilihan, maxroll, besarMap, banyakTele, masukTele, keluarTele;
    char map[besarMap];
    CreateEmptyTele(&l);
    printf("Masukkan nama Player 1: ");
    CreatePlayer(&p1);
    printf("Masukkan nama Player 2: ");
    CreatePlayer(&p2);
    scanf("%d",&besarMap); 
    scanf("%s",map);
    scanf("%d",&maxroll);
    scanf("%d",&banyakTele);
    for(int i=0; i<banyakTele; i++){
        scanf("%d %d",&masukTele,&keluarTele);
        InsVFirst(&l,masukTele, keluarTele);
    }
    while(Posisi(p1)<besarMap-1 && Posisi(p2)<besarMap-1){
        printf("Pilih instruksi:\n 1. Roll Player 1\n 2. Roll Player 2\n 3. Keluar\n");
        scanf("%d",&pilihan);
        switch(pilihan){
            case 1:
                //roll(&p1,map,maxroll);
                teleporter(l,&p1,besarMap);
                break;
            case 2:
                //roll(&p2,map,maxroll);
                teleporter(l,&p2,besarMap);
                break;
            case 3:exit(0); break;
            default:printf("Input salah! mohon ulangi.\n");
        }
    }
    if(Posisi(p1)==besarMap-1){
        printf("%s telah mencapai ujung.\nPemenang game ini adalah %s.", Nama(p1), Nama(p1));
    }else{
        printf("%s telah mencapai ujung.\nPemenang game ini adalah %s.", Nama(p2), Nama(p2));
    }
    return 0;
}
