#pragma once
#include "Affichable.h"
#include "Strategie.h"
class Piece :
    public Affichable
{
public:
    Piece(bool estBlanc) {
        estBlanc_ = estBlanc;
    };
    virtual void afficher() = 0;
    virtual ~Piece() = default;
    Strategie& getStrat() { return strategie_; };
    bool estBlanc() { return estBlanc_; };
protected:
    bool estBlanc_;
    Strategie strategie_;
};

