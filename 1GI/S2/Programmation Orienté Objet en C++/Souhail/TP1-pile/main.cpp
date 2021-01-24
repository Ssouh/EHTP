#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include "pile.h"


///**************************  EX 04:  ***********************************

int main()
{
    cellule cel; cel.etat="Voila";cel.suivant=NULL;
//    cellule ce2; ce2.etat="Vvvvoila";ce2.suivant=&ce1;
    Unepile pile(cel);
//    Unepile P(ce2);
    Unepile pile_Null;
    pile.afficheToi();
//    P.afficheToi();
    pile_Null.afficheToi();
    cout <<endl<< pile.estvide()<<endl;
    cout << pile_Null.estvide();
    fflush(stdin);
    pile.afficheToi();
    cout <<endl<< pile.estpleine()<<endl;
    cout << pile_Null.estpleine();
    pile.Raz();
    pile.afficheToi();
    pile_Null.afficheToi();

}

