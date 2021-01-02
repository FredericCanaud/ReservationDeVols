//
// Created by Freddy on 21/11/2020.
//

#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() {

}

Date::Date(int jour, int mois, int annee, int heure, int minute) {
    this->minute = minute;
    this->heure = heure;
    this->jour = jour;
    this->mois = mois;
    this->annee = annee;
}

string Date::toString() const {
    string result = "";
    string s = ";";

    result += to_string(this->getJour()) + s + to_string(this->getMois()) + s + to_string(this->getAnnee()) + s + to_string(this->getHeure()) + s + to_string(this->getMinute());

    return result;
}

int Date::getHeure() const {
    return heure;
}

int Date::getMinute() const {
    return minute;
}

int Date::getJour() const {
    return jour;
}

int Date::getMois() const {
    return mois;
}

int Date::getAnnee() const {
    return annee;
}

void Date::setHeure(int heure) {
    this->heure = heure;
}

void Date::setMinute(int minute) {
    this->minute = minute;
}

void Date::setJour(int jour) {
    this->jour = jour;
}

void Date::setMois(int mois) {
    this->mois = mois;
}

void Date::setAnnee(int annee) {
    this->annee = annee;
}

string Date::getHoraire() const{
    return to_string(this->heure) + " : " + to_string(this->minute);
}

string Date::getTempo() const{
    return to_string(this->jour) + "/" + to_string(this->mois) + "/" + to_string(this->annee);
}

Date Date::saisirDate() {
    int jourSaisi, moisSaisi, anneeSaisie, heureSaisie, minuteSaisie;
    cout<< " Entrez le jour du vol : " << endl;
    cin >> jourSaisi;

    cout<<" Entrez le mois du vol : " << endl;
    cin >> moisSaisi;

    cout<<" Entrez l'annee du vol : " << endl;
    cin >> anneeSaisie;

    while(!controlerDate(jourSaisi, moisSaisi, anneeSaisie)){
        cout << "La date saisie (" << jourSaisi << "/" << moisSaisi << "/" << anneeSaisie << ") est incoherante !" << endl;
        cout<< " Entrez le jour du vol : " << endl;
        cin >> jourSaisi;

        cout<<" Entrez le mois du vol : " << endl;
        cin >> moisSaisi;

        cout<<" Entrez l'annee du vol : " << endl;
        cin >> anneeSaisie;
    }

    cout<<" Entrez l'heure du vol : " << endl;
    cin >> heureSaisie;
    cout<<" Entrez les minutes du vol : " << endl;
    cin >> minuteSaisie;
    while ( heureSaisie > 23 || heureSaisie < 0 || minuteSaisie < 0 || minuteSaisie > 59){
        cout << "L'heure saisie (" << heureSaisie << ":" << minuteSaisie << ") est incoherente !" << endl;
        cout<<" Entrez l'heure du vol : " << endl;
        cin >> heureSaisie;
        cout<<" Entrez les minutes du vol : " << endl;
        cin >> minuteSaisie;
    }

    cout << "saisirDate zone\n\n";
    return Date(jourSaisi, moisSaisi, anneeSaisie, heureSaisie, minuteSaisie);
}

bool Date::controlerDate(int jourSaisi, int moisSaisi, int anneeSaisie){
    if (moisSaisi < 0 || moisSaisi > 12 || jourSaisi < 0 || jourSaisi > 31 )
    {
        return false;
    }
    if (((moisSaisi == 1) || (moisSaisi == 3) || (moisSaisi == 5) || (moisSaisi == 7) || (moisSaisi == 10) || (moisSaisi == 12) ) && (jourSaisi > 0 && jourSaisi <= 31) )
    {
        return true;
    }
    else
    {
        if ((moisSaisi == 4 || moisSaisi == 6 || moisSaisi == 9 || moisSaisi == 11) && (jourSaisi > 0 && jourSaisi <= 30) )
        {
            return true;
        }
        else if (jourSaisi > 0 && jourSaisi <= 28)
        {
            return true;
        }
        else{
            if ( ( (anneeSaisie % 4 == 0 && anneeSaisie % 100 != 0)  || anneeSaisie % 400 == 0 ) && (jourSaisi > 0 && jourSaisi <= 29) )
            {
                return false;
            }
        }
    }
    return false;
}
