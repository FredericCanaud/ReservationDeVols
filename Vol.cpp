//
// Created by Freddy on 21/11/2020.
//

#include "Vol.h"

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
    for(Vol vol : vols)
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



