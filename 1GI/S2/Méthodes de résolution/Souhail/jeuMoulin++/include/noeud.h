#ifndef NOEUD_H
#define NOEUD_H
#include <vector>
#include <iostream>
using namespace std;



class noeud
{
    public:
        int E[7][7];
        noeud();
        noeud(int [7][7]);
        void afficheToi();
        //virtual ~noeud();
        vector<noeud> noeud_suivant(int);
        float Heuristique_Attaque(int);
        float Heuristique_Defense(int);
        vector<int> Remove(noeud);
        bool Etat_Final();

};

#endif // NOEUD_H
