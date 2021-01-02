//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_PASSAGER_H
#define RESERVATIONDEVOLS_PASSAGER_H

#include "Personne.h"
#include "Reservation.h"
#include "manipulateurFichier.h"
#include <string>
#include <vector>
#include<list>
using namespace std;

enum class Titre {Monsieur, Madame, Mademoiselle};

class Passager : public Personne, public virtual Sauvegardable{
private:
    string nom;
    string prenom;
    int age;
    Titre titre;
    int numeroPasseport;

public:
    // constructeur par défault
    Passager();

    // constructeur
    Passager(string, string, string, string, int, Titre, int);

    // actions utilisateurs
    void reserverVol();
    // afficher vols //
    void confirmerReservation();
    void annulerReservation();
    void afficherReservations();
    void existReservation();
    static Passager inscription();
    static Passager* connexion();

    // fonction pour la sauvegarde
    string toSave() override;
    static void save(list<Passager *> liste, string nomFichier);
    static list<struct Passager *> load(string nomFichier);

    // GETTERS
    string getNom(){
    	return this->nom;
    }
    string getPrenom(){
		return this->prenom;
	}
    int getAge(){
    	return this->age;
    }
    Titre getTitre(){
    	return this->titre;
    }
    int getNumeroPasseport(){
    	return this->numeroPasseport;
    }


    string toString();

    static Passager* recherche(string identifiant);
    static Passager* getPassagerByPasseport(int numPasseport);
    static bool existNumPasseport(int numero);

    string titreString(){
    	switch(this->titre){
			case Titre::Monsieur:
				return "Monsieur";
				break;
			case Titre::Madame:
				return "Madame";
				break;
    		case Titre::Mademoiselle:
				return "Mademoiselle";
				break;
    	}
    	return "Monsieur";
    }
};

extern string s;  // séparateur pour les sauvegardes
extern list<Passager*> passagers;
extern list<Reservation*> reservations;
extern Passager* utilisateur;

#endif //RESERVATIONDEVOLS_PASSAGER_H
