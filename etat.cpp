#include <iostream>
#include "etat.h"
#include "transition.h"
#include <vector>

using namespace std;

Etat::Etat(int _chiffre, bool _entree, bool _sortie, bool _poubelle)
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
    TrList.push_back(Transition1);
    Transition1->Attacher_Sortie_en_retour(this);
}

void Etat::Attacher_en_retour(Transition &Transition1)
{
        TrList.push_back(&Transition1);
}

// Getters

int Etat::get_number()
{
    return chiffre;
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
