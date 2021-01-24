#include "UnePieceSimple.h"
#include <iostream>

using namespace std;

UnePieceSimple::UnePieceSimple(){}

UnePieceSimple::UnePieceSimple(char* telPtr,int telPds):UnePiece(telPtr),sonPoids(telPds)
{}

void UnePieceSimple::affiche(){

    cout << "Nom : " << sonNom <<endl<< "Poids : " << donnePoids();

}

int UnePieceSimple::donnePoids()
{
    return sonPoids;
}
