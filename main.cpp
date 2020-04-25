#include <iostream>
#include"parent.h"
#include"chiild.h"
using namespace std;
//nama:yusuf kamal
//

infotype_Child x;
infotype_Parent b;
address_parent v;
address_child n;
List_parent p;
List_child q;
int main()
{
    cout << "masukan nama";
    cin>>b.nama;
    cout<<"masukan no telp";
    cin>>b.noTelp;
    cout<<"masukan id";
    cin>>b.ID;
    v=alokasiParent(b);
    insertFirst(p,v);
    printInfo(p);
    cin>>x.nama;
    cin>>x.saluran;
    cin>>x.ID;
    n=alokasiChild(x);
    insertFirst(q,n);
    printInfo(q);
    return 0;
}
