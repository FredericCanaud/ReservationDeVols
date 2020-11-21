//
// Created by Freddy on 21/11/2020.
//

#include "Reservation.h"

Reservation::Reservation() {

}

Reservation::Reservation(int numeroReservation, int numeroPasseport, int numeroVol) {
    this->numeroReservation = numeroReservation;
    this->numeroPasseport = numeroPasseport;
    this->numeroVol = numeroVol;
    this->confirmation = false;
}

void Reservation::confirmationReservation(){
    this->confirmation = true;
}


