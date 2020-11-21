//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_DATE_H
#define RESERVATIONDEVOLS_DATE_H


class Date {
public:
    Date();
    Date(int, int, int, int, int);

private:
    int heure;
    int minute;
    int jour;
    int mois;
    int annee;
};


#endif //RESERVATIONDEVOLS_DATE_H
