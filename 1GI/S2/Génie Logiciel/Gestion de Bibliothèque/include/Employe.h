#ifndef EMPLOYE_H
#define EMPLOYE_H


class Employe
{
    public:
        Employe(char* telPrenom, char* telNom);
        void setLogins(char* telPrenom, char* telNom);
        ~Employe();
        void login();



    private:
        char* prenom;
        char* nom;
        char* username;
        char* password;
};

#endif // EMPLOYE_H
