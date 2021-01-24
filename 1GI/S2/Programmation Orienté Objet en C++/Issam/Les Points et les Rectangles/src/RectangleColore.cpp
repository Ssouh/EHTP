#include "RectangleColore.h"
#include <iostream>


using namespace std;

RectangleColore::RectangleColore(int x1, int y1, int x2, int y2, int clr) : Rectangle(x1,y1,x2,y2)
{
    couleur = clr;
}


void RectangleColore::afficheToi(){
    Rectangle::afficheToi();
    cout << ", il est de couleur : " << couleur;

}


RectangleColore::~RectangleColore()
{

}


