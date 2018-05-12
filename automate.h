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

//Création automate à partir d'un fichier
std::vector<std::string> str_to_array(const std::string str, char separator);
void split_str_to_array(std::vector< std::vector<std::string> > &tab_automate, const std::vector<std::string> ligne);
void transition_name(std::vector<std::string> &name, const std::vector<std::string> tab);
void init_etat(Etat &etat, const std::vector<std::string> tab_automate);
void link_transition_etat(int ligne, std::vector<Etat*> ListEtats, const std::vector<std::string> tab_automate, const std::vector<std::string> tab_transition_name);
void creat_etats(std::vector<Etat*> &ListEtats, const std::vector< std::vector<std::string> > tab_automate, const std::vector<std::string> tab_transition_name);
void init_automate(std::vector<Etat*> &ListEtats, std::vector<std::string> &tab_transition_name);

//Affichage
std::string afficher_type_etat(Etat etat);
void afficher_automate(std::vector<Etat*> ListEtats, std::vector<std::string>transitionName);

#endif // AUTOMATE_H_INCLUDED
