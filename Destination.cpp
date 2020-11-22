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

string Destination::getVilleDepart(){
    return villeDepart;
}

string Destination::getVilleArrivee(){
    return villeArrivee;
}

void Destination::saisirDestination(){
    cout << "Entrez la ville de depart :";
    cin >> villeDepart;
    cout << "Entrez la ville d'arrivée :";
    cin >> villeArrivee;
}

void Destination::afficher(){
    cout << "Depart : " << villeDepart;
    cout << "Arrivee : " << villeArrivee;
}
