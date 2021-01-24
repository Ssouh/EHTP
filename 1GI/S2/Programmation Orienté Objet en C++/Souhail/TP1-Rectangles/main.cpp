#include <iostream>
#include "point.h"
#include "Unrectangle.h"

using namespace std;

int main()
{
    Unrectangle LeR1(1,1,3,2),LeR2(-5,8,15,18),LeR3(-5,-8,4,5);
    cout << LeR1.estInclus(LeR2)<< endl;
    cout << LeR2.estInclus(LeR1)<< endl;
    cout <<LeR1.estInclus(LeR3);
}
