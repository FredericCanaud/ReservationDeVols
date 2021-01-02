//
// Created by Freddy on 21/11/2020.
//

#include <iostream>
#include <map>
#include<vector>
#include<string>
#include <list>
#include "Passager.h"
#include "helper.h"
#include "manipulateurFichier.h"
using namespace std;

Passager::Passager() : Personne() {

}

Passager::Passager(string identifiant, string motDePasse, string nom, string prenom, int age, Titre titre, int numeroPasseport) : Personne(identifiant, motDePasse){
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
    this->titre = titre;
    this->numeroPasseport = numeroPasseport;
}

Passager* Passager::recherche(string identifiant){
    list<Passager*>::iterator it;

    // on parcours tous les passagers existant
    for (it = passagers.begin() ; it != passagers.end() ; it++){
        // si l'identifiant correspond
        if ((*it)->getIdentifiant() == identifiant){
            return (*it);  // on retourne l'adresse du passager
        }
    }

    // si on a rien trouver
    return nullptr;
}

Passager* Passager::getPassagerByPasseport(int numPasseport){
    list<Passager*>::iterator it;

    for (it = passagers.begin() ; it != passagers.end() ; it++){
        if ((*it)->getNumeroPasseport() == numPasseport){
            return (*it);
        }
    }
    return nullptr;
}

bool Passager::existNumPasseport(int numero){
    list<Passager*>::iterator it;

    for (it = passagers.begin() ; it != passagers.end() ; it++){
        if ((*it)->getNumeroPasseport() == numero){
            return true;
        }
    }
    return false;
}

string Passager::toString(){
    return this->nom + " " + this->prenom + " ; " + "passeport numero " + to_string(this->numeroPasseport);
}

// inscription à l'aéroport
Passager Passager::inscription() {

	// déclaration des variables
    string identifiant, motDePasse, confirmMotDePasse, nom, prenom, titre;
    int age, numeroPasseport;

    map<string,Titre> m;
    m["Monsieur"] = Titre::Monsieur;
    m["Madame"] = Titre::Madame;
    m["Mademoiselle"] = Titre::Mademoiselle;

    // création identifiant et mot de passe
    cout << "Entrez votre identifiant : " << endl;
    cin >> identifiant;

    cout << "Entrez votre mot de passe : " << endl;
    cin >> motDePasse;

    cout << "Confirmez votre mot de passe : " << endl;
    cin >> confirmMotDePasse;

    // vérification du mot de passe
    while(motDePasse != confirmMotDePasse){
        cout << "Les mots de passe saisis ne se correspondent pas !" << endl << "Entrez votre mot de passe : " << endl;
        cin >> motDePasse;
        cout << "Confirmez votre mot de passe : " << endl;
        cin >> confirmMotDePasse;
    }

    // création des informations personnelles
    // prénom
    cout << " Entrez votre nom : " << endl;
    cin >> nom;

    // nom
    cout << " Entrez votre prenom : " << endl;
    cin >> prenom;

    // age
    Helper::saisirEntier(age, 15, 150, "Entrez votre age : ");

    // titre
    cout << "Entrez votre titre (Monsieur, Madame ou Mademoiselle) : ";
    cin >> titre;

    // vérifiacation du titre
    while ((titre != "Monsieur") && (titre != "Madame") && (titre != "Mademoiselle")){
    	cout << " Erreur : Veuillez saisir un titre correct (Monsieur, Madame ou Mademoiselle) : " << endl;
        cin >> titre;
    }

    // numerot de passeport
    Helper::saisirEntier(numeroPasseport, 0, -1, "Entrez votre numero de passport :");

    // création du compte
    return Passager(identifiant, motDePasse, nom, prenom, age, m[titre], numeroPasseport);
}




// connection
Passager* Passager::connexion() {
    bool correct = false;
    Passager* p;


    string identifiantSaisi, motDePasseSaisi;
    cout <<" Entrez votre identifiant : " << endl;
    cin >> identifiantSaisi;
    cout <<" Entrez votre mot de passe : " << endl;
    cin >> motDePasseSaisi;


    // tant que le mot de passe n'est pas correct
    while(!correct){
        // itérateur sur la liste de passager
        list<Passager*>::iterator it;

        // pour chaque passager enregistré
        for (it = passagers.begin() ; it != passagers.end() ; it++){
            // si on trouve l'id et le mot de passe correspondant
            if (((*it)->getIdentifiant() == identifiantSaisi) && ((*it)->getMdp() == motDePasseSaisi)){
                p = (*it); // on set le passager à retourner
                correct = true; // la connection est correcte
            }
        }

        // si le mot de passe n'est pas correct
        if (!correct){
            cout <<" L'identifiant ou le mot de passe saisi est incorrect ! " << endl;
            cout <<" Entrez a nouveau votre identifiant : " << endl;
            cin >> identifiantSaisi;
            cout <<" Entrez a nouveau votre mot de passe : " << endl;
            cin >> motDePasseSaisi;
        }
    }

    // on retourne le pointeur vers le passager qui s'est connécté
    return p;
}




// ========== SAUVEGARDE =============

//string qui contient les informations à sauvegarder
string Passager::toSave(){
	string result = "";
	string s = ";"; //séparateur

	result += this->getIdentifiant() + s + this->getMdp() + s + this->getNom() + s + this->getPrenom() + s + to_string(this->getAge()) + s + this->titreString() + s + to_string(this->getNumeroPasseport());

	return result;
}

// sauvegarde les informations dans un txt
void Passager::save(list<Passager *> liste, string nomFichier) {
    // manipulateur de fichier
    ManipulateurFichier manip(nomFichier);

    // liste des informations à sauvegarder
    list<string> toSave;

    // itérateur sur la liste
    list<Passager*>::iterator it;

    // pour chaque passager
    for (it = liste.begin() ; it != liste.end() ; it++){
        // ajouter à la liste les informations à sauvegarder
        toSave.push_front((*it)->toSave()) ;
    }

    // écrire dans le fichier
    manip.ecrire(toSave);
}

// retourne une liste de passagers
list<Passager*> Passager::load(string nomFichier){
	// liste des passagers
	list<Passager*> passagers;

	// manipulateur de fichier
	ManipulateurFichier manip(nomFichier);

	// liste des données sauvegardées
	list<string> infos = manip.lireLignes();

	// itérateur sur les informations
	list<string>::iterator it;

	// création du titre avec une map
	map<string,Titre> m;
	m["Monsieur"] = Titre::Monsieur;
	m["Madame"] = Titre::Madame;
	m["Mademoiselle"] = Titre::Mademoiselle;

	// pour chaque lignes
	for (it = infos.begin() ; it != infos.end() ; it++){
	    // liste des champs de la ligne
		vector<string> ligne = Helper::split(*it, s);

		// itérateur sur les champs
		vector<string>::iterator itv = ligne.begin();

		// récupération des valeur des champs
		string identifiant = *itv;
		string mdp = *(itv+1);
		string nom = *(itv+2);
		string prenom = *(itv+3);
		int age = Helper::to_int(*(itv+4));
		Titre titre = m[*(itv+5)];
		int numPasseport = Helper::to_int(*(itv+6));

		// création du passager
		Passager *passager = new Passager(identifiant, mdp, nom, prenom, age, titre, numPasseport);

		//ajout du passager à la liste de passager
		passagers.push_front(passager);
	}


	return passagers;
}


////////////////////////////////
/// ACTION UTILISATEUR
///////////////////////////////

void Passager::reserverVol() {

}

void Passager::confirmerReservation() {
    int numReservation;

    do{
        Helper::saisirEntier(numReservation, 0, -1, "Saisissez le numero de la reservation a valide :");
    }while(!Reservation::existNumReservation(numReservation));

    Reservation* reservation = Reservation::getReservation(numReservation);

    reservation->confirmerReservation();

    cout << "Reservation numero " + to_string(numReservation) + " cofirmee\n" << endl;

}

void Passager::annulerReservation() {

}

void Passager::afficherReservations(){

}

void Passager::existReservation(){

}


























