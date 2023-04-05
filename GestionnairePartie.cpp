#include "GestionnairePartie.h"
#include "Affichable.h"

void GestionnairePartie::appliquerStrategie() {
	if (caseCourante_->getPossedePiece()) {
		
		grilleBool temp;
		for (int i = 0; i < 8; i++)
		{
			vector<bool> ligne;
			for (int j = 0; j < 8; j++)
			{
				if (caseCourante_->piece_->getStrat().appliquer(caseCourante_->x, caseCourante_->y, j, i)) {
					ligne.push_back(true);
				}
				else {
					ligne.push_back(false);
				}
			}
			temp.push_back(ligne);

		}

		grilleStrategie = temp;
		afficherGrille();
	}


}

void GestionnairePartie::afficherGrille() {
	calculDeplacement();
	calculEnnemi();
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) //afficher grilleStrategie
		{
			if (grilleStrategie[i][j]) {
				std::cout << vert_noir;
			}
			cout << grilleStrategie[i][j] << reset << " ";
		}

		std::cout << "    ";

		for (int j = 0; j < 8; j++) //afficher grilleDeplacement
		{
			if (grilleDeplacement[i][j]) {
				std::cout << bleu_noir;
			}
			cout << grilleDeplacement[i][j] << reset << " ";
		}

		std::cout << "    ";

		for (int j = 0; j < 8; j++) //afficher grilleEnnemi
		{
			if (grilleEnnemi[i][j]) {
				std::cout << rouge_noir;
			}
			cout << grilleEnnemi[i][j] << reset << " ";
		}

		std::cout << std::endl;
	}
	std::cout << endl;
}

void GestionnairePartie::calculDeplacement() {
	grilleBool temp;
	for (int i = 0; i < 8; i++)
	{
		vector<bool> ligne;
		for (int j = 0; j < 8; j++)
		{
			if (grilleStrategie[i][j] && !plateau_->operator[](i)[j].getPossedePiece()) { //si la case ne possède pas de piece
				ligne.push_back(true);
			}
			else {
				ligne.push_back(false);
			}
		}
		temp.push_back(ligne);
	}
	grilleDeplacement = temp;
}

void GestionnairePartie::calculEnnemi() {
	grilleBool temp;
	for (int i = 0; i < 8; i++)
	{
		vector<bool> ligne;
		for (int j = 0; j < 8; j++)
		{
			if (grilleStrategie[i][j] && !grilleDeplacement[i][j]) { //si la case est ennemi cad la case possede une pièce de la couleur opposé à la piece de la case courante
				if (caseCourante_->piece_->estBlanc() != plateau_->operator[](i)[j].piece_->estBlanc()) {
					ligne.push_back(true);
				}
				else {
					ligne.push_back(false);
				}
			}
			else {
				ligne.push_back(false);
			}
		}
		temp.push_back(ligne);
	}
	grilleEnnemi = temp;
}