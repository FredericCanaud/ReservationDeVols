//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_PASSAGER_H
#define RESERVATIONDEVOLS_PASSAGER_H

#include "Personne.h"
#include <string>
#include <vector>

using namespace std;

enum class Titre {Monsieur, Madame, Mademoiselle};

class Passager : Personne{
private:
    string nom;
    string prenom;
    int age;
    Titre titre;
    int numeroPasseport;

public:
    Passager();
    Passager(string, string, string, string, int, Titre, int);
    void reserverVol();
    void confirmerReservation();
    void annulerReservation();

    static Passager inscription();
    static Passager connexion(const vector<Passager>& passagers);
};


#endif //RESERVATIONDEVOLS_PASSAGER_H
