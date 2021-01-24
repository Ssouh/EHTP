#ifndef UNEPIECESIMPLE_H
#define UNEPIECESIMPLE_H
#include "UnePiece.h"
#include "une_piece.h"

class UnePieceSimple:public UnePiece,public une_piece
{
    public:
        UnePieceSimple(char* telPtr,int telPds);
        UnePieceSimple();
        int donnePoids();
        void affiche();
    private:
        int sonPoids;
};

#endif // UNEPIECESIMPLE_H
