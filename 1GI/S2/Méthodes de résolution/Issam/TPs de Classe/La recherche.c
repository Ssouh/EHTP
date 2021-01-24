#include <stdio.h>
#include <stdlib.h>

typedef struct Etat
{
    int x;
    int y;
}Etat;

typedef struct Noeud
{
    struct Noeud* suivant;
    Etat eta;
}Noeud;

typedef struct Liste
{
    Noeud* debut;
    Noeud* fin;
}Liste;

int i=0;
Liste listeNoeuds;
int vide ( Liste* );
void insere (Etat,Liste*);
Etat extraire ();
int appartient (Etat,Liste*);
int etatSolution (Etat);
void genereSuccesseurs(Etat);
void rechercheLargeur ( Etat initial , Etat finale)
{
 int n=1;

    Liste noeudDejaTraites;
    Etat etatCourant;
    listeNoeuds.debut=listeNoeuds.fin=NULL;
    insere(initial,&listeNoeuds);
    noeudDejaTraites.debut=NULL;
    noeudDejaTraites.fin=NULL;

    while(!vide(&listeNoeuds))
    {
        n++;
        etatCourant =extraire();
        if(etatSolution(etatCourant))
        {
            printf("\nSucces ! Arret sur le noeud :(%d,%d)\n\n nombre de noeud traite: %d nombre de noeud genere: %d\n",etatCourant.x,etatCourant.y,n,i);
            exit(0);
        }
        else if(!appartient(etatCourant,&noeudDejaTraites))
        {
            genereSuccesseurs(etatCourant);
            insere(etatCourant,&noeudDejaTraites);
        }
    }
puts("pas de solution");

}

int main()
{
    Etat etatInitial = {0,0},etatFinal = {2,1};
    rechercheLargeur (etatInitial, etatFinal);
return 0;
}




int vide ( Liste* liste )
{
    if ((liste->debut == NULL) && (liste->fin == NULL) )
        return 1;
    return 0;
}
void insere(Etat courant,Liste* liste)
{
    Noeud* nouveau;
    nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->eta = courant;
    nouveau->suivant = NULL;

    if ( vide(liste) ) liste->debut = nouveau;
    else liste->fin->suivant = nouveau;
    liste->fin = nouveau;
}

Etat extraire()
{
    Etat test;
    if(!vide(&listeNoeuds))
    {
        test = listeNoeuds.debut->eta;
        if ( listeNoeuds.debut == listeNoeuds.fin )
        {
            listeNoeuds.debut = NULL;
            listeNoeuds.fin = NULL;
        }
        else
            listeNoeuds.debut=listeNoeuds.debut->suivant;
     return test;
    }
}
int appartient(Etat courant,Liste* Dejatraite)
{
    Noeud* test;
    test=(Noeud*)malloc(sizeof(Noeud));
    test=Dejatraite->debut;
    while(test!=NULL)
    {
        if (test->eta.x==courant.x && test->eta.y==courant.y ) return 1;       ///???
    test=test->suivant;
    }
    return 0;
}
int etatSolution ( Etat courant )
{
   if(courant.x==2) return 1;
   return 0;
}
void genereSuccesseurs( Etat courant )
{
    Etat test;
    int m;

    if ( courant.x!=0 ) //V4
    {
        test.x = 0;
        test.y = courant.y;
        insere(test,&listeNoeuds);i++;
    }

    if ( courant.y!=0 ) //V3
    {
        test.y = 0;
        test.x = courant.x;
        insere(test,&listeNoeuds);i++;
    }

    if ( courant.x !=4 ) //R4
    {
        test.x = 4;
        test.y = courant.y;
        insere(test,&listeNoeuds);i++;
    }

    if ( courant.y!=3 ) //R3
    {
        test.y = 3;
        test.x = courant.x;
        insere(test,&listeNoeuds);i++;
    }

    if ( courant.x > 0 && courant.y < 3 ) //V43
    {
        m = ( courant.x < 3-courant.y ) ? courant.x : 3-courant.y;
        test.x = courant.x - m;
        test.y = courant.y + m;
        insere(test,&listeNoeuds);i++;
    }

    if ( courant.x < 4 && courant.y > 0 ) //V43
    {
        m = ( courant.y < 4-courant.x ) ? courant.y : 4-courant.x;
        test.x = courant.x + m;
        test.y = courant.y - m;
        insere(test,&listeNoeuds);i++;
    }

}
