#ifndef UNEVENEMENT_H
#define UNEVENEMENT_H
#include "Date.h"


class unEvenement
{
    public:
        unEvenement(Date d, char* t);
        void afficheToi();

    protected:

    private:
        Date saDate;
        char* Intitule;
};

#endif // UNEVENEMENT_H
