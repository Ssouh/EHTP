#include <stdio.h>
#include <stdlib.h>


typedef struct Noeud
{
    struct Noeud* suivant;
    int Mat[3][3];
}Noeud;

typedef struct Liste
{
    Noeud* fin;
}Liste;

int i=0;
Liste listeNoeuds;
int vide ( Liste* );
void inserer (int Tab[3][3],Liste*);
int** Extraire ();
int appartient (int Tab[3][3],Liste*);
int etatSolution (int Tab[3][3]);
void genereSuccesseurs(int Tab[3][3]);
void rechercheAetoile(int etatInitial[3][3], int etatFinal[3][3],genereSuccesseurs(),h(),g())
{

    Liste listeNoeuds;
    Liste noeudsDejaTraites;
    listeNoeuds.fin=NULL;
    NoeudDejaTraites.fin=NULL;

    insere(etatInitial,&listeNoeuds);

    while(!vide(&listeNoeuds))
    {
        int** etatCourant=Extraire();
        Liste listeSuccesseurs;
        listeSuccesseurs.fin=NULL;

        if (etatSolution(etatCourant)==TRUE)
            printf("Succès!");
        else
        {
            genereSuccesseurs(etatCourant,listeSuccesseurs);

            Noeud *tmp = listeSuccesseurs;
            /* Tant que l'on n'est pas au bout de la liste */
            while(tmp != NULL)
            {
                if (!appartient((tmp->Mat),&listeNoeuds) && !appartient((tmp->Mat),&NoeudsDejaTraites))
                    inserer(tmp->Mat,listeNoeuds);


                /* On avance d'une case */
                tmp = tmp->nxt;
            }

            insere(etatCourant,noeudsDejaTraites);
            Tri(listeNoeuds);
        }
    }


}

int main()
{
    int etatInitial[3][3] = {{2,8,0},{1,6,4},{7,0,5}};
    int etatFinal[3][3] = {{1,2,3},{8,0,4},{7,6,5};
    rechercheLargeur (etatInitial, etatFinal);
return 0;
}


int vide ( Liste* liste )
{
    if(Liste->fin == NULL)
        return 1;
    return 0;
}

void inserer (int Tab[3][3],Liste*) //void inserer( courant,Liste* liste)
{
    Noeud* nouveau;
    nouveau = (Noeud*)malloc(sizeof(Noeud));

    int i,j;
    for (i=0; i<3; i++)
        for(j=0; j<3; ji++)
        {
            nouveau->Mat[i][j] = Tab[i][j];
        }

    nouveau->suivant = NULL;

    if ( vide(liste) ) liste->fin = nouveau;
    else
        {nouveau->suivant=liste->fin;
        liste->fin = nouveau;}
}


int** Extraire ();
{
    int test[3][3];
    if(!vide(&listeNoeuds))
    {

        int i,j;
        for (i=0; i<3; i++)
            for(j=0; j<3; ji++)
            {
                test[i][j] = listeNoeuds.fin->Mat[i][j];
            }

        listeNoeuds.fin=listeNoeuds.fin->suivant;

        return test;
    }
}
int appartient(Etat courant,Liste* Dejatraite)
{
    Noeud* test;
    test=(Noeud*)malloc(sizeof(Noeud));
    test=Dejatraite->fin;
    while(test!=NULL)
    {

        int i,j,compteur=0;
        for (i=0; i<3; i++)
            for(j=0; j<3; ji++)
            {
                if (test->Mat[i][j] = Courant[i][j])
                    compteur++;
            }

        if (compteur==9) return 1;

        test=test->suivant;
    }
    return 0;
}


int etatSolution (int Tab[3][3]);
{
    int etatFinal[3][3] = {{1,2,3},{8,0,4},{7,6,5};

    int i,j,compteur=0;
    for (i=0; i<3; i++)
        for(j=0; j<3; ji++)
        {
            if (Tab[i][j] = etatFinal[i][j])
            compteur++;
        }

   if (compteur==9) return 1;
   return 0;
}
void genereSuccesseurs(int courant[3][3], Liste* listeSuccesseurs )
{
    Etat test;
    int m;

    if ( courant.x!=0 ) //V4
    {
        test.x = 0;
        test.y = courant.y;
        insere(test,&listeNoeuds);i++;

    }
}

void position0(int matrice[3][3],int* x,int* y)
{ int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if (matrice[i][j]==0)
            {
                *x=i;*y=j;
            }
}


void RH(int courant[3][3])
{
 int x,y,i,j;
 int matrice[3][3];
 position0(courant,&x,&y);
 if(x>0)
    {
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                matrice[i][j]=courant[i][j];
        matrice[x][y]=courant[x-1][y];
        matrice[x-1][y]=0;
        Inserer(matrice,&listeSuccesseurs);
    }
}

void RB(int courant[3][3])
{
 int x,y,i,j;
 int matrice[3][3];
 position0(courant,&x,&y);
 if(x<2)
    {
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                matrice[i][j]=courant[i][j];
        matrice[x][y]=courant[x+1][y];
        matrice[x+1][y]=0;
        Inserer(matrice,&listeSuccesseurs);
    }
}


void RG(int courant[3][3])
{
 int x,y,i,j;
 int matrice[3][3];
 position0(courant,&x,&y);
 if(y>0)
    {
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                matrice[i][j]=courant[i][j];
        matrice[x][y]=courant[x][y-1];
        matrice[x][y-1]=0;
        Inserer(matrice,&listeSuccesseurs);
    }
}


void RG(int courant[3][3])
{
 int x,y,i,j;
 int matrice[3][3];
 position0(courant,&x,&y);
 if(y<2)
    {
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                matrice[i][j]=courant[i][j];
        matrice[x][y]=courant[x][y+1];
        matrice[x1][y+1]=0;
        Inserer(matrice,&listeSuccesseurs);
    }
}

int h(matrice[3][3])
{
    int etatFinal[3][3] = {{1,2,3},{8,0,4},{7,6,5};
    int i,j,compteur=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            if (matrice[i][j]!=etatFinal[i][j])
                compteur++;
        }

    return compteur
}
