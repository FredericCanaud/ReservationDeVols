//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_ADMINISTRATEUR_H
#define RESERVATIONDEVOLS_ADMINISTRATEUR_H
#include "Personne.h"
#include <string>
using namespace std;
#include "Personne.h"
#include "Passager.h"
#include "Interface.h"
#include "Vol.h"
#include "Date.h"
#include "Reservation.h"
#include "helper.h"
#include <map>


class Administrateur : virtual Personne{
public:
    Administrateur();
    Administrateur(string, string);

    // action admin
    void connexion();
    void modifierDateVol();
    void modifierHeureVol();
    void ajouterVol();
    void afficherVols();
    void afficherPassagersVol();
    void existVol();
    void ajouterPassager();
    void ajouterReservation();
    void ajouterDestination();
};
extern list<Passager*> passagers;
extern list<Vol*> vols;
extern list<Reservation*> reservations;
extern list<Destination*> destinations;

#endif //RESERVATIONDEVOLS_ADMINISTRATEUR_H
