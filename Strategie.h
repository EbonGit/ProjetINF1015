#pragma once
#include <vector>
#include <string>
#include <functional>

class Strategie
{
public:
	Strategie() = default;
	//TODO creer constructeur
	bool appliquer() { return true; };
protected:
	std::string nomStrat_;
	std::function<bool(int, int, int, int)> strat_;
};

