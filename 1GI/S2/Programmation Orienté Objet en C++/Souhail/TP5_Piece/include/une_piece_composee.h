#ifndef UNE_PIECE_COMPOSEE_H
#define UNE_PIECE_COMPOSEE_H
#include "une_piece.h"


class une_piece_composee:public une_piece
{
    public:
        une_piece_composee(char* telPtrNom,une_piece** telPtrPoids);
        virtual ~une_piece_composee();
        int donnePoids();
        void affiche(int);

    private:
        une_piece** sesComposants;
};

#endif // UNE_PIECE_COMPOSEE_H
