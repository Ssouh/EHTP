#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int j, int m, int a)
{
    //sonJour= (0<j&&j<31)? j:0;
    sonJour=j;
    sonMois=m;
    sonAnnee=a;
}

void Date::verification()
{
    while (0>sonJour || sonJour > 31 )
        {
            cout << "Jour Invalide! , Entrer a nouveau le Jour : " << endl;
            cin >> sonJour;
        }

     while (0> sonMois || sonMois >12)
        {
            cout << "Mois Invalide! , Entrer a nouveau le Mois : " << endl;
            cin >> sonMois;
        }
}

void Date::afficheToi()
{
    cout << "La date : " << sonJour << "/" << sonMois << "/" << sonAnnee << endl;
}
