#pragma once
#include "Piece.h"
class Reine :
    public Piece
{
public:
    Reine(bool estBlanc);
    void afficher() override;
};

