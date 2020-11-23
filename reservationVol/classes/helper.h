/*
 * helper.h
 *
 *  Created on: 23 nov. 2020
 *      Author: Thomas
 */

#ifndef CLASSES_HELPER_H_
#define CLASSES_HELPER_H_

#include<string>
#include <algorithm>

class Helper{

public:
	static bool is_number(const std::string& s);
	static int to_int(const std::string& s);
	static bool isValidInt(const int &i , int min, int max);
	static void saisirEntier(int &value, int min, int max, std::string message);
};



#endif /* CLASSES_HELPER_H_ */
