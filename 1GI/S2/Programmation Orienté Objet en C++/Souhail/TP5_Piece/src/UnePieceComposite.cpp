#include "UnePieceComposite.h"
#include <iostream>

using namespace std;

UnePieceComposite::UnePieceComposite(char* telPtrNom, UnePieceSimple** telPtrPoids ) : UnePiece(telPtrNom),sesComposants(telPtrPoids)
{}

int UnePieceComposite::donnePoids()
{
    UnePieceSimple** Tmp=sesComposants;

    int PoidsComplet=0;
    while (*Tmp!=NULL)
    {
        PoidsComplet+=(*Tmp)->donnePoids();
        Tmp++;
    }

    return PoidsComplet;

}
void UnePieceComposite::affiche(){

    cout << "Nom piece composee : " << sonNom << endl;

    UnePieceSimple** Tmp=sesComposants;
    int ite=1;
    while (*Tmp!=NULL)
    {
        cout << ite << "-> " ; (*Tmp)->affiche(); cout << endl;
        Tmp++;
        ite++;
    }
    cout << "Poids Total = " << donnePoids();
}


UnePieceComposite::~UnePieceComposite()
{
    for (UnePieceSimple* P=*sesComposants;P!=NULL;P++ )
        delete P;
    delete [] sesComposants;
}
