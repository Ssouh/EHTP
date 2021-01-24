#include "class.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


UnRationnel::UnRationnel(int telNum,int telDenom)
{
    sonNum=telNum;
    sonDenom=telDenom;

}

void UnRationnel::affiche()
{
    cout << "Le resultat de l'operation est:"<< sonNum << "/" << sonDenom << endl;
}

void UnRationnel::somme(UnRationnel ras1, UnRationnel ras2)
{
    sonNum = ras1.sonNum*ras2.sonDenom + ras2.sonNum*ras1.sonDenom;
    sonDenom = ras1.sonDenom * ras2.sonDenom;
}
void UnRationnel::lire()
{
    cout << "Donnez votre numerateur:";
    cin >> sonNum;
    cout <<"Donnez votre denominateur:";
    cin >> sonDenom ;
}
void UnRationnel::produit(UnRationnel ras1,UnRationnel ras2)
{
    sonNum = ras1.sonNum * ras2.sonNum ;
    sonDenom = ras1.sonDenom * ras2.sonDenom ;
}
bool UnRationnel::egalite(UnRationnel ras1)
{   float res1=ras1.sonNum/ras1.sonDenom,res2=sonNum/sonDenom;
    if (res1 == res2 ) return true;
    return false;
}
int UnRationnel::pgcd()
{
    int a=sonNum;int b=sonDenom;
    if (a<0) a=-a;if (b<0) b=-b;
    while (b != 0)
    {
     int r = a%b;
      a = b;
      b = r;
    }
  return a;
}


void UnRationnel::reduit()
{
    int P = pgcd();
    sonNum = sonNum/P;sonDenom = sonDenom/P;
}
inline int UnRationnel::donneNum(){return sonNum;}
inline int UnRationnel::donneDenom(){return sonDenom;}

UnRationnel UnRationnel::retourneOperation(UnRationnel X, UnRationnel Y)
{
    UnRationnel Z;
    Z.sonNum = X.sonNum*Y.sonDenom + Y.sonNum*X.sonDenom;
    Z.sonDenom = X.sonDenom * Y.sonDenom;
    return Z;
}


