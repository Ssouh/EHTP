#include <iostream>
using namespace std;

#include "UnRationnel.h"

UnRationnel::UnRationnel(int telNum,int telDenom)
{
    sonNum=telNum;
    sonDenom=telDenom;

}

void UnRationnel::affiche()
{
    cout << sonNum << "/" << sonDenom << endl;
}

void UnRationnel::somme(UnRationnel telX, UnRationnel telY)
{
    sonNum = telX.sonNum*telY.sonDenom + telY.sonNum*telX.sonDenom;
    sonDenom = telX.sonDenom * telY.sonDenom;
}

void UnRationnel::lire()
{
    cin >> sonNum >> sonDenom ;
}

void UnRationnel::produit(UnRationnel telX, UnRationnel telY)
{
    sonNum = telX.sonNum * telY.sonNum ;
    sonDenom = telX.sonDenom * telY.sonDenom ;
}



bool UnRationnel::egales(UnRationnel telX)
{
    return (((float)sonNum/(float)sonDenom) == ((float)telX.sonNum/(float)telX.sonDenom));
}


int UnRationnel::pgcd()
{
    int reste=1, a , b;
    if (sonNum>sonDenom)
        {a=sonNum; b=sonDenom;}
    else
        {int a=sonDenom; b=sonNum;}

    while (a-b!=0)
    {
        int k=a-b;
        a=max(b,k);
        b=min(b,k);
    }

    return b;
    /*while (reste!=0)
    {
        reste=a%b;
        a=a/b;
        b=reste;
    }

    return a;*/
}

void UnRationnel::reduit()
{
    int P = pgcd();
    sonNum = sonNum/P;
    sonDenom = sonDenom/P;

}

inline int UnRationnel::donneNum()
{
    return sonNum;
}


inline int UnRationnel::donneDenom()
{
    return sonDenom;
}

UnRationnel UnRationnel::retourneSomme(UnRationnel telX, UnRationnel telY)
{
    UnRationnel X;
    X.sonNum = telX.sonNum*telY.sonDenom + telY.sonNum*telX.sonDenom;
    X.sonDenom = telX.sonDenom * telY.sonDenom;
    return X;
}
