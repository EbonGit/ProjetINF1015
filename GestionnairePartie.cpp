#include "GestionnairePartie.h"

void GestionnairePartie::ajoutEchec(Case* c) {
	GestionnaireEchec echec = GestionnaireEchec(this, c);
	echecs_.push_back(echec);
}

