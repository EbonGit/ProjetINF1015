#include "Reine.h"

Reine::Reine(bool estBlanc) : Piece(estBlanc) {
	std::function<bool(int, int, int, int)> f = [](int x, int y, int x_autre, int y_autre) -> bool { return (abs(x - x_autre) == abs(y - y_autre)) || (x == x_autre || y == y_autre); };
	strategie_.setStrat(f);
	nom_ = "Reine";
	besoinLigneDeVue = true;
}

void Reine::afficher() {
	if (estBlanc_) {
		std::cout << violet_blanc << "Q" << reset << " ";
	}
	else {
		std::cout << violet_noir << "Q" << reset << " ";
	}

};