#include <iostream>
#include<list>
#include <string>
#include "Passager.h"
#include "Interface.h"
#include "Vol.h"
#include "Reservation.h"
using namespace std;

//variable globale
string s = ";";
list<Passager*> passagers;
list<Vol*> vols;
list<Reservation*> reservations;

int main()
{
    setlocale(LC_ALL, "");
    int choix, choix2;

    // chargement des
    vols = Vol::load("../sauvegarde/vols.txt");
    passagers = Passager::load("../sauvegarde/passagers.txt");
    reservations = Reservation::load("../sauvegarde/reservations.txt");


    list<Passager*>::iterator it = passagers.begin();
    cout << (*it)->toSave()<<endl<<endl;
    it++;
    cout << (*it)->toSave()<<endl<<endl;


    cout << " Programme Reservation de vols" << endl << endl;

    do{
        choix = Interface::menuPrincipal(); //renvoie vers le menu principal
        switch (choix) {
            case 1: {
                Passager p = Passager::inscription(); //renvoie vers la page pour l'inscription
                passagers.push_back(&p); // ajout du passager à la liste de passagers
                do {
                    choix2 = Interface::menuPassager(); // renvoie versle menu passager
                    switch (choix2) {
                        case 1:
                            p.reserverVol();
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
