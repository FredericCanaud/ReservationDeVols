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
    string s = ";"; // séparateur
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
    cout << "Depart : " << villeDepart;
    cout << "Arrivee : " << villeArrivee;
}
