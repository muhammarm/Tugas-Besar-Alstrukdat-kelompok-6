#include<stdio.h>
#include<stdlib.h>
#include "teleporter.h"

/* PROTOTYPE */
/****************** TEST TELEPORT KOSONG ******************/
boolean IsEmptyTele (Tele L){
    return First(L) == Nil;
}
/* Mengirim true jika tele kosong */

/****************** PEMBUATAN TELEPORT KOSONG ******************/
void CreateEmptyTele (Tele *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk tele kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X, infotype Y){
    address P;
	P = (ElmtTele *)malloc(sizeof(ElmtTele));
    if (P != Nil) {
        Masuk(P) = X;
        Keluar(P) = Y;
        Next(P) = Nil;
 		return P;
 	}
 	else {
 		return Nil;
	}
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Masuk(P)=X, Keluar(P)=Y, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (Tele L, infotype X){
    address P;
	boolean found = FALSE;
	P = First(L);
	while (P != Nil && found == FALSE){
    	if (Masuk(P) == X) {
            found = TRUE;
        }
        else {
            P = Next(P);
        }
    }
	return P;
}
/* Mencari apakah ada elemen list dengan Masuk(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (Tele *L, infotype X, infotype Y){
    address P;
	P = Alokasi(X,Y);
	if (P != Nil){
		InsertFirst(L, P);
	}
}
/* I.S. Tele mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai masuk X dan keluar y jika alokasi berhasil */

void InsertFirst (Tele *L, address P){
    Next(P) = First(*L);
	First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

/****************** PROSES SEMUA ELEMEN TELEPORTER ******************/
int teleporter(Tele L, Player *P, int besarMap){
    if(Search(L,Posisi(*P)+1)!=Nil){
        address tele = Search(L,Posisi(*P)+1);
        printf("%s menemukan teleporter.\n%s tidak memiliki imunitas teleport.\n", Nama(*P),Nama(*P));
        Posisi(*P) = Keluar(tele)-1;
        printf("%s teleport ke petak %d\n",Nama(*P), Posisi(*P)+1);
    }else if(Posisi(*P)==besarMap-1){
        // do nothing, tidak memberikan output "tidak menemukan teleporter" jika posisi player berada pada ujung/finish
    }else{
        printf("%s tidak menemukan teleporter.\n", Nama(*P));
    }
} 
// fungsi untuk menentukan sebuah petak termasuk dalam list Tele atau hanya petak kosong.
// Lalu, jika player tidak memiliki imunitas teleport akan berpindah posisi mengikuti teleportnya