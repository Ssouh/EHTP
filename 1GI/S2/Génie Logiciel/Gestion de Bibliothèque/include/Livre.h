#ifndef LIVRE_H
#define LIVRE_H


class Livre
{
    public:
        Livre(int Quant=0,char* codeb="",char* dom="",char* date="",char* aut="", int nbExemple=0);
        void modiefieQuantite(int );
        void exemplaireRetirer(int x)
        {
            nbExemplaire-=x;
        };
        void show();
        ~Livre();


    protected:
    char* codeBare;
    char* domaine;
    char* datePublication;
    char* auteur;
    int quantite;
    int nbExemplaire;
};

#endif // LIVRE_H
