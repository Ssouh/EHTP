#include <iostream>
#include "UnRectangle.h"
#include "UnPoint.h"

using namespace std;

UnRectangle::UnRectangle(UnPoint p,int a,int b)
{
    sonSommet=p;
    saLargeur=a;
    saHauteur=b;
}

int UnRectangle::recupererLargeur()
{
    return saLargeur;
}

int UnRectangle::recupererHauteur()
{
    return saHauteur;
}

UnPoint UnRectangle::recupererSommet()
{
    return sonSommet;
}

bool UnRectangle::estInclus(UnRectangle telRectangle)
{
    int telX=telRectangle.recupererSommet().recupererX(), telY=telRectangle.recupererSommet().recupererY(), telLargeur=telRectangle.recupererLargeur(),
        telHauteur=telRectangle.recupererHauteur();

    if ( (sonSommet.recupererX()>=telX) && (sonSommet.recupererY()>=telY) &&
          (saLargeur+sonSommet.recupererY()<telLargeur+telX) && (saHauteur+sonSommet.recupererY()< telHauteur+telY))
            return 1;
    return 0;
}
