#pragma once
class TourDeJeu
{
public:
	TourDeJeu();
	void operator++();
	//void incremente();
	bool estBlanc() const { return tourEstBlanc_; };
	bool estFini() const { return tourEstFini_; };
	int numero() const { return numeroTour_; };
private:
	int numeroTour_;
	bool tourEstBlanc_;
	bool tourEstFini_;
};

