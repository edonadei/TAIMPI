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
    void AttacherEntree(Etat *Etat1);
    void AttacherSortie(Etat *Etat1);
    void NoTransition(Etat *Etat1);
    std::string get_letter();
    Etat* get_EtEntree();
    Etat* get_EtSortie();

    void set_lettre(std::string _lettre);


private:
    // Relation many to many
    void Attacher_Entree_en_retour(Etat *Etat1);
    void Attacher_Sortie_en_retour(Etat *Etat1);

protected:
    std::string lettre;
    Etat* EtEntree;
    Etat* EtSortie;
};

#endif // TRANSITION_H_INCLUDED
