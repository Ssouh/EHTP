#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"




void RechercheProfondeur( etat etatInitial, etat etatFinal,void generesuccesseurs())
{
    int exploreNbre=0,traiteNbre=0;
    Pile NoeudsDejaTraites=NULL;
    etat etatCourant;
    listeNoeuds=NULL;
    insertion(etatInitial,&listeNoeuds);
    NoeudsDejaTraites=NULL;
    printf("\n\n");
    while(!vide(listeNoeuds))
    {
        etatCourant=extraire(&listeNoeuds);
        exploreNbre++;


        if(etatSolution(etatCourant))
        {
            printf("(%c, %d, %d)    ",etatCourant.position,etatCourant.missionn,etatCourant.cannib);
            affichageGraphique(etatCourant);
            printf("\nX= Cannibal, O= Missionnaire, ||||| = La Barque\n\nSucces! Arret sur le noeud: (%c, %d, %d)\n\nNombre de noeuds explores: %d\, Noeuds traites: %d\n\n",etatCourant.position,etatCourant.missionn,etatCourant.cannib,exploreNbre,traiteNbre);
            exit(EXIT_SUCCESS);
        }
        else if(!appartient(etatCourant,NoeudsDejaTraites))
        {
            traiteNbre++;
            generesuccesseurs(etatCourant);
            insertion(etatCourant,&NoeudsDejaTraites);
            printf("(%c, %d, %d)    ",etatCourant.position,etatCourant.missionn,etatCourant.cannib);
            affichageGraphique(etatCourant);
        }
    }
}


int etatSolution(etat etatCourant)
{
    if(etatCourant.cannib==0 && etatCourant.missionn==0 && etatCourant.position=='G') return 1;
    return 0;
}

void generesuccesseurs(etat E)
{
    char pos=E.position;
    int x=E.missionn;
    int y=E.cannib;
    etat etatFils;
    if(pos=='D')
    {
        etatFils.position='G';
        if(x>0)
        {
            etatFils.missionn=x-1;
            etatFils.cannib=y;
            if ((etatFils.missionn==0 ) || (etatFils.missionn==3) || (etatFils.missionn==etatFils.cannib))

                insertion(etatFils,&listeNoeuds);
            if(x>1)
            {
                etatFils.missionn=x-2;
                etatFils.cannib=y;
                if ((etatFils.missionn==0 ) || (etatFils.missionn==3) || (etatFils.missionn==etatFils.cannib))
                    insertion(etatFils,&listeNoeuds);
            }
            if(y>0)
            {
                etatFils.missionn=x-1;
                etatFils.cannib=y-1;
                if ((etatFils.missionn==0 ) || (etatFils.missionn==3) || (etatFils.missionn==etatFils.cannib))
                    insertion(etatFils,&listeNoeuds);
            }
        }
        if(y>0)
        {
            etatFils.cannib=y-1;
            etatFils.missionn=x;
             if ((etatFils.missionn==0 ) || (etatFils.missionn==3) || (etatFils.missionn==etatFils.cannib))
                    insertion(etatFils,&listeNoeuds);
            if(y>1)
            {
                etatFils.cannib=y-2;
                etatFils.missionn=x;
                 if ((etatFils.missionn==0 ) || (etatFils.missionn==3) || (etatFils.missionn==etatFils.cannib))
                    insertion(etatFils,&listeNoeuds);
            }
        }
    }
    if(pos=='G')
    {
        etatFils.position='D';
        if(x<3)
        {
            etatFils.missionn=x+1;
            etatFils.cannib=y;
             if ((etatFils.missionn==0 ) || (etatFils.missionn==3) || (etatFils.missionn==etatFils.cannib))
                    insertion(etatFils,&listeNoeuds);
            if(x<2)
            {
                etatFils.missionn=x+2;
                etatFils.cannib=y;
                if ((etatFils.missionn==0 ) || (etatFils.missionn==3) || (etatFils.missionn==etatFils.cannib))
                    insertion(etatFils,&listeNoeuds);
            }
            if(y<3)
            {
                etatFils.missionn=x+1;
                etatFils.cannib=y+1;
                 if ((etatFils.missionn==0 ) || (etatFils.missionn==3) || (etatFils.missionn==etatFils.cannib))
                    insertion(etatFils,&listeNoeuds);
            }
        }
        if(y<3)
        {
            etatFils.cannib=y+1;
            etatFils.missionn=x;
             if ((etatFils.missionn==0 ) || (etatFils.missionn==3) || (etatFils.missionn==etatFils.cannib))
                    insertion(etatFils,&listeNoeuds);
            if(y<2)
            {
                etatFils.cannib=y+2;
                etatFils.missionn=x;
                if ((etatFils.missionn==0 ) || (etatFils.missionn==3) || (etatFils.missionn==etatFils.cannib))
                    insertion(etatFils,&listeNoeuds);
            }
        }
    }
}




int appartient(etat etatCourant, Pile liste)
{
    Pile p=liste;
    while(p!=NULL)
    {
        if(p->Etat.cannib==etatCourant.cannib && p->Etat.missionn==etatCourant.missionn && p->Etat.position==etatCourant.position)
            return 1;
        p=p->suivant;
    }
    return 0;
}

etat extraire(Pile *listeNoeuds)
{
    etat etatResultat=(*listeNoeuds)->Etat;
    (*listeNoeuds)=(*listeNoeuds)->suivant;
        return etatResultat;
}


void insertion(etat etatCourant,Pile *liste)
{
    noeud *nouveau;
    nouveau=(noeud*)malloc(sizeof(noeud));
    nouveau->Etat=etatCourant;
    nouveau->suivant=*liste;
    *liste=nouveau;
}



int vide(Pile listeCourante)
{
    if (listeCourante==NULL)return 1;
    else return 0;
}


void affichageGraphique(etat E)
{
    char pos = E.position;
    int x = E.missionn;
    int y = E.cannib;

    char barqueG[] = "||||| -------------------";
    char barqueD[] = " ------------------- |||||";

    int i;
    printf("(");
    for (i=0; i<3-y; i++) printf("X");
    printf(" ");
    for (i=0; i<3-x; i++) printf("O");
    printf(")\t\t");

    if (pos=='G') printf("%s",barqueG);
    else printf("%s",barqueD);

    printf("\t\t(");
    for (i=0; i<y; i++) printf("X");
    printf(" ");
    for (i=0; i<x; i++) printf("O");
    printf(")\n\n");


}
