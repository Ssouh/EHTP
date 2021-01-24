#include <iostream>
#include "Point.h"
#include "Date.h"
#include "unEvenement.h"

using namespace std;

int main()
{

    int j,m,a;
    char t[50];


    cout << "Entrer la date : le jour,le mois et l'annee de l'evenement" << endl;
    cin >> j >> m >> a ;
    Date eventDate(j,m,a);
    eventDate.verification();

    cout << "Entrer l'intitule de l'evenement " << endl;
    cin >> t;

    unEvenement event(eventDate, t);


    event.afficheToi();


    //eventDate.afficheToi();











   /* int x,y;
    cout << "Entrer x et y de premier point P : " << endl;
    cin >> x >> y ;
    Point p(x,y);

    cout << "Entrer x et y de premier point G : " << endl;
    cin >> x >> y ;
    Point g(x,y);

    p.showPoint();
    g.showPoint();

    p.plusGrandPoint(&g);
    p.comparePoint(&g);

    */


    return 0;
}
