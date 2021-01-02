//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_DATE_H
#define RESERVATIONDEVOLS_DATE_H

#include <string>
using namespace std;


class Date {
public:
    Date();
    Date(int jour, int mois, int annee, int heure, int minute);
    Date saisirDate();

    string toString() const;

    int getHeure() const;

    int getMinute() const;

    int getJour() const;

    int getMois() const;

    int getAnnee() const;

    string getHoraire() const;
    string getTempo() const;

    void setHeure(int heure) const;

    void setMinute(int minute) const;

    void setJour(int jour) const;

    void setMois(int mois) const;

    void setAnnee(int annee)const ;

    static bool controlerDate(int jour, int moisSaisi, int annee);

private:
    int heure;
    int minute;
    int jour;
    int mois;
    int annee;

};


#endif //RESERVATIONDEVOLS_DATE_H
