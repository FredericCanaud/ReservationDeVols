//
// Created by Freddy on 21/11/2020.
//

#include "Vol.h"
#include <iostream>
#include <iomanip>
using namespace std;

Vol::Vol() {

}

Vol::Vol(int numero, int nombrePlacesMaximal, float prix) {
    this->numero = numero;
    this->nombrePlacesMaximal = nombrePlacesMaximal;
    this->prix = prix;
}

Vol Vol::ajouterVol(int numero, int nombrePlacesMaximal, float prix) {
    Vol vol = Vol(numero, nombrePlacesMaximal, prix);
    vol.destination = destination.saisirDestination();
    vol.date = date.saisirDate();
    return vol;
}

bool Vol::recherche(const vector<Vol> &vols) const {
    bool trouve;
    for(const Vol& vol : vols)
    {
        int i = 0;
        if(vol.numero == numero)
        {
            trouve=true;
        }
        else
            i++;
    }
    return trouve;
}

void Vol::afficherVols(const vector<Vol> &vols){
    cout << " Liste des vols disponibles :" << endl << endl;
    for(const Vol& vol : vols)
    {
        vol.afficher();
    }
}

void Vol::afficher() const {
    cout << " Vol numero " << numero << " :" << endl;
    cout << " De " << destination.getVilleDepart() << " en destination de " << destination.getVilleArrivee() << endl;
    cout << setw(2) << setfill('0') << " Heure de départ : " << date.getHeure() << ":" << date.getMinute() << endl;
    cout << setw(2) << setfill('0') << " Jour de départ : " << date.getJour() << "/" << date.getMois() << "/" << date.getAnnee() << endl;
    cout << setprecision(2) << " Prix : " << prix << "€" << endl;
    cout << "Nombre de places maximal : " << nombrePlacesMaximal << endl << endl;
}

