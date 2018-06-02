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
    Etat(std::string _chiffre="0", bool _entree=false, bool _sortie=false, bool _poubelle=false);
    ~Etat();

    // Attacher une transition à l'état
    void Attacher_Entree(Transition *Transition1);
    void Attacher_Sortie(Transition *Transition1);
    void PasAttacher(Transition *Transition1);
    // Getters
    std::string get_number();
    bool get_poubelle();
    bool get_entree();
    bool get_sortie();
    //Setters
    void set_chiffre(std::string);
    void set_poubelle(bool);
    void set_entree(bool);
    void set_sortie(bool);

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
    std::string chiffre;

};

#endif // ETAT_H_INCLUDED
