#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <vector>

using namespace std;
#include "Fonction.h"
#include "noeud.h"




noeud AttaqueDefense(noeud N,int Tour)///retourne le noeud a jouer
{
    vector<noeud> Noeud_A_Traite;
    Noeud_A_Traite=N.noeud_suivant(Tour);

    vector<float> Heuri_Def_Noeud_A_Traite;
    for (int i=0;i<Noeud_A_Traite.size();i++)
        Heuri_Def_Noeud_A_Traite.push_back(Noeud_A_Traite[i].Heuristique_Defense(Tour));
    vector<float> Heuri_Att_Noeud_A_Traite;
    for (int i=0;i<Noeud_A_Traite.size();i++)
        Heuri_Att_Noeud_A_Traite.push_back(Noeud_A_Traite[i].Heuristique_Attaque(Tour));

    /// le plus grand element dans un vecteur
    int Indice_Att=0;
    float largest_element_Att = Heuri_Att_Noeud_A_Traite[0];
    for(int i = 1; i < Heuri_Att_Noeud_A_Traite.size(); i++)
    if(Heuri_Att_Noeud_A_Traite[i] > largest_element_Att)
    {
      largest_element_Att = Heuri_Att_Noeud_A_Traite[i];
      Indice_Att=i;
    }
    int Indice_Def=0;
    float largest_element_Def = Heuri_Def_Noeud_A_Traite[0];
    for(int i = 1; i < Heuri_Def_Noeud_A_Traite.size(); i++)
    if(Heuri_Def_Noeud_A_Traite[i] > largest_element_Def)
    {
      largest_element_Def = Heuri_Def_Noeud_A_Traite[i];
      Indice_Def=i;
    }

    int indice_noeud_suivant;
    if (largest_element_Att<largest_element_Def)
        indice_noeud_suivant=Indice_Def;
    else indice_noeud_suivant=Indice_Att;

    return Noeud_A_Traite[indice_noeud_suivant];

}




