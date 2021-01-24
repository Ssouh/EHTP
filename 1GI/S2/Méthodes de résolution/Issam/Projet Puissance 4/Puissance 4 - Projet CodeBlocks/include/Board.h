#ifndef BOARD_H
#define BOARD_H

#include "Board.h"
#include "Player.h"


class Board
{
    public:
        Board();
        Board(int Data[6][7]);
        virtual ~Board();
        //static SDL_surface IMG;
        play(int algoType);
        bool makeMove(int algoType);// deplacer vers la colomne
        emptyPlace(int);
        bool isWin(int, int, int);
        int countHorizontal(int i, int j, int pt);
        int countVertical(int i, int j, int pt);
        int countDiagonal1(int i, int j, int pt);
        int countDiagonal2(int i, int j, int pt);


        int getElement(int i, int j){return T[i][j];}

        void editScore(int&score, int cp1, int cp2);
        int evalH (int i, int j, int &score, int pt);
        int evalV (int i, int j, int &score, int pt);
        int evalD1(int i, int j, int &score, int pt);
        int evalD2(int i, int j, int &score, int pt);
        int heuristic(int pt);

        win();
        replay();
        print();
        copyBoard(int tab[6][7]);

        nextTurn(){
        turn++;
        }

    private:
        int T[6][7]; //Pion
        Player player1,player2;
        PlayerAI CPU;
        int turn; // count the number of tours played.

    friend class playerAI;

};

#endif // BOARD_H
