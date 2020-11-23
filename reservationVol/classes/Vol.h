//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_VOL_H
#define RESERVATIONDEVOLS_VOL_H


#include "Destination.h"
#include "Date.h"
#include <vector>

class Vol {
public:
    Vol();
    Vol(int numero, int nombrePlacesMaximal, float prix);
    bool recherche(const vector<Vol> &vols) const;
    Vol ajouterVol(int numero, int nombrePlacesMaximal, float prix);
    static void afficherVols(const vector<Vol> &vols);
    void afficher() const;

private:
    int numero;
    int nombrePlacesMaximal;
    float prix;
    Destination destination;
    Date date;
};


#endif //RESERVATIONDEVOLS_VOL_H
