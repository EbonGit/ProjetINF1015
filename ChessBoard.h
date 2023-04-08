#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QLayout>
#include <QButtonGroup>

#include "CaseGraphique.h"
#include "AuditeurVue.h"

#include <iostream>
#include <cppitertools/range.hpp>


class ChessBoard : public QMainWindow
{
	Q_OBJECT;

public:
	ChessBoard(QWidget* parent = nullptr);
	~ChessBoard() override = default;

	CaseGraphique* nouvelleCase(int);

	QButtonGroup* groupeBoutons;

	void resetUI();
	void deplacerPieces(int, int);

	void setAuditeur(AuditeurVue* av) { auditeur_ = av; };

private:
	std::vector<CaseGraphique*> cases;
	AuditeurVue* auditeur_ = nullptr;

public slots:
	void selectionnerCase(int);
	void afficherCasesPostSelection(int, int, int);
	void dessinerPiece(int, int, std::string);
	void dessinerPiece(int, std::string);
	void modifierCase(int, std::string, std::string);
	void requestDeplacement();

};
