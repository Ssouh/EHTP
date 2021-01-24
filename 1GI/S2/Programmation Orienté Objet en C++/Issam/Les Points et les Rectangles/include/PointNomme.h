#include "Point.h"
#ifndef POINTNOMME_H
#define POINTNOMME_H


class PointNomme : public Point{ // Point nommé
    public:
        PointNomme(int a=0, int b=0, char* chaine="");      // le constructeur
        PointNomme(const PointNomme&);                      // constructeur par copie
        PointNomme& operator=(const PointNomme& PtNomme);   // surcharge d'operateur d'affectation
        void afficheToi();

        ~PointNomme();

    private:
        char* nom;
};

#endif // POINTNOMME_H
