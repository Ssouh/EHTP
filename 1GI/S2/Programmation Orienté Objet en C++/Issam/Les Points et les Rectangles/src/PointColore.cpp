#include "PointColore.h"
#include <iostream>

using namespace std;

PointColore::PointColore(int a, int b, char* chaine, int clr) :PointNomme(a,b,chaine)
{
    couleur = clr;
}

PointColore::PointColore(const PointColore& PtColore) :PointNomme(PtColore)
{
    couleur = PtColore.couleur;
}

PointColore& PointColore::operator=(const PointColore& PtColore){

    if (this!=&PtColore)
    {
        this->PointNomme::operator=(PtColore);
        couleur = PtColore.couleur;
    }
}

void PointColore::afficheToi(){

    PointNomme::afficheToi();
    cout << " | Couleur : " << couleur;

}

PointColore::~PointColore()
{

}
