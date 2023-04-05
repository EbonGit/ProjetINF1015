#include "Case.h"

Case::Case(int pos_x, int pos_y, bool estBlanc) {
	x = pos_x;
	y = pos_y;
	estBlanc_ = estBlanc;
}

Case::~Case() {
	if (piece_ != nullptr) {
		delete piece_;
		piece_ = nullptr;
	}
}

void Case::posseder(Piece* ptr) { 
	piece_ = ptr; 
	possedePiece_ = true;
}

void Case::deposseder() { 
	piece_ = nullptr; 
	possedePiece_ = false;
}

void Case::afficher() {
	if (possedePiece_) {
		piece_->afficher(); //afficher la pièce
	}
	else {
		std::cout << estBlanc() << " ";
	}
}