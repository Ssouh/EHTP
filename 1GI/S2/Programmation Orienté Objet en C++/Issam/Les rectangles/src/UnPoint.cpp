#include <iostream>
#include "UnPoint.h"

using namespace std;

UnPoint::UnPoint(int a,int b)
{
    sonX=a;
    sonY=b;
}

int UnPoint::recupererX()
{
    return sonX;
}

int UnPoint::recupererY()
{
    return sonY;
}
