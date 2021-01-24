#ifndef UNEPIECE_H
#define UNEPIECE_H


class UnePiece
{
    public:
        UnePiece(char*);
        UnePiece();
        virtual ~UnePiece();

    protected:
        char* sonNom;
};

#endif // UNEPIECE_H
