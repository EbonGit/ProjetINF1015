#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QLayout>
#include <QButtonGroup>
#include <QMessageBox>
#include <QComboBox>

#include "CaseGraphique.h"
#include "GestionnaireStatus.h"

#include <iostream>
#include <cppitertools/range.hpp>

#include "Gestionnaire.h"

const std::string couleurCaseVertClair = "779556";
const std::string couleurCaseVertFonce = "4e6238";
const std::string couleurCaseBeigeClair = "eeeed2";
const std::string couleurCaseBeigeFonce = "bbbba5";
const std::string couleurCaseBleuClair = "388FFF";
const std::string couleurCaseBleuFonce = "2661AD";
const std::string couleurCaseRougeClair = "FA2E2E";
const std::string couleurCaseRougeFonce = "C42525";


class ChessBoard : public QMainWindow
{
	Q_OBJECT;

public:
	ChessBoard(GestionnaireStatus* p, Gestionnaire* g, QWidget* parent = nullptr);
	~ChessBoard() override = default;

	CaseGraphique* nouvelleCase(int);
	QButtonGroup* groupeBoutons;

	void show();

	void resetUI();
	void resetStatus();
	void deplacerPieces(int, int);
	void selectConfig();

private:
	std::vector<CaseGraphique*> cases;
	GestionnaireStatus* status_ = nullptr;
	Plateau* plateau_;
	Gestionnaire* gestionnairePartie_;
	QLabel* statusLabel = nullptr;
	QComboBox* positionsList = nullptr;

public slots:
	void selectionnerCase(int);
	void dessinerPiece(int, int, std::string);
	void dessinerPiece(int, std::string);
	void modifierCase(int, std::string, std::string);
	void setStatusText(std::string);

signals:
	void OnConfigSelected(int);
};
