/*
 * helper.cpp
 *
 *  Created on: 23 nov. 2020
 *      Author: Thomas
 */

#include"helper.h"
#include<string>
#include<vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;


//=============== GESTION DES INT =================

// le string en paramètre est il un entier ?
bool Helper::is_number(const std::string& s){
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}


// transformation d'une chaine de caractère en entier
int Helper::to_int(const std::string& s){
	int i = std::atoi(s.c_str());
	return i;
}


// l'entier est il compris entre le min et le max ?
bool Helper::isValidInt(const int &i, int min, int max){
	if (max == -1){
		if (i<min){
			return false;
		}
		return true;
	}else{
		if ((i<min) || (i>max)){
			return false;
		}
		return true;
	}
}


// automatisation de saisie d'entier
void Helper::saisirEntier(int &value, int min, int max, std::string message){
	string buff;
	cout << message;
	cin >> buff;

	if(Helper::is_number(buff)){
		value = Helper::to_int(buff);
		if (Helper::isValidInt(value, min, max)){
			return;
		}else{
			Helper::saisirEntier(value, min, max, message);
		}
	}else{
		Helper::saisirEntier(value, min, max, message);
	}
}



// ============= GESTION DES STRING ===================

// retourne un vecteur de string
vector<string> Helper::split(const string& chaine, const string& separateur){
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do{
        pos = chaine.find(separateur, prev);
        if (pos == string::npos) pos = chaine.length();
        string token = chaine.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + separateur.length();
    }while (pos < chaine.length() && prev < chaine.length());

    return tokens;
}




































