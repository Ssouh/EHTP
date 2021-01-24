#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <vector> /// include vector https://www.geeksforgeeks.org/vector-in-cpp-stl/
using namespace std;
#include "Fonction.h"


int EI[7][7]=              {{ -1, 10, 10, -1, 10, 10, -1},
                            { 10, -1, 10, -1, 10, -1, 10},
                            { 10, 10, -1, -1, -1, 10, 10},
                            { -1, -1, -1, 10, -1, -1, -1},
                            { 10, 10, -1, -1, -1, 10, 10},
                            { 10, -1, 10, -1, 10, -1, 10},
                            { -1, 10, 10, -1, 10, 10, -1}};
noeud Etat_initial(EI);
int compteur;/// pair le joueur, impair la machine
int JCaisse;
int MCaisse;

void fullscreen() ///function definition for fullscreen source: https://www.dreamincode.net/forums/topic/59497-run-a-c-program-in-full-screen/
{  keybd_event(VK_MENU,
				0x38,
				0,
				0);
	keybd_event(VK_RETURN,
				0x1c,
				0,
				0);
	keybd_event(VK_RETURN,
				0x1c,
				KEYEVENTF_KEYUP,
				0);
	keybd_event(VK_MENU,
				0x38,
				KEYEVENTF_KEYUP,
				0);
}


void color(int t,int f) /// http://www.cplusplus.com/forum/beginner/54360/
{
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,f*16+t);
}


void Choisi(int k)
{
    if (k==-1)
    {printf("+");
    }
    else if (k==0)
    {
        color(0,0);
        printf(" ");
        color(15,3);/// 0 ==> NOIR

    }
    else if (k==1)
    {
        color(0,15);
        printf(" ");
        color(15,3);/// 1 ==> BLANC
    }}

void table(noeud N)
{
    color(3,15);
    int A[7][7];
    for (int i=0;i<7;i++)
        for (int j=0;j<7;j++)
            A[i][j]=N.E[i][j];
    system("cls");
    cout<<  "\n\n\n\t\t\t\t\t";color(15,3);cout<<"  1        2        3         4         5        6        7";color(3,15);cout<<"\n";
    cout<<  "\t\t\t\t\t";color(15,3);cout<<"1 ";Choisi(A[0][0]);cout<<"---------------------------";Choisi(A[0][3]);cout<<"---------------------------";Choisi(A[0][6]);color(3,15);color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |                           |                           |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |                           |                           |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |                           |                           |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"2 |        ";Choisi(A[1][1]);cout<<"------------------";Choisi(A[1][3]);cout<<"------------------";Choisi(A[1][5]);cout<<"        |";color(3,15);color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |        |                  |                  |        |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |        |                  |                  |        |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |        |                  |                  |        |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"3 |        |        ";Choisi(A[2][2]);cout<<"---------";Choisi(A[2][3]);cout<<"---------";Choisi(A[2][4]);cout<<"        |        |";color(3,15);color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |        |        |                   |        |        |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |        |        |                   |        |        |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |        |        |                   |        |        |";color(3,15);cout<<"\n"
            "\t";Caisse(0);cout<<"\t\t";color(15,3);cout<<"4 ";Choisi(A[3][0]);cout<<"--------";Choisi(A[3][1]);cout<<"--------";Choisi(A[3][2]);cout<<"                   ";Choisi(A[3][4]);cout<<"--------";Choisi(A[3][5]);cout<<"--------";Choisi(A[3][6]);color(3,15);cout<<"\t";Caisse(1);cout<<"\t\t\n"
            "\t";Caisse(2);cout<<"\t\t";color(15,3);cout<<"  |        |        |                   |        |        |";color(3,15);cout<<"\t";Caisse(3);cout<<"\t\t\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |        |        |                   |        |        |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |        |        |                   |        |        |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"5 |        |        ";Choisi(A[4][2]);cout<<"---------";Choisi(A[4][3]);cout<<"---------";Choisi(A[4][4]);cout<<"        |        |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |        |                  |                  |        |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |        |                  |                  |        |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |        |                  |                  |        |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"6 |        ";Choisi(A[5][1]);cout<<"------------------";Choisi(A[5][3]);cout<<"------------------";Choisi(A[5][5]);cout<<"        |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |                           |                           |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |                           |                           |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"  |                           |                           |";color(3,15);cout<<"\n"
            "\t\t\t\t\t";color(15,3);cout<<"7 ";Choisi(A[6][0]);cout<<"---------------------------";Choisi(A[6][3]);cout<<"---------------------------";Choisi(A[6][6]);color(3,15);cout<<"\n";
            ;color(15,3);cout<<"\n\t\t\t\t\t\t\tPour QUITTER entrez -1 -1\n";

            Fin(N);
            if (compteur<18)
                table(Saisie(A));/// si compteur < 18
            else table(Deplacement(A));/// si compteur > 18

}

void Caisse(int k)/// les stocks des pierres des joueurs a cote de la table
{
    if (k==0){
    cout << "Joueur Capture="<<JCaisse;
    }
    else if (k==1)
    {
        cout << "Machine Capture="<<MCaisse;
    }else if (k==2 && compteur<18)
    {
        cout << "Pions Restants="<<(int)(18-compteur)/2;
    }else if (k==2)
    {
        cout << "Pions Restants=0";
    }else if (k==3 && compteur<18)
    {
        cout << "Pions Restants="<<(int)(18-compteur)/2;
    }else if (k==3)
    {
        cout << "Pions Restants=0";
    }
}

noeud Saisie(int A[7][7])
{
    noeud R(A);
    if (compteur<18)
    {   int i,j;

        if (compteur % 2 == 0)
          { L:
            cout<< "\n\t\t\t\t\t\t CHOISIR LA LIGNE PUIS COLONNE ^-^ : ";
            cin>> i; cin>>j;
            if (i==-1 && j==-1) main();
            if (!Tester(i,j,A)) {cout<< "\n\t\t\t\t\t\t ERREUR"; goto L;}
            A[i-1][j-1]=0;
            R=Capture(i,j,A);
          }
          else
          {
              noeud N(A);
              noeud M;vector<int> CR;
              M=AttaqueDefense(N,1);
              A=M.E;
              CR=N.Remove(M);///case moved
              R=Capture(CR[0]+1,CR[1]+1,A);
          }
    compteur++;
    }

    return R;
}

bool Tester(int i, int j,int A[7][7])/// return bool en accord avec la validite de l'emplacement
{
    if (A[i-1][j-1]!=-1) return false;
    if (i==1 && j==2 ) return false;
    if (i==1 && j==3 ) return false;
    if (i==1 && j==5 ) return false;
    if (i==1 && j==6 ) return false;
    if (i==2 && j==1 ) return false;
    if (i==2 && j==3 ) return false;
    if (i==2 && j==5 ) return false;
    if (i==2 && j==7 ) return false;
    if (i==3 && j==1 ) return false;
    if (i==3 && j==2 ) return false;
    if (i==3 && j==6 ) return false;
    if (i==3 && j==7 ) return false;
    if (i==4 && j==4 ) return false;
    if (i==5 && j==1 ) return false;
    if (i==5 && j==2 ) return false;
    if (i==5 && j==6 ) return false;
    if (i==5 && j==7 ) return false;
    if (i==6 && j==1 ) return false;
    if (i==6 && j==3 ) return false;
    if (i==6 && j==5 ) return false;
    if (i==6 && j==7 ) return false;
    if (i==7 && j==2 ) return false;
    if (i==7 && j==3 ) return false;
    if (i==7 && j==5 ) return false;
    if (i==7 && j==6 ) return false;
    return true;
}


noeud Deplacement(int A[7][7])
{
    noeud R(A);
    if (compteur>=18)
    {
        int i1,j1,i2,j2;
        if (compteur% 2 == 0)
          { L:
            cout<< "\n\t\t\t\t\t CHOISIR LA LIGNE PUIS COLONNE DU PIONS A DEPLACER ^_^ : ";
            cin>> i1;cin>>j1;
            if (i1==-1 && j1==-1) main();
            if (!valide(i1,j1,A,1)) {cout<< "\n\t\t\t\t\t\t\t ERREUR"; goto L;}
            cout<< "\n\t\t\t\t\t\t CHOISIR LA LIGNE PUIS COLONNE ^_^ : ";
            cin>> i2;cin>>j2;
            if (!Tester(i2,j2,A)) {cout<< "\n\t\t\t\t\t\t\t ERREUR"; goto L;}
            A[i1-1][j1-1]=-1;A[i2-1][j2-1]=0;
            Choisi(A[i2-1][j2-1]);
            R=Capture(i2,j2,A);
          }
          else
          {
              noeud N(A);
              noeud M;vector<int> CR;
              M=AttaqueDefense(N,1);
              A=M.E;
              CR=M.Remove(N);///case moved
              R=Capture(CR[0]+1,CR[1]+1,A);
          }
        compteur++;
    }

    return R;
}

bool valide(int i, int j,int A[7][7],int caseOP)/// return bool en accord avec la validite de la cas a deplacer
{
    if (A[i-1][j-1]==-1) return false;
    if (A[i-1][j-1]==caseOP) return false;
    if (i==1 && j==2 ) return false;
    if (i==1 && j==3 ) return false;
    if (i==1 && j==5 ) return false;
    if (i==1 && j==6 ) return false;
    if (i==2 && j==1 ) return false;
    if (i==2 && j==3 ) return false;
    if (i==2 && j==5 ) return false;
    if (i==2 && j==7 ) return false;
    if (i==3 && j==1 ) return false;
    if (i==3 && j==2 ) return false;
    if (i==3 && j==6 ) return false;
    if (i==3 && j==7 ) return false;
    if (i==4 && j==4 ) return false;
    if (i==5 && j==1 ) return false;
    if (i==5 && j==2 ) return false;
    if (i==5 && j==6 ) return false;
    if (i==5 && j==7 ) return false;
    if (i==6 && j==1 ) return false;
    if (i==6 && j==3 ) return false;
    if (i==6 && j==5 ) return false;
    if (i==6 && j==7 ) return false;
    if (i==7 && j==2 ) return false;
    if (i==7 && j==3 ) return false;
    if (i==7 && j==5 ) return false;
    if (i==7 && j==6 ) return false;
    return true;
}


noeud Retirer(int A[7][7])
{
    int i,j;
    if (compteur% 2 ==0)
    {   R:
        printf("\n\t\t\t\t\t\t CHOISIR LA LIGNE PUIS COLONNE A RETIRER ^_^ : ");
        cin>> i;cin>>j;
        if (valide(i,j,A,0)) A[i-1][j-1]=-1;
        else {cout<< "\n\t\t\t\t\t\t\t ERREUR"; goto R;}
        JCaisse++;
    }
    else
    {
        noeud N(A);
        noeud M;vector<int> CR;
        M=AttaqueDefense(N,0);
        CR=M.Remove(N);///Noeud Remove
        A[CR[0]][CR[1]]=-1;
        MCaisse++;
    }
    noeud H(A);
    H.afficheToi();
    getch();
    return H;
}


bool MurLigne(int i,int j,int A[7][7])
{
        int ite=0;
        if (i!=4){
            for (int r=0;r<7;r++)
                if (A[i-1][r]==A[i-1][j-1]) ite++;
            if (ite==3) return true;}
        else{
            for (int r=0;r<3;r++)
                if (A[i-1][r]==A[i-1][j-1]) ite++;
            if (ite==3) return true;
            ite=0;
            for (int r=4;r<7;r++)
                if (A[i-1][r]==A[i-1][j-1]) ite++;
                if (ite==3) return true;}
        return false;
}
bool MurColonne(int i,int j,int A[7][7])
{
        int ite=0;
        if (j!=4){
            for (int r=0;r<7;r++)
                if (A[r][j-1]==A[i-1][j-1]) ite++;
            if (ite==3) return true;}
        else{
            for (int r=0;r<3;r++)
                if (A[r][j-1]==A[i-1][j-1]) ite++;
            if (ite==3) return true;
            ite=0;
            for (int r=4;r<7;r++)
                if (A[r][j-1]==A[i-1][j-1]) ite++;
                if (ite==3) return true;}
        return false;
}

noeud Capture(int i,int j,int A[7][7])///Mur + retirer
{
    noeud R(A);
    if(MurLigne(i,j,A)) R=Retirer(A);
    if(MurColonne(i,j,A)) R=Retirer(A);
    return R;
}

void Fin(noeud N)
{
    if (N.Etat_Final())
    {
        system("cls");
        cout<<"\n"
              "\n"
              "\t\t\t\t\t        @@@@@@@   @@@@@@@   @@@@@@@   @@@@@@@   @   @@@@@@@\n"
              "\t\t\t\t\t        @     @   @     @   @     @      @      @   @\n"
              "\t\t\t\t\t        @@@@@@@   @     @   @@@@@@@      @      @   @\n"
              "\t\t\t\t\t        @         @@@@@@@   @  @         @      @   @@@@@@@\n"
              "\t\t\t\t\t        @         @     @   @   @        @      @   @\n"
              "\t\t\t\t\t        @         @     @   @    @       @      @   @\n"
              "\t\t\t\t\t        @         @     @   @     @      @      @   @@@@@@@ \n\n\n"
              "\t\t\t\t\t               @@@@@@@   @   @     @   @   @@@@@@@\n"
              "\t\t\t\t\t               @         @   @@    @   @   @\n"
              "\t\t\t\t\t               @         @   @ @   @   @   @\n"
              "\t\t\t\t\t               @@@@@@@   @   @  @  @   @   @@@@@@@\n"
              "\t\t\t\t\t               @         @   @   @ @   @   @\n"
              "\t\t\t\t\t               @         @   @    @@   @   @\n"
              "\t\t\t\t\t               @         @   @     @   @   @@@@@@@ \n";
        getch();
        main();
    }
}







/*
void selectionJVM()
{   int i,k=0,j,x,y;
    if (((compteur+1)/2. - (compteur+1)/2)==0)
    {printf("\n\t\t\t\t\t\t\t\t CHOISIR LA LIGNE PUIS COLONNE ^_^ : ");
    cin>> i,j;
    if ( i>8 || j>8) {printf("\t\t\t\t\t\t\t CASE INCORRECTE '~' "); selectionJVM();}
    if (H[i][j]==0 || H[i][j]==1) {printf("\t\t\t\t\t\t\t CASE PLEINE '-' "); selectionJVM();}
    else {
    //Coup_interdit(i+1,j+1);Coup_interdit_grp(i+1,j+1);
    A[i][j]=1;}}
    else{
    srand(time(NULL) );
    do {x=rand()%9;
    y=rand()%9;k=1;
    } while ( H[x][y]!= -1 || k==0);
    A[x][y]=1;}
    compteur++;
    system("cls");
    table();
    }

void selectionJVJ()
{   int i,j;
    if (((compteur+1)/2. - (compteur+1)/2)==0)
    {   color(15,3);
        printf("\n\t\t\t\t\t JOUEUR EN ");
        color(0,0);
        printf("  ");
        color(15,3);
        printf(" ");
        color(3,15);
        printf(" CHOISIT TA LIGNE PUIS COLONNE ^_^ : ");
        }
    else {color(15,3);
        printf("\n\t\t\t\t\t JOUEUR EN ");
        color(0,15);
        printf("  ");
        color(15,3);
        printf(" ");
        color(3,15);
        printf(" CHOISIT TA LIGNE PUIS COLONNE ^_^ : ");}

    cin>> i>>j;
    //vector<int> V; V.push_back();
    ///if (H[i-1][j-1]==0 || H[i-1][j-1]==1) {printf("\t\t\t\t CASE PLEINE '-' "); selectionJVJ();}
    /// vecteur is needed in this area .
    ///if(std::find(v.begin(), v.end(), x) != v.end()) {
    ///         v contains x
    ///    } else {
    ///         v does not contain x
    if ( i>7 || j>7) {printf("\t\t\t\t CASE INCORRECTE '~' "); selectionJVJ();}
    else {
    compteur++;
    A[i-1][j-1]=1;
    system("cls");
    table();
    }
}
*/
