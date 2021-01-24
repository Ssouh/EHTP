#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include "Board.h"


using namespace std;


Board::Board():player1(1,"player 1"),player2(2,"player 2")
{
    turn=0;
    for (int i=0;i<6;i++)for(int j=0;j<7;j++) T[i][j]=0;
}

Board::Board(int Data[6][7])
{
    for (int i=0;i<6;i++)for(int j=0;j<7;j++) T[i][j]=Data[i][j];
}

Board::~Board()
{
    //dtor
}

Board::play(int algoType)
{
    bool continuer=true;
    while(continuer)
    {
        system("cls");
        print(); // affichage graphique
        makeMove(algoType);
        nextTurn();
        return play(algoType);// ?
    }
}

bool Board::makeMove(int algoType){  // deplacer vers la colomne
    int i,j;
    switch(turn%2+1) // = 1 if p1's turn, 2 if p2's turn
    {
    case 1:
        j=player1.getPos(); // get desired column to play from player
        i=emptyPlace(j); // retuns empty line in the chosen column
        if(i==-1) return makeMove(algoType);
        T[i][j]=1;
        break;

    case 2:
        int state[6][7];
        copyBoard(state);
        if (algoType==2) j=CPU.alpha_beta(state,0,true,0,0,-100000000000,+100000000000);
        else j=CPU.minimax(state,0,true,0,0);
        i=emptyPlace(j);
        T[i][j]=2;
    }

    if(isWin(i,j,turn%2+1)) return win();
}

Board::emptyPlace(int j)
{
    int i;
    if(T[0][j]!=0) return -1; // return -1 when the column is FULL
    for(i=0;i<5;i++)
        if(T[i+1][j]!=0) // this means when i+1 is FULL, we break and return i (i is above i+1)
            break;
    return i;
}

bool Board::isWin(int i, int j, int pt)
{
    return (T[i][j]==pt && (countHorizontal(i,j,pt)==4 || countVertical(i,j,pt)==4 || countDiagonal1(i,j,pt)==4 || countDiagonal2(i,j,pt)==4)) ? true:false;
}

int Board::countHorizontal(int i, int j, int pt)
{
    int u,v;
    int counter=0;
        u=i; v=j;
        while(u>=-1 && u<6 && v>-1 && v<7 && T[u][v++]==pt && counter<4)
            counter++;
        u=i; v=j-1;
        while(u>-1 && u<6 && v>-1 && v<7 && T[u][v--]==pt && counter<4)
            counter++;
    return counter;
}

int Board::countVertical(int i, int j, int pt)
{
    int u,v;
    int counter=0;

    u=i; v=j;
    while(u>-1 && u<6 && v>-1 && v<7 && T[u++][v]==pt && counter<4)
        counter++;
    u=i-1; v=j;
    while(u>-1 && u<6 && v>-1 && v<7 && T[u--][v]==pt && counter<4)
        counter++;
    return counter;
}

int Board::countDiagonal1(int i, int j, int pt)
{
    int u,v;
    int counter=0;

    u=i; v=j;
    while(u>-1 && u<6 && v>-1 && v<7 && T[u++][v++]==pt && counter<4)
        counter++;
    u=i-1; v=j-1;
    while(u>-1 && u<6 && v>-1 && v<7 && T[u--][v--]==pt && counter<4)
        counter++;

    return counter;
}

int Board::countDiagonal2(int i, int j, int pt)
{
    int u,v;
    int counter=0; // on suppose que T[i][j]==pt

    u=i; v=j;
    while(u>-1 && u<6 && v>-1 && v<7 && T[u++][v--]==pt && counter<4)
        counter++;
    u=i-1; v=j+1;

    while(u>-1 && u<6 && v>-1 && v<7 && T[u--][v++]==pt && counter<4)
        counter++;

    return counter;
}

Board::win()
{
    print();
    switch(turn%2+1)
    {

    case 1:
        cout<<player1.name<<"win";
        break;
    case 2:
        cout<<player2.name<<"win";
    }
    exit(0);
}

Board::print()
{
    cout<<endl<<endl;
    cout<<"\311"<<string(3, '\315')<<"1"<<string(3, '\315'); for(int j=2;j<8;j++) cout<<"\313"<<string(3, '\315')<<j<<string(3, '\315'); cout<<"\273"<<endl;
    for (int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++) cout<<"\272"<<string(7, ' '); cout<<"\272\n\272";
        for(int j=0;j<7;j++)
            cout<<"   "<<(char) (T[i][j]==0 ? ' ' : (T[i][j]==1?'X':'O'))<<"   \272";    cout<<endl;

        for(int j=0;j<7;j++) cout<<"\272"<<string(7, ' '); cout<<"\272\n";
        if(i!=5){cout<<"\314"<<string(7, '\315'); for(int j=0;j<6;j++) cout<<"\316"<<string(7, '\315'); cout<<"\271"<<endl;}
    }
        cout<<"\310"<<string(7, '\315'); for(int j=0;j<6;j++) cout<<"\312"<<string(7, '\315'); cout<<"\274"<<endl;

    cout << "Nombre de Noeuds = " << CPU.nbreNoeuds << endl;
    CPU.nbreNoeuds=0;
}

Board::copyBoard(int tab[6][7]){

    for (int i=0;i<6;i++)for(int j=0;j<7;j++) tab[i][j] = T[i][j];

}

int Board::evalH(int i, int j, int &score, int pt)
{
    int p1t=pt%2+1, p2t=p1t%2+1;
    int cp1=0,cp2=0;
    for(int k=0;k<4;k++)
    {
        if(T[i][j+k]==p2t) cp2++;
        if(T[i][j+k]==p1t) cp1++;
    }
    editScore(score,cp1,cp2);
}

int Board::evalV(int i, int j, int &score, int pt)
{
    int p1t=pt%2+1, p2t=p1t%2+1;
    int cp1=0,cp2=0;
    for(int k=0;k<4;k++)
    {
        if(T[i+k][j]==p2t) cp2++;
        if(T[i+k][j]==p1t) cp1++;
    }
    editScore(score,cp1,cp2);
}

int Board::evalD1(int i, int j, int &score, int pt)
{
    int p1t=pt%2+1, p2t=p1t%2+1;
    int cp1=0,cp2=0;
    for(int k=0;k<4;k++)
    {
        if(T[i+k][j+k]==p2t) cp2++;
        if(T[i+k][j+k]==p1t) cp1++;
    }
    editScore(score,cp1,cp2);
}

int Board::evalD2(int i, int j, int &score, int pt)
{
    int p1t=pt%2+1, p2t=p1t%2+1;
    int cp1=0,cp2=0;
    for(int k=0;k<4;k++)
    {
        if(T[i-k][j+k]==p2t) cp2++;
        if(T[i-k][j+k]==p1t) cp1++;
    }
    editScore(score,cp1,cp2);
}


void Board::editScore(int&score, int cp1, int cp2)
{
    if(cp2==0)
    {
        switch(cp1)
        {
        case 1:
            score+=1;
            break;
        case 2:
            score+=10;
            break;
        case 3:
            score+=50;
        }
    }
    if(cp1==0)
    {
        switch(cp2)
        {
        case 1:
            score-=1;
            break;
        case 2:
            score-=10;
            break;
        case 3:
            score-=50;
        }
    }
}


int Board::heuristic(int pt)
{
    int score=0;
    for(int i=0; i<6;i++)
        for(int j=0; j<4;j++)
        {
            evalH(i,j, score, pt);
        }
    for(int i=0; i<3;i++)
        for(int j=0; j<7;j++)
        {
            evalV(i,j, score, pt);
        }
    for(int i=0; i<3;i++)
        for(int j=0; j<4;j++)
        {
            evalD1(i,j, score, pt);
        }
    for(int i=3; i<6;i++)
        for(int j=0; j<4;j++)
        {
            evalD2(i,j, score, pt);
        }
    //cout<<score<<endl;

    return score;
}
