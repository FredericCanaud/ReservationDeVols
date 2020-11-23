//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_PERSONNE_H
#define RESERVATIONDEVOLS_PERSONNE_H

#include <string>
using namespace std;

class Personne {
public:
    Personne();
    Personne(string,string);

private:
    string identifiant;
    string motDePasse;
};


#endif //RESERVATIONDEVOLS_PERSONNE_H
