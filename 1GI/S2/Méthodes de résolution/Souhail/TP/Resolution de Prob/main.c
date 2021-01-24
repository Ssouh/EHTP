#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
int x,y;}etat;
typedef struct noeud{
    struct noeud * suivant;
    etat Etat;
}Noeud;
typedef struct{
Noeud* debut;Noeud* fin;}liste;

liste NoeudsDejaTraites;
liste listeNoeuds;
int n;

int vide(liste* Liste)
{
    if(Liste->debut==NULL) return 1;
    return 0;
}

void Inserer(etat e,liste* L)
{
    Noeud* tmp;
    tmp= (Noeud*)malloc(sizeof(Noeud));
    tmp->Etat = e;
    tmp->suivant = NULL;

    if (vide(L)) L->debut = tmp;
    else L->fin->suivant = tmp;
    L->fin = tmp;
}

etat Extraire(liste* L) /// liste st suppose non vide
{
    etat tmp;
    tmp.x=(L->debut->Etat).x;
    tmp.y=(L->debut->Etat).y;
    if (vide(L)) L->fin =NULL;
    L->debut=L->debut->suivant;
    return tmp;
}

int Appartient(etat e,liste Liste)
{
    Noeud* tmp;
    tmp=(Noeud*)malloc(sizeof(Noeud));
    tmp=Liste.debut;

    while (tmp != NULL)
        {if((e.x==tmp->Etat.x)&&(e.y==tmp->Etat.y)) return 1;
         tmp=tmp->suivant;
         }

    return 0;
}

int etatSolution(etat etatCourant)
{
    if (etatCourant.x==2) return 1;
    return 0;
}

/// LES REGLES A SUIVRE
void R1(etat e)
{
    if (e.x<4) {e.x=4;
    Inserer(e,&listeNoeuds);}
}
void R2(etat e)
{
    if (e.y<3) {e.y=3;
    Inserer(e,&listeNoeuds);}
}
void R3(etat e)
{
    if (e.x>0) {e.x=0;
    Inserer(e,&listeNoeuds);}
}
void R4(etat e)
{
    if (e.y>0) {e.y=0;
    Inserer(e,&listeNoeuds);}
}
void R5(etat e){
    if(e.x>0 && e.y<3){
        int y= fmin(e.x,-e.y+3);
        e.x-=y;
        e.y+=y;
        Inserer(e,&listeNoeuds);
    }
}
void R6(etat e){
    if(e.y>0 && e.x<4){
        int q = fmin(e.y,4-e.x);
        e.x+=q;
        e.y-=q;
        Inserer(e,&listeNoeuds);
    }
}
/*void R5(etat e) /// Verser x en y
{
        while (e.x!=0 && e.y!=3)
            {
                e.y+=1;
                e.x-=1;
            }
        Inserer(e,&listeNoeuds);printf("\t93");
}

void R6(etat e) /// Verser y en x
{
        while (e.x!=4 && e.y!=0)
            {
                e.y-=1;
                e.x+=1;
            }
        Inserer(e,&listeNoeuds);printf("\t103");
}
*/
void genereSuccesseurs(etat e)
{
    R1(e);
    R2(e);   R3(e);
    R4(e);  R5(e);   R6(e);

}


void rechercheLargeur(etat etatInitial,etat etatFinal,void genereSuccesseurs())
{
    listeNoeuds.debut=listeNoeuds.fin=NULL;
    Inserer(etatInitial,&listeNoeuds);
    NoeudsDejaTraites.debut=NULL;NoeudsDejaTraites.fin=NULL;
    etat etatCourant;
    printf("Wait a minute ^~~^ \n");
    while (!vide(&listeNoeuds))
        {etatCourant=Extraire(&listeNoeuds);n++;
        if (etatSolution(etatCourant))
            {
                printf("Success ! Arret sur l'Etat: (%d ,%d)\n",etatCourant.x,etatCourant.y);
                printf("Nombre de noeuds explorer est : %d \n",n);
                exit(0);
            }
        else if (!Appartient(etatCourant,NoeudsDejaTraites))
            {

                genereSuccesseurs(etatCourant);
                Inserer(etatCourant,&NoeudsDejaTraites);
            }
          }
    printf("\nPAS DE SOLUTION\n");
}

int main()
{
    etat etatInitial={0,0},etatFinal={2,1};
    rechercheLargeur(etatInitial,etatFinal,genereSuccesseurs);
    return 0;
}
