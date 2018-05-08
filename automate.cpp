#include <iostream>
#include "automate.h"
#include "etat.h"
#include "fichier.h"
#include "transition.h"

using namespace std;

Etat creer_etat ()
{
Etat Etat_a_retourner;
return Etat_a_retourner;
}

void creer_liaison (Etat &Etat_entree, Etat &Etat_sortie, string lettre)
{
Transition Transition_entre_deux(lettre);
Etat_entree.Attacher_Entree(Transition_entre_deux);
Etat_sortie.Attacher_Sortie(Transition_entre_deux);
}

void informations_etat (Etat &Etat_a_verifier)
{
    cout << "Verification de l'etat, chiffre: " << Etat_a_verifier.get_number() << " | Entree: " << Etat_a_verifier.know_if_entrance() << " | Sortie: "<< Etat_a_verifier.know_if_exit() << " | Poubelle: " << Etat_a_verifier.know_if_trash() << endl << endl;
    cout << "Nombre de liaisons de cet etat: " << Etat_a_verifier.TrList.size() << endl;

    // encore en debug
    for (unsigned int i = 0; i<Etat_a_verifier.TrList.size(); i++)
        {
            cout << "    - Transition numero " << i+1 << " | Lettre: "  /* << Etat_a_verifier.TrList[i]->lettre */ << endl;
        }

}


