#include "Plateau.h"

Plateau::Plateau() {
	init();
}

void Plateau::init() {
	bool estBlanc = true;
	for (int j = 0; j < 8; j++)
	{
		vector<Case> ligne;
		for (int i = 0; i < 8; i++)
		{
			Case c = Case(i, j, estBlanc);
			ligne.push_back(c);
			estBlanc = !estBlanc; //une case sur deux est blanche ou noire
		}
		estBlanc = !estBlanc;
		cases_.push_back(ligne);
	}

}

void Plateau::afficher() {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cases_[i][j].afficher();
		}
		std::cout << std::endl;
	}
	std::cout << endl;
}

vector<vector<Case>>& Plateau::get() {
	return cases_;
}