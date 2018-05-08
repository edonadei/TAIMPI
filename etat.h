#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED
#include <vector>
#include "transition.h"

class Etat
{
    // Utile de friend pour faire des liens entre les deux
friend class Transition;

public:
    // Constructeurs, Destructeurs
    Etat(int _chiffre=0, bool _entree=false, bool _sortie=false, bool _poubelle=false);
    ~Etat();

    // Attacher une transition à l'état
    void Attacher_Entree(Transition *Transition1);
    void Attacher_Sortie(Transition *Transition1);
    // Getters
    int get_number();
    bool know_if_trash();
    bool know_if_entrance();
    bool know_if_exit();

    std::vector<Transition*> TrList;

private:
    // Relation many to many
     void Attacher_en_retour(Transition &Transition1);

protected:
    bool poubelle;
    bool entree;
    bool sortie;
    int chiffre;

};

#endif // ETAT_H_INCLUDED
