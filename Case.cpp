#include "Case.h"

//convertir bool en string pour le nom du .png de la piece
std::string bool_en_string(bool b)
{
	if (b) {
		return "1";
	}
	return "0";
}

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

int Case::operator^(const Case& autre) const{
	return sqrt(pow(x - autre.x, 2) + pow(y - autre.y, 2));
}

bool Case::operator()(const Case& p1, const Case& p2) const {
	if ((*this).operator^(p1) == 0 || (*this).operator^(p2) == 0) {
		return false;
	}
	
	int minX = std::min(p1.x, p2.x);
	int maxX = std::max(p1.x, p2.x);
	int minY = std::min(p1.y, p2.y);
	int maxY = std::max(p1.y, p2.y);
	return (x >= minX && x <= maxX && y >= minY && y <= maxY);
}

void Case::posseder(Piece* ptr) { 
	piece_ = ptr; 
	piece_->setQt(getQt());
	possedePiece_ = true;
}

void Case::deposseder() { 
	piece_->setQt(nullptr);
	piece_ = nullptr; 
	possedePiece_ = false;
}

void Case::afficher() {
	if (possedePiece_) {
		piece_->afficher(); //afficher la pièce
		string nomPiece = piece_->nom() + bool_en_string(piece_->estBlanc());
		qtGraphique->dessinerPiece(x, y, nomPiece);
	}
	else {
		std::cout << estBlanc() << " ";
	}
}