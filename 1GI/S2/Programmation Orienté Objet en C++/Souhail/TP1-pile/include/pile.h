#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


///**************************  EX 04:  ***********************************

typedef struct cellule{
    char* etat;
    struct cellule* suivant;
}cellule;
class Unepile
{
private:
    cellule* sommet;
public:
    Unepile() {sommet=NULL;};
    Unepile(cellule c) {
        sommet= &c;};

    void Raz(){sommet=NULL;}
    bool estvide() {if (sommet==NULL) return true;return false;}
    bool estpleine() {if (sommet!=NULL) return true;return false;}
    void afficheToi(){
        cellule* Sommet=sommet;
        cout<<"\nVotre Pile est :[";
        while (Sommet!=NULL)
           {cout <<Sommet->etat<<";";
            Sommet=Sommet->suivant;}
        cout<<"]";}
};
