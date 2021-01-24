#include "Database.h"
#include <iostream>

using namespace std;

Database::Database(int maxiusers, int maxibooks)
{
    CurrentUsers = 0;
    CurrentBooks = 0;

    maxUsers = maxiusers;
    users = new Utilisateur[maxUsers];

    maxBooks = maxibooks;
    books = new Livre[maxBooks];
}

void Database::addUser(Utilisateur user)
{
    if (CurrentUsers<maxUsers)
    {
        users[CurrentUsers] = user;
        users[CurrentUsers].setID(CurrentUsers);
        CurrentUsers++;
    }


}

void Database::addBook(Livre& book)
{
    if (CurrentBooks<maxBooks)
    {
        books[CurrentBooks] = book;
        CurrentBooks++;
    }


}



void Database::removeUser(Utilisateur user)
{
    for (int i=0; i <CurrentUsers; i++)
        if (users[i].getID()  ==  user.getID())
        {
            users[i].setNom("Supprime");
            users[i].setPrenom("Supprime");
            users[i].setPaymentStatus(false);
            users[i].setSubscriptionDuration(0);
            users[i].setPoints(0);
        }

}

void Database::showUsers(){

    cout << "\t\t\t Base donnes des utilisateurs de la bibliotheque : " << endl << endl;
    cout << "ID" << "\t\t" << "Prenom" << "\t\t" << "Nom" << "\t\t" << "points" << "\t\t" << "duree abon" << "\t\t"  << "Etat Paiement" << "\t\t" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    for (int i=0; i<CurrentUsers; i++)
        users[i].show();

}

void Database::showBooks(){

    Livre exemple1(50,"47A85B281","Aventure","22/04/1966","VectorHugo",19);
    Livre exemple2(500,"178OP52B11","Amour","11/03/1970","jonathanAlfred",159);
    Livre exemple3(500,"17MML52B11","Haine","11/03/1997","Taha Hussain",159);
    Livre exemple4(500,"178C52XX1","Romance","11/03/1970","jonathanAlfred",159);


    cout << "\t\t\t Catalogue des livres de la bibliotheque : " << endl << endl;
    cout << "Code Barre" << "\t\t" << "Domaine" << "\t\t" << "Date Publciation" << "\t\t" << "Auteur" << "\t\t" << "Quantite" << "\t\t"  << "Nbr Exemplaires" << "\t\t" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    for (int i=0; i<CurrentBooks; i++)
        books[i].show();


}

Database::~Database()
{
    delete []users;
}
