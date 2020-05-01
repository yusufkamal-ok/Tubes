#include "chiild.h"
#include<iostream>
using namespace std;

void createList_Child(List_child &L) {
    first(L) = NULL;

    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}

address_child alokasiChild(infotype_Child x) {
    address_child P = new elmlist_child;
    info(P).nama = x.nama;
    info(P).saluran = x.saluran;
    info(P).kode = x.kode;
    next(P) = NULL;
    prev(P) = NULL;
    return P;

    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}
void dealokasi_Child(address_child &P){
    delete P;

    /* NAMA: Erlangga Bagja Anugrah
                                                             NIM :1301194393*/
}

void insertFirst_Child(List_child &L, address_child P) {
    if(first(L) != NULL){
        next(P)=first(L);
        prev(P)=prev(first(L));
        next(prev(first(L)))=P;
        prev(first(L))=P;
    }else{
        first(L)=P;
        next(P)=P;
        prev(P)=P;
    }

    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}

void printInfo_Child(List_child L) {
    address_child P = first(L);
    if(P !=NULL){
        do{
            cout<<"nama : "<<info(P).nama<<endl;
            cout<<"saluran : "<<info(P).saluran<<endl;
            cout<<"kode channel : "<<info(P).kode<<endl;
            P = next(P);
            cout<<endl;
        }while(P!=first(L));
    }else{
        cout<<"list kosong";
    }
    cout<<endl;
    /* NAMA: Erlangga Bagja Anugrah
                                                             NIM :1301194393*/
}


address_child searchID_Child(List_child L, int y) {
    address_child P = first(L);
    while(P != NULL) {
        if(info(P).kode==y) {
            return P;
        }
        P = next(P);
    }
    return NULL;

    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}

void insertAfter_Child(List_child &L, address_child &Prec, address_child P) {
    next(P)=next(Prec);
    prev(P)=Prec;
    prev(next(Prec))=P;
    next(Prec) = P;

    /* NAMA: Erlangga Bagja Anugrah
                                                             NIM :1301194393*/
}
void insertLast_Child(List_child &L, address_child P){
    if(first(L)!=NULL){
        next(P)=first(L);
        prev(P)=prev(first(L));
        next(prev(first(L)))=P;
        prev(first(L))=P;
    }else{
        first(L)=P;
        next(P)=P;
        prev(P)=P;
    }

    /* NAMA: Erlangga Bagja Anugrah
                                                             NIM :1301194393*/
}
void deleteFirst_Child(List_child &L, address_child &P){
    P = first(L);
    if(next(P) != P){
        first(L) = next(P);
        prev(first(L))=prev(P);
        next(prev(P))=first(L);
        next(P)=NULL;
        prev(P)=NULL;
    }else{
        first(L)=NULL;
    }
    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}
void deleteLast_Child(List_child &L, address_child &P){
    P = prev(first(L));
    if(next(P)!=NULL){
        prev(first(L))=prev(P);
        next(prev(P))=first(L);
        next(P)=NULL;
        prev(P)=NULL;
    }else{
        first(L)=NULL;
    }
    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}
void deleteAfter_Child(List_child &L, address_child Prec, address_child &P){
    P = next(Prec);
    if(next(Prec)!=first(L)){
        next(Prec)=next(P);
        prev(next(P))=Prec;
        next(P)=NULL;
        prev(P)=NULL;
    }else if(next(Prec)==first(L)){
        first(L)=next(first(L));
        deleteAfter_Child(L,Prec,P);
    }else if(next(Prec)==first(L)){
        first(L)=NULL;
    }
    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}
void insertSorted_child(List_child &L, infotype_Child Y){
    if(first(L)==NULL || info(first(L)).kode > Y.kode){
        insertFirst_Child(L,alokasiChild(Y));
    }else{
        address_child Q = next(first(L));
        while(Q->next != first(L) && Y.kode > Q->info.kode){
            Q = Q->next;
        }
        if(Q->next==first(L) && Y.kode > Q->info.kode){
            insertLast_Child(L,alokasiChild(Y));
        }
    }
    /* NAMA: Erlangga Bagja Anugrah
                                                             NIM :1301194393*/
}
