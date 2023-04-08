#include "GestionnaireEchec.h"

void GestionnaireEchec::selectionner(Case* c) {
	if (c->getPossedePiece()) {
		setCaseCourante(c);
		getTourDeJeu().setEstBlanc(c->piece_->estBlanc()); //set la couleur du tour afin de trouver les pièces adverses mangeables
		//std::cout << c->piece_->nom() << " " << c->piece_->estBlanc() << endl;
		appliquerStrategie();
	}
	else {
		cout << "impossible de selectionner case vide" << endl;
	}
}

//ajouter methode qui test chaque case mangeable
void GestionnaireEchec::tester() {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grilleEnnemi[i][j]) {
				if (getPlateau()->operator[](i)[j].piece_->nom() == "Roi" && verifierDeplacement(&getPlateau()->operator[](i)[j])) {//est Roi adverse
					if (getTourDeJeu().estBlanc()) {
						setEchecN(true);
					}
					else {
						setEchecB(true);
					}
					cout << getCaseCourante()->piece_->nom() << " " << getTourDeJeu().estBlanc() << endl;
					remonterEchecParent();
				}
			}
		}
	}
}

void GestionnaireEchec::remonterEchecParent() {
	if (getParent()->getParent() == nullptr) { //si le parent de mon parent est un pointeur null alors je suis un gestionnairePartie
		getParent()->recupererEchecEnfant(!getTourDeJeu().estBlanc());
	}
}