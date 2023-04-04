#pragma once
#include <iostream>
using namespace std;
class Affichable
{
public:
	Affichable() = default;
	virtual void afficher() = 0;
	virtual ~Affichable() = default;
};

