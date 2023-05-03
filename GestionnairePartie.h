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
	GestionnairePartie(Gestionnaire* partie, Case* c) : Gestionnaire(partie->getPlateau()) { //uniquement pour la fonction sacrificeRoi()
		setTourDeJeu(partie->getTourDeJeu());
		setParent(partie);
		setCaseCourante(partie->getCaseCourante());
		selectionner(c);
		//deplacer(c);
	};

	Plateau* plateau() { return plateau_; };

	void deplacer(Case*) override;

	void ajoutEchec(Case*);
	void viderEchec();
	void testerEchec();

	void sacrificeRoi(Case*);


private:
	vector<Gestionnaire*> echecs_;
	Plateau* plateau_;
};

