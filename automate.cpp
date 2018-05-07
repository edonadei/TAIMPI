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

void creer_liaison (Etat &Etat_a_lier, Etat &Etat_precedent, Etat &Etat_suivant)
{
Transition Transition_de_droite;
Transition Transition_de_gauche;
Etat_a_lier.Attacher(Transition_de_droite);
Etat_a_lier.Attacher(Transition_de_gauche);
}

