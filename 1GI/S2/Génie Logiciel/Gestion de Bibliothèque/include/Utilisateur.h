#ifndef UTILISATEUR_H
#define UTILISATEUR_H


class Utilisateur
{
    public:
        Utilisateur(int cle=0, char* telPrenom="",char* telNom="", int pt=30, int telleDureAbo=1,bool telPai=true);

        void setID(int cle){   ID=cle; }
        void setPoints(int pts);
        void setSubscriptionDuration(int duration);
        void setPaymentStatus(bool status);
        void setNom(char* Nom);
        void setPrenom(char* Prenom);

        void show();

        int getID(){    return ID;  }
        ~Utilisateur();

    protected:

    private:
        int ID;
        char* Prenom;
        char* Nom;
        int points;
        int duree_abonnement;
        bool paiement;

};

#endif // UTILISATEUR_H
