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

void creer_liaison (Etat &Etat_precedent, Etat &Etat_suivant, string lettre)
{
Transition Transition_entre_deux(lettre);
Etat_precedent.Attacher(Transition_entre_deux);
Etat_suivant.Attacher(Transition_entre_deux);
}

