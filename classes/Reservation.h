//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_RESERVATION_H
#define RESERVATIONDEVOLS_RESERVATION_H
#include <string>
#include <list>
#include "manipulateurFichier.h"
using namespace std;

using namespace std;

class Reservation : public Sauvegardable{
public:
    //constructeur par défault
    Reservation();

    //constructeur
    Reservation(int numeroReservation, int numeroPasseport, int numeroVol);

    // actions utilisateurs
    void confirmerReservation();

    // données à sauvegarder
    string toSave() override;

    // méthodes de sauvegarde
    static void save(list<Reservation*> reservations, string nomFichier);
    static list<Reservation*> load(string nomFichier);


    // GETTERS
    int getNumeroReservation() const;

    int getNumeroPasseport() const;

    int getNumeroVol() const;

    bool isConfirmer() const;

    static bool existNumReservation(int numero);

private:
    int numeroReservation;
    int numeroPasseport;
    int numeroVol;
    bool confirmation;
};

extern string s;
extern list<Reservation*> reservations;

#endif //RESERVATIONDEVOLS_RESERVATION_H
