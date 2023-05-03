#pragma once
#include<QObject>
#include "Gestionnaire.h"
#include "Plateau.h"
#include "ChessBoard.h"

class ControleurPlateau : public QObject
{
	Q_OBJECT;
public:
	ControleurPlateau(Plateau* p, Gestionnaire* g, ChessBoard* chess) { 
		plateau_ = p; 
		gestionnaire_ = g;
		QObject::connect(chess, &ChessBoard::OnConfigSelected, this, &ControleurPlateau::OnConfigReceived);
	};

private:
	Plateau* plateau_ = nullptr;
	Gestionnaire* gestionnaire_;

public slots:
	void OnConfigReceived(int);
};

