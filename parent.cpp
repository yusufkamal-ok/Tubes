#include"parent.h"
#include <string>
using namespace std;

void createList(List_parent &L) {
    L.first = NULL;
}

address_parent alokasiParent(infotype_Parent z) {

    address_parent P;
    P = new elmlist_parent;
    info(P).nama[g]=z.nama[g];
    info(P).noTelp=z.noTelp;
    info(P).ID=z.ID;
    P->next = NULL;
    return P;
}
void printInfo_Parent(List_parent L) {

    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<info(P).nama<<endl;
            cout<<info(P).noTelp<<endl;
            cout<<info(P).ID<<endl;
            P = next(P);
        } while((P)!=first(L));
    }
}
void insertFirst_Parent(List_parent &L, address_parent P) {

    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}
address_parent searchID_Parent(List_parent L, int x) {

    address_parent P = first(L);
    do {
        if(info(P).ID == x) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}
void dealokasi_Parent(address_parent &P){
    delete P;
}
void insertAfter_Parent(List_parent &L, address_parent Prec, address_parent &P){
    if(Prec!=NULL){
        if(Prec->next==NULL){
            insertLast_Parent(L,P);
        }else{
            next(P)=next(Prec);
            next(Prec)=P;
        }
    }
}
void insertLast_Parent(List_parent &L, address_parent P){
    if(first(L)==NULL){
        insertFirst_Parent(L,P);

    }else{
        address_parent Q = first(L);
        while(next(Q)!=NULL){
            Q=next(Q);
        }
        next(Q)=P;
    }
}
void deleteFirst_Parent(List_parent &L, address_parent &P){
    if(first(L)==NULL){
        cout<<"TIdak ada data"<<endl;
    }else{
        if(next(first(L))==NULL){
            P=first(L);
            first(L)=NULL;
        }else{
            P=first(L);
            first(L)=next(P);
            next(P)=NULL;
        }
    }

}
void deleteLast_Parent(List_parent &L, address_parent &P){
    if(first(L)!=NULL){
        if(next(first(L))==NULL){
            P=first(L);
            first(L)=NULL;
        }else{
            address_parent Q = first(L);
            while(next(next(Q))!= NULL){
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
        }
    }
}
void deleteAfter_Parent(List_parent &L, address_parent Prec, address_parent &P){
    if(Prec != NULL){
        if(next(next(Prec))== NULL){
            deleteLast_Parent(L,P);
        }else{
            address_parent Q = next(P);
            next(Prec) = Q;
            next(P) = NULL;
        }
    }
}
