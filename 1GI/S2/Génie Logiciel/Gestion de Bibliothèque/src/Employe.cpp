#include <iostream>
#include "Employe.h"
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

Employe::Employe(char* telPrenom, char* telNom)
{
    prenom= new char[strlen(telPrenom)+1];
    strcpy(prenom,telPrenom);

    nom=new char[strlen(telNom)+1];
    strcpy(nom,telNom);

    username=new char[50];
    strcpy(username,"Admin");

    password=new char[50];
    strcpy(password,"123456");
}

Employe::~Employe()
{

}

void Employe::setLogins(char* telUser, char* telPW)
{

    username= new char[strlen(telUser)+1];
    strcpy(username,telUser);

    password=new char[strlen(telPW)+1];
    strcpy(password,telPW);

}

void Employe::login()
{
    char user[70];
    char pw[70];
    cout << "Il faut sauthentifier pour acceder au système de gestion de biliotheque" <<endl;
    cout << "Username = "; cin >>user;
    cout << "Password = "; cin >>pw;


    if (strcmp(username,user)==0 && strcmp(password,pw)==0)
        cout << "Bienvenue " << prenom << " " << nom << endl << "Cliquez sur une touche pour continuer ..." << endl;
    else
    {
        cout << "Identification Invalide ..." << endl;
        login();
    }

    getch();
    return;
}
