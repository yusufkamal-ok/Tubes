#include "chiild.h"
#include<iostream>
using namespace std;

void createList_Child(List_child &L) {
    first(L) = NULL;
}

address_child alokasiChild(infotype_Child x) {
    address_child P = new elmlist_child;
    info(P).nama = x.nama;
    info(P).saluran = x.saluran;
    info(P).kode = x.kode;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void dealokasi_Child(address_child &P){
    delete P;
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
}

void insertAfter_Child(List_child &L, address_child &Prec, address_child P) {
    next(P)=next(Prec);
    prev(P)=Prec;
    prev(next(Prec))=P;
    next(Prec) = P;
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
}
