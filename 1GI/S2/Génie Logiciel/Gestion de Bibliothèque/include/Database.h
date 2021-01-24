#ifndef DATABASE_H
#define DATABASE_H
#include "Utilisateur.h"
#include "Livre.h"

class Database
{
    public:
        Database(int maxiusers, int maxibooks);
        void addUser(Utilisateur user);
        void removeUser(Utilisateur user);

        void addBook(Livre &book);

        void showUsers();
        void showBooks();

        int getCurrentUsers(){ return CurrentUsers;}
        ~Database();

    private:
        Utilisateur* users;
        Livre* books;
        int maxUsers;
        int maxBooks;
        int CurrentUsers;
        int CurrentBooks;
};

#endif // DATABASE_H
