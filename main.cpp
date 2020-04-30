#include <iostream>
#include"parent.h"
#include"chiild.h"
#include"relasi.h"

using namespace std;
/* NAMA: YUSUF KAMAL
 NIM : 1301190464
 NAMA: Reyhan Fadhlurohman Arrafi
 NIM: 1301190356
 NAMA : Erlangga Bagja Anugrah
 NIM: 1301194393
 */

infotype_Parent a;
infotype_Child b;
List_parent P;
List_child Q;
List_relasi R;
address_child child;
address_parent parent;
address_relasi relasi;
bool cek;
int main()
{
    createList_Child(Q);
    createList_Parent(P);
    createListRelasi(R);

    int pilihMenu,in1,in2,in3;

    do{
        system("CLS");
        cout<<"=============================="<<endl;
        cout<<"**          MENU           **"<<endl;
        cout<<"=============================="<<endl;
        cout<<" 1. Input Pelanggan            "<<endl;
        cout<<" 2. Print Semua Pelanggan      "<<endl;
        cout<<" 3. Input Channel            "<<endl;
        cout<<" 4. Print Channel            "<<endl;
        cout<<" 5. Connect            "<<endl;
        cout<<" 6. Check Connect            "<<endl;
        cout<<" 7. Disconnect            "<<endl;
        cout<<" 8. Print Relasi            "<<endl;
        cout<<" 9. Search Pelanggan            "<<endl;
        cout<<" 10. Delete Pelanggan            "<<endl;
        cout<<" 11. Delete Channel            "<<endl;
        cout<<"==============================="<<endl;
        cout<<" Pilih menu : ";
        cin>>pilihMenu;

        switch(pilihMenu){
            case 1:{
                system("CLS");
                cout<<"======Input Pelanggan======"<<endl;
                cout<<" ID   : ";
                cin>>a.ID;
                cout<<"no telp  : ";
                cin>>a.noTelp;
                cout<<"nama pelanggan : ";
                cin>>a.nama;
                if(first(P)==NULL){
                    insertFirst_Parent(P,alokasiParent(a));
                }else{
                    address_parent S = first(P);
                    while(S!=NULL){
                        if(S->info.ID==a.ID){
                            cek= true;
                        }
                        S = next(S);
                    }
                    if(!cek){
                        insertLast_Parent(P,alokasiParent(a));
                    }else{
                        cout<<"ID sudah ada "<<endl;
                    }
                }

                break;
            }

            case 2 :{
                system("CLS");
                cout<<"===Info Data Pelanggan===="<<endl;
                printInfo_Parent(P);

            }
            break;


        case 3 :{
            system("CLS");
            cout<<"====Input Channel===="<<endl;
            cout<<" ID Channel :";
            cin>>b.kode;
            if(searchID_Child(Q,b.kode)==NULL){
                cout<<"Masukkan Nama Channel : ";
                cin>>b.nama;
                cout<<"Masukkan ID Channel  :";
                cin>>b.kode;
                insertSorted_child(Q,b);
                cout<<endl;
                cout<<" Data channel telah terdaftar "<<endl;

            }else{
                cout<<endl;
                cout<<" ID telah digunakan coba lagi "<<endl;
            }
        }
        case 4 :{
            system("CLS");
            cout<<"===Info Channel===="<<endl;
            printInfo_Child(Q);
        }
        break;

        case 5 : {
            system("CLS");
            cout<<"===Connect==="<<endl;
            cout<<"ID Pelanggan : ";
            cin>>in1;
            cout<<"ID Channel : ";
            cin>>in2;
            connention(R,Q,P,in1,in2);

        }
        break;

        case 6 :{
            system("CLS");
            cout<<"===Check Connection==="<<endl;
            cout<<"ID Pelanggan  ";
            cin>>in1;
            cout<<"ID Channel " ;
            cin>>in2;
            if(checkConnect(R,Q,P,child,parent,relasi)!=NULL){
                address_parent S = searchID_Parent(P,in1);
                address_child T = searchID_Child(Q,in2);
                cout<<endl;
                cout<<"Pelanggan "<<S->info.nama<<"mensubcription  channel"<<T->info.nama;

            }else{
                cout<<endl;
                cout<<"Pelanggan tidak mensubcription";
            }
        }
        break;

        case  7 :{
            system("CLS");
            cout<<"===Disconnect==="<<endl;
            cout<<" ID pelanggan : ";
            cin>>in1;
            cout<<" ID channel :";
            cin>>in2;
            disconnect(R,Q,P,in1,in2);
            cout<<"Disconnect dilakukan";
            cout<<endl;
            cout<<"Press any key to continue";
        }
        break;

        case 8 :{
            system("CLS");
            printInfo_Relasi(R);
        }
        break;

        case 9 :{
            system("CLS");
            cin>>in3;
            address_parent S = searchID_Parent(P,in3);
            address_relasi T = R.First;
            if(S==NULL){
                cout<<"ID Pelanggan "<<in3<<"tidak di temukan"<<endl;

            }else{
                cout<<"ID Pelanggan :"<<S->info.ID<<endl;
                if(T!=NULL){
                    cout<<"ID Channel :";
                    do{
                        if(T->parent==S){
                            cout<<" "<<T->child->info.kode;
                        }
                        T = T->next;
                    }while(T!=NULL);
                }
            }
            cout<<" Press any key to continue";
        }
        break;

        case 10 :{
            system("CLS");
            cout<<"==Delete Pelanggan=="<<endl;
            cout<<"ID Pelanggan : ";
            cin>>in3;
            deleteParent(R,P,in3);
            cout<<endl;
            cout<<"Press any key to continue";
        }
        break;

        case 11 :{
            system("CLS");
            cout<<"==Delete Channel== "<<endl;
            cout<<" ID channel :";
            cin>>in3;
            deleteChild(R,Q,in3);
            cout<<"Press any key to continue";

        }
        break;
        }
    }while(pilihMenu != 0);
    return 0;

}




