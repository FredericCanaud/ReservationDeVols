//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_ADMINISTRATEUR_H
#define RESERVATIONDEVOLS_ADMINISTRATEUR_H

#include <string>
using namespace std;

class Administrateur {
public:
    Administrateur();
    Administrateur(string, string);

private:
    string identifiant;
    string motDePasse;
};


#endif //RESERVATIONDEVOLS_ADMINISTRATEUR_H
