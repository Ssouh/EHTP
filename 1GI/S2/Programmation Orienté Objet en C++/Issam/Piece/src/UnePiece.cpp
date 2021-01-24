#include "UnePiece.h"
#include <string.h>

UnePiece::UnePiece(char* tel_ptr)
{
    int taille = strlen(tel_ptr) + 1;
    sonNom = new char[taille];
    strcpy(sonNom,tel_ptr);
}

UnePiece::~UnePiece()
{
    delete []sonNom;
}
