#include "roll.c"
#include "../../ADT/Map/arraypeta.c"
#include "../../ADT/Mesin_Karakter/mesin_kar.c"
#include "../../ADT/Mesin_Kata/mesin_kata.c"
#include "../../ADT/player/adtplayer.c"
#include "../../ADT/skill/skill.c"


int main(){
    TabPeta TP;
    Pemain P;
    int maxroll=10,minroll=1, turn=0, besarMap=11;

    // test getNomor
    int x = getNomor(minroll,maxroll);
    printf("%d\n",x);

    // test langkahPemain
    langkahPemain(&P,x,turn);
    printf("%d",P.Pos[turn]);

    // test roll
    MakeEmptyMap(&TP);
    char configpath[] = "..\\..\\config\\";
    char filename[100];
    char filepath[255];

    strcpy(filepath, configpath);
    printf("Masukkan nama file konfigurasi : ");
    scanf("%s", &filename);
    strncat(filepath, filename, 100);
    while (!CheckIfFileExists(filepath)){
        printf("File %s tidak ada, mohon ulangi.\n", filename);
        strcpy(filepath, configpath);
        printf("Masukkan nama file konfigurasi : ");
        scanf("%s", &filename);
        strncat(filepath, filename, 100);
    }
    ReadMap(&TP, filepath);

    roll(&P,&TP,maxroll,turn);
    return 0;
}