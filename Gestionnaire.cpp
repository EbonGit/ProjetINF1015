#include "Gestionnaire.h"
#include "Affichable.h"

//si la case possède une piece et la piece de la couleur du tour
void Gestionnaire::selectionner(Case* c) {
	if (c->getPossedePiece() && (tourDeJeu_.estBlanc() == c->piece_->estBlanc())) {
		caseCourante_ = c;
		appliquerStrategie();
		afficherGrille();
	}
	else {
		cout << "impossible de selectionner case vide || pas le tour de cette couleur" << endl;
	}
};

void Gestionnaire::appliquerStrategie() {
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
	}
	calculDeplacement();
	calculEnnemi();

}

//affichage juste pour la console
void Gestionnaire::afficherGrille() {
	

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

void Gestionnaire::calculDeplacement() {
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

void Gestionnaire::calculEnnemi() {
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

void Gestionnaire::deplacer(Case* autre) {
	if (caseCourante_ != nullptr) {

		if (!verifierDeplacement(autre)) {
			cout << "pas possible obstruction" << endl;
			deselectionner();
			return;
		}

		if (grilleDeplacement[autre->y][autre->x]) {

			cout << "deplacement possible " << endl;
			autre->posseder(caseCourante_->piece_);
			caseCourante_->deposseder();
			deselectionner();
			++tourDeJeu_;
		}
		else if (grilleEnnemi[autre->y][autre->x]) {

			cout << "piece mange" << endl;
			delete autre->piece_;
			autre->deposseder();
			autre->posseder(caseCourante_->piece_);
			caseCourante_->deposseder();
			deselectionner();
			++tourDeJeu_;
		}
		else {

			cout << "deplacement impossible" << endl;
		}
	}
	else {
		cout << "pas de case dans caseCourante_" << endl;
	}

	plateau_->afficher();
}

bool Gestionnaire::verifierDeplacement(Case* autre) {

	bool pasObstruction = true;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grilleStrategie[i][j] && !grilleDeplacement[i][j] && (caseCourante_->operator^(plateau_->operator[](i)[j])) != 0) { //si la case est un obstacle et n'est pas la caseCourante
				if (plateau_->operator[](i)[j].operator()(*autre, *caseCourante_)) {
					pasObstruction = false;
				}
			}
		}
	}
	return pasObstruction;
}

void Gestionnaire::recupererEchecEnfant(bool echecEstBlanc) {
	if (echecEstBlanc) {
		setEchecB(true);
		cout << "echec roi blanc" << endl;
	}
	else {
		setEchecN(true);
		cout << "echec roi noir" << endl;
	}
}