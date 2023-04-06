#pragma once
#include "GestionnaireEchec.h"
class GestionnairePartie : public Gestionnaire//essayer de passer composite avec une classe parent Gestionnaire et possibilit� d'avoir des enfants GestionnaireEchec
{
public:
	GestionnairePartie() = default;
	GestionnairePartie(Plateau* plateau) : Gestionnaire(plateau) {};
	void ajoutEchec(Case*);
	void viderEchec() { echecs_.clear(); };

	
private:
	vector<Gestionnaire> echecs_;
};

