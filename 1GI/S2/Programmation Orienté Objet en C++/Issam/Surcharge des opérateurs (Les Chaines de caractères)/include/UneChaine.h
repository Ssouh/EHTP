#ifndef UNECHAINE_H
#define UNECHAINE_H

#include <ostream>

struct PCellule
{
    char caractere;
    PCellule* suivant;
};

class UneChaine
{
    private:
        PCellule* sonContenu;
        int saLongueur;

    public:
        /* Constructeurs */
        UneChaine();
        UneChaine(char*);
        UneChaine(const UneChaine&);

        /*Accesseurs*/
        int getLongueur();
        void getContenu(char**) ;

        /* Entrées-Sorties */
        friend std::ostream& operator<<( std::ostream& telFlux, const UneChaine& telleChaine);
        friend std::istream& operator>>( std::istream& telFlux, UneChaine& telleChaine);

        UneChaine& operator=(const UneChaine&);
        bool operator==( UneChaine& telleChaine);
        bool operator!=(UneChaine& telleChaine);

        void ajoute(char telCaractere);

        ~UneChaine();

};

#endif // UNECHAINE_H
