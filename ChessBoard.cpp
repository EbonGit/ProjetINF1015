#include "ChessBoard.h"

using iter::range;


QString generateStyleSheet(std::string bg_color, std::string hover_color) {
	QString sheet = "CaseGraphique {background-color: #";
	sheet.append(bg_color);
	sheet.append("} CaseGraphique:hover{ background-color: #");
	sheet.append(hover_color);
	sheet.append("}");
	return sheet;
}

void ChessBoard::resetUI() {
	QString path = "./chess_maestro_bw/";
	path.append("empty.png");
	QIcon icon(path);
	for (int i : range(64)) {
		if (cases[i]->get_side() == 1) {
			cases[i]->setStyleSheet(generateStyleSheet("779556", "4e6238"));
		}
		else {
			cases[i]->setStyleSheet(generateStyleSheet("eeeed2", "bbbba5"));
		}
		
		cases[i]->setIcon(icon);
	}
}

CaseGraphique* ChessBoard::nouvelleCase(int side) {
	auto case_graphique = new CaseGraphique(side, this);
	case_graphique->setFixedSize(60, 60);
	case_graphique->setIconSize(QSize(60, 60));

	if (side == 1) {
		case_graphique->setStyleSheet(generateStyleSheet("779556", "4e6238"));
	}
	else
	{
		case_graphique->setStyleSheet(generateStyleSheet("eeeed2", "bbbba5"));
	}
	return case_graphique;
}

ChessBoard::ChessBoard(QWidget* parent) :
	QMainWindow(parent)
{

	auto widgetPrincipal = new QWidget(this);
	auto layoutPrincipal = new QVBoxLayout(widgetPrincipal);

	auto grid_layout = new QGridLayout();
	grid_layout->setSpacing(0);
	layoutPrincipal->addLayout(grid_layout);

	groupeBoutons = new QButtonGroup(this);

	for (int i : range(8)) {
		std::vector<CaseGraphique*> v;
		for (int j : range(8)) {
			int side = (i + j) % 2 == 0 ? 1 : 0;
			auto case_graphique = nouvelleCase(side);
			groupeBoutons->addButton(case_graphique, i * 8 + j); // L'ID du bouton est i (doit être un entier).
			grid_layout->addWidget(case_graphique, i, j, 1, 1);
			cases.push_back(case_graphique);
		}
	}

	QObject::connect(groupeBoutons, &QButtonGroup::idClicked, this, &ChessBoard::selectionnerCase); // ajouterChiffre prend un int, donc le ID du bouton est bon directement.

	//QPushButton* btn = new QPushButton("Deplacer");
	//layoutPrincipal->addWidget(btn);
	//QObject::connect(btn, &QPushButton::clicked, this, &ChessBoard::requestDeplacement);


	setCentralWidget(widgetPrincipal);
	setWindowTitle("ChessBoard");

}

// Doit appeller la fonction correpondante sur le controlleur
void ChessBoard::selectionnerCase(int id) {
	int x = id % 8;
	int y = id / 8;
	std::cout << "(" << x << ", " << y << ")" << std::endl;
	auditeur_->cliquer(x, y);
}

// Doit mettre à jour le plateau en prenant en paramètre le plateau (vector<vector<Case>>)
// color = 1 peut bouger, color = 0 ne peut pas, color = 2 peut manger
void ChessBoard::afficherCasesPostSelection(int x, int y, int color) {

	int id = y * 8 + x;
	if (color == 0) {
		modifierCase(id, "999999", "242633");
	}
	else if (color == 1) {
		modifierCase(id, "4E95F2", "12337A");
	}
	else {
		modifierCase(id, "F44949", "750000");
	}
}

void ChessBoard::modifierCase(int id, std::string color1, std::string color2) {
	cases[id]->setStyleSheet(generateStyleSheet(color1, color2));
}

void ChessBoard::dessinerPiece(int x, int y, std::string piece) {
	int id = x + y * 8;
	QString path = "./chess_maestro_bw/";
	path.append(piece);
	path.append(".png");
	QIcon icon(path);
	cases[id]->setIcon(icon);
}

void ChessBoard::dessinerPiece(int id, std::string piece) {
	QString path = "./chess_maestro_bw/";
	path.append(piece);
	path.append(".png");
	QIcon icon(path);
	cases[id]->setIcon(icon);
}

void ChessBoard::requestDeplacement() {
	//deplacerPieces(2, 3);
}

void ChessBoard::deplacerPieces(int ancienne, int nouvelle) {
	cases[nouvelle]->setIcon(cases[ancienne]->icon());
	cases[ancienne]->setIcon(QIcon());
}