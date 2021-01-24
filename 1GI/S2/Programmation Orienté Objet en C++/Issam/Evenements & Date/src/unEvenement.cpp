#include <iostream>
#include "unEvenement.h"
using namespace std;

unEvenement::unEvenement(Date d, char* t)
{
    saDate=d;
    Intitule=t;
}

void unEvenement::afficheToi()
{
    cout << "Evenement : " << Intitule << " - ";
    saDate.afficheToi();
}
