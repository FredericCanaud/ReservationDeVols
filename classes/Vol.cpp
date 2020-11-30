//
// Created by Freddy on 21/11/2020.
//

#include "Vol.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "helper.h"
using namespace std;


Vol::Vol() {

}

Vol::Vol(int numero, int nombrePlacesMaximal, float prix) {
    this->numero = numero;
    this->nombrePlacesMaximal = nombrePlacesMaximal;
    this->prix = prix;
}

Vol::Vol(int numero, int nombrePlacesMaximal, float prix, Destination destination, Date date){
    this->numero = numero;
    this->nombrePlacesMaximal = nombrePlacesMaximal;
    this->prix = prix;
    this->destination = destination;
    this->date = date;
}

int Vol::getNumero() const {
    return numero;
}

int Vol::getNombrePlacesMaximal() const {
    return nombrePlacesMaximal;
}

float Vol::getPrix() const {
    return prix;
}

const Destination Vol::getDestination() const {
    return destination;
}

const Date Vol::getDate() const {
    return date;
}

Vol Vol::ajouterVol(int numero, int nombrePlacesMaximal, float prix) {
    Vol vol = Vol(numero, nombrePlacesMaximal, prix);
    vol.destination = destination.saisirDestination();
    vol.date = date.saisirDate();
    return vol;
}

bool Vol::recherche(int numeroVol) const {
    list<Vol*>::iterator it ;
    for(it = vols.begin(); it != vols.end() ; it++){
        if((*it)->getNumero() == numeroVol){
            return true;
        }
    }
    return false;
}

void Vol::afficherVols(){
    cout << " Liste des vols disponibles :" << endl << endl;
    list<Vol*>::iterator it ;
    for(it = vols.begin(); it != vols.end() ; it++){
        (*it)->afficher();
    }
}

// fonction qui affiche les champs du vol
void Vol::afficher() const {
    cout << " Vol numero " << numero << " :" << endl;
    cout << " De " << destination.getVilleDepart() << " en destination de " << destination.getVilleArrivee() << endl;
    cout << setw(2) << setfill('0') << " Heure de départ : " << date.getHeure() << ":" << date.getMinute() << endl;
    cout << setw(2) << setfill('0') << " Jour de départ : " << date.getJour() << "/" << date.getMois() << "/" << date.getAnnee() << endl;
    cout << setprecision(2) << " Prix : " << prix << "€" << endl;
    cout << "Nombre de places maximal : " << nombrePlacesMaximal << endl << endl;
}


//string qui contient les informations à sauvegarder
string Vol::toSave(){
    string result = "";

    result += to_string(this->getNumero()) + s + to_string(this->getNombrePlacesMaximal()) + s + to_string(this->getPrix()) + this->getDestination().toString() + s + this->getDate().toString();

    return result;
}

// sauvegarde les informations dans un txt
void Vol::save(list<Vol *> liste, string nomFichier) {
    // manipulateur de fichier
    ManipulateurFichier manip(nomFichier);

    // liste des informations à sauvegarder
    list<string> toSave;

    // itérateur sur la liste
    list<Vol*>::iterator it;

    // pour chaque passager
    for (it = liste.begin() ; it != liste.end() ; it++){
        // ajouter à la liste les informations à sauvegarder
        toSave.push_front((*it)->toSave()) ;
    }

    // écrire dans le fichier
    manip.ecrire(toSave);
}

list<Vol*> Vol::load(string nomFichier){
    // liste des vols
    list<Vol*> vols;

    // manipulateur de fichier
    ManipulateurFichier manip(nomFichier);

    // liste des données sauvegardées
    list<string> infos = manip.lireLignes();

    // itérateur sur les informations
    list<string>::iterator it;

    // pour chaque lignes
    for (it = infos.begin() ; it != infos.end() ; it++){
        // séparateur utilisé pour la sauvegarde
        string separateur = ";";

        // différents champ d'un vol
        vector<string> ligne = Helper::split(*it, separateur);

        // itérateur sur les champs de la ligne
        vector<string>::iterator itv = ligne.begin();

        // récupération des champs
        int numero = Helper::to_int(*itv);
        int nbPlace = Helper::to_int(*(itv+1));
        int prix = Helper::to_int(*(itv+2));
        string villeDep = *(itv+3);
        string villeArr = *(itv+4);
        int j = Helper::to_int(*(itv+5));
        int m = Helper::to_int(*(itv+6));
        int a = Helper::to_int(*(itv+7));
        int h = Helper::to_int(*(itv+8));
        int min = Helper::to_int(*(itv+9));

        Destination destination(villeDep, villeArr);
        Date date(j, m, a, h, min);

        // création du vol
        Vol *vol = new Vol(numero, nbPlace, prix, destination, date);

        vols.push_front(vol);
    }

    return vols;
}


