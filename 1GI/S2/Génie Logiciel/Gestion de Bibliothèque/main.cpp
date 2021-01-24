#include <iostream>
#include "Database.h"
#include "Utilisateur.h"
#include "Livre.h"
#include "Employe.h"
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void clearScreen();

using namespace std;

int main()
{
    // Identification pour accéder au système de gestion de bibliothèque
    Employe Administrateur("Said","Akhnouch");
    //Administrateur.setLogins("test","test");
    Administrateur.login();

    Database DB(5,5);

    Livre *book = new Livre[8];

    Utilisateur user1(0,"Omar","Zouhaid",30,1,true);
    Utilisateur user2(1,"Smail","Hinda",30,2,true);
    Utilisateur user3(2,"Sana","Boutitu");
    Utilisateur user4(3,"Omar","Kady",30,4,false);
    Utilisateur user5(4,"Ismail","Hani",30,3,true);


    Livre exemple1(50,"47A85B281","Aventur","22/04/1966","Vector Hugo",19);
    Livre exemple2(500,"178OP52B11","Amour","11/03/1970","jonathan Alfred",159);
    Livre exemple3(500,"17MML52B11","Haine","11/03/1997","Taha Hussain",159);
    Livre exemple4(500,"178C52XX1","Romance","11/03/1970","jonathan Said",159);
    Livre exemple5(500,"178C52XX1","Action","11/03/1940","AhmedBaha",159);



    DB.addBook(exemple1);
    DB.addBook(exemple2);
    DB.addBook(exemple3);
    DB.addBook(exemple4);
    DB.addBook(exemple5);


    DB.addUser(user1);
    DB.addUser(user2);
    DB.addUser(user3);
    DB.addUser(user4);
    DB.addUser(user5);



while(1)
{
    clearScreen();
    int choix;
    cout << "Qu'ce que vous voulez faire ? " << endl;
    cout << "1. Consulter la liste des utilisateurs." << endl;
    cout << "2. Consulter le catalogue des livres." << endl;
    cout << "Votre choix : "; cin >> choix;

    switch(choix)
    {

    case 1:
        clearScreen();
        DB.showUsers();
        cout << "Cliquez sur une touche pour retourner";
        getch();
        break;

    case 2:
        clearScreen();
        DB.showBooks();
        cout << "Cliquez sur une touche pour retourner";
        getch();
        break;

    default:
        break;

    }
}



}


void clearScreen()
{
   system("cls");
}
