#ifndef UNENSEMBLE_H
#define UNENSEMBLE_H

struct Noeud
{
    int Element;
    Noeud* suivant;
};

class UnEnsemble
{
    public:
        UnEnsemble(int n=0,Noeud* p=nullptr);
        bool contient(int telEntier);
        bool estInclus(UnEnsemble telEnsemble);
        void afficheToi();
        void ajoute(int telEntier);
        void supprime(int telEntier);


    private:
        Noeud* tete;
        int sonCardinal;
};

#endif // UNENSEMBLE_H
