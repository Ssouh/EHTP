#include <iostream>
#include <stdlib.h>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(int x1, int y1, int x2, int y2) : point1(x1,y1), point2(x2,y2){}

int Rectangle::SaLongueur()
{
    int dx = abs(point1.sonX()-point2.sonX());
    int dy = abs(point1.sonY()-point2.sonY());
    return dx>dy ? dx:dy;
}

int Rectangle::SaLargeur()
{
    int dx = abs(point1.sonX()-point2.sonX());
    int dy = abs(point1.sonY()-point2.sonY());
    return dx<dy ? dx:dy;
}

void Rectangle::afficheToi(){
    cout << "Ce rectangle est delimte par " ; point1.afficheToi();
    cout << " et "; point2.afficheToi();
}


Rectangle::~Rectangle()
{

}
