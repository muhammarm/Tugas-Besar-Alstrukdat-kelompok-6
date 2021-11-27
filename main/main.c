/* File : main.c*/
/* berisi program utama untuk menjalankan permainan ular tangga*/

#include "../command/MainCommand/command.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    printf("++========================================================================================================================++\n");
    printf("||++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++||\n");
    printf("||                                                                                                                        ||\n");
    printf("|| ....                 ....  ............  ....          ............  ............  .....           .....  ............ ||\n");
    printf("|| 'ooo'               'ooo'  |88oooooooo|  |oo|          |88oooooooo|  |88oooooo88|  |88o|`         `|o88|  |88oooooooo| ||\n");
    printf("||  'ooo'      .      'ooo'   |88|````````  |88|          |88|````````  |88|`````88|  |88| `8`     `8` |88|  |88|```````` ||\n");
    printf("||   'ooo'    '.'    'ooo'    |88oooooo|    |88|          |88|          |88|     88|  |88|  `8`   `8`  |88|  |oooooooo|   ||\n");
    printf("||    'ooo'  '.8.'  'ooo'     |88|``````    |88|          |88|          |88|     88|  |88|   `8`.`8`   |88|  |88|``````   ||\n");
    printf("||     'oo. '.' '. '.oo'      |88|........  |88|........  |88|          |88|     88|  |88|     `8`     |88|  |88|........ ||\n");
    printf("||      'oooo'   'oooo'       |88oooooooo|  |88oooooooo|  |88oooooooo|  |88oooooo88|  |88|      `      |88|  |88oooooooo| ||\n");
    printf("||       ````     ````        ````````````  ````````````  ````````````  ````````````  ````             ````  ```````````` ||\n");
    printf("||                                                                                                                        ||\n");
    printf("||++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++||\n");
    printf("++========================================================================================================================++\n");
    printf("                                                  ->  NEWGAME                                                               \n");
    printf("                                                  ->   EXIT                                                                 \n");
    /*Kamus*/
    int JumlahPemain;
    Pemain P; /*dari adt player*/
    TabPeta PetaGame;/*dari arraypeta*/


    /*START GAME*/
    /*meminta jumlah pemain*/
    boolean valid;
    valid = false;
    char FirstCommand[100];
    int firstinp;
    while (!valid){
        printf("Masukkan command : ");
        scanf("%s",FirstCommand);
        printf("\n");
        if (strcmp(FirstCommand, "NEWGAME") == 0){
            firstinp = 1;
        }
        else if (strcmp(FirstCommand, "EXIT") == 0){
            firstinp = 2;
        }
        else{
            printf("Input Anda salah!\n");
            firstinp = 0;
        }

        switch (firstinp){
            boolean JumlahInvalid;
            case 1 : 
                JumlahInvalid = false ;
                while(!JumlahInvalid)
                {
                    printf("Masukkan jumlah pemain game: ") ;
                    scanf("%d", &JumlahPemain) ;
                    if (JumlahPemain < 2 || JumlahPemain > 4)
                    {
                        printf("Jumlah pemain game tidak sesuai dengan ketentuan. Silahkan masukkan kembali jumlah pemain game.\n");
                    }
                    else
                    {
                        JumlahInvalid=true;
                    }
                }
                printf("\n");
                
                /*Membuat list pemain kosong*/
                CreateEmptyPemainList(&P);
                /*membuat list pemain sebanyak "JumlahPemain"*/
                AddPemain(&P,JumlahPemain);
                printf("\n");

                /*Program Membaca Map dari File konfigurasi*/
                int maxroll;
                char configpath[] =  "..\\config\\";
                char filename[100];
                char filepath[255];

                strcpy(filepath, configpath);
                printf("Masukkan nama file konfigurasi : ");
                scanf("%s", &filename);
                strncat(filepath, filename, 100);
                while (!CheckIfFileExists(filepath))
                {
                    printf("File %s tidak ada, mohon ulangi.\n", filename);
                    strcpy(filepath, configpath);
                    printf("Masukkan nama file konfigurasi : ");
                    scanf("%s", &filename);
                    strncat(filepath, filename, 100);
                }
                ReadMap(&PetaGame, filepath);
                maxroll = ReadMaxroll(filepath);

                /*Membuat Stack kosong*/
                Stack S;
                CreateEmpty(&S);
                

                /*Game akan terus looping hingga ada pemain yang menang*/
                boolean GameBerakhir=false;
                boolean EndRonde=false;
                int JumlahRonde = 1;

                Push(&S,&P);
                while (!GameBerakhir)
                {
                    int x =1;
                    EndRonde=false;
                    printf("-- Ronde ke-%d --\n\n", JumlahRonde);

                    /*Setiap pemain mendapatkan turn pada sebuah ronde*/
                    while (!EndRonde && x <= JumlahPemain)
                    {
                        printf("-- Giliran %s --\n\n", (P).NamaPemain[x]) ;
                        getSkill(&P,x,0);

                        /*Menuliskan Peta di awal giliran*/
                        for (int j = 1;j <= Neff(P);j++){
                            printf("%s", NamaPemain(P)[j]);
                            int lenNama = strlen(NamaPemain(P)[j]);
                            while (lenNama < 10){
                                printf(" ");
                                lenNama++;
                            }
                            printf(": ");
                            PosisiPemain(PetaGame, Pos(P)[j]);
                            printf("\n");
                        }
                        printf("\n");
                        
                    /*Prosedur command akan meminta user untuk memasukkan command yang tersedia lalu akan menjalankan fitur command sesuai input user */
                        command(&PetaGame, &P, &S, x, &GameBerakhir, &EndRonde, &JumlahRonde, maxroll) ;
                        x++;
                    }
                    for (x=1;x<=P.Neff;x++)
                    {
                        P.IsDoneRoll[x]=false;
                    }
                    JumlahRonde++;
                    printf("\n");
                    Push(&S,&P);
                }
                printf("Leaderboard\n");
                PeringkatPemain(&P);
                printf("\n");
                valid = true;
                break;
        
            //EXIT
            case 2 : 
                printf("Terima Kasih!\n");
                valid = true;
                break;

            default :
                printf("Silahkan ulangi dengan benar!\n");
                printf("\n");
        }
    }
}    