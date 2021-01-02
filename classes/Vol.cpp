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

Destination* Vol::getDestination() {
    return &destination;
}

Date* Vol::getDate() {
    return &this->date;
}


Vol* Vol::getVol(int numeroVol){
    list<Vol*>::iterator it;

    for (it = vols.begin() ; it != vols.end() ; it++){
        if ((*it)->getNumero() == numeroVol){
            return (*it);
        }
    }
    return nullptr;
}

list<Passager*> Vol::getPassagersVol(){
    return this->passagersVol;
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
    cout << setw(2) << setfill('0') << " Heure de depart : " << date.getHeure() << ":" << date.getMinute() << endl;
    cout << setw(2) << setfill('0') << " Jour de depart : " << date.getJour() << "/" << date.getMois() << "/" << date.getAnnee() << endl;
    cout << setprecision(2) << " Prix : " << to_string(prix) << " euros" << endl;
    cout << "Nombre de places maximal : " << nombrePlacesMaximal << endl << endl;
}


void Vol::ajouterPassager(Passager* passager){
    if (this->passagersVol.size() < this->nombrePlacesMaximal){
        this->passagersVol.push_front(passager);
    }else{
        cout << "Il n'y a plus de place pour ce vol" << endl;
    }
}

bool Vol::existNumero(int numero){
    cout << "taille vols :" << vols.size() << endl;
    if (vols.empty()){
        cout << "Il n'y a pas de vols\n";
        return false;
    }

    list<Vol*>::iterator it;

    for (it = vols.begin() ; it != vols.end() ; it++){
        if ((*it)->getNumero() == numero){
            return true;
        }
    }
    return false;
}

//string qui contient les informations à sauvegarder
string Vol::toSave(){
    string result = "";

    result += to_string(this->getNumero()) + s + to_string(this->getNombrePlacesMaximal()) + s + to_string(this->getPrix()) + s + this->getDestination()->toString() + s + this->getDate()->toString();

    // itérateur sur la liste de passager du vol
    list<Passager*>::iterator it;

    for (it = this->passagersVol.begin() ; it != passagersVol.end() ; it++){
        result += s + (*it)->getIdentifiant();
    }

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
        float prix = ::atof((*(itv+2)).c_str());
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

        if (ligne.size() > 9){
            // pour chaque identifiant de passager
            for (itv = (itv+10) ; itv != ligne.end() ; itv++){
                Passager* passager = Passager::recherche((*itv));
                // si le passager exisite
                if (nullptr != passager){
                    // on ajoute le passager au vol
                    vol->ajouterPassager(passager);
                }else{
                    cout << "Erreur de chargement des passagers du vol numero " + to_string(numero) << endl;
                }
            }

            vols.push_front(vol);
        }

    }

    return vols;
}


