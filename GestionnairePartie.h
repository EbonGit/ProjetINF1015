#pragma once
#include "Plateau.h"
#include "TourDeJeu.h"

using grilleBool = vector<vector<bool>>;
class GestionnairePartie
{
public:
	GestionnairePartie() = default;
	GestionnairePartie(Plateau* plateau) { plateau_ = plateau; };
	void appliquerStrategie();
	void selectionner(Case* c);
	void deselectionner() { caseCourante_ = nullptr; };
	void deplacer(Case* autre);
	bool verifierDeplacement(Case* autre);
	
	void calculDeplacement();
	void calculEnnemi();
	void afficherGrille(); //fonction temporaire pour aider à visualiser
private:
	Plateau* plateau_;
	TourDeJeu tourDeJeu_;
	Case* caseCourante_ = nullptr;

	grilleBool grilleStrategie;
	grilleBool grilleDeplacement;
	grilleBool grilleEnnemi;
};

