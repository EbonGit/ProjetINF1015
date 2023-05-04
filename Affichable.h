#pragma once
#include <iostream>
using namespace std;

const std::string bleuBlanc("\033[0;34;47m");
const std::string bleuNoir("\033[0;34m");
const std::string rougeBlanc("\033[0;31;47m");
const std::string rougeNoir("\033[0;31m");
const std::string vertBlanc("\033[0;32;47m");
const std::string vertNoir("\033[0;32m");
const std::string violetBlanc("\033[0;35;47m");
const std::string violetNoir("\033[0;35m");

const std::string reset("\033[0m");

//mettre les couleurs dans un map<string, string>, mais plus facile à utiliser comme ça

class Affichable 
{
public:
	Affichable() = default;
	virtual void afficher() = 0;
	virtual ~Affichable() = default;

	
};

