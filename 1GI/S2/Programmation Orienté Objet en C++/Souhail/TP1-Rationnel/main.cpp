#include <iostream>
#include "class.h"
using namespace std;

///**************************  EX 03:  ***********************************


int main()
{
    UnRationnel i(17,2),j(10,3),k,x;
    k.somme(i,j);/// k = 17/2 + 10/3
    k.affiche();
    x.lire();
    x.affiche();
    k.produit(i,j);/// k= 17/2 * 10/3
    k.affiche();
    cout<<"*********** LE PGCD ***************"<<endl;
    cout<<x.pgcd()<<endl;
    x.reduit();
    x.affiche();
    cout << k.egalite(j) << endl ;
    x.retourneOperation(i,j).affiche();
}

