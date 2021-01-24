#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "UnEnsemble.h"


int main()
{
    UnEnsemble Ens(3);
    int tab[3]={1,2,3};
    UnEnsemble Ensemble(tab,3,5);
    Ens.afficheToi();
    Ensemble.afficheToi();
    cout <<endl<<"\"0\" est-il dans l'ensemble:"<< Ensemble.contient(0)<<endl;
    cout <<"\"2\" est-il dans l'ensemble:"<< Ensemble.contient(2)<<endl;
    UnEnsemble test(tab,2,2);
    test.afficheToi();
    cout << "  Est-il inclus :"<< Ensemble.estInclus(test);
    Ens.ajoute(8);
    Ens.ajoute(9);
    Ens.afficheToi();
    Ens.supprime(8);
    Ens.afficheToi();
}
