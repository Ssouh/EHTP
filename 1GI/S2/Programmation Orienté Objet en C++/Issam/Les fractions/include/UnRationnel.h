#ifndef UNRATIONNEL_H
#define UNRATIONNEL_H


class UnRationnel
{
    public:
        UnRationnel(int=1,int=1);
        void affiche();
        void somme(UnRationnel,UnRationnel);
        void lire();
        void produit(UnRationnel,UnRationnel);
        bool egales(UnRationnel);
        int pgcd();
        void reduit();
        inline int donneNum();
        inline int donneDenom();

        UnRationnel retourneSomme(UnRationnel telX, UnRationnel telY);

    private:
        int sonNum,sonDenom;
};

#endif // UNRATIONNEL_H
