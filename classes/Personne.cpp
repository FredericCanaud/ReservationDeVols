//
// Created by Freddy on 21/11/2020.
//

#include "Personne.h"

Personne::Personne() = default;

Personne::Personne(string identifiant, string motDePasse) {
    this->identifiant = identifiant;
    this->motDePasse = motDePasse;
}

const string &Personne::getIdentifiant() const {
    return identifiant;
}

const string &Personne::getMotDePasse() const {
    return motDePasse;
}

