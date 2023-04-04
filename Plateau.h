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
    
private:
    vector<vector<Case>> cases_;
};

