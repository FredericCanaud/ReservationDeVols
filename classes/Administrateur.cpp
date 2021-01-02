//
// Created by Freddy on 21/11/2020.
//

#include "Administrateur.h"
#include <iostream>
using namespace std;

Administrateur::Administrateur() : Personne() {

}

Administrateur::Administrateur(string identifiant, string motDePasse) : Personne(identifiant, motDePasse){

}


///////////////////////////
/// ACTION ADMIN
///////////////////////////


void Administrateur::connexion() {
    string identifiantSaisi, motDePasseSaisi;
    cout <<" Entrez votre identifiant : " << endl;
    cin >> identifiantSaisi;
    cout <<" Entrez votre mot de passe : " << endl;
    cin >> motDePasseSaisi;
    cout << identifiantSaisi << "  " << motDePasseSaisi << endl;

    while((this->getIdentifiant() != identifiantSaisi) || (this->getMdp() != motDePasseSaisi)){
        cout <<" L'identifiant ou le mot de passe saisi est incorrect ! " << endl;
        cout <<" Entrez a nouveau votre identifiant : " << endl;
        cin >> identifiantSaisi;
        cout <<" Entrez a nouveau votre mot de passe : " << endl;
        cin >> motDePasseSaisi;
    }

    cout << "\nConnected !\n" <<endl<<endl;
}


void Administrateur::modifierDateVol(){
    int numeroVol;
    do{
        cout << "Saisissez le numero du vol :";
        cin >> numeroVol;
    }while(!Vol::existVol(numeroVol));

    Vol* vol = Vol::getVol(numeroVol);

    cout << "Date actuel : " << vol->getDate()->getTempo() << endl;


    int jour, mois, annee;

    do{
        do{
            cout << "Saisir nouveau jour : ";
            cin >> jour;
        }while (jour < 0 || jour > 31);

        do{
            cout << "Saisir nouveau mois :";
            cin >>mois;
        }while(mois < 0 || mois > 12);

        do{
            cout << "Saisir nouvelle année :";
            cin >>annee;
        }while(annee < 2021);
    }while (!Date::controlerDate(jour, mois, annee));

    vol->getDate()->setJour(jour);
    vol->getDate()->setMois(mois);
    vol->getDate()->setAnnee(annee);

    cout << "modification effectuées";
}

void Administrateur::modifierHeureVol(){
    int numeroVol;
    do{
        cout << "Saisissez le numero du vol :";
        cin >> numeroVol;
    }while(!Vol::existVol(numeroVol));

    Vol* vol = Vol::getVol(numeroVol);

    cout << "Horaire actuel : " << vol->getDate()->getHoraire();

    int heure, minute;
    do{
        cout << "Saisir nouvelle heure : ";
        cin >> heure;
    }while (heure < 0 || heure > 24);

    do{
        cout << "Saisir nouvelles minutes :";
        cin >>minute;
    }while(minute < 0 || minute > 59);


    vol->getDate()->setHeure(heure);
    vol->getDate()->setMinute(minute);

    cout << "Modification effectuées" << endl;
}

void Administrateur::ajouterVol(){


}

void Administrateur::afficherVols(){


}

void Administrateur::afficherPassagersVol(){


}

void Administrateur::existVol(){


}

void Administrateur::ajouterPassager(){


}

void Administrateur::ajouterReservation(){


}

void Administrateur::ajouterDestination(){


}






























