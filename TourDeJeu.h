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
	void setEstBlanc(bool b) { tourEstBlanc_ = b; };
private:
	int numeroTour_;
	bool tourEstBlanc_;
	bool tourEstFini_;
};

