#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include "Point.h"
#include "PointNomme.h"
#include "PointColore.h"
#include "Rectangle.h"
#include "RectangleColore.h"


using namespace std;



int main()
{


    Point ptsimple(2,4);
    PointNomme ptnomme(1,1,"ptnomme");
    PointColore ptcolore(5,4,"ptcolore",0);


    RectangleColore rectcolore(1,3,2,9);
    Rectangle rectsimple(1,2,3,4);

    ptsimple.afficheToi();cout << endl;
    ptnomme.afficheToi();cout << endl;
    ptcolore.afficheToi();cout << endl;
    rectcolore.afficheToi();cout << endl;
    rectsimple.afficheToi();cout << endl;



    return 0;
}

