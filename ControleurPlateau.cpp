#include "ControleurPlateau.h"
#include<iostream>

void ControleurPlateau::OnConfigReceived(int config) {
	std::cout << config << " was chosen" << std::endl;
	// TODO : effacer le plateau
	plateau_->chargerConfiguration(config);
	plateau_->afficher();
}