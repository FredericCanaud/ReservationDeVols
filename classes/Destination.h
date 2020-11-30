//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_DESTINATION_H
#define RESERVATIONDEVOLS_DESTINATION_H

#include <string>
using namespace std;

class Destination {
public:
    Destination();
    Destination(string villeDepart, string villeArrivee);
    string getVilleDepart() const;
    string getVilleArrivee() const;
    void afficher();
    string toString() const;
    Destination saisirDestination();

private:
    string villeDepart;
    string villeArrivee;
};


#endif //RESERVATIONDEVOLS_DESTINATION_H
