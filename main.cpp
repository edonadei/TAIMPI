#include <iostream>
#include "automate.h"
#include "fichier.h"
#include "etat.h"
#include "transition.h"
#include <vector>

using namespace std;

int main()
{
    cout << "Test de fonctionnement des fonctions" << endl;
    Etat Etat_1(1,true,false,false);
    Etat Etat_2(2,false,true,false);

    // On crée la liaison entre les deux états
    creer_liaison(Etat_1,Etat_2,"a");

    cout << "Premier etat, chiffre: " << Etat_1.get_number() << " | Entree: " << Etat_1.know_if_entrance() << " | Sortie: "<< Etat_1.know_if_exit() << " | Poubelle: " << Etat_1.know_if_trash() << endl;
    cout << "Liste de liaison de cet etat:  " << endl;
    cout << "Premier etat, chiffre: " << Etat_2.get_number() << " | Entree: " << Etat_2.know_if_entrance() << " | Sortie: "<< Etat_2.know_if_exit() << " | Poubelle: " << Etat_2.know_if_trash() << endl;
    cout << "Liste de liaison de cet etat:  " << endl;

    return 0;
}
