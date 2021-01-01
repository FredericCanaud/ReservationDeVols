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
Administrateur* admin;
Passager* utilisateur;

int main()
{
    setlocale(LC_ALL, "");
    int choix, choix2;
    admin = new Administrateur("admin", "lejavadabord");

    // chargement des morceaux
    vols = Vol::load("../sauvegarde/vols.txt");
    passagers = Passager::load("../sauvegarde/passagers.txt");
    reservations = Reservation::load("../sauvegarde/reservations.txt");


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
                            system("CLS");
                            break;
                        case 2:
                            //Vol::afficherVols(vols);
                            system("CLS");
                            break;
                        case 3:
                            system("CLS");
                            break;
                        case 4:
                            system("CLS");
                            break;
                        case 5:
                            system("CLS");
                            break;
                        case 6:
                            system("CLS");
                            break;
                        default:
                            break;
                    }
                } while (choix2 != 6);
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
                                        system("CLS");
                                        break;
                                    case 2:
                                        //Vol::afficherVols(vols);
                                        system("CLS");
                                        break;
                                    case 3:
                                        system("CLS");
                                        break;
                                    case 4:
                                        system("CLS");
                                        break;
                                    case 5:
                                        system("CLS");
                                        break;
                                    case 6:
                                        system("CLS");
                                        break;
                                    default:
                                        break;
                                }
                            } while (choix2 != 6);
                            break;
                        case 2:
                            admin->connexion();
                            choix2 = Interface::menuAdministrateur();
                            do{

                            }while (choix2 != 5);
                    }
                }while (choix != 3);
                choix2 = 0;
                choix = 0;
                system("cls");
                break;
            }
            case 3: {
            	cout << "\nboubye";
                system("cls");
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
}
