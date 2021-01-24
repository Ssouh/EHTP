#include "../Fonction.h"


extern int compteur;

noeud::noeud(int Tab[7][7])
{
    for (int i=0;i<7;i++)
        for (int j=0;j<7;j++)
            E[i][j]=Tab[i][j];
}
noeud::noeud(){}

void noeud::afficheToi()
{
    for (int i=0;i<7;i++)
        {
            cout<<"\t\t\t";
            for (int j=0;j<7;j++)
        {
            cout<<E[i][j]<<"|";
        }
        cout<<"\n";}
}


vector<int> noeud::Remove(noeud A)
{
    vector<int> CR;
    for (int i=0;i<7;i++)
        for (int j=0;j<7;j++)
            if(A.E[i][j]!=E[i][j])
            {
                CR.push_back(i);
                CR.push_back(j);
            }
    return CR;
}

float noeud::Heuristique_Attaque(int tour)
{
    float HeuriAtt=0;
    vector<int> PC,PL;
    for (int i=0;i++;i<7)
        for (int j=0;j++;j<7)
        {
            if (E[i][j]==tour){
            PL=PionsLigne(i,j,E);
            PC=PionsColonne(i,j,E);
            cout<< "PL=";
            for (int i=0;i<PL.size();i++)  cout<<PL[i];
            cout<< "PC=";
            for (int i=0;i<PC.size();i++)  cout<<PC[i];getch();
            if (PL[0]==2 || PC[0]==2) HeuriAtt+=4;
            else if (PL[0]==1 && PC[0]==1 && PL[2]==0 && PC[2]==0) HeuriAtt+=3;
            else if (PL[1]==1 && PL[2]==0) HeuriAtt+=2;
            else if (PC[1]==1 && PC[2]==0) HeuriAtt+=2;
            else if (PC[0]==0 && PC[2]==0 && PL[0]==0 && PL[2]==0) HeuriAtt+=1;
            else HeuriAtt+=1/2;
        }}
    return HeuriAtt;
}
float noeud::Heuristique_Defense(int tour)
{
    float HeuriDef=0;
    vector<int> PC,PL;
    for (int i=0;i++;i<7)
        for (int j=0;j++;j<7)
        {
            if (E[i][j]==tour){
            PL=PionsLigne(i,j,E);
            PC=PionsColonne(i,j,E);
            cout<< "PL=";
            for (int i=0;i<PL.size();i++)  cout<<PL[i];
            cout<< "PC=";
            for (int i=0;i<PC.size();i++)  cout<<PC[i];getch();
            if (PL[2]==2 && PC[2]==2) HeuriDef+=4;
            else if (PL[2]==2 || PC[2]==2) HeuriDef+=3;
            else if (PL[2]==1 && PC[2]==1) HeuriDef+=2;
            else if (PL[2]==1 || PC[2]==1) HeuriDef+=1;
            else HeuriDef+=1/2;
        }}

    return HeuriDef;
}

vector<int> PionsLigne(int i,int j,int A[7][7])/// retourne la vecteur(ite,adj,iteOP,adjOP);Precondition=Tour;
{
    vector<int> PL;
    int ite=0;int adj=0;
    int iteOP=0;int adjOP=0;
    if (i!=3){
        for (int r=0;r<7 && r!=j;r++)
            if (A[i][r]==A[i][j])
            {
                ite++;
                if (r==j-1 || r==j+1) adj++;}
            else if (A[i][r]==1-A[i][j])
            {
                iteOP++;
                if (r==j-1 || r==j+1) adjOP++;
            }}
    else if (i<3)
        {
        for (int r=0;r<3 && r!=j;r++)
            if (A[i][r]==A[i][j])
            {
                ite++;
                if (r==j-1 || r==j+1) adj++;}
            else if (A[i][r]==1-A[i][j])
            {
                iteOP++;
                if (r==j-1 || r==j+1) adjOP++;
            }
        }
    else{
        for (int r=4;r<7 && r!=j;r++)
            if (A[i][r]==A[i][j])
            {
                ite++;
                if (r==j-1 || r==j+1) adj++;}
            else if (A[i][r]==1-A[i][j])
            {
                iteOP++;
                if (r==j-1 || r==j+1) adjOP++;
            }
        }
    PL.push_back(ite);
    PL.push_back(adj);
    PL.push_back(iteOP);
    PL.push_back(adjOP);
    return PL;
}

vector<int> PionsColonne(int i,int j,int A[7][7])
{
    vector<int> PC;
    int ite=0;int adj=0;
    int iteOP=0;int adjOP=0;
    if (j!=3){
        for (int r=0;r<7 && r!=i;r++)
            if (A[r][j]==A[i][j])
            {
                ite++;
                if (r==i-1 || r==i+1) adj++;}
            else if (A[r][j]==1-A[i][j])
            {
                iteOP++;
                if (r==i-1 || r==i+1) adjOP++;
            }}
    else if (j<3)
        {
        for (int r=0;r<3 && r!=i;r++)
            if (A[r][j]==A[i][j])
            {
                ite++;
                if (r==i-1 || r==i+1) adj++;}
            else if (A[r][j]==1-A[i][j])
            {
                iteOP++;
                if (r==i-1 || r==i+1) adjOP++;
            }
        }
    else{
        for (int r=4;r<7 && r!=i;r++)
            if (A[r][j]==A[i][j])
            {
                ite++;
                if (r==i-1 || r==i+1) adj++;}
            else if (A[r][j]==1-A[i][j])
            {
                iteOP++;
                if (r==i-1 || r==i+1) adjOP++;
            }
        }
    PC.push_back(ite);
    PC.push_back(adj);
    PC.push_back(iteOP);
    PC.push_back(adjOP);
    return PC;
}



vector<noeud> noeud::noeud_suivant(int TourSuivant)
{
    vector<noeud> NS;
    if (compteur<18)
    {
        for(int i=0;i<7;i++)
            for(int j=0;j<7;j++)
            {
                if (Tester(i+1,j+1,E))
                {
                    noeud A(E);/// cas de probleme essayer par reference
                    A.E[i][j]=TourSuivant;
                    NS.push_back(A);
                }
            }
    }
    else
    {
        for(int i=0;i<7;i++)
            for(int j=0;j<7;j++)
            {
                if (valide(i+1,j+1,E,TourSuivant))
                {
                        for(int i0=0;i0<7;i0++)
                            for(int j0=0;j0<7;j0++)
                            {
                                if (Tester(i0+1,j0+1,E))
                                {
                                    noeud A(E);/// cas de probleme essayer par reference
                                    A.E[i][j]=-1;
                                    A.E[i0][j0]=TourSuivant;
                                    NS.push_back(A);

                                }
                            }
                }
            }
    }
    return NS;
}

bool noeud::Etat_Final()
{
    int Terrain_Noir=0;int Terrain_Blanc=0;
    for(int i0=0;i0<7;i0++)
        for(int j0=0;j0<7;j0++)
            {
                if (E[i0][j0]==0) Terrain_Noir++;
                if (E[i0][j0]==1) Terrain_Blanc++;
            }
    if ((Terrain_Blanc<3 || Terrain_Noir<3 )&& compteur>18) return true;
    return false;
}



