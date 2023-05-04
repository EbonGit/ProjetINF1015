#pragma once
#include "Case.h"
#include <vector>

const int nombreCaseLigne = 8;
const int nombreCaseColonne = 8;
const int nombreCase = 64;

class Plateau :
    public Affichable
{

public:
    Plateau();
    void init();
    void afficher() override;
    vector<vector<Case>>& get();
    vector<Case>& operator[](int i) { return cases_[i]; };
    void viderPlateau();
    void chargerConfiguration(int);

private:
    vector<vector<Case>> cases_;
};

