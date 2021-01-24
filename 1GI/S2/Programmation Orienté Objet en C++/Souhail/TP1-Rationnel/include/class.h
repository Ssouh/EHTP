#include <iostream>
#include <string.h>
using namespace std;

///**************************** EX03 ********************************

class UnRationnel
{
    public:
        UnRationnel(int=1,int=1);
        void affiche();
        void somme(UnRationnel,UnRationnel);
        void lire();
        void produit(UnRationnel,UnRationnel);
        bool egalite(UnRationnel);
        int pgcd();
        void reduit();
        inline int donneNum();
        inline int donneDenom();
        UnRationnel retourneOperation(UnRationnel ras1, UnRationnel ras2);

    private:
        int sonNum,sonDenom;
};

