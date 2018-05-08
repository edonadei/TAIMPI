#include <iostream>
#include "automate.h"
#include "fichier.h"
#include "etat.h"
#include "transition.h"
#include <vector>

using namespace std;

int main()
{
    cout << "Test de fonctionnement des fonctions" << endl << endl;
    Etat Etat_1(1,true,false,false);
    Etat Etat_2(2,false,true,false);

    // On crée la liaison entre les deux états
    creer_liaison(Etat_1,Etat_2,"a");
    creer_liaison(Etat_1,Etat_2,"b");

    informations_etat(Etat_1);
    informations_etat(Etat_2);

    return 0;
}
