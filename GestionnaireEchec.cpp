#include "GestionnaireEchec.h"

void GestionnaireEchec::selectionner(Case* c) {
	if (c->getPossedePiece()) {
		setCaseCourante(c);
		getTourDeJeu().setEstBlanc(c->piece_->estBlanc()); //set la couleur du tour afin de trouver les pièces adverses mangeables
		std::cout << c->piece_->nom() << " " << c->piece_->estBlanc() << endl;
		appliquerStrategie();
	}
	else {
		cout << "impossible de selectionner case vide" << endl;
	}
}

//ajouter methode qui test chaque case mangeable