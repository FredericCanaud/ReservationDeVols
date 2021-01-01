//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_DESTINATION_H
#define RESERVATIONDEVOLS_DESTINATION_H

#include <string>
#include<vector>
#include"helper.h"
#include "manipulateurFichier.h"
using namespace std;

class Destination : public Sauvegardable{
public:
    Destination();
    Destination(string villeDepart, string villeArrivee);
    string getVilleDepart() const;
    string getVilleArrivee() const;
    void afficher();
    string toString() const;
    Destination saisirDestination();

    // sauvegarde
    string toSave();
    static void save(list<Destination*> liste, string nomFichier);
    static list<Destination*> load(string nomFichier);

private:
    string villeDepart;
    string villeArrivee;
};

extern string s;  // séparateur pour les sauvegardes
#endif //RESERVATIONDEVOLS_DESTINATION_H
