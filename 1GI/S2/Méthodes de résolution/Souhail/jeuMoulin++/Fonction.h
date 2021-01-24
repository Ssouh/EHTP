/** variables :
     compteur = le nombre de coup joue*/
#include <vector>
#include <conio.h>
#include <iostream>
#include "noeud.h"
/**
int compteur;/// pair le joueur, impair la machine
int JCaisse;
int MCaisse;
int MinTour;/// 0==N==>>Max(Joueur) et 1==B==>>Min(Machine)*/

///color et tableau : LES FONCTIONS IMPLEMENTANTS L'INTERACTION ENTRE L'UTILISATEUR ENTRE PROGRAMME

int main();
void Choisi(int k);   /// DEPOSE LES ROCHES NOIRES OU BLANCHES DANS LA CASE (i,j)
void color(int t,int f);  /// COLORIE EN T LES CARATERES ET F EN ARRIERE PLAN
void fullscreen();
void Caisse(int k);/// les stocks des pierres des joueurs a cote de la table

void table(noeud);  /// LA TABLE 7X7 DU JEU
noeud Saisie(int A[7][7]);
noeud Deplacement(int A[7][7]);
noeud Capture(int i,int j,int A[7][7]);///Mur + retirer
noeud Retirer(int A[7][7]);

void Fin(noeud);

bool Tester(int i, int j,int A[7][7]);
bool valide(int i, int j,int A[7][7],int t);
vector<int> PionsLigne(int i,int j,int A[7][7]);/// retourne la vecteur(ite,adj,iteOP,adjOP);Precondition= MinTour;
vector<int> PionsColonne(int i,int j,int A[7][7]);
/// La statégie Min&Max
noeud AttaqueDefense(noeud, int);

