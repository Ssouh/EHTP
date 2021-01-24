#include <iostream>
#include "UnePiece.h"
#include "UnePieceSimple.h"
#include "UnePieceComposite.h"

using namespace std;

int main()
{

    UnePieceSimple la_s1("ecrou",20);
    UnePieceSimple la_s2=la_s1, la_s3=la_s1;
    UnePieceSimple la_s4("vis",15);
    UnePieceSimple la_s5=la_s4,la_s6=la_s4;
    UnePieceSimple la_s7("plaque",20);


    UnePieceSimple** liste;
    liste = new UnePieceSimple*[8];

    for (int i=0; i<8; i++)
        liste[i]=new UnePieceSimple();

    *liste[0]=la_s1;
    *liste[1]=la_s2;
    *liste[2]=la_s3;
    *liste[3]=la_s4;
    *liste[4]=la_s5;
    *liste[5]=la_s6;
    *liste[6]=la_s7;
    liste[7]=nullptr;

   /* while (*simplepiece!=nullptr)
    {
        poidsTotal+=(*simplepiece)->donnePoids();
        simplepiece++;
    }*/


    UnePieceComposite la_c1("Composer",liste);
    la_c1.affiche();

}
