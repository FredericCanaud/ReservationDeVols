//
// Created by Freddy on 21/11/2020.
//

#include "Administrateur.h"
#include <iostream>
using namespace std;

Administrateur::Administrateur() : Personne() {

}

Administrateur::Administrateur(string identifiant, string motDePasse) : Personne(identifiant, motDePasse){

}

void Administrateur::connexion() {
    string identifiantSaisi, motDePasseSaisi;
    cout <<" Entrez votre identifiant : " << endl;
    cin >> identifiantSaisi;
    cout <<" Entrez votre mot de passe : " << endl;
    cin >> motDePasseSaisi;
    cout << identifiantSaisi << "  " << motDePasseSaisi << endl;

    while((this->getIdentifiant() != identifiantSaisi) || (this->getMdp() != motDePasseSaisi)){
        cout <<" L'identifiant ou le mot de passe saisi est incorrect ! " << endl;
        cout <<" Entrez a nouveau votre identifiant : " << endl;
        cin >> identifiantSaisi;
        cout <<" Entrez a nouveau votre mot de passe : " << endl;
        cin >> motDePasseSaisi;
    }

    cout << "connected " <<endl<<endl;
}


