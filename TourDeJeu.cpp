#include "TourDeJeu.h"

TourDeJeu::TourDeJeu() {
	numeroTour_ = 1;
	tourEstBlanc_ = true;
	tourEstFini_ = false;
}

void TourDeJeu::operator++() {
	if (estBlanc()) {
		tourEstBlanc_ = false;
	}
	else {
		tourEstBlanc_ = true;
		tourEstFini_ = true;
	}
	if (estFini()) {
		numeroTour_++;
		tourEstFini_ = false;
	}
}
