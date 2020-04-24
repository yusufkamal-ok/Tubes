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
void insertLastRelasi(address_relasi &l,address_relasi P);
void insertAfterRelasi(address_relasi Prec,address_relasi P);
void deleteFirstRelasi(address_relasi &l,address_relasi &P);
void deleteAfterRelasi(address_relasi Prec,address_relasi &P);
void deleteLastRelasi(address_relasi &l,address_relasi &P);
void checkConnect(List_relasi l,List_child L1,List_parent L2,string a,int b);
#endif // RELASI_H_INCLUDED
