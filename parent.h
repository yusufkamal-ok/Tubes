#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include<iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#include<bits/stdc++.h>

typedef struct elmlist_parent *address_parent;
const int g=20;
struct pelanggan{
    char nama[g];
    int noTelp;
    int ID;
};
typedef pelanggan infotype_Parent;
struct elmlist_parent {
    infotype_Parent info;
    address_parent next;

};

struct List_parent {
    address_parent first;
};
void createList_Parent(List_parent &L);
address_parent alokasiParent(infotype_Parent z);
void printInfo_Parent(List_parent L);
void insertFirst_Parent(List_parent &L, address_parent P);
void insertAfter_Parent(List_parent &L, address_parent Prec, address_parent P);
void insertLast_Parent(List_parent &L, address_parent P);
void deleteFirst_Parent(List_parent &L, address_parent &P);
void deleteLast_Parent(List_parent &L, address_parent &P);
void deleteAfter_Parent(List_parent &L, address_parent Prec, address_parent &P);
void dealokasi_Parent(address_parent &P);
address_parent searchID_Parent(List_parent L, int x);


#endif // PARENT_H_INCLUDED
