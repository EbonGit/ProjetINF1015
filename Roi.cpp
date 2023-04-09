#include "Roi.h"

Roi::Roi(bool estBlanc) : Piece(estBlanc) {
	std::function<bool(int, int, int, int)> f = [](int x, int y, int x_autre, int y_autre) -> bool { return (abs(x - x_autre) <= 1 && abs(y - y_autre) <= 1); };
	strategie_.setStrat(f);
	nom_ = "Roi";
	besoinLigneDeVue = true;
}

void Roi::afficher() {
	if (estBlanc_) {
		std::cout << bleu_blanc << "R" << reset << " ";
	}
	else {
		std::cout << bleu_noir << "R" << reset << " ";
	}

};