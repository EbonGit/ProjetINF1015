#pragma once
#include "Piece.h"
class Tour :
    public Piece
{
public:
    Tour(bool estBlanc);
    void afficher() override;
};

