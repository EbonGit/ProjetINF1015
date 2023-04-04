#pragma once
#include "Affichable.h"
#include "Case.h"
#include <vector>

class Plateau :
    public Affichable
{
public:
    Plateau();
    void afficher() override;
    vector<vector<Case>>& get();
    void init();
    vector<Case>& operator[](int i) { return cases_[i]; };
    
private:
    vector<vector<Case>> cases_;
};

