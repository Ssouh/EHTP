#ifndef UNEPIECECOMPOSITE_H
#define UNEPIECECOMPOSITE_H
#include "UnePieceSimple.h"

class UnePieceComposite : public UnePiece
{
    public:
        UnePieceComposite(char* tel_ptrn, UnePieceSimple** tel_ptrp);
        ~UnePieceComposite();
        int donnePoids();
        void affiche();

    private:
        UnePieceSimple** sesComposants;
};

#endif // UNEPIECECOMPOSITE_H
