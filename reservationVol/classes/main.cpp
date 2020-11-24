#include <iostream>
#include<list>
#include "Passager.h"
#include "Interface.h"
#include "Vol.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int choix, choix2;
    vector<Vol> vols;

    list<Sauvegardable> passagers;
    passagers = Passager::load("./sauvegarde/passagers.txt");
    list<Sauvegardable>::iterator it = passagers.begin();
    cout << it->thisu().toSave()<<endl<<endl;

    cout << " Programme Reservation de vols" << endl << endl;

    do{
        choix = Interface::menuPrincipal(); //renvoie vers le menu principal
        switch (choix) {
            case 1: {
                Passager p = Passager::inscription(); //renvoie vers la page pour l'inscription
                passagers.push_back(p);
                do {
                    choix2 = Interface::menuPassager();
                    switch (choix2) {
                        case 1:
                            p.reserverVol();
                            system("CLS");
                            break;
                        case 2:
                            Vol::afficherVols(vols);
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
            	cout << "boubye";
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
   // Passager::save(passagers, "./sauvegarde/passagers.txt");
}
