#include <iostream>
#include <windows.h>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>

#include "Board.h"


using namespace std;


int main()
{
    Board B; // création de tableau de jeu

    int algoType;

    cout << "1. MinMax" << endl << "2. Alpha-Beta" << endl;
	cout << "Choisir l'algorithme a utiliser : " << endl;
    cin >> algoType;

    while(algoType!=1 && algoType!=2 )
    {
        cout << "Choix inavlide d'algorithme, veuillez choisir soit 1 ou 2." << endl;
        cin >> algoType;
    }

    B.play(algoType); //lancement de jeu
    return 0;
}
