#include<iostream>
#include"relasi.h"


address_relasi alokasiRelasi(address_parent P,address_child Q){
    address_relasi R = new elmlist_relasi;
    R->parent = P;
    R->child = Q;
    R->next = NULL;

    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/

}
void createListRelasi(List_relasi &l){
    l.First=NULL;
    l.last=NULL;

    /* NAMA: Reyhan Fadhlurohman Arrafi
                                                             NIM :1301190356*/
}
void insertFirstRelasi(List_relasi &l,address_relasi P){
    if(l.First==NULL){
        l.First = P;
        l.last = P;

    }else{
        next(P)=l.First;
        l.First=P;
    }

    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}
void insertLastRelasi(List_relasi &l,address_relasi P){
    if(l.First==NULL){
        l.First=P;
        l.First=P;
    }else{
        next(l.last)=P;
        l.last=P;
    }

    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}
void insertAfterRelasi(address_relasi Prec,address_relasi P){
    P = next(Prec);
    next(Prec)=P;


    /* NAMA: Reyhan Fadhlurohman Arrafi
                                                             NIM :1301190356*/
}
void deleteFirstRelasi(List_relasi &l,address_relasi &P){
    P=l.First;
    if(l.First->next!=NULL){
        l.First=next(P);
        next(P)=NULL;
    }else{
        l.First=NULL;
    }
    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}
void deleteAfterRelasi(address_relasi Prec,address_relasi &P){
    P = next(Prec);
    next(Prec)=next(P);
    next(P)=NULL;

    /* NAMA: Reyhan Fadhlurohman Arrafi
                                                             NIM :1301190356*/
}
void deleteLastRelasi(List_relasi &l,address_relasi &P){
    address_relasi temp=l.First;
    P = l.First;
    while(next(temp)!=l.last){
        temp=next(temp);
    }
    l.last=temp;
    next(l.last)=NULL;

    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}
address_relasi checkConnect(List_relasi &l,List_child &l1,List_parent &l2,address_child &Q,address_parent &R,address_relasi &S){
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



    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/

}
void connention(List_relasi &l,List_child l1, List_parent l2,int x,int y){
    address_parent P = searchID_Parent(l2,y);
    address_child Q = searchID_Child(l1,x);
    insertLastRelasi(l,alokasiRelasi(P,Q));

    /* NAMA: Erlangga Bagja Anugrah
                                                             NIM :1301194393*/
}
void dealokasi_Relasi(address_relasi &R){
    delete R;
    /* NAMA: Erlangga Bagja Anugrah
                                                             NIM :1301194393*/
}
void disconnect(List_relasi &l,List_child l1, List_parent l2,int x,int y){
    address_parent P = searchID_Parent(l2,y);
    address_child Q = searchID_Child(l1,x);
    address_relasi R = l.First,S;
    if(P!=NULL && Q!=NULL){
        if(R->parent==P && R->child == Q){
        R->child =NULL;
        R->parent =NULL;
        deleteFirstRelasi(l,R);
    }else{
        while (R != NULL && R->next->parent != P && R->next->child != Q){
            R=next(R);
        }
        if(R->next==l.last){
            R->next->child=NULL;
            R->next->parent=NULL;
            deleteLastRelasi(l,R);
        }else{
            R->child=NULL;
            R->parent=NULL;
            S=R;
            R=R->next;
            deleteAfterRelasi(S,R);
        }
        dealokasi_Relasi(R);
    }
    }

    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}
void printInfo_Relasi(List_relasi l){
    address_relasi Q;
    if(l.First==NULL){
        cout<<"======================================"<<endl;
        cout<<"Daftar pelanggan channel subscribetion"<<endl;
        cout<<"======================================"<<endl;
        cout<<" Tidak ada pelanggan channel subscribetion"<<endl;

    }else{
        cout<<"====================================="<<endl;
        cout<<"Daftar pelanggan channel subsribetion"<<endl;
        cout<<"====================================="<<endl;
        Q=l.First;
        do{
            cout<<"ID pelanggan :"<<Q->parent->info.ID<<endl;
            cout<<"No telp pelanggan :"<<Q->parent->info.noTelp<<endl;
            cout<<"nama :"<<Q->parent->info.nama<<endl;
            cout<<"Data channel"<<endl;
            cout<<"ID Channel : "<<Q->child->info.kode<<endl;
            cout<<"Bsnysk subscribtion:"<<Q->child->info.saluran<<endl;
            cout<<"nama channel :"<<Q->child->info.nama<<endl;
            cout<<endl;
            Q=Q->next;

        }while(Q!=NULL);
        cout<<"================"<<endl;
        cout<<endl;
    }

    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}
void deleteParent(List_relasi &l,List_parent &l1,int a){
    address_parent P = searchID_Parent(l1,a);
    address_relasi Q = l.First,R;
    if(P!=NULL){
        while(Q!=NULL){
            if(Q->parent==P){
                if(Q==l.First){
                    Q->child=NULL;
                    Q->parent=NULL;
                    Q=Q->next;
                    deleteFirstRelasi(l,R);
                    dealokasi_Relasi(R);
                }else{
                    deleteAfterRelasi(Q,R);
                    Q=Q->next;
                    dealokasi_Relasi(R);
                }
            }else{
        Q=Q->next;
        }

    }
    if(P==l1.first){
        deleteFirst_Parent(l1,P);
    }else if(P->next==NULL){
        deleteLast_Parent(l1,P);
    }else{
        address_parent temp = l1.first;
        while(temp->next!=P){
            temp = temp->next;
        }
        deleteAfter_Parent(l1,temp,P);
    }
    dealokasi_Parent(P);
    }else{
        cout<<"ID pelanggan tidak di temukan"<<endl;
    }

    /* NAMA: YUSUF KAMAL
                                                             NIM : 1301190464*/
}
void deleteChild(List_relasi &l,List_child l1,int a){
    address_child P = searchID_Child(l1,a);
    address_relasi Q = l.First,R;
    if(P!=NULL){
        while(Q!=NULL){
            if(Q->child==P){
                if(Q==l.First){
                    Q->child=NULL;
                    Q->parent=NULL;
                    Q=Q->next;
                    deleteFirstRelasi(l,R);
                    dealokasi_Relasi(R);
                }else{
                    deleteAfterRelasi(Q,R);
                    Q=Q->next;
                    dealokasi_Relasi(R);
                }
            }else{
        Q=Q->next;
        }

}
deleteLast_Child(l1,P);
    }else{
        cout<<"ID channel tidak ditemukan "<<endl;
    }
    /* NAMA: Reyhan Fadhlurohman Arrafi
                                                             NIM :1301190356*/
}




