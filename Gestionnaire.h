#pragma once
#include "Plateau.h"
#include "TourDeJeu.h"

using grilleBool = vector<vector<bool>>;
class Gestionnaire
{
public:
	Gestionnaire() = default;
	Gestionnaire(Plateau * plateau) { plateau_ = plateau; };
	Plateau* getPlateau() { return plateau_; };
	void setTourDeJeu(const TourDeJeu& tdj) { tourDeJeu_ = tdj; };
	void setParent(Gestionnaire* g) { parent = g; };
	TourDeJeu& getTourDeJeu() { return tourDeJeu_; };
	void appliquerStrategie();
	void selectionner(Case * c);
	void deselectionner() { caseCourante_ = nullptr; };
	void deplacer(Case * autre);
	bool verifierDeplacement(Case * autre);

	void setEchec(bool b) { estEchec_ = b; };
	void setEchecMat(bool b) { estEchecMat_ = b; };

	void calculDeplacement();
	void calculEnnemi();
	void afficherGrille(); //fonction temporaire pour aider à visualiser
private:
	Plateau* plateau_;
	TourDeJeu tourDeJeu_;
	Case* caseCourante_ = nullptr;

	Gestionnaire* parent = nullptr;

	bool estEchec_ = false;
	bool estEchecMat_ = false;

	grilleBool grilleStrategie;
	grilleBool grilleDeplacement;
	grilleBool grilleEnnemi;
};

