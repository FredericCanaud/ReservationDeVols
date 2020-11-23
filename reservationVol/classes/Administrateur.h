//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_ADMINISTRATEUR_H
#define RESERVATIONDEVOLS_ADMINISTRATEUR_H
#include "Personne.h"
#include <string>
using namespace std;

class Administrateur : virtual Personne{
public:
    Administrateur();
    Administrateur(string, string);

    void connexion();
};


#endif //RESERVATIONDEVOLS_ADMINISTRATEUR_H
