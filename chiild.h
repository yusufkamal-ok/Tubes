#ifndef CHIILD_H_INCLUDED
#define CHIILD_H_INCLUDED
#include <iostream>
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define parent(P) P->parent
#define info(P) P->info
#include<bits/stdc++.h>
using namespace std;

typedef struct elmlist_child *address_child;

struct channel{
    string nama;
    int saluran;
    int kode;
};
typedef channel infotype_Child;
struct elmlist_child{
    infotype_Child info;
    address_child next;
    address_child prev;

};


struct List_child{
    address_child first;
};


void createList_Child(List_child &L);
void insertFirst_Child(List_child &L, address_child P);
void insertLast_Child(List_child &L, address_child P);
void insertAfter_Child(List_child &L, address_child Prec, address_child P);
void deleteFirst_Child(List_child &L, address_child &P);
void deleteLast_Child(List_child &L, address_child &P);
void deleteAfter_Child(address_child Prec, address_child &P);
address_child alokasiChild(infotype_Child x);
void dealokasi_Child(address_child &P);
address_child searchID_Child(List_child L, int y);
void printInfo_Child(List_child L);

/*
NAMA: YUSUF KAMAL
NIM : 1301190464
NAMA: Reyhan Fadhlurohman Arrafi
NIM: 1301190356
NAMA : Erlangga Bagja Anugrah
NIM: 1301194393
*/

#endif // CHIILD_H_INCLUDED
