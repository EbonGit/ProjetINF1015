#pragma once
#include "Affichable.h"
#include "Roi.h"
#include "Fou.h"
#include "Tour.h"

class Case : public Affichable
{
public:
	Case() = default;
	Case(int, int, bool);
	~Case();
	int x, y;
	bool estBlanc() { return estBlanc_; };
	void afficher() override;

	void posseder(Piece* ptr);
	void deposseder();
	
	void setPossedePiece(bool b) { possedePiece_ = b; };
	bool getPossedePiece() { return possedePiece_; };

	Piece* piece_ = nullptr;
private:
	bool estBlanc_;
	bool possedePiece_ = false;
};

