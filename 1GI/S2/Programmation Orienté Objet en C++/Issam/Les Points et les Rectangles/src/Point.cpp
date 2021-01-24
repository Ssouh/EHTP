#include "Point.h"
#include <math.h>
#include <iostream>

using namespace std;

Point::Point(int a,int b){
    x=a;
    y=b;
}

void Point::deplacer(int dx,int dy){
    x+=dx;
    y+=dy;
}

int Point::saNorme(){
    return sqrt(x*x+y*y);
}

void Point::afficheToi(){
    cout << "Point : " << "(" << x <<","<< y << ")" ;
}

int Point::sonX() { return x;}
int Point::sonY() { return y;}

Point::~Point()
{

}
