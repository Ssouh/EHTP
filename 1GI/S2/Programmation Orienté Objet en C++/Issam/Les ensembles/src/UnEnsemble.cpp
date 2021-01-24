#include "UnEnsemble.h"
#include <iostream>


using namespace std;

UnEnsemble::UnEnsemble(int n,Noeud* p)
{
    tete=p;
    sonCardinal=n;
}


bool UnEnsemble::contient(int telEntier)
{
    Noeud* p=this->tete;
    while(p)
    {
        if (p->Element==telEntier)
            return 1;
        p=p->suivant;

    }

    return 0;
}

bool UnEnsemble::estInclus(UnEnsemble telEnsemble)
{

    Noeud* p=this->tete;
    while(p)
    {

        for (int i=0; i<telEnsemble.sonCardinal; i++)
        {
            if (!telEnsemble.contient(p->Element))
                return 0;
        }

        p=p->suivant;
    }

    return 1;

}


void UnEnsemble::afficheToi()
{
    Noeud* p=this->tete;

    cout << "Ensemble de cardinal " << sonCardinal << " : " ;
    while(p)
    {
        cout << p->Element << " | ";
        p=p->suivant;
    }
    cout << endl;
}

void UnEnsemble::ajoute(int telEntier)
{
    Noeud* nouveau;
    nouveau= new Noeud();
    nouveau->Element=telEntier;
    nouveau->suivant=this->tete;
    this->tete=nouveau;
    sonCardinal++;
}
