#include "Unensemble.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include <windows.h>
#include <conio.h>

//  J'ai rencontre un probleme etrange dans la compilation


int main()
{
    unensemble Ens;
    H:
    cout<< "\n\n\n\t\t\t LES ENSEMBLES:"
            "\n\t 1- Determiner votre ensemble"
            "\n\t 2- Afficher votre ensemble"
            "\n\t 3- Ajouter element a votre ensemble"
            "\n\t 4- Supprimer element de votre ensemble"
            "\n\t 5- Tester si votre ensemble est inclus dans un autre"
            "\n\t 6- L'intersection des deux ensembles"
            "\n\t 7- L'union des deux ensembles"
            "\n\t 8- Les nombres premiers de l'ensemble"
            "\n\n\t\tVotre reponse :";
    int i;
    cin>>i;
    system("cls");

switch (i)
{
    case 1:

        cout<<"\n\n\n\t\t Donner un element initial: ";
        int elm;cin>>elm;
        Ens.ajoute(elm);
        system("cls");
        goto H;
        break;
    case 2:
        Ens.afficheToi();
        getch();
        system("cls");
        goto H;
        break;
    case 3:
        L:
        cout<<"\n\n\n\t\t Inserer un element a votre ensemble: ";
        cin>>elm;
        Ens.ajoute(elm);
        cout<<"\n\n\n\t\t Voulez-vous ajouter autre ? (o/n) ";
        char r;cin>>r;
        if (r=='o') goto L;
        system("cls");
        goto H;
        break;
    case 4:
        cout<<"\n\n\n\t\t Inserer un element a supprimer de votre ensemble: ";
        cin>>elm;
        Ens.supprime(elm);
        system("cls");
        goto H;
        break;
    case 5:
        {
        cout<<"\n";
        unensemble Tel_ens;
        Ls:
        cout<<"\n\n\t\t Donner un element du nouveau ensemble: ";
        cin>>elm;
        Tel_ens.ajoute(elm);
        cout<<"\n\n\n\t\t Voulez-vous ajouter autre ? (o/n) ";
        cin>>r;
        if (r=='o') goto Ls;
        Tel_ens.afficheToi();
        cout << "  Est-il inclus :"<< Ens.estInclus(Tel_ens);
        getch();
        system("cls");
        }
        goto H;
        break;
    case 6:
        {
        cout<<"\n";
        unensemble Tel_Eens;
        Les:
        cout<<"\n\n\t\t Donner un element du nouveau ensemble: ";
        cin>>elm;
        Tel_Eens.ajoute(elm);
        cout<<"\n\n\n\t\t Voulez-vous ajouter autre ? (o/n) ";
        cin>>r;
        if (r=='o') goto Les;
        Tel_Eens.afficheToi();
        cout << "  L'interserction est ";
        Ens.Intersection(Tel_Eens).afficheToi();
        getch();
        system("cls");
        }
        goto H;
        break;
    case 7:
        {
        cout<<"\n";
        unensemble Tel_Eeens;
        Lts:
        cout<<"\n\n\t\t Donner un element du nouveau ensemble: ";
        cin>>elm;
        Tel_Eeens.ajoute(elm);
        cout<<"\n\n\n\t\t Voulez-vous ajouter autre ? (o/n) ";
        cin>>r;
        if (r=='o') goto Lts;
        Tel_Eeens.afficheToi();
        cout << "  L'Union est ";
        Ens.Union(Tel_Eeens).afficheToi();
        getch();
        system("cls");
        }
        goto H;
        break;
    case 8:
        cout<<"\n\n\n\t\t L'ensemble des nombres Premiers de votre ensemble: ";
        Ens.Ensemble_Premier();
        Ens.afficheToi();
        getch();
        system("cls");
        goto H;
        break;

}}
///*/
/**

int main()
{
    unensemble Ens;
    int tab[3]={1,4,3};
    unensemble Ensemble(tab,3);
    Ens.afficheToi();
    Ensemble.afficheToi();
    cout <<endl<<"\"0\" est-il dans l'ensemble:"<< Ensemble.contient(0)<<endl;
    cout <<"\"4\" est-il dans l'ensemble:"<< Ensemble.contient(4)<<endl;
    unensemble test(tab,2);
    test.afficheToi();
    cout << "  Est-il inclus :"<< Ensemble.estInclus(test);
    Ens.ajoute(7);
    Ens.ajoute(8);
    Ens.ajoute(9);
    Ens.ajoute(15);
    Ens.afficheToi();
    Ens.supprime(8);
    Ens.afficheToi();
    Ens.supprime(15);
    Ens.afficheToi();
    int t[12]={10,4,3,2,4,5,8,9,7,8,15,13};
    unensemble T(t,12);
    T.afficheToi();
    //unensemble Res;
    T.Ensemble_Premier();
    T.afficheToi();
}
///*/
