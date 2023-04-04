#pragma once
#include <iostream>
using namespace std;
const std::string bleu_blanc("\033[0;34;47m");
const std::string bleu_noir("\033[0;34m");

const std::string reset("\033[0m");
class Affichable
{
public:
	Affichable() = default;
	virtual void afficher() = 0;
	virtual ~Affichable() = default;
};

