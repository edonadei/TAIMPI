#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

using namespace std;

class Etat
{
public:
    Etat();
    ~Etat();
private:
protected:
    bool poubelle;
    bool entree;
    bool sortie;
    Transition * Transitions;
};

#endif // ETAT_H_INCLUDED
