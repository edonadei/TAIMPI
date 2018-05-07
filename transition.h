#ifndef TRANSITION_H_INCLUDED
#define TRANSITION_H_INCLUDED
#include <vector>

// Forward declaration
class Etat;

class Transition
{

// Utile de friend pour faire des liens entre les deux
friend class Etat;

public:
    Transition(std::string _lettre="UNDEF");
    ~Transition();

    // Attacher un état à la transition
    void Attacher(Etat &Etat1);

private:
    // Relation many to many
    void Attacher_en_retour(Etat &Etat1);

protected:
    std::string lettre;
    std::vector<Etat*> EtList;
};

#endif // TRANSITION_H_INCLUDED
