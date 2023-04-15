#pragma once
#include<QObject>
#include "Gestionnaire.h"
#include "Plateau.h"

class ControleurPlateau : public QObject
{
	Q_OBJECT;
public:
	ControleurPlateau(Plateau* p, Gestionnaire* g) { 
		plateau_ = p; 
		gestionnaire_ = g;
		QObject::connect(p->getQt(), &ChessBoard::OnConfigSelected, this, &ControleurPlateau::OnConfigReceived);
	};

private:
	Plateau* plateau_ = nullptr;
	Gestionnaire* gestionnaire_;

public slots:
	void OnConfigReceived(int);
};

