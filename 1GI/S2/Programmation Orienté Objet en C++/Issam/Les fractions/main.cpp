#include <iostream>
using namespace std;
#include "UnRationnel.h"


int main()
{

    /* programme de calcul de somme */
    UnRationnel i(1,5),j(2,3),k(1,1),y(30,10),z(2,15);
    k.somme(i,j); // k = 13/15
    k.affiche();

    /* Test de lecture
    UnRationnel x;
    x.lire();
    x.affiche(); */

    /*Test de calcul de produit */
    k.produit(i,j);
    k.affiche();

    /* test d'egalité */
    cout << k.egales(j) << endl ;
    cout << k.egales(k) << endl ;

    /* PGCD */
    cout << z.pgcd() << endl;
    cout << y.pgcd() << endl;

    /* Reduction */
    y.affiche();
    y.reduit();
    y.affiche();



}


