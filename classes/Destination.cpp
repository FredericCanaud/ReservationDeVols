//
// Created by Freddy on 21/11/2020.
//

#include "Destination.h"
#include <iostream>

Destination::Destination() {

}

Destination::Destination(string villeDepart, string villeArrivee) {
    this->villeDepart = villeDepart;
    this->villeArrivee = villeArrivee;
}

string Destination::toString() const {
    string result = "";
    result += this->getVilleDepart() + s + this->getVilleArrivee();

    return result;
}

string Destination::getVilleDepart() const {
    return villeDepart;
}

string Destination::getVilleArrivee() const {
    return villeArrivee;
}

Destination Destination::saisirDestination(){
    cout << "Entrez la ville de depart :";
    cin >> villeDepart;
    cout << "Entrez la ville d'arrivée :";
    cin >> villeArrivee;
    return Destination(villeDepart,villeArrivee);
}

void Destination::afficher(){
    cout << "Depart : " << villeDepart<<endl;
    cout << "Arrivee : " << villeArrivee;
}

string Destination::toSave() {
    return this->toString();
}

void Destination::save(list<Destination*> liste, string nomFichier){
    // manipulateur de fichier
    ManipulateurFichier manip(nomFichier);

    // liste des informations à sauvegarder
    list<string> toSave;

    // itérateur sur la liste
    list<Destination*>::iterator it;

    // pour chaque passager
    for (it = liste.begin() ; it != liste.end() ; it++){
        // ajouter à la liste les informations à sauvegarder
        toSave.push_front((*it)->toSave()) ;
    }

    // écrire dans le fichier
    manip.ecrire(toSave);
}

list<Destination*> Destination::load(string nomFichier){
    // liste des destinations
    list<Destination*> destinations;

    // manipulateur de fichier
    ManipulateurFichier manip(nomFichier);

    // liste des données sauvegardées
    list<string> infos = manip.lireLignes();

    // itérateur sur les informations
    list<string>::iterator it;

    // pour chaque lignes
    for (it = infos.begin() ; it != infos.end() ; it++) {
        // liste des champs de la ligne
        vector<string> ligne = Helper::split(*it, s);

        // itérateur sur les champs
        vector<string>::iterator itv = ligne.begin();

        string depart = *itv;
        string arrivee = *(itv+1);

        Destination* destination = new Destination(depart, arrivee);

        destinations.push_front(destination);

    }

    return destinations;
}