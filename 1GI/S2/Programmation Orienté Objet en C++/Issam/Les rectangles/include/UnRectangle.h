#include "UnPoint.h"

#ifndef UNRECTANGLE_H
#define UNRECTANGLE_H


class UnRectangle
{
    public:
        UnRectangle(UnPoint p,int a,int b);
        int recupererLargeur();
        int recupererHauteur();
        UnPoint recupererSommet();
        bool estInclus (UnRectangle telRectangle);

    private:
        UnPoint sonSommet;
        int saLargeur;
        int saHauteur;
};

#endif // UNRECTANGLE_H
