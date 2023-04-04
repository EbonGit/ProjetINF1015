#include "Roi.h"

void Roi::afficher() {
	if (estBlanc_) {
		std::cout << bleu_blanc << "R" << reset << " ";
	}
	else {
		std::cout << bleu_noir << "R" << reset << " ";
	}

};