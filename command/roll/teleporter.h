/* File : teleporter.h */
/* ADT teleporter menggunakan list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef teleporter_H
#define teleporter_H

#include "boolean.h"
#include "roll.h"

#define Nil NULL

/* Definisi Type Data */
typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype teleMasuk;
    infotype teleKeluar;
	address next;
} ElmtTele;
typedef struct {
	address First;
} Tele;

/* Definisi list Tele : */
/* List tele kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Masuk(P), Keluar(P), Next(P) */
/* Elemen terakhir list tele : jika addressnya Last, maka Next(Last)=Nil */

/* Notasi Akses */
#define Masuk(P) (P)->teleMasuk
#define Keluar(P) (P)->teleKeluar
#define Next(P) (P)->next
#define First(L) (L).First

/* PROTOTYPE */
/****************** TEST TELEPORT KOSONG ******************/
boolean IsEmptyTele (Tele L);
/* Mengirim true jika tele kosong */

/****************** PEMBUATAN TELEPORT KOSONG ******************/
void CreateEmptyTele (Tele *L);
/* I.S. sembarang             */
/* F.S. Terbentuk tele kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X, infotype Y);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Masuk(P)=X, Keluar(P)=Y, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (Tele L, infotype X);
/* Mencari apakah ada elemen list dengan Masuk(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (Tele *L, infotype X, infotype Y);
/* I.S. Tele mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai masuk X dan keluar y jika alokasi berhasil */

void InsertFirst (Tele *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

/****************** PROSES SEMUA ELEMEN TELEPORTER ******************/
int teleporter(Tele L, Player *P, int besarMap); 
// fungsi untuk menentukan sebuah petak termasuk dalam list Tele atau hanya petak kosong.
// Lalu, jika player tidak memiliki imunitas teleport akan berpindah posisi mengikuti teleportnya

#endif