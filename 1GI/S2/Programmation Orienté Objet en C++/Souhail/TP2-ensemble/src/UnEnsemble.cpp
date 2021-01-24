#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "UnEnsemble.h"

UnEnsemble::UnEnsemble(int t)
{
    taille=t;sonCardinal=t;
    sesElements=NULL;
}
UnEnsemble::UnEnsemble(int* tab,int card,int t)
{
    taille=t;sonCardinal=card;
    int len;
    if (card<=taille)
        {sesElements=new int [card]; len=card;}
        else {sesElements=new int [taille]; len=taille;}
    for (int i=0;i<len;i++)
        sesElements[i]=tab[i];
}

UnEnsemble::~UnEnsemble()
{
    delete [] sesElements;
}
void UnEnsemble::ajoute(int elm)
{
    if (sesElements!=NULL){
    if (sonCardinal<=taille)
        {
            sesElements=(int*)realloc(sesElements,sonCardinal+1);
            sesElements[sonCardinal]=elm;
        }}
    else {sesElements=new int [1];sesElements[0]=elm;}
}
void UnEnsemble::afficheToi()
{
    if (sesElements!=NULL){
    cout<<endl<<"L'ensemble est : {";
    for (int i=0;i<sonCardinal;i++)
        {
            cout<<sesElements[i] <<";";
        }
    cout<<"}";}
    else cout<<"L'ensemble est : {;}";
}
bool UnEnsemble::contient(int elm)
{
    for (int i=0;i<sonCardinal;i++)
        if (sesElements[i]==elm) return true;
    return false;
}
bool UnEnsemble::estInclus(UnEnsemble esm)
{
    int tmp=0;
    for (int j=0;j<esm.sonCardinal;j++)
        for (int i=0;i<sonCardinal;i++)
            if (sesElements[i]==esm.sesElements[j]) tmp++;
    if (tmp==esm.sonCardinal) return true;
    return false;
}

void UnEnsemble::supprime(int elm)/// l'ensemble doit etre non vide
{
    int* tmp;static int r;
    for (int i=0;i<sonCardinal;i++)
        if (sesElements[i]!=elm)
            {
                tmp=(int*)realloc(tmp,r+1);
                tmp[r]=sesElements[i];r++;
            }
    delete [] sesElements;
    sesElements=tmp;
}
