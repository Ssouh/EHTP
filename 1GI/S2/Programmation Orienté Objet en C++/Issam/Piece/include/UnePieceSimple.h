#ifndef UNEPIECESIMPLE_H
#define UNEPIECESIMPLE_H
#include "UnePiece.h"

class UnePieceSimple : public UnePiece
{
    public:
        UnePieceSimple(){};
        UnePieceSimple(char* tel_ptr, int tel_poids): UnePiece(tel_ptr),sonPoids(tel_poids){};
        void affiche();
        int donnePoids();
        ~UnePieceSimple();

    private:
        int sonPoids;
};

#endif // UNEPIECESIMPLE_H
