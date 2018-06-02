#include <iostream>
#include "etat.h"
#include "transition.h"
#include <vector>

using namespace std;

Etat::Etat(string _chiffre, bool _entree, bool _sortie, bool _poubelle)
{
chiffre = _chiffre;
entree = _entree;
sortie = _sortie;
poubelle = _poubelle;
}

Etat::~Etat()
{

}

void Etat::Attacher_Entree(Transition *Transition1)
{
    TrList.push_back(Transition1);
    Transition1->Attacher_Entree_en_retour(this);
}

void Etat::Attacher_Sortie(Transition *Transition1)
{
    //TrList.push_back(Transition1);
    Transition1->Attacher_Sortie_en_retour(this);
}

void Etat::Attacher_en_retour(Transition &Transition1)
{
        TrList.push_back(&Transition1);
}

void Etat::PasAttacher(Transition *Transition1){
    Transition1->NoTransition(this);
    TrList.push_back(Transition1);

}

// Getters

string Etat::get_number()
{
    return chiffre;
}

bool Etat::get_poubelle(){
    return poubelle;
}

bool Etat::get_entree(){
    return entree;
}

bool Etat::get_sortie(){
    return sortie;
}
//Setters

void Etat::set_chiffre(string _chiffre){
    chiffre = _chiffre;
}

void Etat::set_poubelle(bool _poubelle){
    poubelle = _poubelle;
}

void Etat::set_entree(bool _entree){
    entree = _entree;
}

void Etat::set_sortie(bool _sortie){
    sortie = _sortie;
}

bool Etat::know_if_trash()
{
    return poubelle;
}

bool Etat::know_if_entrance()
{
    return entree;
}

bool Etat::know_if_exit()
{
    return sortie;
}
