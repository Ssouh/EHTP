#include "une_piece.h"

une_piece::une_piece()
{}

une_piece::une_piece(char* tel_nom):son_nom(tel_nom)
{}

void une_piece::affiche(int blink)
{
    //code
}
int une_piece::donnePoids()
{
    //code
}

une_piece::~une_piece()
{
    delete []son_nom;
}
