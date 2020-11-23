/*
 * manipulateurFichier.h
 *
 *  Created on: 23 nov. 2020
 *      Author: Thomas
 */

#ifndef CLASSES_MANIPULATEURFICHIER_H_
#define CLASSES_MANIPULATEURFICHIER_H_

#include<string>
#include<list>
using namespace std;

class Sauvegardable{
public:

	// retourne un string qui servira de sauvegarde
	virtual string toSave();
	//methode de sauvegarde à compléter
	static void save(list<Sauvegardable> liste, string nomFichier);

	virtual ~Sauvegardable();
};


// https://openclassrooms.com/fr/courses/1894236-programmez-avec-le-langage-c/1896398-lisez-et-modifiez-des-fichiers


class ManipulateurFichier{
private:
	string fichier; //fichier courant
public:
	ManipulateurFichier();
	ManipulateurFichier(string nomFichier);

	//sélectionne le fichier à utiliser
	void ouvrir(string nomFichier);

	// écrase le fichier et écrit les lignes
	void ecrire(list<string>);

	// ajoute une ligne à la fin
	void ecrire(string ligne);

	//retourne le fichier sous forme de chaine de caractères
	string lire();
};



#endif /* CLASSES_MANIPULATEURFICHIER_H_ */
