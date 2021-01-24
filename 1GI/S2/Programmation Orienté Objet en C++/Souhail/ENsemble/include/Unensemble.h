#ifndef UNENSEMBE_H
#define UNENSEMBE_H


typedef struct cellule{
    int v;
    struct cellule* suivant;
    struct cellule* precedent;
}Tcellule;

class unensemble
{
    public:
        unensemble(int*,int);
        unensemble();
        bool contient(int);
        void Multiple(int);
        bool estInclus(unensemble);
        void afficheToi();
        void ajoute(int);
        unensemble Union(unensemble);
        unensemble Intersection(unensemble);
        unensemble Ensemble_Premier();
        void supprime(int);

    private:
        Tcellule* sesElements;
        int sonCardinal;
        Tcellule* recherche(int);
};

#endif // UNENSEMBE_H
