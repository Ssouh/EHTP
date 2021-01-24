#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct
{
    char position; // Position de la barque, 2 valeurs sont possibles 'G' pour gauche et 'D' pour droite.
    int missionn,cannib;// Nombre des cannibales et missionnaire se trouvant dans la rive droite

}etat;

typedef struct Noeud
{
    struct Noeud *suivant;
    etat Etat;
}noeud;

typedef noeud* Pile;

Pile listeNoeuds; // D�claration de la pile officielle qui contiendra les noeuds

/* C'est l'algorithme de recherche en profondeur en utilisant une pile */
void RechercheProfondeur( etat etatInitial, etat etatFinal,void generesuccesseurs());
int etatSolution(etat etatCourant);             // Retourne 1 si etatCourant est une solution effective
void generesuccesseurs(etat E);                 // g�n�ration des successeurs � partir d'un noeud en suivant les r�gles de jeu
int appartient(etat etatCourant, Pile liste);   // V�rifi si etatCourant appartient � la pile, on retourne 1 dans ce cas, sinon 0
etat extraire(Pile *listeNoeuds);               // Op�ration de d�piler
void insertion(etat etatCourant,Pile *liste);   // Insertion d'un nouveau noeud dans la pile
int vide(Pile listeCourante);                   // V�erifie si la pile est vide, retourne 1 dans ce cas sinon 0
void affichageGraphique(etat E);                // un affichage graphique montrant les diffirentes �tapes pour atteindre le r�sultat final

#endif // FONCTIONS_H_INCLUDED
