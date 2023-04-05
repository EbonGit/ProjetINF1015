#pragma once
#include <vector>
#include <string>
#include <functional>

class Strategie
{
public:
	Strategie() = default;
	//TODO creer constructeur
	bool appliquer(int x, int y, int x_autre, int y_autre) { return strat_(x, y, x_autre, y_autre); };
	void setStrat(std::function<bool(int, int, int, int)> f) { strat_ = f; };
private:
	std::string nomStrat_;
	std::function<bool(int, int, int, int)> strat_ = [](int, int, int, int) -> bool { return true; };
};

