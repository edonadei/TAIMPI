#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED
#include <vector>
#include "transition.h"

class Etat
{
// Utile de friend pour faire des liens entre les deux
friend class Transition;

public:
    Etat();
    ~Etat();

// Attacher une transition � l'�tat
    void Attacher(Transition &Transition1);

private:
// Relation many to many
     void Attacher_en_retour(Transition &Transition1);

protected:
    bool poubelle;
    bool entree;
    bool sortie;
    std::vector<Transition*> TrList;
};

#endif // ETAT_H_INCLUDED
