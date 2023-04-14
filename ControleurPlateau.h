#pragma once
#include<QObject>
#include "Plateau.h"

class ControleurPlateau : public QObject
{
	Q_OBJECT;
public:
	ControleurPlateau(Plateau* p) { 
		plateau_ = p; 
		QObject::connect(p->getQt(), &ChessBoard::OnConfigSelected, this, &ControleurPlateau::OnConfigReceived);
	};

private:
	Plateau* plateau_ = nullptr;

public slots:
	void OnConfigReceived(int);
};

