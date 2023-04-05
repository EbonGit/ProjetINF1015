#pragma once
#include "Piece.h"
class Tour :
    public Piece
{
public:
    Tour(bool estBlanc) : Piece(estBlanc) {};
    void afficher() override;
};

