#pragma once

#include "GestionnaireEchec.h"
#include "AuditeurVue.h"

class GestionnairePartie : 
	public Gestionnaire,
	public AuditeurVue
{
public:
	GestionnairePartie() = default;
	~GestionnairePartie();
	GestionnairePartie(Plateau* plateau, GestionnaireStatus* p) : Gestionnaire(plateau, p) { 
		testerEchec();
		plateau->getQt()->setAuditeur(this);
		plateau_ = plateau;
	};

	Plateau* plateau() { return plateau_; };

	void cliquer(int, int) override;
	void cliquer(Case*);
	void deplacer(Case*) override;

	void ajoutEchec(Case*);
	void viderEchec();
	void testerEchec();


private:
	vector<Gestionnaire*> echecs_;
	Plateau* plateau_;
};

