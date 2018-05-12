#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <utility>

#include "automate.h"
#include "etat.h"
#include "fichier.h"
#include "transition.h"

using namespace std;

Etat creer_etat ()
{
Etat Etat_a_retourner;
return Etat_a_retourner;
}

void creer_liaison (Etat &Etat_entree, Etat &Etat_sortie, string lettre)
{
Transition *Transition_entre_deux = new Transition(lettre);
Etat_entree.Attacher_Entree(Transition_entre_deux);
Etat_sortie.Attacher_Sortie(Transition_entre_deux);
}

void informations_etat (Etat &Etat_a_verifier)
{
    cout << "Verification de l'etat, chiffre: " << Etat_a_verifier.get_number() << " | Entree: " << Etat_a_verifier.get_entree() << " | Sortie: "<< Etat_a_verifier.get_sortie()<< " | Poubelle: " << Etat_a_verifier.get_poubelle() << endl << endl;
    cout << "Nombre de liaisons de cet etat: " << Etat_a_verifier.TrList.size() << endl;
    cout << "Liste de liaisons de cet etat: " << Etat_a_verifier.TrList.size() << endl;
    for (unsigned int i = 0; i<Etat_a_verifier.TrList.size(); i++)
        {
            cout << "    - Transition vers l'etat " << Etat_a_verifier.TrList[i]->get_EtSortie()->get_number() << " | Lettre: "   << Etat_a_verifier.TrList[i]->get_letter()  << endl << endl;
        }

}

vector<string> str_to_array(const string str, char separator) { //Sépare str pour transformer en tab à chaque separateur

    stringstream stream(str);
    string buff = "";
    vector<string> tab;
    while (getline(stream, buff, separator)) {
        tab.push_back(buff);
    }
    return tab;
}

void split_str_to_array(vector< vector<string> > &tab_automate, const vector<string> ligne){ //Sépare les différentes lignes du tableau

    for(unsigned i=0; i<ligne.size();i++){
        tab_automate.push_back(str_to_array(ligne[i],'\t'));
    }
}

void transition_name(vector<string> &name, const vector<string> tab){ //Tableau avec le nom des transitions

for(unsigned i=2; i<tab.size();i++){
    name.push_back(tab[i]);
}

}


void init_etat(Etat &etat, const vector<string> tab_automate){ //Définie le.s type.s de l'état
    etat.set_chiffre(tab_automate[1]);

    if(tab_automate[0] == "E"){
        etat.set_entree(true);
    }else if(tab_automate[0] == "S"){
        etat.set_sortie(true);
    }else if(tab_automate[0] == "ES"){
        etat.set_entree(true);
        etat.set_sortie(true);
    }
}

void link_transition_etat(int ligne, vector<Etat*> ListEtats, const vector<string> tab_automate, const vector<string> tab_transition_name){ //Création tab avec toutes les liaisons de l'état
    int nbr_sortie;
    for (unsigned i=2;i<tab_automate.size();i++){ //Parcour toute les transition de l'état
        for(unsigned j=0;j<ListEtats.size();j++){
            if(ListEtats[j]->get_number() == tab_automate[i]){//Si transition même -> ajouter à la liste
                nbr_sortie = j;
                j = ListEtats.size() + 1;
                creer_liaison(*ListEtats[ligne],*ListEtats[nbr_sortie],tab_transition_name[i-2]);
            }
            else if(j == ListEtats.size() - 1){
                creer_liaison(*ListEtats[ligne],*ListEtats[ligne],"-");
            }
        }
    }
}

void creat_etats(vector<Etat*> &ListEtats, const vector< vector<string> > tab_automate, const vector<string> tab_transition_name){
    //Création Etat
    for(unsigned i=1; i<tab_automate.size();i++){
        Etat *etat1 = new Etat;
        init_etat(*etat1,tab_automate[i]);
        ListEtats.push_back(etat1);
    }
    //Création liaison
    for(unsigned i=0;i<ListEtats.size();i++){
        link_transition_etat(i,ListEtats,tab_automate[i+1],tab_transition_name);
    }
}

void init_automate(vector<Etat*> &ListEtats, vector<string> &tab_transition_name)
{
    string name_folder = "automates/automate-1.txt";
    ifstream fichier(name_folder.c_str(), ios::in); //Ouverture du fichier en monde lecture

    if(fichier){
        //On lit le fichier
        string ligne;
        vector<string> ligne_buff;

        while(getline(fichier, ligne)) {
            ligne_buff.push_back(ligne); //On stock les lignes
        }
        fichier.close();
        // On ferme le fichier

        //Convertir les str en tableau
        vector< vector<string> > tab_automate;
        split_str_to_array(tab_automate,ligne_buff);

        //Nom des transitions
        transition_name(tab_transition_name, tab_automate[0]);

        //Création des Etats et transitions
        creat_etats(ListEtats,tab_automate,tab_transition_name);
    }
    else{
        cerr << "L'automate n'existe pas" << endl;
    }
}

string afficher_type_etat(Etat etat){ //Donne le type de l'etat en lettre
    if(etat.get_entree() == 1 && etat.get_sortie() == 1){
        return "ES";
    }else if(etat.get_entree() == 1){
        return "E";
    }else if(etat.get_sortie() == 1){
        return "S";
    }else{
        return "-";
    }
}
void afficher_automate(vector<Etat*> ListEtats, vector<string> transitionName){

    cout << "\t" << "Etat"; //Données du tableau
    for (unsigned i=0; i<transitionName.size(); i++){
        cout << "\t" << transitionName[i];
    }
    cout << endl;
    //Affichage de chaque états
    for (unsigned i=0; i<ListEtats.size();i++){
        cout << afficher_type_etat(*ListEtats[i]) << "\t" << ListEtats[i]->get_number(); //Affichage type,nom
        for(unsigned j=0; j<ListEtats[i]->TrList.size(); j++){//Affichage transition
            cout << "\t" << ListEtats[i]->TrList[j]->get_letter();
        }
        cout << endl;
    }
}
