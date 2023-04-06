#pragma once
#include "GestionnaireEchec.h"
class GestionnairePartie : public Gestionnaire//essayer de passer composite avec une classe parent Gestionnaire et possibilité d'avoir des enfants GestionnaireEchec
{
public:
	GestionnairePartie() = default;
	~GestionnairePartie();
	GestionnairePartie(Plateau* plateau) : Gestionnaire(plateau) {};
	void ajoutEchec(Case*);
	void viderEchec() { echecs_.clear(); };
	void testerEchec();
private:
	vector<Gestionnaire*> echecs_;
};

