#include <stdio.h>
#include <stdlib.h>

typedef struct {
int x;
int y;
} etat;

typedef struct Noeud
{
    struct Noeud* suivant;
    etat Etat;
} noeud;

/* File */
typedef struct
{
    noeud *debut;
    noeud *fin;
} liste;

liste listeNoeuds;
int n;


int main()
{
    etat etatInitial ={0,0}, etatFinal={2,1};
    RechercheLargeur(etatInitial,etatFinal,genereSuccesseurs);
    return 0;
}

void  RechercheLargeur(etat etatInitial, etat etatFinal, void generesuccesseurs())
{
    liste NoeudsDejaTraittes;
    etat etatCourant;
    listeNoeuds.debut = listeNoeuds.fin = NULL;

    Inserer(etatInitial,&listeNoeuds);
    NoeudsDejaTraites.debut = NoeudsDejaTraites.fin = NULL;
    while(Vide(listeNoeuds)==FALSE)
    {
        etatCourant = Extraire(&listeNoeuds));
        n++;
        if (etatSolution(etatCourant))
        {
            printf("Succes, on arret sur le noeud : (%d,%d) avec %d noeuds explores!\n",etatCourant.x,etatCourant.y,n);
            exit(0);
        }
        else if (!Appartient(etatCourant,NoeudsDejaTraites))
        {
            genereSuccesseurs(etatCourant);
            Inserer(etatCourant,&NoeudsDejaTraites);
        }
    }
    puts("\nPas de Solution");
}

int Vide(liste listeNoeuds)
{
    if (listeNoeuds->debut==NULL&&listeNoeuds->in==NULL)
        return TRUE;
    else return FALSE;
}

Inserer(etat Etat, liste* listeNoeuds)
{

}
