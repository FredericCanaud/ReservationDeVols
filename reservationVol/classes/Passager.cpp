//
// Created by Freddy on 21/11/2020.
//

#include <iostream>
#include <map>
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

void Passager::reserverVol() {

}

void Passager::confirmerReservation() {

}

void Passager::annulerReservation() {

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


    while(Titre::Monsieur >= m[titre] && Titre::Mademoiselle <= m[titre]){

    }

    // numerot de passeport
    Helper::saisirEntier(numeroPasseport, 0, -1, "Entrez votre numero de passport :");

    // création du compte
    return Passager(identifiant, motDePasse, nom, prenom, age, m[titre], numeroPasseport);
}




// connection
Passager Passager::connexion(const vector<Passager>& passagers) {
    bool correct = false;
    Passager p;

    string identifiantSaisi, motDePasseSaisi;
    cout <<" Entrez votre identifiant : " << endl;
    cin >> identifiantSaisi;
    cout <<" Entrez votre mot de passe : " << endl;
    cin >> motDePasseSaisi;
    while(!correct){
        for (const Passager& passager : passagers){
            if (passager.getIdentifiant() == identifiantSaisi && passager.getMotDePasse() == motDePasseSaisi){
                p = passager;
                correct = true;
            }
        }
        if(!correct){
            cout <<" L'identifiant ou le mot de passe saisi est incorrect ! " << endl;
            cout <<" Entrez a nouveau votre identifiant : " << endl;
            cin >> identifiantSaisi;
            cout <<" Entrez a nouveau votre mot de passe : " << endl;
            cin >> motDePasseSaisi;
        }
    }
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


// fonction pour sauvegarder les passagers
void Passager::save(list<Passager> passagers, string nomFichier){
	// manipulateur de fichier
	ManipulateurFichier manip(nomFichier);

	// liste des informations à sauvegarder
	list<string> toSave;

	// itérateur sur la liste
	list<Passager>::iterator it;

	// pour chaque passager
	for (it = passagers.begin() ; it != passagers.end() ; it++){
		// ajouter à la liste les informations à sauvegarder
		toSave.push_back(it->toSave()) ;
	}

	// écrire dans le fichier
	manip.ecrire(toSave);
}


// retourne une liste de passagers
list<Sauvegardable> Passager::load(string nomFichier){
	// liste des passagers
	list<Sauvegardable> passagers;

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
		string separateur = ";";
		string identifiant = it->substr(0, it->find(separateur));
		string mdp = it->substr(1, it->find(separateur));
		string nom = it->substr(2, it->find(separateur));
		string prenom = it->substr(3, it->find(separateur));
		int age = Helper::to_int(it->substr(4, it->find(separateur)));
		Titre titre = m[it->substr(5, it->find(separateur))];
		int numPasseport = Helper::to_int(it->substr(6, it->find(separateur)));

		Sauvegardable *passager = new Passager(identifiant, mdp, nom, prenom, age, titre, numPasseport);

		passagers.push_front(*passager);
	}


	return passagers;
}



























