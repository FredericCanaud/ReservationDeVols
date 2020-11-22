#include <iostream>
#include "Passager.h"
#include "Interface.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int choix, choix2;

    cout << " Programme Reservation de vols" << endl << endl;

    choix = Interface::menuPrincipal();
    switch (choix) {
        case 1:{
            Passager p = Passager::inscription();
            int choix2 = Interface::menuPassager();
            switch (choix2)
            {
                case 1:
                    system("CLS");
                    break;
                case 2:
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
            break;
        }
        case 2:{
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
}