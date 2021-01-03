//
// Created by Freddy on 21/11/2020.
//

#include "Interface.h"
#include <iostream>
using namespace std;

int Interface::menuPrincipal() {
    int choix;
    do {
        cout << " ----- Menu principal ----- " << endl << endl;
        cout << " Voici les differentes operations possibles : " << endl;
        cout << " 1 - S'inscrire" << endl;
        cout << " 2 - Se connecter" << endl;
        cout << " 3 - Quitter l'application" << endl;
        Helper::saisirEntier(choix, 1, 32, "Saisissez votre choix:");
        cout << endl;
    } while (choix <= 0 || choix >= 4);
    return choix;
}

int Interface::menuConnexion() {
    int choix;
    do
    {
        cout << "            Page de connexion ! " << endl << endl;
        cout << " Voici les differentes operations possibles : " << endl;
        cout << " 1 - Connection passager" << endl;
        cout << " 2 - Connection admin" << endl;
        cout << " 3 - Retour" << endl << endl;
        Helper::saisirEntier(choix, 1, 3, "Saisissez votre choix:");
        cout << endl;
    } while (choix < 1 || choix > 3);
    return choix;
}

int Interface::menuPassager() {
    int choix;
    do
    {
        cout << " Bienvenue sur l'application de vol ! " << endl << endl;
        cout << " ----- Menu passager ----- " << endl << endl;
        cout << " Voici les differentes operations possibles : " << endl;
        cout << " 1 - Reserver un vol" << endl;
        cout << " 2 - Afficher la liste des vols" << endl;
        cout << " 3 - Afficher la liste de mes reservations" << endl;
        cout << " 4 - Confirmer une reservation" << endl;
        cout << " 5 - Annuler une reservation" << endl;
        cout << " 6 - Verifier l'existence d'une reservation" << endl;
        cout << " 7 - Verifier l'existence d'un vol" << endl;
        cout << " 8 - Deconnexion" << endl << endl;
        Helper::saisirEntier(choix, 1, 8, "Saisissez votre choix:");
        cout << endl;
    } while (choix <= 0 || choix >= 9);
    return choix;
}

int Interface::menuAdministrateur() {
    int choix;
    do
    {
        cout << " Bienvenue sur l'application de vol ! " << endl << endl;
        cout << " ----- Menu administration ----- " << endl << endl;
        cout << " Voici les differentes operations possibles : " << endl;
        cout << " 1 - Modifier date d'un vol" << endl;
        cout << " 2 - Modifier heure d'un vol" << endl;
        cout << " 3 - Ajouter un vol" << endl;
        cout << " 4 - Afficher la liste des vols" << endl;
        cout << " 5 - Afficher la liste des passagers d'un vol" << endl;
        cout << " 6 - Verifier l'existence d'un vol" << endl;
        cout << " 7 - Ajouter un passager" << endl;
        cout << " 8 - Ajouter une reservation" << endl;
        cout << " 9 - Ajouter une destination" << endl;
        cout << " 10 - Quitter et sauvegarder" << endl;
        Helper::saisirEntier(choix, 1, 10, "Saisissez votre choix:");
        cout << endl;
    } while (choix < 1 && choix > 10);
    return choix;
}
