#pragma once
#include "Gestionnaire.h"
class GestionnaireEchec :
    public Gestionnaire
{
public:
    GestionnaireEchec() = default;
    GestionnaireEchec(Gestionnaire* partie, Case* c) : Gestionnaire(partie->getPlateau(), partie->getGestionnaireStatus()) { 
        setTourDeJeu(partie->getTourDeJeu());
        selectionner(c); 
        setParent(partie);
    };
    void selectionner(Case*) override;
    void tester();
    void remonterEchecParent();
};

