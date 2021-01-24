#include "PointNomme.h"
#include <iostream>
#include <string.h>

using namespace std;

PointNomme::PointNomme(int a, int b, char* chaine) : Point(a,b)
{

    nom = new char[   strlen(chaine) + 1  ];
    strcpy(nom,chaine);
}


PointNomme::PointNomme(const PointNomme& PtNomme){

    nom = new char[ strlen(PtNomme.nom)+1   ];
    strcpy(nom,PtNomme.nom);
}

PointNomme& PointNomme::operator=(const PointNomme& PtNomme)
{
    if (this!=&PtNomme)
    {
        nom = new char[strlen(PtNomme.nom) + 1];
        strcpy(nom,PtNomme.nom);
    }

}


void PointNomme::afficheToi(){

    Point::afficheToi();
    cout <<" | Nom : " << nom ;
}

PointNomme::~PointNomme()
{
    delete []nom;
}
