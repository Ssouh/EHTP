#include <iostream>
#include "Unrectangle.h"
#include "point.h"
using namespace std;

Unrectangle::Unrectangle(int x,int y,int longeur,int hauteur):sommet_HG(x,y)
{
    Long_dimension=longeur;
    Larg_dimension=hauteur;
}
void Unrectangle::Larg_afficheToi()
{
    cout << "La taille de la Largeur du rectangle courant :"<< Larg_dimension;
}
void Unrectangle::Long_afficheToi()
{
    cout << "La taille de la Longeur du rectangle courant :"<< Long_dimension;
}
bool Unrectangle::estInclus(Unrectangle telrectangle)
{
    if ((sommet_HG.X_afficheToi()+Long_dimension<=telrectangle.sommet_HG.X_afficheToi()+telrectangle.Long_dimension && sommet_HG.X_afficheToi()>=telrectangle.sommet_HG.X_afficheToi()) && (sommet_HG.Y_afficheToi()+Larg_dimension<=telrectangle.sommet_HG.Y_afficheToi()+telrectangle.Larg_dimension && sommet_HG.Y_afficheToi()<=telrectangle.sommet_HG.Y_afficheToi()))
       return true;
    return false;
}
