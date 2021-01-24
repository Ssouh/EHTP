#include "une_piece_composee.h"
#include <iostream>
using namespace std;

une_piece_composee::une_piece_composee(char* telPtrNom, une_piece** telPtrPoids ) : une_piece(telPtrNom),sesComposants(telPtrPoids)
{}

une_piece_composee::~une_piece_composee()
{
    for (une_piece* P=*sesComposants;P!=NULL;P++ )
        delete P;
    delete [] sesComposants;
}


int une_piece_composee::donnePoids()
{
    une_piece** Tmp=sesComposants;

    int PoidsComplet=0;
    while (*Tmp!=NULL)
    {
        PoidsComplet+=(*Tmp)->donnePoids();
        Tmp++;
    }

    return PoidsComplet;

}
void une_piece_composee::affiche(int blink){
    for (int i=0;i<blink;i++) cout<<"\t";
    cout << "Nom piece composee : " << son_nom << endl;

    une_piece** Tmp=sesComposants;
    int ite=1;
    while (*Tmp!=NULL)
    {
        for (int i=0;i<blink;i++) cout<<"\t";cout << ite << "-> " ; (*Tmp)->affiche(blink); cout << endl;
        Tmp++;
        ite++;
    }
    for (int i=0;i<blink;i++) cout<<"\t";cout << "Poids Total = " << donnePoids();
}

