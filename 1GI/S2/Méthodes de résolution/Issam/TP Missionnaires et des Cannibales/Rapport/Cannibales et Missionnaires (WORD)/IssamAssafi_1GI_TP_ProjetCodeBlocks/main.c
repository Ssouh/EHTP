#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"


int main()
{
    /* Cr�ation de la pile contenant les noeuds */
    Pile *listeNoeuds=NULL;
    listeNoeuds=(Pile*)malloc(sizeof(Pile));

    /* D�claration des �tats : initial et final */
    etat etatInitial={'D',3,3};
    etat etatFinal={'G',0,0};

    /* Application de la recherche en profondeur */
    RechercheProfondeur(etatInitial, etatFinal, generesuccesseurs);

    return 0;
}
