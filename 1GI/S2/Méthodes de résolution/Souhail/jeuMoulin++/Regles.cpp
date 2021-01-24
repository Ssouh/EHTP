//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//#include <string.h>
//#include <vector>
//using namespace std;
//#include "Fonction.h"
//
//extern int compteur;
//extern int JCaisse;
//extern int MCaisse;
//
//
//                       {{ -1, 10, 10, -1, 10, 10, -1},
//                        { 10, -1, 10, -1, 10, -1, 10},
//                        { 10, 10, -1, -1, -1, 10, 10},
//                        { -1, -1, -1, 10, -1, -1, -1},
//                        { 10, 10, -1, -1, -1, 10, 10},
//                        { 10, -1, 10, -1, 10, -1, 10},
//                        { -1, 10, 10, -1, 10, 10, -1}};
//
//
//void existe(int i,int j,int Tmp[9][9])///tester si un mur existe et return sa position
//{
//    int ite=0; static vector<int> Mur;
//    if (Tmp[i-1][j-1]==Tmp[i-1][j] && Tmp[i-1][j]==Tmp[i-1][j+1] && Tmp[i-1][j]!=10) {ite++;Mur.push_back(i-1);Mur.push_back(j-1);Mur.push_back(i-1);Mur.push_back(j);Mur.push_back(i-1);Mur.push_back(j+1);}
//    if (Tmp[i][j-1]==Tmp[i][j] && Tmp[i][j]==Tmp[i][j+1]) {ite++;Mur.push_back(i);Mur.push_back(j-1);Mur.push_back(i);Mur.push_back(j);Mur.push_back(i);Mur.push_back(j+1);}
//    if (Tmp[i+1][j-1]==Tmp[i+1][j] && Tmp[i+1][j]==Tmp[i+1][j+1] && Tmp[i+1][j]!=10) {ite++;Mur.push_back(i+1);Mur.push_back(j-1);Mur.push_back(i+1);Mur.push_back(j);Mur.push_back(i+1);Mur.push_back(j+1);}
//
//    if (Tmp[i-1][j-1]==Tmp[i][j-1] && Tmp[i][j-1]==Tmp[i+1][j-1] && Tmp[i][j-1]!=10) {ite++;Mur.push_back(i-1);Mur.push_back(j-1);Mur.push_back(i);Mur.push_back(j-1);Mur.push_back(i+1);Mur.push_back(j-1);}
//    if (Tmp[i-1][j]==Tmp[i][j] && Tmp[i][j]==Tmp[i+1][j]) {ite++;Mur.push_back(i-1);Mur.push_back(j);Mur.push_back(i);Mur.push_back(j);Mur.push_back(i+1);Mur.push_back(j);}
//    if (Tmp[i-1][j+1]==Tmp[i][j+1] && Tmp[i][j+1]==Tmp[i+1][j+1] && Tmp[i][j+1]!=10) {ite++;Mur.push_back(i-1);Mur.push_back(j+1);Mur.push_back(i);Mur.push_back(j+1);Mur.push_back(i+1);Mur.push_back(j+1);}
//
//    if (Tmp[i-1][j-1]==Tmp[i][j] && Tmp[i][j]==Tmp[i+1][j+1] && Tmp[i][j]!=10) {ite++;Mur.push_back(i-1);Mur.push_back(j-1);Mur.push_back(i);Mur.push_back(j);Mur.push_back(i+1);Mur.push_back(j+1);}
//    if (Tmp[i-1][j+1]==Tmp[i][j] && Tmp[i][j]==Tmp[i+1][j-1] && Tmp[i][j]!=10) {ite++;Mur.push_back(i-1);Mur.push_back(j+1);Mur.push_back(i);Mur.push_back(j);Mur.push_back(i+1);Mur.push_back(j-1);}
//
//    if (ite=!0) return Mur;
//    return false;
//}
//
//void Retirer(int& A[7][7])
//{
//    if (((compteur+1)/2. - (compteur+1)/2)==0)
//    {
//        printf("\n\t\t\t\t\t\t\t CHOISIR LA LIGNE PUIS COLONNE A RETIRER ^_^ : ");
//        cin>> i,j;
//        A[i][j]=-1;
//        JCaise++;
//    }
//    else
//    {
//        ///Noeud Remove
//        MCaise++;
//    }
//    table(A[7][7]);
//}
///*
//void R1(int A[7][7],int x,int y)///Mur + retirer
//{
//    /// astuce:9x9
//    int Tmp[9][9];
//    for (int i=0;i<9;i++)
//        for (int j=0;j<9;j++)
//            Tmp[i][j]=10;
//    for (int i=1;i<8;i++)
//        for (int j=1;j<8;j++)
//            Tmp[i][j]=A[i-1][j-1];
//
//    ///
//    if(existe(x+1,y+1,Tmp[9][9])!=false)
//            Retirer(Tmp[7][7]);
//
//}
//
//void R2(int A[7][7])
//{
//
//}
//*/
