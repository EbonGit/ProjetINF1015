#include "Reine.h"

Reine::Reine(bool estBlanc) : Piece(estBlanc) {
	std::function<bool(int, int, int, int)> f = [](int x, int y, int x_autre, int y_autre) -> bool { return (abs(x - x_autre) == abs(y - y_autre)) || (x == x_autre || y == y_autre); };
	strategie_.setStrat(f);
	nom_ = "Reine";
}

void Reine::afficher() {
	if (estBlanc_) {
		std::cout << bleu_blanc << "R" << reset << " ";
	}
	else {
		std::cout << bleu_noir << "R" << reset << " ";
	}

};