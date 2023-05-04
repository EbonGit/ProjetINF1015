#include "Tour.h"

Tour::Tour(bool estBlanc) : Piece(estBlanc) {
	std::function<bool(int, int, int, int)> f = [](int x, int y, int x_autre, int y_autre) -> bool { return (x == x_autre || y == y_autre); };
	strategie_.setStrat(f);
	nom_ = "Tour";
	besoinLigneDeVue = true;
}

void Tour::afficher() {
	if (estBlanc_) {
		std::cout << vertBlanc << "T" << reset << " ";
	}
	else {
		std::cout << vertNoir << "T" << reset << " ";
	}

};