//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_VOL_H
#define RESERVATIONDEVOLS_VOL_H

class Passager;

#include "Destination.h"
#include "Date.h"
#include "manipulateurFichier.h"
#include "Passager.h"
#include <list>
#include <string>



class Vol : public Sauvegardable{
public:
    //constructeur par défault
    Vol();

    //constructeurs
    Vol(int numero, int nombrePlacesMaximal, float prix);
    Vol(int numero, int nombrePlacesMaximal, float prix, Destination destination, Date date);

    // actions utilisateur
    static void afficherVols();


    void afficher() const;
    void ajouterPassager(Passager* passager);
    static bool existNumero(int numero);

    // retourne un string qui servira de sauvegarde
    string toSave() override;

    //methode de sauvegarde
    static void save(list<Vol *> liste, string nomFichier);
    static list<Vol*> load(string nomFichier);

    // GETTERS
    int getNumero() const;

    int getNombrePlacesMaximal() const;

    float getPrix() const;

    list<Passager*> getPassagersVol();

    Destination* getDestination() ;

    Date* getDate() ;

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


#endif //RESERVATIONDEVOLS_VOL_H
