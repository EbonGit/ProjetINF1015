#pragma once
#include "Affichable.h"
class Piece :
    public Affichable
{
public:
    Piece() = default;
    virtual void afficher();
    virtual ~Piece() = default;
protected:
    bool couleur_;
};

