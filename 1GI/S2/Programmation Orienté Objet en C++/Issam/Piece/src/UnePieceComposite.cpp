#include "UnePieceComposite.h"
#include <iostream>

using namespace std;

UnePieceComposite::UnePieceComposite(char* tel_ptrn, UnePieceSimple* (*tel_ptrp) ) : UnePiece(tel_ptrn),sesComposants(tel_ptrp)
{

}

int UnePieceComposite::donnePoids()
{
    UnePieceSimple** simplepiece=sesComposants;

    int poidsTotal = 0;
    while (*simplepiece!=nullptr)
    {
        poidsTotal+=(*simplepiece)->donnePoids();
        simplepiece++;
    }

    return poidsTotal;

}
void UnePieceComposite::affiche(){

    cout << "Nom de piece compose : " << sonNom << endl;

    UnePieceSimple** simplepiece=sesComposants;
    int compteur=0;
    while (*simplepiece!=nullptr)
    {
        cout << compteur << ". " ; (*simplepiece)->affiche(); cout << endl;
        simplepiece++;
        compteur++;
    }

    cout << "Poids Total = " << donnePoids();

}


UnePieceComposite::~UnePieceComposite(){}
