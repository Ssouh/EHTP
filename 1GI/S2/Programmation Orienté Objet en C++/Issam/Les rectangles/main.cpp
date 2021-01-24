#include <iostream>
#include "UnPoint.h"
#include "UnRectangle.h"

using namespace std;

int main()
{
    UnPoint C1(4,4),C2(2,2),C3(3,3);
    UnRectangle R1(C1,2,2),R2(C2,7,7),R3(C3,1,1);

    cout << "R1 est inclus dans R2? : " << R1.estInclus(R2) << endl
         << "R1 est inclus dans R3? : " << R1.estInclus(R3) << endl;


    return 0;
}
