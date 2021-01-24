#include <iostream>
#include "UneChaine.h"

using namespace std;

int main()
{
    /* Programme de test */

    //Les construteurs
    UneChaine chainevide;
    UneChaine prenom("Issam");
    UneChaine prenomparcopie = prenom; //constructeur par copie

    cout << "chainevide = " << chainevide << endl;
    cout << "prenom = " << prenom << endl;
    cout << "prenomparcopie = " << prenomparcopie << endl << endl;

    //Accesseurs
    int longueur = prenom.getLongueur();
    cout << "Longueur de prenom est = " << longueur << endl;

    char* p;
    prenom.getContenu(&p);
    cout << "Copie de prenom dans la chaine de caractere p, p = " << p << endl << endl;

    // Entr�es-sorties
    UneChaine ville;
    cin >> ville; // Entr�e : Lecture d'une chaine
    cout << "Vous avez entre comme ville : " << ville; // Sortie : affichage d'une chaine
    cout << endl << endl;

    // Op�rateurs
    chainevide = prenom; // Affectation
    cout << "On a affecte prenom a chainevide, chainevide = " << chainevide << endl;

    UneChaine prenom2("Hassan"),prenom3("Issam");
    cout << "\"Issam\" = \"Hassan\" ? : " << (prenom == prenom2) << endl; // Test d'op�rateur ==
    cout << "\"Issam\" = \"Issam\" ? : " << (prenom == prenom3) << endl;  // Test d'op�rateur !=

    return 0;
}
