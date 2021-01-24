
#ifndef UNRATIONNEL_H
#define UNRATIONNEL_H
#include <ostream>

class UnRationnel
{
    int sonNum,sonDenom;

    public:
        UnRationnel( int=0 , int=1 );
        void somme(UnRationnel,UnRationnel) ;
        void produit(UnRationnel,UnRationnel) ;
        void affiche();

        UnRationnel operator+(const UnRationnel telF) const;

        UnRationnel& operator=(const UnRationnel& );

        bool operator==(UnRationnel& telF);
        bool operator!=(UnRationnel& telF);
        bool operator<=(UnRationnel& telF);
        bool operator>=(UnRationnel& telF);
        bool operator<(UnRationnel& telF);
        bool operator>(UnRationnel& telF);

        friend std::ostream& operator<<(std::ostream& telFlux,const UnRationnel& telleFraction);
        friend std::istream& operator>>(std::istream& telFlux,UnRationnel& telleFraction);


};

#endif // UNRATIONNEL_H
