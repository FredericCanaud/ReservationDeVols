//
// Created by Freddy on 21/11/2020.
//

#include <iostream>
#include <map>
#include "Passager.h"
#include "helper.h"

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
    string buff;


    // remplissage des champs
    cout << "Entrez votre identifiant : ";
    cin >> identifiant;

    cout << "Entrez votre mot de passe : ";
    cin >> motDePasse;

    cout << "Confirmez votre mot de passe : ";
    cin >> confirmMotDePasse;

    // vérification du mot de passe
    while(motDePasse != confirmMotDePasse){
        cout << "Les mots de passe saisis ne se correspondent pas !" << endl << "Entrez votre mot de passe : ";
        cin >> motDePasse;

        cout << "Confirmez votre mot de passe : ";
        cin >> confirmMotDePasse;
    }

    cout << "Entrez votre nom : ";
    cin >> nom;

    cout << "Entrez votre prenom : ";
    cin >> prenom;

    Helper::saisirEntier(age, "Entrez votre age : ");


    cout << "Entrez votre titre (Monsieur, Madame ou Mademoiselle) : ";
    cin >> titre;

    while(Titre::Monsieur >= m[titre] && Titre::Mademoiselle <= m[titre]){
        cout << "Erreur : Veuillez saisir un titre correct (Monsieur, Madame ou Mademoiselle) : ";
        cin >> titre;
    }


    Helper::saisirEntier(numeroPasseport, "Entrez votre numero de passport :");


    return Passager(identifiant, motDePasse, nom, prenom, age, m[titre], numeroPasseport);
}
