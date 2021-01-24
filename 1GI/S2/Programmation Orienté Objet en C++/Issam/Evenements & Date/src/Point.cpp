#include "Point.h"
#include <iostream>
#include <math.h>

using namespace std;

Point::Point(int a,int b)
{
    x=a,y=b;
}

void Point::inputPoint()
{
    cin >> x >> y ;
}

void Point::showPoint()
{
    cout << "(x,y) = " << "(" <<x <<"," << y <<")"<< endl;
}

bool Point::comparePoint(Point *p)
{
    cout << (p == this) ;
}

int Point::normePoint()
{
    return sqrt(x*x+y*y);
}

void Point::plusGrandPoint(Point *p)
{
    if (normePoint() > p->normePoint() )
       {cout << "Le plus grand est " ; showPoint();}
    else
       {cout << "Le plus grand est " ; p->showPoint();}
}
