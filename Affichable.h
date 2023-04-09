#pragma once
#include <iostream>
#include "ChessBoard.h"
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

class Affichable
{
public:
	Affichable() = default;
	virtual void afficher() = 0;
	virtual ~Affichable() = default;

	void setQt(ChessBoard* cb) { qtGraphique = cb; };
	ChessBoard* getQt() { return qtGraphique; };
protected:
	ChessBoard* qtGraphique = nullptr;
};

