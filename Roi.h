#pragma once
#include "Piece.h"
class Roi :
    public Piece
{
public:
    Roi(bool estBlanc);
    void afficher() override;
};

