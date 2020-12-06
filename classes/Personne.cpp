//
// Created by Freddy on 21/11/2020.
//

#include "Personne.h"

Personne::Personne() = default;

Personne::Personne(string identifiant, string motDePasse) {
    this->identifiant = identifiant;
    this->motDePasse = motDePasse;
}


