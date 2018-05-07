#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED
#include <vector>
#include "transition.h"

using namespace std;

class Etat
{
// Utile de friend pour faire des liens entre les deux
friend class Transition;

public:
    Etat();
    ~Etat();

// Attacher une transition à l'état
    Attacher(Transition &Transition1);

private:
// Relation many to many
     Attacher_en_retour(Transition &Transition1);

protected:
    bool poubelle;
    bool entree;
    bool sortie;
    vector<Transition*> TrList;
};

#endif // ETAT_H_INCLUDED
