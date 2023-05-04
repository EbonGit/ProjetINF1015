#include "Plateau.h"

Plateau::Plateau() {
	init();
	chargerConfiguration(0);
}

void Plateau::init() {
	bool estBlanc = true;
	for (int j = 0; j < nombreCaseColonne; j++)
	{
		vector<Case> ligne;
		for (int i = 0; i < nombreCaseLigne; i++)
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
	
	for (int i = 0; i < nombreCaseColonne; i++)
	{
		for (int j = 0; j < nombreCaseLigne; j++)
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

void Plateau::chargerConfiguration(int config) {
	const bool blanc = true;

	switch (config) {
	case 0:
		// Queens only
		cases_[0][7].posseder(new Reine(blanc));
		cases_[1][0].posseder(new Reine(!blanc));
		cases_[4][1].posseder(new Roi(!blanc));
		cases_[5][4].posseder(new Reine(blanc));
		cases_[6][5].posseder(new Roi(blanc));
		cases_[7][0].posseder(new Reine(blanc));
		break;

	case 1:
		// Queen vs two rooks
		cases_[0][7].posseder(new Roi(!blanc));
		cases_[0][6].posseder(new Tour(!blanc));
		cases_[1][6].posseder(new Tour(!blanc));
		cases_[7][0].posseder(new Reine(blanc));
		cases_[7][7].posseder(new Roi(blanc));
		break;

	case 2:
		// Two rooks vs two minor pieces
		cases_[1][5].posseder(new Roi(!blanc));
		cases_[2][6].posseder(new Fou(!blanc));
		cases_[3][4].posseder(new Fou(!blanc));
		cases_[6][3].posseder(new Tour(blanc));
		cases_[7][3].posseder(new Tour(blanc));
		cases_[7][2].posseder(new Roi(blanc));
		break;
	}
}

void Plateau::viderPlateau() {
	for (int i = 0; i < nombreCaseColonne; i++)
	{
		for (int j = 0; j < nombreCaseLigne; j++)
		{
			if(cases_[i][j].getPossedePiece() == true)
				cases_[i][j].reset();
		}
	}
}