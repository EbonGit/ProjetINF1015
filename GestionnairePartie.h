#pragma once

#include "GestionnaireEchec.h"
#include "AuditeurVue.h"

class GestionnairePartie : 
	public Gestionnaire,//essayer de passer composite avec une classe parent Gestionnaire et possibilité d'avoir des enfants GestionnaireEchec
	public AuditeurVue
{
public:
	GestionnairePartie() = default;
	~GestionnairePartie();
	GestionnairePartie(Plateau* plateau, GestionnaireStatus* p) : Gestionnaire(plateau, p) { 
		testerEchec();
		plateau->getQt()->setAuditeur(this);
	};


	void cliquer(int, int) override;
	void cliquer(Case*);
	void deplacer(Case*) override;

	void ajoutEchec(Case*);
	void viderEchec();
	void testerEchec();
private:
	vector<Gestionnaire*> echecs_;

};

