#pragma once
#include <iostream>
using namespace std;

const std::string bleu_blanc("\033[0;34;47m");
const std::string bleu_noir("\033[0;34m");
const std::string rouge_blanc("\033[0;31;47m");
const std::string rouge_noir("\033[0;31m");
const std::string vert_blanc("\033[0;32;47m");
const std::string vert_noir("\033[0;32m");
const std::string violet_blanc("\033[0;35;47m");
const std::string violet_noir("\033[0;35m");

const std::string reset("\033[0m");

//mettre les couleurs dans un map<string, string>, mais plus facile à utiliser comme ça

class Affichable 
{
public:
	Affichable() = default;
	virtual void afficher() = 0;
	virtual ~Affichable() = default;

	
};

