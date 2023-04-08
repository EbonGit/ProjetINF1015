#pragma once
#include "Affichable.h"
#include "Roi.h"
#include "Fou.h"
#include "Tour.h"
#include "Reine.h"

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

	int operator^(const Case&) const; //ici utiliser pour calculer la distance entre 2 points

	bool operator()(const Case& c1, const Case& c2) const;

	Piece* piece_ = nullptr;
private:
	bool estBlanc_;
	bool possedePiece_ = false;
};


