#include <iostream>
#include "UnEnsemble.h"
using namespace std;



int main()
{
    UnEnsemble N;
    N.ajoute(5);
    N.ajoute(3);
    N.ajoute(1);
    N.ajoute(4);

    UnEnsemble Q;
    Q.ajoute(1);
    Q.ajoute(3);
    Q.ajoute(8);


    N.afficheToi();
    Q.afficheToi();

    cout << Q.estInclus(N) ;
    return 0;
}
