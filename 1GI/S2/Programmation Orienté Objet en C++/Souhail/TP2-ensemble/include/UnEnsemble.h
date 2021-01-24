#ifndef UNENSEMBLE_H
#define UNENSEMBLE_H


class UnEnsemble
{
    public:
        UnEnsemble(int*,int,int);
        UnEnsemble(int);
        virtual ~UnEnsemble();
        bool contient(int);
        bool estInclus(UnEnsemble);
        void afficheToi();
        void ajoute(int);
        void supprime(int);

    private:
        int* sesElements;
        int sonCardinal;
        int taille;
};

#endif // UNENSEMBLE_H
