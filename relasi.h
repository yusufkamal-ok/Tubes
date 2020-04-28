#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include"parent.h"
#include"chiild.h"
#include<iostream>

using namespace std;
typedef struct elmlist_relasi *address_relasi;
struct elmlist_relasi{
    address_relasi next;
    address_parent parent;
    address_child child;

};
struct List_relasi{
    address_relasi First;
    address_relasi last;
};
address_relasi alokasiRelasi(address_parent P,address_child Q);
void createListRelasi(List_relasi &l);
void insertFirstRelasi(address_relasi &l,address_relasi P);
void insertLastRelasi(List_relasi &l,address_relasi P);
void insertAfterRelasi(address_relasi Prec,address_relasi P);
void deleteFirstRelasi(address_relasi &l,address_relasi &P);
void deleteAfterRelasi(address_relasi Prec,address_relasi &P);
void deleteLastRelasi(address_relasi &l,address_relasi &P);
address_relasi checkConnect(List_relasi &l,List_child &l1,List_parent &l2,address_child &Q,address_parent &R,address_relasi &S);
void connention(List_relasi &l,List_child l1, List_parent l2,int x,int y);
void dealokasi_Relasi(address_relasi &R);
void disconnect(List_relasi &l,List_child l1, List_parent l2,int x,int y);
void printInfo_Relasi(List_relasi l);
void deleteParent(List_relasi &l,List_parent &l1,int a);
void deleteChild(List_relasi &l,List_child l1,int a);
#endif // RELASI_H_INCLUDED
