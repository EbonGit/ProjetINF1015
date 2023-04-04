#pragma once
#include "Piece.h"
class Roi :
    public Piece
{
public:
    Roi() = default;
    void afficher() override;
};

