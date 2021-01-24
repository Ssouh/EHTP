#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAILLE 10
using namespace std;

///**************************** EX02 ********************************
class Date
{
private:
    int sonJour,sonMois,sonAnnee;
public:
    Date(){sonJour=01;sonAnnee=01;sonMois=1900;};
    Date(int a,int b,int c){
        if (0<a && a<32)sonJour=a;else sonJour=01;
        if (0<b && b<13)sonMois=b;else sonMois=01;
        sonAnnee=c;};
    void afficheToi(){
        cout<<"La DATE :"<<sonJour<<"/"<<sonMois<<"/"<<sonAnnee<<"\n"<<endl;
    }
};
class Cercle2D
{
private:
    int sonCentre_x,sonCentre_y,sonRayon;
public:
    Cercle2D(int a,int b,int c){sonCentre_x=a;sonCentre_y=b;sonRayon=c;}
    void presenteToi(){
        cout<<"Le Centre: ("<<sonCentre_x<<","<<sonCentre_y<<")"<<endl;
        cout<<"Le Rayon:"<<sonRayon<<"\n\n";
    }
};

class Citation
{
    char sonContenu[500],sonAuteur[50];
public:
    Citation(char p[500]="", char q[50]=""){strcpy(sonContenu,p);strcpy(sonAuteur,q);};
    void presenteToi(){
        cout<<"********* La Citation est :*********"<<endl;
        cout<<sonContenu<<endl;
        cout<<"********* Son Auteur est :**********"<<endl;
        cout<<"\t"<<sonAuteur<<"\n";
    }
};
class unEvenement
{
private:
    char* sonIntitule;Date* saDate;
public:
    unEvenement(char* a,Date b){
        saDate = new Date;
        sonIntitule = new char[strlen(a)+1];
        *saDate=b;strcpy(sonIntitule,a);}

    ~unEvenement(){
        delete [] sonIntitule;
        delete  saDate;
    }
    void afficheToi(){
        cout<<"\nNotre Evenement est :"<<sonIntitule<<endl;
        cout<<"Il va etre organiser ";saDate->afficheToi();
    }
};


///**************************** EX03 ********************************

class UnRationnel
{
    public:
        UnRationnel(int=1,int=1);
        void affiche();
        void somme(UnRationnel,UnRationnel);
        void lire();
        void produit(UnRationnel,UnRationnel);
        bool egalite(UnRationnel);
        int pgcd();
        void reduit();
        inline int donneNum();
        inline int donneDenom();
        UnRationnel retourneOperation(UnRationnel ras1, UnRationnel ras2);

    private:
        int sonNum,sonDenom;
};

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
    bool estvide() {if (sommet->etat==NULL) return true;return false;}
    bool estpleine() {if (sommet->etat!=NULL) return true;return false;}
    void afficheToi(){
        cellule* Sommet=sommet;
        cout<<"\nVotre Pile est :[";
        while (Sommet!=NULL)
           {cout <<Sommet->etat<<";";
            Sommet=Sommet->suivant;}
        cout<<"]";}
};
