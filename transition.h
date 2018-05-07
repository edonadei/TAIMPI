#ifndef TRANSITION_H_INCLUDED
#define TRANSITION_H_INCLUDED
#include <vector>
#include "etat.h"


using namespace std;

class Transition
{

// Utile de friend pour faire des liens entre les deux
friend class Etat;

public:
    Transition();
    ~Transition();

    // Attacher un état à la transition
    Attacher(Etat &Etat1);

private:
    // Relation many to many
    Attacher_en_retour(Etat &Etat1);

protected:
    string lettre;
    vector<Etat*> EtList;
};

#endif // TRANSITION_H_INCLUDED
