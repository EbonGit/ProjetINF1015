#pragma once
#include "Case.h"
#include <vector>

class Plateau :
    public Affichable
{
public:
    Plateau(ChessBoard*);
    void afficher() override;
    vector<vector<Case>>& get();
    void init(ChessBoard*);
    vector<Case>& operator[](int i) { return cases_[i]; };

    void choisirConfiguration(int);

private:
    vector<vector<Case>> cases_;
};

