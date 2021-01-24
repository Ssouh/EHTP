#include "Utilisateur.h"
#include <string.h>
#include <iostream>

using namespace std;

Utilisateur::Utilisateur(int cle, char* telPrenom,char* telNom, int pt, int telleDureAbo,bool telPai)
{
    ID = cle;

    Prenom=new char[strlen(telPrenom)+1];
    strcpy(Prenom,telPrenom);

    Nom=new char[strlen(telNom)+1];
    strcpy(Nom,telNom);

    points = pt;
    duree_abonnement = telleDureAbo;
    paiement = telPai;
}


void Utilisateur::setPoints(int pts){  points=pts;  }
void Utilisateur::setSubscriptionDuration(int duration){ duree_abonnement = duration;   }
void Utilisateur::setPaymentStatus(bool status){  paiement = status;   }

void Utilisateur::setPrenom(char* telPrenom){

    delete []Prenom;
    Prenom=new char[strlen(telPrenom)+1];
    strcpy(Prenom,telPrenom);

    }

void Utilisateur::setNom(char* telNom){

    delete []Nom;
    Prenom=new char[strlen(telNom)+1];
    strcpy(Nom,telNom);

}

void Utilisateur::show(){

    cout << ID << "\t\t" << Prenom << "\t\t" << Nom << "\t\t" << points << "\t\t" << duree_abonnement << "\t\t\t" ; (paiement)? cout << "Paye": cout << "Non Paye" ; cout << "\t\t" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
}

Utilisateur::~Utilisateur()
{
    delete []Prenom;
    delete []Nom;
}
