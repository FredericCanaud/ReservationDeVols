//
// Created by Freddy on 21/11/2020.
//

#include "manipulateurFichier.h"
#include "helper.h"
#include "Reservation.h"

Reservation::Reservation() {

}

Reservation::Reservation(int numeroReservation, int numeroPasseport, int numeroVol) {
    this->numeroReservation = numeroReservation;
    this->numeroPasseport = numeroPasseport;
    this->numeroVol = numeroVol;
    this->confirmation = false;
}

int Reservation::getNumeroReservation() const {
    return numeroReservation;
}

int Reservation::getNumeroPasseport() const {
    return numeroPasseport;
}

int Reservation::getNumeroVol() const {
    return numeroVol;
}

bool Reservation::isConfirmer() const {
    return confirmation;
}

bool Reservation::existNumReservation(int numero){
    list<Reservation*>::iterator it;

    for (it = reservations.begin() ; it != reservations.end() ; it++){
        if ((*it)->getNumeroReservation() == numero){
            return true;
        }
    }
    return false;
}

Reservation* Reservation::getReservation(int numeroReservation){
    list<Reservation*>::iterator it;

    for (it = reservations.begin() ; it != reservations.end() ; it++){
        if ((*it)->getNumeroReservation() == numeroReservation){
            return (*it);
        }
    }
    return nullptr;
}

void Reservation::setConfirme(bool valide){
    this->confirmation = valide;
}

void Reservation::confirmerReservation(){
    this->confirmation = true;
}

string Reservation::toSave(){
    string result = "";

    result += to_string(this->getNumeroReservation()) + s + to_string(this->getNumeroPasseport()) + s + to_string(this->getNumeroVol());

    if (this->isConfirmer()){
        result += s + to_string(1);
    }else{
        result += s + to_string(0);
    }

    return result;
}

// sauvegarde dans un fichier texte
void Reservation::save(list<Reservation*> reservations, string nomFichier){
    // manipulateur de fichier
    ManipulateurFichier manip(nomFichier);

    // liste des informations à sauvegarder
    list<string> toSave;

    // itérateur sur la liste
    list<Reservation*>::iterator it;

    // pour chaque passager
    for (it = reservations.begin() ; it != reservations.end() ; it++){
        // ajouter à la liste les informations à sauvegarder
        toSave.push_front((*it)->toSave()) ;
    }

    // écrire dans le fichier
    manip.ecrire(toSave);
}

// chargement des réservations
list<Reservation*> Reservation::load(string nomFichier) {
    // liste des passagers
    list<Reservation*> reservations;

    // manipulateur de fichier
    ManipulateurFichier manip(nomFichier);

    // liste des données sauvegardées
    list<string> infos = manip.lireLignes();

    // itérateur sur les informations
    list<string>::iterator it;


    // pour chaque lignes
    for (it = infos.begin() ; it != infos.end() ; it++){
        // liste des champs présents sur la ligne
        vector<string> ligne = Helper::split(*it, s);

        // itérateur sur les champs
        vector<string>::iterator itv = ligne.begin();

        int numReservation = Helper::to_int(*itv);
        int numPasseport =  Helper::to_int(*(itv+1));
        int numVol = Helper::to_int(*(itv+2));
        int isValide = Helper::to_int(*(itv+3));

        bool valide;
        if (isValide == 1){
            valide = true;
        }else{
            valide = false;
        }

        Reservation *reservation = new Reservation(numReservation, numPasseport, numVol);

        reservation->setConfirme(valide);

        reservations.push_front(reservation);
    }


    return reservations;
}




