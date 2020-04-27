#include<iostream>
#include"relasi.h"
using namespace std;

address_relasi alokasiRelasi(address_parent P,address_child Q){
    address_relasi R = new elmlist_relasi;
    R->parent = P;
    R->child = Q;
    R->next = NULL;

}
void createListRelasi(List_relasi &l){
    l.First=NULL;
    l.last=NULL;
}
void insertFirstRelasi(List_relasi &l,address_relasi P){
    if(l.First==NULL){
        l.First = P;
        l.last = P;

    }else{
        next(P)=l.First;
        l.First=P;
    }
}
void insertLastRelasi(List_relasi &l,address_relasi P){
    if(l.First==NULL){
        l.First=P;
        l.First=P;
    }else{
        next(l.last)=P;
        l.last=P;
    }
}
void insertAfterRelasi(address_relasi Prec,address_relasi P){
    P = next(Prec);
    next(Prec)=P;
}
void deleteFirstRelasi(List_relasi &l,address_relasi &P){
    P=l.First;
    if(l.First->next!=NULL){
        l.First=next(P);
        next(P)=NULL;
    }else{
        l.First=NULL;
    }
}
void deleteAfterRelasi(address_relasi Prec,address_relasi &P){
    P = next(Prec);
    next(Prec)=next(P);
    next(P)=NULL;
}
void deleteLastRelasi(List_relasi &l,address_relasi &P){
    address_relasi temp=l.First;
    P = l.First;
    while(next(temp)!=l.last){
        temp=next(temp);
    }
    l.last=temp;
    next(l.last)=NULL;
}
void checkConnect(List_relasi &l,List_child &l1,List_parent &l2,address_child &Q,address_parent &R,address_relasi &S){
    int a;
    int b;
    cout<<"kode channel :";
    cin>>a;
    cout<<"ID pelanggan : ";
    cin>>b;
    Q=searchID_Child(l1,a);
    R=searchID_Parent(l2,b);
    if(Q&&R){
        S=alokasiRelasi(R,Q);
        insertLastRelasi(l,S);
        cout<<"selamat anda telah berlangganan di channel "<<endl;

    }else{
        cout<<"maaf anda tidak terdaftar sebagi pelanggan channel"<<endl;
    }

}

/*
NAMA: YUSUF KAMAL
NIM : 1301190464
NAMA: Reyhan Fadhlurohman Arrafi
NIM: 1301190356
NAMA : Erlangga Bagja Anugrah
NIM: 1301194393
*/
