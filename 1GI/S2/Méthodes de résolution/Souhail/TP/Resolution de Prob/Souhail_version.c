#include <stdio.h>
#include <stdlib.h>

typedef struct{
int x,y;}etat;
typedef struct noeud{
    struct noeud * suivant;
    etat Etat;
}Noeud;
typedef struct{
Noeud* debut,fin;}liste;


liste listeNoeuds;
int n;

void Inserer(etat etatCourant,liste NoeudsDejaTraites)
{
    Noeud* tmp=NoeudsDejaTraites.debut;
    NoeudsDejaTraites.debut.Etat=etatCourant;
    NoeudsDejaTraites.debut.suivant=NoeudsDejaTraites.tmp;
}
void rechercheLargeur(etat etatInitial,etat etatFinal,void genereSuccesseurs())
{
    listeNoeuds =NULL;
    Inserer(etatInitial,listeNoeuds);
    liste NoeudsDejaTraites; NoeudsDejaTraites=NULL;
    while vide(listeNoeuds)==FALSE;
        {etat etatCourant;
        etatCourant=Extraire(listeNoeuds);
        if (etatSolution(etatCourant)==TRUE)
            {
                printf("Succes ! Arret sur l'état: (%d ,%d)",etatCourant.x,etatCourant.y);
                return(etatCourant);
            }
        else if (Appartient(etatCourant,NoeudsDejaTraites)==FALSE)
            {
                genereSuccesseurs(etatCourant,listeNoeuds);
                Inserer(etatCourant,NoeudsDejaTraites);
            }}
    printf("PAS DE SOLUTION");return(etatFinal);
}

etat Extraire(liste* Liste)
{
    etat tmp(x,y)=Liste->debut->Etat(x,y);
    Liste.debut=Liste.debut.suivant;
}
