#include <iostream>
#include "UnePiece.h"
#include "une_piece.h"
#include "UnePieceSimple.h"
#include "UnePieceComposite.h"
#include "une_piece_composee.h"
using namespace std;
#define MAX_COMPOSANT 11

int main()
{

    UnePieceSimple la_s1("ecrou",20);
    UnePieceSimple la_s2=la_s1, la_s3=la_s1;
    UnePieceSimple la_s4("vis",15);
    UnePieceSimple la_s5=la_s4,la_s6=la_s4;
    UnePieceSimple la_s7("plaque",200);


    UnePieceSimple** PieceComposee;
    PieceComposee = new UnePieceSimple*[8];

    for (int i=0; i<8; i++)
        PieceComposee[i]=new UnePieceSimple();

    *PieceComposee[0]=la_s1;
    *PieceComposee[1]=la_s2;
    *PieceComposee[2]=la_s3;
    *PieceComposee[3]=la_s4;
    *PieceComposee[4]=la_s5;
    *PieceComposee[5]=la_s6;
    *PieceComposee[6]=la_s7;
    PieceComposee[7]=NULL;
    UnePieceComposite la_c1("PieceComposee",PieceComposee);
    la_c1.affiche();
    la_c1.donnePoids();


    une_piece** TMP
    une_piece* Exemple[8]={&la_s1,&la_s2,&la_s3,&la_s4,&la_s5,&la_s6,&la_s7,NULL} ;

    Exemple = new une_piece*[2];
    Exemple[0]= new une_piece_composee("plateau",Exemple);
    Exemple[1]=(une_piece_composee*)TMP;
    cout<<"\n\n";
    une_piece_composee P_C("piece_composee",Exemple);
    P_C.affiche(1);



}
