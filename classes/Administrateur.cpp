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
    }while(!Vol::existNumero(numeroVol));

    Vol* vol = Vol::getVol(numeroVol);

    cout << "Date actuel : " << vol->getDate()->getTempo() << endl;


    int jour, mois, annee;

    do{
        Helper::saisirEntier(jour, 0, 31, "Saisir nouveau jour : ");

        Helper::saisirEntier(mois, 0, 12, "Saisir nouveau mois :");

        Helper::saisirEntier(annee, 2021, -1, "Saisir nouvelle annee :");

    }while (!Date::controlerDate(jour, mois, annee));

    vol->getDate()->setJour(jour);
    vol->getDate()->setMois(mois);
    vol->getDate()->setAnnee(annee);

    cout << "modification effectuees\n"<<endl;
}

void Administrateur::modifierHeureVol(){
    int numeroVol;
    do{
        cout << "Saisissez le numero du vol :";
        cin >> numeroVol;
    }while(!Vol::existNumero(numeroVol));

    Vol* vol = Vol::getVol(numeroVol);

    cout << "Horaire actuel : " << vol->getDate()->getHoraire() <<endl;

    int heure, minute;

    Helper::saisirEntier(heure, 0, 23, "Saisir nouvelle heure : ");

    Helper::saisirEntier(minute, 0, 59, "Saisir nouvelles minutes :");

    vol->getDate()->setHeure(heure);
    vol->getDate()->setMinute(minute);

    cout << "Modification effectuees" << endl;
}

void Administrateur::ajouterVol(){
    int numero, nbPlaces;
    float prix;
    int numDestination;
    Destination* destination;
    Date date;

    do{
        cout << "Saisissez le numero du vol :";
        cin >> numero;
    }while(Vol::existNumero(numero));

    Helper::saisirEntier(nbPlaces, 1, -1, "Saisissez le nombre de places maximales :");

    do{
        cout << "Saisissez le prix du billet :";
        cin >> prix;
    }while(prix < 0.0);

    list<Destination*>::iterator it;

    int i = 1;
    // affichage des destinations possibles
    for (it = destinations.begin() ; it != destinations.end() ; it++){
        cout << "destination " << i << " : " << (*it)->toString() << endl;
        i++;
    }

    Helper::saisirEntier(numDestination, 1, destinations.size(), "Choisir le numero de la destination :");

    it = destinations.begin();

    // on avance le curseur jusqu'au bon index
    int j;
    for (j =  0 ; j < numDestination ; j++){
        // empty
    }

    destination = (*it);


    date = Date::saisirDate();

    Vol* newVol = new Vol(numero, nbPlaces, prix, *destination, date);

    vols.push_front(newVol);

    cout << "Vol ajoute\n"<<endl;

    Vol::save(vols, "../sauvegarde/vols.txt");
}

void Administrateur::afficherVols(){
    Vol::afficherVols();
}

void Administrateur::afficherPassagersVol(){
    int numeroVol;
    do{
        cout << "Saisissez le numero du vol :";
        cin >> numeroVol;
    }while (!Vol::existNumero(numeroVol));

    Vol* vol = Vol::getVol(numeroVol);

    cout << "Passagers du vol numero " << vol->getNumero() << " :" << endl;

    if (!vol->getPassagersVol().empty()){
        list<Passager*>::iterator it;
        // pour chaque passager du vol
        for (it = vol->getPassagersVol().begin() ; it != vol->getPassagersVol().end() ; it++){
            cout << (*it)->toString() << endl;
        }
    }else{
        cout << "Il n'y a pas de passager sur ce vol\n"<<endl;
    }

}

void Administrateur::existVol(){
    int numeroVol;
    cout << "Saisissez le numero du vol a verifier :";
    cin >> numeroVol;

    bool exist = Vol::existNumero(numeroVol);

    if (exist){
        cout << "Le vol numero " << numeroVol << " existe\n" <<endl;
    }else{
        cout << "Le vol numero " << numeroVol << " n'existe pas\n" <<endl;
    }
}

void Administrateur::ajouterPassager(){
    // déclaration des variables
    string identifiant, motDePasse, confirmMotDePasse, nom, prenom, titre;
    int age, numeroPasseport;

    map<string,Titre> m;
    m["Monsieur"] = Titre::Monsieur;
    m["Madame"] = Titre::Madame;
    m["Mademoiselle"] = Titre::Mademoiselle;

    // création identifiant et mot de passe
    cout << "Entrez l'identifiant : " << endl;
    cin >> identifiant;

    cout << "Entrez le mot de passe : " << endl;
    cin >> motDePasse;

    cout << "Confirmez le mot de passe : " << endl;
    cin >> confirmMotDePasse;

    // vérification du mot de passe
    while(motDePasse != confirmMotDePasse){
        cout << "Les mots de passe saisis ne se correspondent pas !" << endl << "Entrez le mot de passe : " << endl;
        cin >> motDePasse;
        cout << "Confirmez le mot de passe : " << endl;
        cin >> confirmMotDePasse;
    }

    // création des informations personnelles
    // prénom
    cout << " Entrez le nom : " << endl;
    cin >> nom;

    // nom
    cout << " Entrez le prenom : " << endl;
    cin >> prenom;

    // age
    Helper::saisirEntier(age, 15, 150, "Entrez l'age : ");

    // titre
    cout << "Entrez le titre (Monsieur, Madame ou Mademoiselle) : ";
    cin >> titre;

    // vérifiacation du titre
    while ((titre != "Monsieur") && (titre != "Madame") && (titre != "Mademoiselle")){
        cout << " Erreur : Veuillez saisir un titre correct (Monsieur, Madame ou Mademoiselle) : " << endl;
        cin >> titre;
    }

    // numerot de passeport
    Helper::saisirEntier(numeroPasseport, 0, -1, "Entrez le numero de passport :");

    // création du compte
    passagers.push_front(new Passager(identifiant, motDePasse, nom, prenom, age, m[titre], numeroPasseport));

    Passager::save(passagers, "../sauvegarde/passagers.txt");

    cout << "Passager ajoute\n" << endl;
}

void Administrateur::ajouterReservation(){
    int numeroReservation, numeroPasseport, numeroVol;

    do{
        Helper::saisirEntier(numeroReservation, 1, -1, "Saisissez le numero pour la reservation :");
    }while(Reservation::existNumReservation(numeroReservation));

    do{
        Helper::saisirEntier(numeroPasseport, 0, -1, "Saisissez le numero du passeport :");
    }while(!Passager::existNumPasseport(numeroPasseport));

    do{
        Helper::saisirEntier(numeroVol, 0, -1, "Saisissez le numero du vol :");
    }while(!Vol::existNumero(numeroVol));

    reservations.push_front(new Reservation(numeroReservation, numeroPasseport, numeroVol));

    Vol* vol = Vol::getVol(numeroVol);
    vol->ajouterPassager(Passager::getPassagerByPasseport(numeroPasseport));

    Reservation::save(reservations, "../sauvegarde/reservations.txt");

    cout << "Reservation ajoutee\n" << endl;
}

void Administrateur::ajouterDestination(){
    string villeDep, villeArr;

    cout << "Saisissez la ville de depart :";
    cin >> villeDep;

    cout << "Saisissez la ville d'arrivee :";
    cin >> villeArr;

    destinations.push_front(new Destination(villeDep, villeArr));

    Destination::save(destinations, "../sauvegarde/destinations.txt");

    cout << "Destination ajoutee\n" << endl;
}






























