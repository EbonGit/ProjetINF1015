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
	void afficherCasesPostSelection(int, int, int);
	void dessinerPiece(int, int, std::string);
	void dessinerPiece(int, std::string);
	void modifierCase(int, std::string, std::string);
	void showMessage(std::string, std::string, int);
	void setStatusText(std::string);

signals:
	void OnConfigSelected(int);
};
