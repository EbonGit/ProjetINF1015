#pragma once
#include "Plateau.h"
#include "TourDeJeu.h"
#include "GestionnaireStatus.h"

using grilleBool = vector<vector<bool>>;
class Gestionnaire 
{
public:
	//constructeur
	Gestionnaire() = default;
	Gestionnaire(Plateau * plateau, GestionnaireStatus* p) {
		plateau_ = plateau; 
		status_ = p;
	};
	virtual ~Gestionnaire() {};

	//getter setter
	Plateau* getPlateau() { return plateau_; };
	void setTourDeJeu(const TourDeJeu& tdj) { tourDeJeu_ = tdj; };
	void setParent(Gestionnaire* g) { parent = g; };
	Gestionnaire* getParent() { return parent; };
	TourDeJeu& getTourDeJeu() { return tourDeJeu_; };
	void setCaseCourante(Case* c) { caseCourante_ = c; };
	Case* getCaseCourante() { return caseCourante_; };
	GestionnaireStatus* getGestionnaireStatus() { return status_; };

	//strategie
	void appliquerStrategie();

	//selection
	virtual void selectionner(Case * c);
	virtual void deselectionner() {
		caseCourante_ = nullptr; 
		string tour = tourDeJeu_.estBlanc() ? "Tour blanc" : "Tour noir";
		status_->setStatus(tour);
	};

	//ddeplacement
	virtual void deplacer(Case * autre);
	virtual bool verifierDeplacement(Case * autre);

	//echec
	void setEchecB(bool b) { EstEchecB_ = b; };
	void setEchecN(bool b) { EstEchecN_ = b; };
	//void setEchecMat(bool b) { estEchecMat_ = b; };
	void recupererEchecEnfant(bool);

	//calcul grille
	void calculDeplacement();
	void calculEnnemi();
	void afficherGrille(); //fonction temporaire pour aider à visualiser

	grilleBool grilleStrategie;
	grilleBool grilleDeplacement;
	grilleBool grilleEnnemi;
private:
	Plateau* plateau_;
	TourDeJeu tourDeJeu_;
	Case* caseCourante_ = nullptr;
	GestionnaireStatus* status_ = nullptr;

	Gestionnaire* parent = nullptr;

	bool EstEchecB_ = false;
	bool EstEchecN_ = false;
	//bool estEchecMat_ = false;

};

