#include "GestionnairePartie.h"

void GestionnairePartie::ajoutEchec(Case* c) {
	GestionnaireEchec* echec = new GestionnaireEchec(this, c);
	echecs_.push_back(echec);
}

GestionnairePartie::~GestionnairePartie() {
	viderEchec();
}

void GestionnairePartie::viderEchec() {
	for (Gestionnaire* g : echecs_) {
		delete g;
	}
	echecs_.clear();
}

void GestionnairePartie::deplacer(Case* c) {
	sacrifice_ = false;
	sacrificeRoi(c);
	Gestionnaire::deplacer(c);
	testerEchec();
}

//appelé avant le changement de couleur
void GestionnairePartie::testerEchec() {
	//pour chaque case possedant une piece enemmi: creer un gestionnaireEchec qui setEchec à son *parent si une des pieces peut manger le roi de la couleur du tour
	setEchecB(false);
	setEchecN(false);
	
	for (int i = 0; i < nombreCaseLigne; i++)
	{
		for (int j = 0; j < nombreCaseColonne; j++)
		{
			if (getPlateau()->operator[](i)[j].getPossedePiece()) { //considere unqiuement les cases avec des pièces
				ajoutEchec(&getPlateau()->operator[](i)[j]);
			}
		}
	}

	for (Gestionnaire* echec : echecs_) {
		dynamic_cast<GestionnaireEchec*>(echec)->tester();
	}
	std::cout << endl;
	viderEchec();
}

void GestionnairePartie::sacrificeRoi(Case* c) {
	Piece* p = c->piece_;
	
	c->deposseder();
	c->posseder(getCaseCourante()->piece_);
	getCaseCourante()->deposseder();

	testerEchec();
	if ((getEchecB() && getTourDeJeu().estBlanc()) || (getEchecN() && !getTourDeJeu().estBlanc())) {
		sacrifice_ = true;
	}
	else {
		sacrifice_ = false;
	}

	getCaseCourante()->posseder(c->piece_);
	c->deposseder();
	if (p != nullptr) {
		c->posseder(p);
	}
	
}


