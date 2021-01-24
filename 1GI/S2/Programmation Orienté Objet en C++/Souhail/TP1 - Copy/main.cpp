#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "class.h"
#define TAILLE 10
using namespace std;

///*****************************  EX 01:  *********************************
/*
int main()
{
    int leTab[TAILLE],indice;
    srand(time(NULL));
    for (indice=0; indice<TAILLE;indice++)
    {
        leTab[indice]=rand();
    }
///    ***********************************
    cout<< "LE TABLEAU = ( ";
    for (indice=0; indice<TAILLE;indice++) /// AFFICHAGE D'UN TABLEAU
    {
        cout<<leTab[indice]<<"\t";
    }
    cout<< ") ";
///    ***********************************
    int MAX=leTab[0];
    for (indice=1; indice<TAILLE;indice++) /// LE PLUS GRAND ELEM DU TABLEAU
      if(leTab[indice]>MAX) MAX=leTab[indice];
      cout<<endl<<"La plus Grande Valeur du Tableau : "<<MAX;
}
//*/
///*********************************    EX 02:  ************************************
/*

int main()
{
    Date Ladate(0,16,2015);
    Ladate.afficheToi();
    Cercle2D cercle(5,1,15);
    cercle.presenteToi();
    char Contenu[500]="Demain j'irai a l'ecole c'est la jour le plus bon\n",Auteur[50]="Souhail amghar";
    Citation cit(Contenu,Auteur);
    cit.presenteToi();
    Date dt(11,10,2016);
    unEvenement event("Blabla",dt);
    event.afficheToi();
}
//*/
///**************************  EX 03:  ***********************************


int main()
{
    UnRationnel i(17,2),j(10,3),k(2,11),x;
    k.somme(i,j);
    k.affiche();
    x.lire();
    x.affiche();
    k.produit(i,j);
    k.affiche();
    cout << k.egalite(j) << endl ;
    x.retourneOperation(i,j).affiche();
}

//*/
///**************************  EX 04:  ***********************************
/*

int main()
{
    cellule cel; cel.etat="Voila";cel.suivant=NULL;
    Unepile pile(cel);
    pile.afficheToi();
    pile.estvide();
    pile.afficheToi();
    pile.estpleine();
    pile.Raz();
    pile.afficheToi();

}
//*/
