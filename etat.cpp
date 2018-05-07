#include <iostream>


using namespace std;

Etat::Attacher(Transition &Transition1)
    {
    TrList.push_back(&Etat1);
    Transition1.Attacher_en_retour(*this);
    }

Etat::Attacher_en_retour(Transition &Transition1)
    {
        TrList.push_back(&Transition1);
    }
