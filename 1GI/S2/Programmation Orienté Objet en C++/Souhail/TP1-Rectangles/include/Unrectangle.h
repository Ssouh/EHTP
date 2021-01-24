#include "point.h"
#ifndef UNRECTANGLE_H
#define UNRECTANGLE_H
using namespace std;

class Unrectangle
{
    public:
        Unrectangle();
        Unrectangle(int,int,int,int);
        void Long_afficheToi();
        void Larg_afficheToi();
        bool estInclus(Unrectangle);

    private:
        point sommet_HG;
        int Long_dimension;
        int Larg_dimension;
};

#endif // UNRECTANGLE_H
