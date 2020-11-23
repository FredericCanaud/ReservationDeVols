/*
 * helper.cpp
 *
 *  Created on: 23 nov. 2020
 *      Author: Thomas
 */

#include"helper.h"
#include<string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;


bool Helper::is_number(const std::string& s){
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int Helper::to_int(const std::string& s){
	int i = std::atoi(s.c_str());
	return i;
}

bool Helper::isValidInt(const int &i){
	if (i<=0){
		return false;
	}
	return true;
}

void Helper::saisirEntier(int &value, std::string message){
	string buff;
	cout << message;
	cin >> buff;

	if(Helper::is_number(buff)){
		value = Helper::to_int(buff);
		if (Helper::isValidInt(value)){
			return;
		}else{
			Helper::saisirEntier(value, message);
		}
	}else{
		Helper::saisirEntier(value, message);
	}
}
