#include "PointNomme.h"
#ifndef POINTCOLORE_H
#define POINTCOLORE_H


class PointColore : public PointNomme // Point nommé et coloré
{
    public:
        PointColore(int a=0, int b=0, char* chaine="", int couleur=0);
        PointColore(const PointColore&);                    // constructeur par copie
        PointColore& operator=(const PointColore& PtNomme); // surcharge d'operateur d'affectation
        void afficheToi();

        ~PointColore();

    private:
        int couleur;
};

#endif // POINTCOLORE_H
