#include "Fou.h"

void Fou::afficher() {
	if (estBlanc_) {
		std::cout << rouge_blanc << "F" << reset << " ";
	}
	else {
		std::cout << rouge_noir << "F" << reset << " ";
	}

};