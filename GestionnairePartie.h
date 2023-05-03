#pragma once

#include "GestionnaireEchec.h"


class GestionnairePartie : 
	public Gestionnaire
{
public:
	GestionnairePartie() = default;
	~GestionnairePartie();
	GestionnairePartie(Plateau* plateau, GestionnaireStatus* p) : Gestionnaire(plateau, p) { 
		testerEchec();
		plateau_ = plateau;
	};

	Plateau* plateau() { return plateau_; };

	void deplacer(Case*) override;

	void ajoutEchec(Case*);
	void viderEchec();
	void testerEchec();


private:
	vector<Gestionnaire*> echecs_;
	Plateau* plateau_;
};

