#include "Classy.h"
#include <iostream>
using namespace std;

Classy::Classy()
: var2(b)
{
    var1=a;
}

Classy::~Classy(){
    cout << "I'm dead now" << endl;
}

void Classy::getvars(){

cout << var1 << " " << var2 <<endl;
}


