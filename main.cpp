#include <iostream>
#include "Passager.h"
#include "Interface.h"
#include "Vol.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int choix, choix2;
    vector<Vol> vols;

    cout << " Programme Reservation de vols" << endl << endl;

    do{
        choix = Interface::menuPrincipal();
        switch (choix) {
            case 1: {
                Passager p = Passager::inscription();
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
                system("CLS");
                break;
            }
            case 3: {
                system("CLS");
                break;
            }
            default: {
                cout << " Erreur : Choix incorrect." << endl << endl;
                break;
            }
        }
    } while(choix != 3);
}