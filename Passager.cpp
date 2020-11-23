//
// Created by Freddy on 21/11/2020.
//

#include <iostream>
#include <map>
#include "Passager.h"

Passager::Passager() : Personne() {

}

Passager::Passager(string identifiant, string motDePasse, string nom, string prenom, int age, Titre titre, int numeroPasseport) : Personne(identifiant, motDePasse){
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
    this->titre = titre;
    this->numeroPasseport = numeroPasseport;
}

void Passager::reserverVol() {

}

void Passager::confirmerReservation() {

}

void Passager::annulerReservation() {

}

Passager Passager::inscription() {
    string identifiant, motDePasse, confirmMotDePasse, nom, prenom, titre;
    int age, numeroPasseport;
    map<string,Titre> m;
    m["Monsieur"] = Titre::Monsieur;
    m["Madame"] = Titre::Madame;
    m["Mademoiselle"] = Titre::Mademoiselle;

    cout << "Entrez votre identifiant : " << endl;
    cin >> identifiant;
    cout << "Entrez votre mot de passe : " << endl;
    cin >> motDePasse;
    cout << "Confirmez votre mot de passe : " << endl;
    cin >> confirmMotDePasse;
    while(motDePasse != confirmMotDePasse){
        cout << "Les mots de passe saisis ne se correspondent pas !" << endl << "Entrez votre mot de passe : " << endl;
        cin >> motDePasse;
        cout << "Confirmez votre mot de passe : " << endl;
        cin >> confirmMotDePasse;
    }
    cout << " Entrez votre nom : " << endl;
    cin >> nom;
    cout << " Entrez votre prenom : " << endl;
    cin >> prenom;
    cout << " Entrez votre age : " << endl;
    cin >> age;
    cout << " Entrez votre titre (Monsieur, Madame ou Mademoiselle) : " << endl;
    cin >> titre;
    while(Titre::Monsieur >= m[titre] && Titre::Mademoiselle <= m[titre]){
        cout << " Erreur : Veuillez saisir un titre correct (Monsieur, Madame ou Mademoiselle) : " << endl;
        cin >> titre;
    }
    cout << " Entrez votre numero de passport :" << endl;
    cin >> numeroPasseport;
    return Passager(identifiant, motDePasse, nom, prenom, age, m[titre], numeroPasseport);
}

Passager Passager::connexion(const vector<Passager>& passagers) {
    bool correct = false;
    Passager p;

    string identifiantSaisi, motDePasseSaisi;
    cout <<" Entrez votre identifiant : " << endl;
    cin >> identifiantSaisi;
    cout <<" Entrez votre mot de passe : " << endl;
    cin >> motDePasseSaisi;
    while(!correct){
        for (const Passager& passager : passagers){
            if (passager.getIdentifiant() == identifiantSaisi && passager.getMotDePasse() == motDePasseSaisi){
                p = passager;
                correct = true;
            }
        }
        if(!correct){
            cout <<" L'identifiant ou le mot de passe saisi est incorrect ! " << endl;
            cout <<" Entrez a nouveau votre identifiant : " << endl;
            cin >> identifiantSaisi;
            cout <<" Entrez a nouveau votre mot de passe : " << endl;
            cin >> motDePasseSaisi;
        }
    }
    return p;
}