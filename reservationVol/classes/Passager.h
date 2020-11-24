//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_PASSAGER_H
#define RESERVATIONDEVOLS_PASSAGER_H

#include "Personne.h"
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
    Passager();
    Passager(string, string, string, string, int, Titre, int);
    void reserverVol();
    void confirmerReservation();
    void annulerReservation();

    static Passager inscription();
    static Passager connexion(const vector<Passager>& passagers);

    virtual string toSave() override;
    static void save(list<Passager>, string nomFichier);
    static list<Sauvegardable> load(string nomFichier);

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
    Passager* thisu(){
    	return this;
    }

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


#endif //RESERVATIONDEVOLS_PASSAGER_H
