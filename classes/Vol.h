//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_VOL_H
#define RESERVATIONDEVOLS_VOL_H


#include "Destination.h"
#include "Date.h"
#include "manipulateurFichier.h"
#include <list>



class Vol : public Sauvegardable{
public:
    //constructeur par défault
    Vol();

    //constructeurs
    Vol(int numero, int nombrePlacesMaximal, float prix);
    Vol(int numero, int nombrePlacesMaximal, float prix, Destination destination, Date date);

    // actions utilisateur
    bool recherche(int numeroVol) const;
    Vol ajouterVol(int numero, int nombrePlacesMaximal, float prix);
    static void afficherVols();

    void afficher() const;

    // retourne un string qui servira de sauvegarde
    string toSave() override;

    //methode de sauvegarde
    static void save(list<Vol *> liste, string nomFichier);
    static list<Vol*> load(string nomFichier);

    // GETTERS
    int getNumero() const;

    int getNombrePlacesMaximal() const;

    float getPrix() const;

    const Destination getDestination() const;

    const Date getDate() const;

private:
    int numero;
    int nombrePlacesMaximal;
    float prix;
    Destination destination;
    Date date;


};

// variables globales
extern string s;
extern list<Vol*> vols;

#endif //RESERVATIONDEVOLS_VOL_H
