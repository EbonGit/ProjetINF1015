#include "GestionnairePartie.h"

void GestionnairePartie::ajoutEchec(Case* c) {
	GestionnaireEchec* echec = new GestionnaireEchec(this, c);
	echecs_.push_back(echec);
}

GestionnairePartie::~GestionnairePartie() {
	for (Gestionnaire* g : echecs_) {
		delete g;
	}
	viderEchec();
}

void GestionnairePartie::testerEchec() {
	//pour chaque case possedant une piece enemmi: creer un gestionnaireEchec qui setEchec à son *parent si une des pieces peut manger le roi de la couleur du tour
}
