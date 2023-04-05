#pragma once
#include "Plateau.h"

using grilleBool = vector<vector<bool>>;
class GestionnairePartie
{
public:
	GestionnairePartie() = default;
	GestionnairePartie(Plateau* plateau) { plateau_ = plateau; };
	void appliquerStrategie();
	void selectionner(Case* c) {caseCourante_ = c;};
	
	void calculDeplacement();
	void calculEnnemi();
	void afficherGrille(); //focntion temporaire pour aider à visualiser
private:
	Plateau* plateau_;
	int nombreTour_;
	bool tourEstBlanc_;
	Case* caseCourante_ = nullptr;

	grilleBool grilleStrategie;
	grilleBool grilleDeplacement;
	grilleBool grilleEnnemi;
};

