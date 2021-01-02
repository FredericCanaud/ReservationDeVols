//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_VOL_H
#define RESERVATIONDEVOLS_VOL_H


#include "Destination.h"
#include "Date.h"
#include "manipulateurFichier.h"
#include "Passager.h"
#include <list>



class Vol : public Sauvegardable{
public:
    //constructeur par défault
    Vol();

    //constructeurs
    Vol(int numero, int nombrePlacesMaximal, float prix);
    Vol(int numero, int nombrePlacesMaximal, float prix, Destination destination, Date date);

    // actions utilisateur
    static bool existVol(int numeroVol);
    static void afficherVols();

    void afficher() const;
    void ajouterPassager(Passager* passager);

    // retourne un string qui servira de sauvegarde
    string toSave() override;

    //methode de sauvegarde
    static void save(list<Vol *> liste, string nomFichier);
    static list<Vol*> load(string nomFichier);

    // GETTERS
    int getNumero() const;

    int getNombrePlacesMaximal() const;

    float getPrix() const;

    const Destination* getDestination() const;

    const Date* getDate() const;

    static Vol* getVol(int numeroVol);

private:
    int numero;
    int nombrePlacesMaximal;
    float prix;
    Destination destination;
    Date date;
    list<Passager*> passagersVol;

};

// variables globales
extern string s;
extern list<Vol*> vols;
extern list<Passager*> passagers;

#endif //RESERVATIONDEVOLS_VOL_H
