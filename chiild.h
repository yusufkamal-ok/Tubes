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
    int ID;
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

/** TIDAK PERLU MODIFIKASI */
void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertLast(List_child &L, address_child P);
void insertAfter(List_child &L, address_child Prec, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(address_child Prec, address_child &P);


/** PERLU MODIFIKASI */
address_child alokasiChild(infotype_Child x);
void dealokasi(address_child &P);
address_child searchID(List_child L, int y);
void printInfo(List_child L);



#endif // CHIILD_H_INCLUDED
