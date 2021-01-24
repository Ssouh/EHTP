#include "UnePieceSimple.h"
#include <iostream>

using namespace std;

void UnePieceSimple::affiche(){

    cout << "Nom : " << sonNom << ", Poids : " << donnePoids();

};

int UnePieceSimple::donnePoids()
{
    return sonPoids;
}

UnePieceSimple::~UnePieceSimple()
{

}
