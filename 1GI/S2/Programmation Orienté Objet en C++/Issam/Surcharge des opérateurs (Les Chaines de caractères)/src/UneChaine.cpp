#include "UneChaine.h"
#include <iostream>
#include <string.h>
#include <ostream>
using namespace std;

UneChaine::UneChaine()
{
    sonContenu = nullptr;
    saLongueur = 0;
}


UneChaine::UneChaine(char* telleChaine)
{
    sonContenu = nullptr;
    saLongueur = 0;

    int telleLongueur = strlen(telleChaine);


    for (int i=telleLongueur-1; i>=0; i--)
    {
        this->ajoute(*(telleChaine+i));
    }
}

UneChaine::UneChaine(const UneChaine& telleChaine)
{
    sonContenu = nullptr;
    saLongueur = 0;

    int telleLongueur = telleChaine.saLongueur;


    for (int i=telleLongueur; i>0; i--)
    {
        int j=1;
        PCellule* p;
        p = telleChaine.sonContenu;
        while(j<=i-1)
        {
            p= p->suivant;
            j++;
        }

        this->ajoute(p->caractere);
    }

}

int UneChaine::getLongueur()
{
    return saLongueur;
}

void UneChaine::getContenu(char** telleChaine)
{
    int i=0;
    *telleChaine = new char[saLongueur + 1];

    PCellule* p=this->sonContenu;
    while(p)
    {
        *(*telleChaine+i) = p->caractere;
        p=p->suivant;
        i++;
    }

    *(*telleChaine+saLongueur) = '\0';

}


ostream& operator<<(ostream& telFlux, const UneChaine& telleChaine)
{
    char* chaine;
    UneChaine Chainelibre = telleChaine;
    Chainelibre.getContenu(&chaine);
    return telFlux << chaine ;
}

istream& operator>>( istream& telFlux, UneChaine& telleChaine)
{
    char* aide= new char[40];
    cout << "Entrer la chaine de caracteres : ";
    telFlux >> aide;
    telleChaine = UneChaine(aide);
    delete aide;

    return telFlux ;
}

UneChaine& UneChaine::operator=(const UneChaine& telleChaine)
{
    if (this!=&telleChaine)
    {

        sonContenu = nullptr;
        saLongueur = 0 ;

        int telleLongueur = telleChaine.saLongueur;


        for (int i=telleLongueur; i>0; i--)
        {
            int j=1;
            PCellule* p;
            p = telleChaine.sonContenu;
            while(j<=i-1)
            {
                p= p->suivant;
                j++;
            }

            this->ajoute(p->caractere);
        }

    }

    return *this;
}

bool UneChaine::operator==( UneChaine& telleChaine)
{
    char *temp1,*temp2;

    this->getContenu(&temp1);
    telleChaine.getContenu(&temp2);

    bool estEgale = (strcmp(temp1,temp2)==0);


    delete temp1;
    delete temp2;

    return estEgale;
}

bool UneChaine::operator!=( UneChaine& telleChaine)
{
    return !(*this==telleChaine);
}

void UneChaine::ajoute(char telCaractere)
{
    PCellule* nouveau;
    nouveau= new PCellule();
    nouveau->caractere=telCaractere;
    nouveau->suivant=this->sonContenu;
    this->sonContenu=nouveau;
    saLongueur++;
}

UneChaine::~UneChaine()
{
    while(sonContenu)
    {
        PCellule *temp = sonContenu;
        sonContenu=sonContenu->suivant;
        delete temp;
    }
}


