#include <iostream>
#include "transition.h"
#include "etat.h"
#include <vector>

using namespace std;

Transition::Transition()
{

}

Transition::~Transition()
{

}

Transition::Attacher(Etat &Etat1)
    {
    EtList.push_back(&Etat1);
    Etat1.Attacher_en_retour(*this);
    }

Transition::Attacher_en_retour(Etat &Etat1)
    {
        EtList.push_back(&Etat1);
    }


