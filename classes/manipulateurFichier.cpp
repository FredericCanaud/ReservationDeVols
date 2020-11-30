/*
 * manipulateurFichier.cpp
 *
 *  Created on: 23 nov. 2020
 *      Author: Thomas
 */

#include "manipulateurFichier.h"
#include <iostream>
#include <fstream>
using namespace std;


// =========== SAUVEGARDABLE =============
/*Sauvegardable::Sauvegardable(){

}*/

Sauvegardable::~Sauvegardable(){

}

// retourne un string qui servira de sauvegarde
string Sauvegardable::toSave(){
	return "mauvaise classe (ce toSave() vient de Sauvegardable) lol ";
}

//========== MANIPULATEUR DE FICHIER ============

ManipulateurFichier::ManipulateurFichier(){
	this->fichier = "undefined";
}

ManipulateurFichier::ManipulateurFichier(string nomFichier){
	this->fichier = nomFichier;
}

void ManipulateurFichier::ouvrir(string nomFichier){
	this->fichier = nomFichier;
}


void ManipulateurFichier::ecrire(list<string> lignes){
	list<string>::iterator it;

	ofstream monFlux(this->fichier.c_str()); //Ouverture d'un fichier en écriture

	if(monFlux){
		// pour chaque ligne (chaque Objet)
		for (it = lignes.begin() ; it != lignes.end() ; it++){
			monFlux << *it << endl;
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." + this->fichier + " en écriture" << endl;
	}

	monFlux.close();
}


void ManipulateurFichier::ecrire(string ligne){
	ofstream monFlux(this->fichier.c_str(), ios::app);

	if(monFlux){
		monFlux << ligne << endl;
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." + this->fichier + " en écriture" << endl;
	}
	monFlux.close();
}


string ManipulateurFichier::lire(){
	ifstream monFlux(this->fichier.c_str());  //Ouverture d'un fichier en lecture
	string result ="";

	if(monFlux){
		string ligne; //Une variable pour stocker les lignes lues

		while(getline(monFlux, ligne)) //Tant qu'on n'est pas à la fin, on lit
		{
			result += ligne;
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier " + this->fichier + " en lecture" << endl;
	}
	monFlux.close();

	return result;
}


list<string> ManipulateurFichier::lireLignes(){
	list<string> passagers;
	ifstream monFlux(this->fichier.c_str());  //Ouverture d'un fichier en lecture

	if(monFlux){
		string ligne; //Une variable pour stocker les lignes lues

		while(getline(monFlux, ligne)) //Tant qu'on n'est pas à la fin, on lit
		{
			passagers.push_back(ligne);
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier " + this->fichier + " en lecture" << endl;
	}
	monFlux.close();

	return passagers;
}







