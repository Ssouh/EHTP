#include "Livre.h"
#include <string.h>
#include <iostream>

using namespace std;

Livre::Livre(int Quant,char* codeb,char* dom,char* date,char* aut,int nbExemple)
{
     quantite=Quant;  nbExemplaire=nbExemple;
    int taille = strlen(dom)+1;
    domaine = new char[taille];
    strcpy(domaine,dom);

    taille = strlen(date)+1;
    datePublication = new char[taille];
    strcpy(datePublication,date);

    taille = strlen(aut)+1;
    auteur = new char[taille];
    strcpy(auteur,aut);

    taille = strlen(codeb)+1;
    codeBare = new char[taille];
    strcpy(codeBare,codeb);
}

void Livre::show()
{
    //std::cout<<codeBare<<"\t\t"<<domaine<<"\t\t"<<datePublication<<"\t\t"<<auteur<<"\t\t"<<quantite<<"\t\t"<<nbExemplaire<<std::endl<<std::endl;;

    cout << codeBare << "\t\t" << domaine << "\t\t" << datePublication << "\t\t" << auteur << "\t\t" << quantite << "\t\t\t"<< nbExemplaire << "\t\t" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
Livre::~Livre()
{
            delete domaine;
            delete datePublication;
            delete auteur;
            delete codeBare;
}
