// CAMPREDON Thomas
// CANAUD Frédéric

#include <iostream>
#include<list>
#include <string>
#include "Personne.h"
#include "Passager.h"
#include "Interface.h"
#include "Vol.h"
#include "Administrateur.h"
#include "Reservation.h"
using namespace std;

//variables globales
string s = ";";
list<Passager*> passagers;
list<Vol*> vols;
list<Reservation*> reservations;
list<Destination*> destinations;
Administrateur* admin;
Passager* utilisateur;

int main()
{
    setlocale(LC_ALL, "");
    int choix, choix2;
    admin = new Administrateur("admin", "lejavadabord");

    // chargement des morceaux
    passagers = Passager::load("../sauvegarde/passagers.txt");
    vols = Vol::load("../sauvegarde/vols.txt");
    reservations = Reservation::load("../sauvegarde/reservations.txt");
    destinations = Destination::load("../sauvegarde/destinations.txt");


    cout << " Programme Reservation de vols" << endl << endl;

    do{
        choix = Interface::menuPrincipal(); //renvoie vers le menu principal
        switch (choix) {
            case 1: {
                Passager p = Passager::inscription(); //renvoie vers la page pour l'inscription
                passagers.push_back(&p); // ajout du passager à la liste de passagers
                utilisateur = &p;
                do {
                    choix2 = Interface::menuPassager(); // renvoie vers le menu passager
                    switch (choix2) {
                        case 1:
                            utilisateur->reserverVol();
                            system("PAUSE");
                            break;
                        case 2:
                            Vol::afficherVols();
                            system("PAUSE");
                            break;
                        case 3:
                            utilisateur->afficherReservations();
                            system("PAUSE");
                            break;
                        case 4:
                            utilisateur->confirmerReservation();
                            system("PAUSE");
                            break;
                        case 5:
                            utilisateur->annulerReservation();
                            system("PAUSE");
                            break;
                        case 6:
                            utilisateur->existReservation();
                            system("PAUSE");
                            break;
                        case 7:
                            admin->existVol();
                            system("PAUSE");
                            break;
                        case 8:
                            cout << "\nDeconnexion" << endl;
                            break;
                        default:
                            break;
                    }
                } while (choix2 != 8);
                break;
            }
            case 2: {
                do{
                    choix = Interface::menuConnexion();
                    switch (choix) {
                        case 1:
                            utilisateur = Passager::connexion();
                            do {
                                choix2 = Interface::menuPassager(); // renvoie vers le menu passager
                                switch (choix2) {
                                    case 1:
                                        utilisateur->reserverVol();
                                        system("PAUSE");
                                        break;
                                    case 2:
                                        Vol::afficherVols();
                                        system("PAUSE");
                                        break;
                                    case 3:
                                        utilisateur->afficherReservations();
                                        system("PAUSE");
                                        break;
                                    case 4:
                                        utilisateur->confirmerReservation();
                                        system("PAUSE");
                                        break;
                                    case 5:
                                        utilisateur->annulerReservation();
                                        system("PAUSE");
                                        break;
                                    case 6:
                                        utilisateur->existReservation();
                                        system("PAUSE");
                                        break;
                                    case 7:
                                        admin->existVol();
                                        system("PAUSE");
                                        break;
                                    case 8:
                                        cout << "\nDeconnexion" << endl;
                                        break;
                                    default:
                                        break;
                                }
                            } while (choix2 != 8);
                            break;
                        case 2:
                            admin->connexion();

                            do {
                                choix2 = Interface::menuAdministrateur();
                                switch (choix2) {
                                    case 1:
                                        admin->modifierDateVol();
                                        system("PAUSE");
                                        break;
                                    case 2:
                                        admin->modifierHeureVol();
                                        system("PAUSE");
                                        break;
                                    case 3:
                                        admin->ajouterVol();
                                        system("PAUSE");
                                        break;
                                    case 4:
                                        admin->afficherVols();
                                        system("PAUSE");
                                        break;
                                    case 5:
                                        admin->afficherPassagersVol();
                                        system("PAUSE");
                                        break;
                                    case 6:
                                        admin->existVol();
                                        system("PAUSE");
                                        break;
                                    case 7:
                                        admin->ajouterPassager();
                                        system("PAUSE");
                                        break;
                                    case 8:
                                        admin->ajouterReservation();
                                        system("PAUSE");
                                        break;
                                    case 9:
                                        admin->ajouterDestination();
                                        system("PAUSE");
                                        break;
                                    case 10:
                                        cout << "\nExit" << endl;
                                        break;
                                    default:
                                        break;
                                }
                            }while (choix2 != 10);
                    }
                }while (choix != 3);
                choix2 = 0;
                choix = 0;
                break;
            }
            case 3: {
            	cout << "\nboubye";
                break;
            }
            default: {
                cout << " Erreur : Choix incorrect." << endl << endl;
                break;
            }
        }
    } while(choix != 3);

    // sauvegarde à la fin du programme
    Passager::save(passagers, "../sauvegarde/passagers.txt");
    Vol::save(vols, "../sauvegarde/vols.txt");
    Reservation::save(reservations, "../sauvegarde/reservations.txt");
    Destination::save(destinations, "../sauvegarde/destinations.txt");
}
