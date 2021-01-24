#include <iostream>
#include "point.h"

using namespace std;
point::point()
{
    sonX=0;sonY=0;
}
point::point(int x,int y)
{
    sonX=x;sonY=y;
}
point::point(point &p)
{
    sonX=p.sonX;sonY=p.sonY;
}
int point::X_afficheToi()
{
    //cout << "Le coordonne X du point:"<<sonX;
    return sonX;
}
int point::Y_afficheToi()
{
    //cout << "Le coordonne Y du point:"<< sonY;
    return sonY;
}
