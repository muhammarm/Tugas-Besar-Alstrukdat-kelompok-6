/* Nama : William Gunawan
   NIM  : 18220077
   Kelas : 1
   tanggal : 27 Oktober 2021
   */

#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return (First(L) == Nil);
}

void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *P = (ElmtList *) malloc (sizeof (ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    } else
    {
        return Nil;
    }
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    boolean Found = false;
    address Found_address = Nil;
    address El = First(L);

    if (!IsEmpty(L))
    {
      do
      {
          if (Info(El) == X)
          {
              Found_address = El;
              Found = true;
          }
          else
          {
              El = Next(El);
          }
      }
      while ((El != Nil) && (!Found));
    }
    return Found_address;
}

void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = Alokasi(X);
    if (P != Nil)
    {
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi(X);
    if (P != Nil)
    {
        InsertLast(L, P);
    }
}

void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address Last = First(*L);
    if (IsEmpty(*L))
    {
        Next(P) = Nil;
        First(*L) = P;
    } else
    {
        while (Next(Last) != Nil) {
            Last = Next(Last);
       }
       InsertAfter(L, P, Last);
    }
}

void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    if (Next(First(*L)) == Nil)
    {
        CreateEmpty(L);
    } else
    {
        First(*L) = Next(First(*L));
    }
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = Search(*L, X);
    address Prec = First(*L);
    if (P != Nil)
    {
        address Prec = First(*L);
    }
        if (Prec == P) {
            DelFirst(L, &P);
        } else
        {
            while (Next(Prec) != P)
            {
                Prec = Next(Prec);
            }
            DelAfter(L, &P, Prec);
        }
        Dealokasi(&P);
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    if (Next(First(*L)) == Nil)
    {
        *P = First(*L);
        CreateEmpty(L);
    }
    else
    {
        address Prec = First(*L);
        while (Next(Next(Prec)) != Nil)
        {
            Prec = Next(Prec);
        }

        DelAfter(L, P, Prec);
    }
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    if (*Pdel != Nil)
        Next(Prec) = Next(Next(Prec));
}

void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmpty(L))
    {
        address El = First(L);

        do
        {
            printf("%d", Info(El));
            El = Next(El);

            if (El != Nil)
            {
                printf(",");
            }
        }
        while (El != Nil);
    }
    printf("]");
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    address El = First(L);

    while (El != Nil) {
        El = Next(El);
        count = count + 1;
    }
    return count;
}

infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    address P = First(L);
    infotype Maximum = Info(P);

    while (P != Nil) {
        if (Info(P) >= Maximum)
        {
            Maximum = Info(P);
        }
        P = Next(P);
    }
    return Maximum;
}

void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    address Last1 = First(*L1);
    CreateEmpty(L3);

    if (!IsEmpty(*L1))
    {
        First(*L3) = First(*L1);
        address Last1  = First(*L1);
        while (Next(Last1) != Nil)  {
            Last1  = Next(Last1);
        }
        Next(Last1) = First(*L2);
    } else
    {
        First(*L3) = First(*L2);
    }

    CreateEmpty(L1);
    CreateEmpty(L2);
}
