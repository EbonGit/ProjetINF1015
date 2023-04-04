#pragma once
#include "Affichable.h"
class Case : public Affichable
{
public:
	Case() = default;
	Case(int, int, bool);
	int x, y;
	bool estBlanc() { return estBlanc_; };
	void afficher() override;
private:
	bool estBlanc_;
};

