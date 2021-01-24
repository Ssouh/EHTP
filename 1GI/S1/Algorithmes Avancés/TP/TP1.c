#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fusionner(int * tab, int p, int q, int r)
{

    int i,j,k;
    i=p;
    j=q+1;
    int* c;
    c=malloc((r-p+1)*sizeof(int));
    k=0;
    while (i<=q&&j<=r)
    {
        if (tab[i]<tab[j]) {c[k]=tab[i]; i++;}
        else {c[k]=tab[j]; j++;}
        k++;
    }
    while (i<=q){c[k]=tab[i]; i++; k++;}
    while (j<=r){c[k]=tab[j]; j++; k++;}
    for (k=0;k<=r-p;k++) {tab[p+k]=c[k];}
}


void trifusion(int * tab, int p, int r)
{
    int q;
    if (p<r)
    {
        q=(int)((p+r)/2);
        trifusion(tab,p,q);
        trifusion(tab,q+1,r);
        fusionner(tab,p,q,r);
    }
}

int * triParFusion(int * tab, int taille)
{
    trifusion(tab,0,taille);
    return tab;
}


void afficher(int * tab, int taille)
{
    int i;
    for (i=0; i<taille; i++){
    printf("%d | ",tab[i]);
}

}


int * triParSelection(int * tab, int taille)
{
    int i,j,posmini,temp;
    for (j=0;j<taille-1;j++){
        posmini=j;
        for (i=j+1;i<taille;i++){
            if (tab[i]<tab[posmini]) posmini=i;
        }
        temp=tab[posmini];
        tab[posmini]=tab[j];
        tab[j]=temp;
    }
    return tab;
}

int* Tri_Bulles(int * tab, int n)
{
    int j=0,i,temp;
    while(j!=n-1)
    {
        for (i=0; i<=n-2; i++)
        {
            if (tab[i]>tab[i+1])
            {
                temp=tab[i+1];
                tab[i+1]=tab[i];
                tab[i]=temp;

            }
            else j++;
        }
    }
    return tab;
}


main(){

double t1,t2,t3,t4,t5;
int n,i;
int* tab;
int* tabtri,tabtrifus,tabtribulles;

srand(time(NULL));
printf("donner la taille de tbleau : \n");
scanf("%d",&n);
tab=malloc(n*sizeof(int));

for (i=0;i<n;i++){

    tab[i]=rand()%100;

}
printf("Avant le tri :\n");
afficher(tab,n);

printf("\n\nApres le tri par selection :\n");
t1=clock();
tabtri=triParSelection(tab,n);
t2=clock();
afficher(tabtri,n);
t3=t2-t1;

printf("\n\nApres le tri par fusion :\n");
t1=clock();
tabtrifus=triParFusion(tab,n);
t2=clock();
afficher(tabtrifus,n);
t4=t2-t1;

printf("\n\nApres le tri par bulles :\n");
t1=clock();
tabtribulles=Tri_Bulles(tab,n);
t2=clock();
afficher(tabtribulles,n);
t5=t2-t1;


printf("\n\nLa duree de tri par selection est : %f\n",t3);
printf("La duree de tri par fusion est : %f\n",t4);
printf("La duree de tri par bulles est : %f\n\n",t5);






}
