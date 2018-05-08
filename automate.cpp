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

