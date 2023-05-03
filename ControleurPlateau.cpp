#include "ControleurPlateau.h"

void ControleurPlateau::OnConfigReceived(int config) {
	plateau_->viderPlateau();
	plateau_->chargerConfiguration(config);
	plateau_->afficher();

	TourDeJeu tdj;
	gestionnaire_->setTourDeJeu(tdj);
}