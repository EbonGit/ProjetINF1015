#pragma once
#include "GestionnaireEchec.h"
class GestionnairePartie : public Gestionnaire//essayer de passer composite avec une classe parent Gestionnaire et possibilité d'avoir des enfants GestionnaireEchec
{
public:
	GestionnairePartie() = default;
	~GestionnairePartie();
	GestionnairePartie(Plateau* plateau) : Gestionnaire(plateau) { testerEchec(); };

	void deplacer(Case*) override;

	void ajoutEchec(Case*);
	void viderEchec();
	void testerEchec();
private:
	vector<Gestionnaire*> echecs_;
};

