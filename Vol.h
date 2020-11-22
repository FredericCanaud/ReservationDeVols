//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_VOL_H
#define RESERVATIONDEVOLS_VOL_H


#include "Destination.h"
#include "Passager.h"
#include "Date.h"
#include <vector>

class Vol {
public:
    Vol();
    Vol(int numero, int nombrePlacesMaximal, float prix);
    bool recherche(const vector<Vol> &vols);
    Vol ajouterVol(int numero, int nombrePlacesMaximal, float prix);

private:
    int numero;
    int nombrePlacesMaximal;
    float prix;
    Destination destination;
    Date date;
    vector<Passager> passagers;

};


#endif //RESERVATIONDEVOLS_VOL_H
