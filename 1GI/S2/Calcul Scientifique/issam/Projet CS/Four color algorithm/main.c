#include <stdio.h>
#include <stdlib.h>

#define ORDER_MAX 30
#define TRUE  0
#define FALSE  1


//////////////////////////////////////

typedef struct t_graphe Type_G;
struct t_graphe {
 int order;
 int matrice[ORDER_MAX][ORDER_MAX];
};

int dsat[ORDER_MAX];
int degre[ORDER_MAX];
int coloration_issu_de_dsat[ORDER_MAX];

//////////////////////////////////////
// INIT
//////////////////////////////////////

Type_G init(Type_G g){
 int i,j;
 for(i=1;i<= g.order;i++){
  for(j=1;j<= g.order;j++){
   g.matrice[i][j]=0;
   }
  }
 return (g);
}

Type_G init_rand(Type_G g){
//matrice sym�trique
 int i,j;
 for(i=1;i<= g.order;i++){
  for(j=1;j<=(i-1);j++){
   if(rand()%2==0){
    g.matrice[i][j]=0;
    g.matrice[j][i]=0;
    }
   else {
    g.matrice[i][j]=1;
    g.matrice[j][i]=1;
    }
   }
  }
 return (g);
}

void init_dsat(Type_G g){
 int i,j;
 for(i=1;i<=g.order;i++){
  dsat[i]=0;
  coloration_issu_de_dsat[i]=0;
  for(j=1;j<=g.order;j++){
   if(g.matrice[i][j]==1) dsat[i]++;
  }//for j
  degre[i]=dsat[i];
 }//for i
}

//////////////////////////////////////
// walking Graph Function
//////////////////////////////////////
void parcours_profondeur(Type_G g, unsigned int som_depart)
{
     int *marque,i;
     marque=malloc(sizeof(int)*(g.order));
     for(i=1;i<=g.order;i++)
        marque[i]=0;

  printf("\n\nParcours en profondeur � partir du sommet=%d\n",som_depart);
     printf("\n\n\tRencontre prefixe de %d\n",som_depart);
     parcours_profondeur_rec(g,som_depart,marque);
     printf("\tRencontre suffixe de %d\n",som_depart);
     free(marque);
     printf("\n");
}


void parcours_profondeur_rec(Type_G g, unsigned int s, int *marque)
{
     unsigned int i;
     marque[s]=1;
     for (i=1;i<=g.order;i++)
     {
  if (g.matrice[s][i]!=0)  // si i est un voisin de s
            if(!marque[i])   // si i n'est pas encore visite
            {
               printf("\tRencontre prefixe de %d\n",i);
               parcours_profondeur_rec(g,i,marque);
               printf("\tRencontre suffixe de %d\n",i);
            }
     }
}


void parcours_largeur(Type_G g, unsigned int s){
// la pile fifo
     int * list;
//le juda pour memoriser les sommets par ou on est deja pass�
  int *marque;
  int i,deb,fin;
  int sommet_a_parcourir;

  list  =(int *)malloc(sizeof(int)*(g.order+2));
  marque=(int *)malloc(sizeof(int)*(g.order+2));
  //init du marque
 for(i=1;i<=g.order;i++)
        marque[i]=0;
  //on enfile le sommet de depart
  deb=1;
  fin=2;
  list[deb]=s;
  marque[s]=1;// on le marque deja passe
  while(deb<=g.order){
  //depiler
  sommet_a_parcourir=list[deb];
  deb++;
  printf("\n sommet %d) ",sommet_a_parcourir);
  //enfiler les voisins de sommet_a_parcourir
   for(i=1;i<=g.order;i++){
   //si voisin et non marque
   if((g.matrice[sommet_a_parcourir][i]!=0)&&(marque[i]==0)){
    list[fin]=i;
    marque[i]=1;
    fin++;
    }
   }
  }

}

int * copyYdansZ(int * destination, int *origine, Type_G g){
 int i;
 for(i=1;i<=g.order;i++)
  destination[i]=origine[i];
 return(destination);
}

int premier_sommet_de_Z (int * vecteur,  Type_G g){
 int i;
 for(i=1;i<=g.order;i++)
  if (vecteur[i]==0)
   return(i);
 return(-1);
}

int * retirer_s_et_ces_voisins (int s, int * vecteur,  Type_G g){
 int i;
 vecteur[s]=1;
 vecteur[g.order+1]++;
 for(i=1;i<=g.order;i++)
  if((g.matrice[s][i]>0)&&(vecteur[i]==0)){
   vecteur[g.order+1]++;
   vecteur[i]=1;
   }
 return(vecteur);
}

//////////////////////////////////////
// Glouton Graph algorithm
//////////////////////////////////////
int * glouton(Type_G g){
 int i,s;
 int * Y;
 int * Z;
 int cardY=0;
 int cardZ=0;
 int color=0;

 Y=(int *)malloc(sizeof(int)*(g.order+2));
 Z=(int *)malloc(sizeof(int)*(g.order+2));
 Z[g.order+1]=0;//contient cardZ
 //init
 for(i=1;i<=g.order;i++){
  Y[i]=0;
  Z[i]=0;
  }
 while (cardY<g.order){
  Z=copyYdansZ(Z,Y,g);
  Z[g.order+1]=cardY;
  color++;
  printf("\n\tChangement de couleur � %d",color);
  while(Z[g.order+1]<g.order){
   s=premier_sommet_de_Z(Z,g);
   printf("\ncoloration de y=%d avec color=%d",s,color);
   Y[s]=color;cardY++;
   Z=retirer_s_et_ces_voisins(s,Z,g);
  }
 }
 return (Y);
}

//////////////////////////////////////
// DSAT graph algorithm
//////////////////////////////////////

int sommet_non_colorie_de_dsat_max(Type_G g){
 //coloration_issu_de_dsat
 int v,i,dsat_max_local=0;
 for(i=1;i<= g.order;i++){
  if (coloration_issu_de_dsat[i]==0){
   if (dsat[i]>dsat_max_local){
    v=i;
    dsat_max_local=dsat[i];
   }
  }//if
 }//for i
 return(v);
}//end fct

int coloration_avec_couleur_mininum(int t, Type_G g){
 int i;
 int color_used[ORDER_MAX];

 //init
 for(i=1;i<= g.order;i++)color_used[i]=0;

 for(i=1;i<= g.order;i++){
  if((g.matrice[t][i]==1)&&(coloration_issu_de_dsat[i]>0)){
   color_used[coloration_issu_de_dsat[i]]=1;
  }//if
 }//for

 // on colorie t par la plus petite couleur non utilise
 // dans son premier voisinage
 for(i=1;i<= g.order;i++){
  if (color_used[i]==0){
    return (i);
   }
 }//for
}

int nb_de_couleur_differente_autour_de (int t, Type_G g){
 int i, nb_de_couleur_utilisee_autour_de_t;
 int color_used[ORDER_MAX];

 //init
 for(i=1;i<= g.order;i++)color_used[i]=0;

 for(i=1;i<= g.order;i++){
  if((g.matrice[t][i]==1)&&(coloration_issu_de_dsat[i]>0)){
   color_used[coloration_issu_de_dsat[i]]=1;
  }//if
 }//for

 nb_de_couleur_utilisee_autour_de_t=0;
 for(i=1;i<= g.order;i++)
  if (color_used[i]==1) nb_de_couleur_utilisee_autour_de_t++;
 return (nb_de_couleur_utilisee_autour_de_t);
}

void maj_du_vecteur_dsat (int t, Type_G g){
 int i;

 // synth�se pour que le sommet actuellement colori�
 // soit rapidement ecart� pour les autres choix
 dsat[t]=-1;
 for(i=1;i<= g.order;i++){
  if((g.matrice[t][i]==1)&&(coloration_issu_de_dsat[i]==0)){
   dsat[i]= nb_de_couleur_differente_autour_de (i,g);
  }//if
 }//for
}

void color_by_dsatur(Type_G g){
 int i,j,s;

 init_dsat(g);
 for(i=1;i<= g.order;i++){
  s=sommet_non_colorie_de_dsat_max(g);
  coloration_issu_de_dsat[s]=coloration_avec_couleur_mininum(s,g);
  printf("\n s=%d colori� par %d",s,coloration_issu_de_dsat[s]);
  maj_du_vecteur_dsat(s,g);
 }
}

//////////////////////////////////////
// Utilities
//////////////////////////////////////

int verif_color(Type_G g){
 int i,j;

 for(i=1;i<= g.order;i++){
  for(j=1;j<= g.order;j++){
   if ((g.matrice[i][j]==1)&&(coloration_issu_de_dsat[i]==coloration_issu_de_dsat[j])){
    printf("\n erreur le sommet %d  voisin de %d colori� avec la meme couleur %d",i,j,coloration_issu_de_dsat[i]);
    return (FALSE);
    }//if
  }//if j
 }//for i
 return (TRUE);
}



void lecture_dimacs_aretes(){
/*
// nettoyer le fichier pour avoir seulement les aretes, ie..
e 1 2
*/
   FILE *file;
   int retour_fscanf,x,y;
   char indic;
   file=fopen("./graph.txt","r");
   retour_fscanf = fscanf(file,"\n%c %d %d",&indic, &x, &y);
   while (retour_fscanf!=EOF)
      {
	  //101 code asci de e
	  //printf("\n%c(%d)",indic,indic);
	  if ((indic==101)&&(x>0)&&(y>0)){
		printf("\n arete entre %d %d",x,y);
		}
	  retour_fscanf = fscanf(file,"%c %d %d",&indic, &x, &y);
      }
   fclose(file);
   }


//////////////////////////////////////
// DISPLAY
//////////////////////////////////////
void display_graph(Type_G g){
 int i,j;
 printf("\n\nDISPLAY graph:\n");
 for(i=1;i<= g.order;i++){
  printf("\n");
  for(j=1;j<=(i-1);j++){
   printf(" (%d,%d)=%d ",i,j,g.matrice[i][j]);
   }
  }
}

void display_vecteur(int *vecteur, Type_G g){
 int i;
 printf("\n\nDISPLAY vecteur (i,value):\n");
 for(i=1;i<= g.order;i++){
  printf(" (%d,%d) ",i,vecteur[i]);
  }
}

//////////////////////////////////////
// MAIN
//////////////////////////////////////

int main (int argc, const char * argv[]) {
    // insert code here...
 int i;
 Type_G g;
 int * coloration;
 int verification_de_la_coloration;



 g.order=10;
 g=init_rand(g);

 //lecture graph dimacs
 lecture_dimacs_aretes();

 display_graph(g);
 //parcours_profondeur(g,1);
 //parcours_largeur(g,1);


 //coloration=glouton(g);
 //display_vecteur(coloration,g);


 color_by_dsatur(g);
 verification_de_la_coloration=verif_color(g);
 if (verification_de_la_coloration==TRUE)
  printf("\n Bonne coloration approuv�");
 else
  printf("\n Erreur dans la coloration");

    printf("\nFin.\n");
    return 0;
}
