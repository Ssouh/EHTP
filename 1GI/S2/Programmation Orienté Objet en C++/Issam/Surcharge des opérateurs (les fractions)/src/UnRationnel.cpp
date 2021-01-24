#include "UnRationnel.h"
#include <iostream>
#include <ostream>
using namespace std;

UnRationnel::UnRationnel(int telNum,int telDenom)
{
    sonNum=telNum;
    sonDenom=telDenom;
}

void UnRationnel::somme(UnRationnel telX, UnRationnel telY)
{
    sonNum = telX.sonNum*telY.sonDenom + telY.sonNum*telX.sonDenom;
    sonDenom = telX.sonDenom * telY.sonDenom;
}


void UnRationnel::produit(UnRationnel telX, UnRationnel telY)
{
    sonNum = telX.sonNum * telY.sonNum ;
    sonDenom = telX.sonDenom * telY.sonDenom ;
}



UnRationnel& UnRationnel::operator=(const UnRationnel& telF)
{
    if (&telF != this)
    {
        // Denominateur doit etre positif
        if (telF.sonDenom < 0 )
        {
            sonDenom = -telF.sonDenom;
            sonNum = -telF.sonNum;
        }
        else if (telF.sonDenom > 0 )
        {
            sonDenom = telF.sonDenom;
            sonNum = telF.sonNum;
        }
    }

    return *this;
}

bool UnRationnel::operator==(UnRationnel& telF)
{
    return (sonNum*telF.sonDenom == sonDenom*telF.sonNum);
}

bool UnRationnel::operator!=(UnRationnel& telF)
{
    return !(sonNum*telF.sonDenom == sonDenom*telF.sonNum);
}

bool UnRationnel::operator<=(UnRationnel& telF)
{
    if (sonDenom*telF.sonDenom>0)
        return (sonNum*telF.sonDenom <= sonDenom*telF.sonNum);
    else
        return (sonNum*telF.sonDenom >= sonDenom*telF.sonNum);

}

bool UnRationnel::operator>=(UnRationnel& telF)
{
    if (sonDenom*telF.sonDenom>0)
        return (sonNum*telF.sonDenom >= sonDenom*telF.sonNum);
    else
        return (sonNum*telF.sonDenom <= sonDenom*telF.sonNum);

}

bool UnRationnel::operator<(UnRationnel& telF)
{
    if (sonDenom*telF.sonDenom>0)
        return (sonNum*telF.sonDenom < sonDenom*telF.sonNum);
    else
        return (sonNum*telF.sonDenom > sonDenom*telF.sonNum);

}

bool UnRationnel::operator>(UnRationnel& telF)
{
    return !(*this < telF );
}

ostream& operator<<(ostream& telFlux,const UnRationnel& telleFraction)
{
    return telFlux << telleFraction.sonNum << "/" << telleFraction.sonDenom ;
}

istream& operator>>(istream& telFlux, UnRationnel& telleFraction)
{
    cout << "Numerateur = "; telFlux >> telleFraction.sonNum;
    cout << "Denominateur = "; telFlux >> telleFraction.sonDenom;

    while (telleFraction.sonDenom == 0)
        {cout << "Denominateur invalide, entrer a nouveau = "; telFlux >> telleFraction.sonDenom;}

    return telFlux;
}
