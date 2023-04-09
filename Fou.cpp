#include "Fou.h"

Fou::Fou(bool estBlanc) : Piece(estBlanc) {
	std::function<bool(int, int, int, int)> f = [](int x, int y, int x_autre, int y_autre) -> bool { return (abs(x - x_autre) == abs(y - y_autre)); };
	strategie_.setStrat(f);
	nom_ = "Fou";
	besoinLigneDeVue = true;
}

void Fou::afficher() {
	if (estBlanc_) {
		std::cout << rouge_blanc << "F" << reset << " ";
	}
	else {
		std::cout << rouge_noir << "F" << reset << " ";
	}

};