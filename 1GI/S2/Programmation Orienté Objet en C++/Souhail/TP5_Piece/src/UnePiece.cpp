#include "UnePiece.h"
#include <iostream>
#include <string.h>

UnePiece::UnePiece(){}

UnePiece::UnePiece(char* tel_ptr)
{
    sonNom = new char[strlen(tel_ptr) + 1];
    strcpy(sonNom,tel_ptr);
}

UnePiece::~UnePiece()
{
    delete []sonNom;
}
