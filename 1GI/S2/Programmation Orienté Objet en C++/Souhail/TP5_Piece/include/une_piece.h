#ifndef UNE_PIECE_H
#define UNE_PIECE_H


class une_piece
{
    public:
        une_piece();
        une_piece(char* tel_nom);
        virtual ~une_piece();
        virtual void affiche(int);
        virtual int donnePoids();

    protected:
        char* son_nom;
};

#endif // UNE_PIECE_H
