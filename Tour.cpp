#include "Tour.h"

Tour::Tour(bool estBlanc) : Piece(estBlanc) {
	std::function<bool(int, int, int, int)> f = [](int x, int y, int x_autre, int y_autre) -> bool { return (x == x_autre || y == y_autre); };
	strategie_.setStrat(f);
	nom_ = "Tour";
}

void Tour::afficher() {
	if (estBlanc_) {
		std::cout << vert_blanc << "T" << reset << " ";
	}
	else {
		std::cout << vert_noir << "T" << reset << " ";
	}

};