#pragma once
#include "Affichable.h"
#include "Strategie.h"
class Piece :
    public Affichable
{
public:
    Piece() = default;
    virtual void afficher();
    virtual ~Piece() = default;
protected:
    bool couleur_;
    Strategie strategie_;
};

