#include "Tour.h"

void Tour::afficher() {
	if (estBlanc_) {
		std::cout << vert_blanc << "T" << reset << " ";
	}
	else {
		std::cout << vert_noir << "T" << reset << " ";
	}

};