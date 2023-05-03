#pragma once

#include "GestionnaireEchec.h"


class GestionnairePartie : 
	public Gestionnaire
{
public:
	GestionnairePartie() = default;
	~GestionnairePartie();
	GestionnairePartie(Plateau* plateau) : Gestionnaire(plateau) { 
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

