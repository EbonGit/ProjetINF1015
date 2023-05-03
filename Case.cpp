#include "Case.h"

using iter::range;

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

bool Case::operator()(const Case& p1, const Case& p2) const { //return true si this est entre p1 et p2
	if ((*this).operator^(p1) == 0 || (*this).operator^(p2) == 0) {
		return false;
	}

	int minX = std::min(p1.x, p2.x);
	int maxX = std::max(p1.x, p2.x);
	int minY = std::min(p1.y, p2.y);
	int maxY = std::max(p1.y, p2.y);
	return (x >= minX && x <= maxX && y >= minY && y <= maxY);
}

vector<pair<int, int>> Case::coordonnees_points_entiers_droite(const Case& c1) {
	float deltaX = c1.x - this->x;
	float deltaY = c1.y - this->y;
	float pente = deltaY / deltaX;
	float origine = c1.y - pente * c1.x;

	//cout << pente << " " << origine << endl;
	vector<pair<int, int>> liste_points;

	int x_min, x_max;

	if (c1.x < this->x) {
		x_min = c1.x;
		x_max = this->x;
	}
	else {
		x_min = this->x;
		x_max = c1.x;
	}

	int y_min, y_max;
	if (c1.y < this->y) {
		y_min = c1.y;
		y_max = this->y;
	}
	else {
		y_min = this->y;
		y_max = c1.y;
	}

	if (c1.x == this->x) {
		x = c1.x;
		for (int y : range(y_min + 1, y_max)) {
			std::pair <int, int> point(x, y);
			liste_points.push_back(point);
		}
		return liste_points;
	}

	float y;
	for (int x : range(x_min+1, x_max)) {
		y = pente * x + origine;
		//cout << y << endl;
		if ((int)y == y) {
			std::pair <int, int> point(x, (int)y);
			liste_points.push_back(point);
		}
	}

	return liste_points;
}


void Case::posseder(Piece* ptr) { 
	piece_ = ptr; 
	possedePiece_ = true;
}

void Case::deposseder() { 
	piece_ = nullptr; 
	possedePiece_ = false;
}

void Case::reset() {
	delete piece_;
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