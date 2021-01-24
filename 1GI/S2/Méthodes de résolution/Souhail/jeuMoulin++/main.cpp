#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include "Fonction.h"

extern noeud Etat_initial;
int path;
int main()
{
    if (path==0) fullscreen();
    path=1;
    int i,j;
    color(3,15);
    printf("\n"
           "\n"
           "\n"
            "\t\t\t\t\t\t###############################################\n"
            "\t\t\t\t\t\t################# JEU MOULIN ##################\n"
            "\t\t\t\t\t\t###                                         ###\n"
            "\t\t\t\t\t\t###                                         ###\n"
            "\t\t\t\t\t\t###         OOOOOOOOO       OOOOOOOOO       ###\n"
            "\t\t\t\t\t\t###         O       O       O       O       ###\n"
            "\t\t\t\t\t\t###         O       O       O       O       ###\n"
            "\t\t\t\t\t\t###         O               O       O       ###\n"
            "\t\t\t\t\t\t###         O   OOOOO       O       O       ###\n"
            "\t\t\t\t\t\t###         O       O       O       O       ###\n"
            "\t\t\t\t\t\t###         OOOOOOOOO       OOOOOOOOO       ###\n"
            "\t\t\t\t\t\t###                                         ###\n"
            "\t\t\t\t\t\t###                                         ###\n"
            "\t\t\t\t\t\t###############################################\n"
            "\t\t\t\t\t\t###############################################\n");

            color(3,15);
            color(12,15);cout<<"\n\n\t\t\t\t\t\t                ||||| Souhail |||||";color(3,15);cout<<"\n";
            cout<<"\n\n\n\t\t\t\t\t\t\t   ";system("pause");system("cls");
            printf("\n\n");
H:
     printf("\n"
            "\n"
            "\t\t\t\t\t ---------------------- MENU ----------------------\n"
            "\t\t\t\t\t|                                                  |\n"
            "\t\t\t\t\t|                1_ JOUER UNE PARTIE               |\n"
            "\t\t\t\t\t|                                                  |\n"
            "\t\t\t\t\t|                  2_ REGLES DU JEU                |\n"
            "\t\t\t\t\t|                                                  |\n"
            "\t\t\t\t\t|                    3_ QUITTER                    |\n"
            "\t\t\t\t\t|                                                  |\n"
            "\t\t\t\t\t|                                                  |\n"
            "\t\t\t\t\t --------------------------------------------------\n"
            "\n"
            "\t\t\t\t\t                   Votre reponse : ");
            scanf("\n%d",&i);
            system("cls");

switch (i)
{
    case 1:
     printf("\n\n\n\n"
            "\t\t\t\t\t -------------------- MODES DU JEU --------------------\n"
            "\t\t\t\t\t|                                                      |\n"
            "\t\t\t\t\t|                   1_ JOUEUR VS MIN&MAX               |\n"
            "\t\t\t\t\t|                                                      |\n"
            "\t\t\t\t\t|                     2_ JOUEUR VS ALPHA&BETA          |\n"
            "\t\t\t\t\t|                                                      |\n"
            "\t\t\t\t\t|                       3_    RETOUR                   |\n"
            "\t\t\t\t\t|                                                      |\n"
            "\t\t\t\t\t ------------------------------------------------------\n"
            "\n"
            "\n"
            "\t\t\t\t\t                       Votre reponse :  ");
            scanf("\n%d",&j);
            system("cls");
            switch (j)
            {
            case 1:
                printf("\n"
                       "\n"
                       "\t\t\t\t\t             @@@@@@@@@@@     @@@@@@@@@    @@@@@@@@@@@\n"
                       "\t\t\t\t\t             @               @                 @\n"
                       "\t\t\t\t\t             @               @                 @\n"
                       "\t\t\t\t\t             @               @@@@@@@@@         @\n"
                       "\t\t\t\t\t             @     @@@@@     @                 @\n"
                       "\t\t\t\t\t             @         @     @                 @\n"
                       "\t\t\t\t\t             @@@@@@@@@@@     @@@@@@@@@         @\n"
                       "\n"
                       "\n");

                printf("\n"
                       "\n"
                       "\t\t\t\t\t        @@@@@@@     @@@@@@@   @@@@@@@   @@@@@      @     @ \n"
                       "\t\t\t\t\t        @     @     @         @     @   @     @     @   @\n"
                       "\t\t\t\t\t        @  @@@@     @         @     @   @     @      @ @\n"
                       "\t\t\t\t\t        @  @        @@@@@@@   @@@@@@@   @     @       @\n"
                       "\t\t\t\t\t        @   @       @         @     @   @     @       @ \n"
                       "\t\t\t\t\t        @    @      @         @     @   @     @       @\n"
                       "\t\t\t\t\t        @     @     @@@@@@@   @     @   @@@@@         @ \n");

                getch();
                system("cls");
                table(Etat_initial);
                getch();
                break;

            case 2:
                printf("\n"
                       "\n"
                       "\t\t\t\t\t             @@@@@@@@@@@     @@@@@@@@@    @@@@@@@@@@@\n"
                       "\t\t\t\t\t             @               @                 @\n"
                       "\t\t\t\t\t             @               @                 @\n"
                       "\t\t\t\t\t             @               @@@@@@@@@         @\n"
                       "\t\t\t\t\t             @     @@@@@     @                 @\n"
                       "\t\t\t\t\t             @         @     @                 @\n"
                       "\t\t\t\t\t             @@@@@@@@@@@     @@@@@@@@@         @\n"
                       "\n"
                       "\n");

                printf("\n"
                       "\n"
                       "\t\t\t\t\t        @@@@@@@     @@@@@@@   @@@@@@@   @@@@@      @     @ \n"
                       "\t\t\t\t\t        @     @     @         @     @   @     @     @   @\n"
                       "\t\t\t\t\t        @  @@@@     @         @     @   @     @      @ @\n"
                       "\t\t\t\t\t        @  @        @@@@@@@   @@@@@@@   @     @       @\n"
                       "\t\t\t\t\t        @   @       @         @     @   @     @       @ \n"
                       "\t\t\t\t\t        @    @      @         @     @   @     @       @\n"
                       "\t\t\t\t\t        @     @     @@@@@@@   @     @   @@@@@         @ \n");


                getch();system("cls");
                table(Etat_initial);
                getch();
                break;
            case 3:
                goto H;
                break;
            }
        break;
    case 2:
        printf("\n\n\n\n"
               "\t\t\t\t\t--------------------- REGLES DU JEU ------------------------\n\n\n");
        printf("\t\t\t LE JEU CONSISTE A CONTROLER DES MURS, ENSUITE LES SECURISER CONTRE LES ATTAQUES ENNEMIS \n"
               "\t\t\t UN MUR EST UN ENSEMBLE DE TROIS PIERRES VOISINS DE MEME COULEUR. \n"
               "\t\t\t  LE JOUEUR AVEC PLUS DE MURS A GRANDE CHANCE DE GAGNER.  \n\n\t\t\t\t\t\t\t\t\t press to return");
        getch();system("cls");goto H;
        break;
    case 3:
        exit(EXIT_SUCCESS);
        break;}



}



