#include "Gestionnaire.h"
#include "Affichable.h"

Gestionnaire::Gestionnaire(Plateau* plateau, GestionnaireStatus* p) {
	plateau_ = plateau;
	status_ = p;

	grilleBool temp;
	for (int i = 0; i < 8; i++)
	{
		vector<bool> ligne;
		for (int j = 0; j < 8; j++)
		{
			ligne.push_back(false);
		}
		temp.push_back(ligne);
	}
	grilleStrategie = temp;
	grilleEnnemi = temp;
	grilleDeplacement = temp;
};

//si la case possède une piece et la piece de la couleur du tour
void Gestionnaire::selectionner(Case* c) {
	
	if (caseCourante_ != nullptr) {
		deplacer(c);

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				grilleDeplacement[i][j] = false;
				grilleEnnemi[i][j] = false;
				grilleStrategie[i][j] = false;
			}
		}
		return;
	}
	
	if (c->getPossedePiece() && (tourDeJeu_.estBlanc() == c->piece_->estBlanc())) {
		caseCourante_ = c;
		appliquerStrategie();
		afficherGrille();
	}
	else {
		cout << "impossible de selectionner case vide || pas le tour de cette couleur" << endl;
		status_->sendMessage("Attention", "impossible de selectionner case vide || pas le tour de cette couleur");
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
			if (grilleDeplacement[i][j] && verifierDeplacement(&(*plateau_)[i][j])) {
				std::cout << bleu_noir;
			}
			cout << grilleDeplacement[i][j] << reset << " ";
		}

		std::cout << "    ";

		for (int j = 0; j < 8; j++) //afficher grilleEnnemi
		{
			if (grilleEnnemi[i][j] && verifierDeplacement(&plateau_->operator[](i)[j])) {
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
			if (grilleStrategie[i][j] && !plateau_->operator[](i)[j].getPossedePiece()) { //si la case ne possède pas de piece et n'a pas de de ligne de vue obstrué
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
			plateau_->afficher();
			return;
		}

		if (grilleDeplacement[autre->y][autre->x]) {

			cout << "deplacement possible " << endl;
			autre->posseder(caseCourante_->piece_);
			caseCourante_->deposseder();
			++tourDeJeu_;
			deselectionner();
		}
		else if (grilleEnnemi[autre->y][autre->x]) {

			cout << "piece mange" << endl;
			delete autre->piece_;
			autre->deposseder();
			autre->posseder(caseCourante_->piece_);
			caseCourante_->deposseder();
			++tourDeJeu_;
			deselectionner();
		}
		else {

			cout << "deplacement impossible" << endl;
			deselectionner();
		}
	}
	else {
		cout << "pas de case dans caseCourante_" << endl;
	}

	plateau_->afficher();
}

bool Gestionnaire::verifierDeplacement(Case* autre) {

	bool pasObstruction = true;
	
	if (caseCourante_->piece_->getBesoinLigneDeVue()) {
		vector<pair<int, int>> cases = caseCourante_->coordonnees_points_entiers_droite(*autre);

		for (auto c : cases) {
			if (plateau_->operator[](c.second)[c.first].getPossedePiece()) {
				pasObstruction = false;
			}
		}
	}
	/*
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grilleStrategie[i][j] && !grilleDeplacement[i][j] && (caseCourante_->operator^(plateau_->operator[](i)[j])) != 0) { //si la case est un obstacle et n'est pas la caseCourante
				
				if (plateau_->operator[](i)[j].operator()(*autre, *caseCourante_)) {
					pasObstruction = false;
					//cout << plateau_->operator[](i)[j].piece_->nom() << endl;
				}
				
			}
		}
	}*/
	return pasObstruction;
}

void Gestionnaire::recupererEchecEnfant(bool echecEstBlanc) {
	if (echecEstBlanc) {
		setEchecB(true);
		status_->setStatus(status_->getCurrentStatus() + ", echec roi blanc");
		cout << "echec roi blanc" << endl;
		
	}
	else {
		setEchecN(true);
		status_->setStatus(status_->getCurrentStatus() + ", echec roi noir");
		cout << "echec roi noir" << endl;
	}
}