#ifndef AUTOMATE_H_INCLUDED
#define AUTOMATE_H_INCLUDED
#include <iostream>
#include "automate.h"
#include "fichier.h"
#include "etat.h"
#include "transition.h"
#include <vector>

Etat creer_etat ();
void creer_liaison (Etat &Etat_entree, Etat &Etat_sortie, std::string lettre);
void informations_etat (Etat &Etat_a_verifier);

#endif // AUTOMATE_H_INCLUDED
