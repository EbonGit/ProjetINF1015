#include "Case.h"

Case::Case(int pos_x, int pos_y, bool estBlanc) {
	x = pos_x;
	y = pos_y;
	estBlanc_ = estBlanc;
}

void Case::afficher() {
	std::cout << estBlanc() << " ";
}