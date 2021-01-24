#ifndef UNEPIECECOMPOSITE_H
#define UNEPIECECOMPOSITE_H
#include "UnePiece.h"
#include "UnePieceSimple.h"

class UnePieceComposite:public UnePiece
{
    public:
        UnePieceComposite(char* telPtrNom,UnePieceSimple** telPtrPoids);
        virtual ~UnePieceComposite();
    int donnePoids();
    void affiche();

    private:
        UnePieceSimple** sesComposants;
};

#endif // UNEPIECECOMPOSITE_H
