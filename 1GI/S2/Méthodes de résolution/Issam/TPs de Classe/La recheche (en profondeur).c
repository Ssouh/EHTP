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

typedef struct Noeud *liste;

/*typedef struct Liste
{
    Noeud* sommet;

}Liste; */

int i=0;
liste listeNoeuds;
int vide ( liste* );
void insere (Etat,liste*);
Etat extraire ();
int appartient (Etat,liste*);
int etatSolution (Etat);
void genereSuccesseurs(Etat);
void rechercheLargeur ( Etat initial , Etat finale)
{
 int n=1;

    liste noeudDejaTraites;
    Etat etatCourant;
    //listeNoeuds.debut=listeNoeuds.fin=NULL;
    insere(initial,&listeNoeuds);
    //noeudDejaTraites.debut=NULL;
    //noeudDejaTraites.fin=NULL;

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




int vide ( liste* liste )
{
    return (liste == NULL);
}
void insere(Etat courant,liste *sommet)
{

    liste sommet0 = *sommet;
    Noeud* nouveau;
    nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->eta = courant;
    nouveau->suivant = sommet0;

    sommet0=nouveau;
    *sommet=sommet0;

    /*if ( vide(liste) ) liste->debut = nouveau;
    else liste->fin->suivant = nouveau;
    liste->fin = nouveau;*/
}

Etat extraire(liste* sommet)
{
    liste sommet0 = *sommet;

    liste P = sommet0;

    Etat E = sommet0->eta;

    sommet0=sommet0->suivant;

    *sommet=sommet0;

    free(P);





    /*Etat test;
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
    }*/
}
int appartient(Etat courant,liste* sommet)
{
    liste sommet0=*sommet;

    while(sommet0!=NULL) // we can use : for(sommet0=sommet,sommet0!=NULL)
    {
        if (sommet0->eta.x==courant.x && sommet0->eta.y==courant.y ) return 1;       ///???
        sommet0=sommet0->suivant;
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
