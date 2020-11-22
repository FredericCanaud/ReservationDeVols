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
        cout << " Saissisez votre choix : ";
        cin >> choix;
        cout << endl;
    } while (choix <= 0 || choix >= 4);
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
        cout << " 2 - Afficher la liste de mes reservations" << endl;
        cout << " 4 - Confirmer une reservation" << endl;
        cout << " 5 - Annuler une reservation" << endl;
        cout << " 6 - Deconnexion" << endl << endl;
        cout << " Saissisez votre choix : ";
        cin >> choix;
        cout << endl;
    } while (choix <= 0 || choix >= 7);
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
        cout << " 5 - Quitter et sauvegarder" << endl;
        cout << " 6 - Quitter sans sauvegarder." << endl << endl;
        cout << " Saissisez votre choix : ";
        cin >> choix;
        cout << endl;
    } while (!(choix == 5 || choix == 6));
    return choix;
}
