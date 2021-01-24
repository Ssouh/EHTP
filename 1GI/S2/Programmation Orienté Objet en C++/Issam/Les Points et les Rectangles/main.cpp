#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include "Point.h"
#include "PointNomme.h"
#include "PointColore.h"
#include "Rectangle.h"
#include "RectangleColore.h"


using namespace std;

// Fonctions permettant de récupérer le choix d'utilisateur pendant la navigation
int PremiereChoix();
int QuelPoint();
int QuelRectangle();
int QuelAction();
void effacerEcran();

int main()
{
    // Déclaration des diffirents types de points

    Point ptsimple;
    PointNomme ptnomme;
    PointColore ptcolore;

    // Déclaration des diffirents types de rectangles
    RectangleColore rectcolore;
    Rectangle rectsimple;

    // Variables permettant d'effectuer le test
    int choix,temp;
    int x,y,x2,y2;
    char* nom = new char[50];
    int couleur;


while(1) // boucle principale de programme
{

    choix=PremiereChoix();
    effacerEcran();

    switch(choix)
    {
        case 1: // Creer un point
            choix=QuelPoint();
            effacerEcran();

            cout<<"\nEntrer les coordones du point (x,y)"<<endl;
            cout<<"x = "; cin >> x;
            cout<<"y = "; cin>> y;

            switch(choix)
            {
                case 1: // Creation d'un point simple
                    ptsimple = Point(x,y);
                    effacerEcran();
                    ptsimple.afficheToi();
                    break;

                case 2: // Creation d'un point nommé
                    cout <<"Entrer un nom pour votre point : ";
                    cin >> nom;
                    effacerEcran();
                    ptnomme = PointNomme(x,y,nom);
                    ptnomme.afficheToi();
                    break;

                case 3: // Creation d'un point nommé + coloré
                    cout <<"Entrer un nom pour votre point : ";
                    cin >> nom;
                    cout <<"Entrer une couleur pour votre point : ";
                    cin >> couleur;
                    effacerEcran();
                    ptcolore = PointColore(x,y,nom,couleur);
                    ptcolore.afficheToi();
                    break;

            }

            temp = choix;
            choix=QuelAction();
            switch(choix)
            {
                case 1: // Deplacer un point
                    cout << "Vers ou? donner dx et dy :" ;
                    cin >> x >> y;
                    if (temp==1) { ptsimple.deplacer(x,y); ptsimple.afficheToi();}
                    else if (temp==2) { ptnomme.deplacer(x,y); ptnomme.afficheToi();}
                    else { ptcolore.deplacer(x,y); ptcolore.afficheToi(); }
                    break;
                case 2: // Calculer norme de point
                    cout << "La norme est : ";
                    if (temp==1) { cout  << ptsimple.saNorme(); }
                    else if (temp==2) { cout  << ptnomme.saNorme();}
                    else { cout << ptcolore.saNorme(); }
                    break;

            }

            cout << "\n\nAppuyez sur une touche pour redemarrer" ;
            getch();
            effacerEcran();
            break;

        case 2:// Creer un rectangle simple
            choix=QuelRectangle();
            cout << "Entrez les cordonees de premier point (x puis y) :";
            cin >> x >>y;

            cout << "Entrez les cordonees de deuxieme point (x puis y) :";
            cin >> x2 >>y2;


            switch(choix)
            {
                case 1:
                    rectsimple = Rectangle(x,y,x2,y2);
                    rectsimple.afficheToi();
                    break;

                case 2:
                    cout << "Donner la couleur de rectangle : ";
                    cin >> couleur;
                    rectcolore = RectangleColore(x,y,x2,y2,couleur);
                    rectcolore.afficheToi();
                    break;
            }

            cout << "\n\nAppuyez sur une touche pour redemarrer" ;
            getch();
            effacerEcran();
            break;

        case 3: // Quitter
            return 0;



    }



}

    return 0;
}

int PremiereChoix()
{
    int choix;
    cout<<"Faites un choix :"<<endl;
    cout<<" 1- Creer un point"<<endl;
    cout<<" 2- Creer un rectangle"<<endl;
    cout<<" 3- Quitter"<<endl;
    cout<<"    Votre choix : ";
    cin>>choix;

    return choix;
}

int QuelPoint()
{
    int choix;
    cout<<" Quel type de point ?"<<endl;
    cout<<" 1- Creer un point simple"<<endl;
    cout<<" 2- Creer un point nomme"<<endl;
    cout<<" 3- Creer un point nomme et colore"<<endl;
    cout<<"    Votre choix : ";
    cin>>choix;

    return choix;

}

int QuelRectangle()
{
    int choix;
    cout<<" Quel type de rectangle ?"<<endl;
    cout<<" 1- Creer un rectangle simple"<<endl;
    cout<<" 2- Creer un rectangle colore"<<endl;
    cout<<"    Votre choix : ";
    cin>>choix;

    return choix;

}

int QuelAction(){

    int choix;
    cout<<"\n\nQuel operation souhaitez vous effectuer ?"<<endl;
    cout<<" 1- Deplacer le point"<<endl;
    cout<<" 2- Afficher sa norme"<<endl;
    cout<<"    Votre choix : ";
    cin>>choix;

    return choix;
}

void effacerEcran()
{
   system("cls");
}
