//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_RESERVATION_H
#define RESERVATIONDEVOLS_RESERVATION_H


class Reservation {
public:
    Reservation();
    Reservation(int, int, int);
    void confirmationReservation();

private:
    int numeroReservation;
    int numeroPasseport;
    int numeroVol;
    bool confirmation;
};


#endif //RESERVATIONDEVOLS_RESERVATION_H
