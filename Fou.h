#pragma once
#include "Piece.h"
class Fou :
    public Piece
{
public:
    Fou(bool estBlanc) : Piece(estBlanc) {};
    void afficher() override;
};

