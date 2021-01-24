#include <iostream>
#include "UnRationnel.h"

using namespace std;

int main()
{
    /* Programme de test */


    UnRationnel fraction;
    UnRationnel f1(9,2),f2(2,-1),f3(-4,-7);

    // Test d'operateur d'affectation
    fraction = f1;
    cout << "on affecte " << f1 << " a fraction, fraction = " << fraction << endl;

    fraction = f2;
    cout << "on affecte "<< f2 << " a fraction, fraction = " << fraction << endl;

    fraction = f3;
    cout << "on affecte "<< f3 <<" a fraction, fraction = " << fraction << endl<< endl;

    // Operateurs Logiques
    UnRationnel f4(9,2),f5(11,2);
    cout << f1 << " = " << f4 << "? : " << (f1 == f4) << endl;
    cout << f1 << " = " << f2 << "? : " << (f1 == f2) << endl << endl;

    cout << f1 << " != " << f4 << "? : " << (f1 != f4) << endl;
    cout << f1 << " != " << f2 << "? : " << (f1 != f2) << endl << endl;

    cout << f1 << " <= " << f2 << "? : " << (f1 <= f2) << endl;
    cout << f5 << " > " << f1 << "? : " << (f1 > f2) << endl << endl;

    // Entrées-Sorties
    cout << "Entrer une fraction : " << endl;
    cin >> fraction;
    cout << "Vous avez entre comme fraction : " << fraction << endl;


}
