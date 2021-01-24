#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "Unensemble.h"


unensemble::unensemble()
{///creer un ensemble vide
    sesElements = NULL;
    sonCardinal = 0;
}

unensemble::unensemble(int T[], int taille)
{
    sesElements = NULL;
    sonCardinal = 0;
    for (int i=0; i<taille; i++)
        ajoute(T[i]);
}


void unensemble::afficheToi()
{
    if (sesElements){
    cout<<endl<<"L'ensemble = {";
    for (Tcellule* p=sesElements;p!=NULL;p=p->suivant)
        {
            cout<< p->v <<";";
        }
    cout<<"}";}
    else cout<<"L'ensemble est : {;}";
}


void unensemble::ajoute(int telEntier)
{
    if (!contient(telEntier))
    {
        Tcellule* nouveau;
        nouveau= new Tcellule;
        nouveau->v = telEntier;
        nouveau->suivant = sesElements;
        nouveau->precedent = NULL;
        if ( sesElements!=NULL)sesElements->precedent=nouveau;
        sesElements = nouveau;
        sonCardinal++;
    }
}


Tcellule* unensemble::recherche(int telEntier)
{
    Tcellule* T;
    Tcellule* p = sesElements;
    while(p)
    {
        if (p->v == telEntier)
        {
            T=p;
            return T;
        }
        p=p->suivant;
    }
    return NULL;
}

bool unensemble::contient(int telEntier)
{
    return recherche(telEntier) != NULL;
}

bool unensemble::estInclus(unensemble telEnsemble)
{
    Tcellule* p = sesElements;
    while(p)
    {
            if (!telEnsemble.contient(p->v))
                return false;
        p = p->suivant;
    }
    return true;
}

unensemble unensemble::Union(unensemble telEnsemble)
{
    unensemble T;
    for (Tcellule* p=sesElements;p!=NULL;p=p->suivant)
        T.ajoute(p->v);
    for (Tcellule* p=telEnsemble.sesElements;p!=NULL;p=p->suivant)
        T.ajoute(p->v);
    return T;
}

unensemble unensemble::Intersection(unensemble telEnsemble)
{
    unensemble T;
    for (Tcellule* p=telEnsemble.sesElements;p!=NULL;p=p->suivant)
        if (contient(p->v)) T.ajoute(p->v);
    return T;
}


void unensemble::Multiple(int a)
{
    for (Tcellule* p=sesElements;p!=NULL;p=p->suivant)
        if ((((float)p->v/a) - p->v/a)==0 && p->v!=a ) {int val=p->v;p=p->precedent;supprime(val);}
}

unensemble unensemble::Ensemble_Premier()
{
    for (Tcellule* p=sesElements;p!=NULL;p=p->suivant)
        Multiple(p->v);
}

void unensemble::supprime(int telEntier)
{
    Tcellule* p= recherche(telEntier);
    if (p)
    {
        if (sonCardinal == 1)///singleton
        {
            sesElements = NULL;
            delete p;
        }
        else if (p == sesElements)
        {
            sesElements = sesElements->suivant;
            sesElements->precedent = NULL;
            delete p;
        }
        else
        {
            p->precedent->suivant = p->suivant;
            if (p->suivant != NULL)
                p->suivant->precedent = p->precedent;
            delete p;
        }
        sonCardinal--;
    }
}
