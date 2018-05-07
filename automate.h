#ifndef AUTOMATE_H_INCLUDED
#define AUTOMATE_H_INCLUDED
#include <iostream>
#include "automate.h"
#include "fichier.h"
#include "etat.h"
#include "transition.h"
#include <vector>

Etat creer_etat ();
void creer_liaison (Etat &Etat_a_lier, Etat &Etat_precedent, Etat &Etat_suivant);

#endif // AUTOMATE_H_INCLUDED
