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

//convertir bool en string pour le nom du .png de la piece
std::string bool_en_string(bool b)
{
	if (b) {
		return "1";
	}
	return "0";
}

void ChessBoard::resetUI() {
	for (int i : range(64)) {
		if (cases[i]->get_side() == 1) {
			cases[i]->setStyleSheet(generateStyleSheet(couleurCaseVertClair, couleurCaseVertFonce));
		}
		else {
			cases[i]->setStyleSheet(generateStyleSheet(couleurCaseBeigeClair, couleurCaseBeigeFonce));
		}
		int x = i % 8;
		int y = i / 8;

		if (gestionnairePartie_->grilleDeplacement[y][x] && gestionnairePartie_->verifierDeplacement(&(*plateau_)[y][x])) {
			cases[i]->setStyleSheet(generateStyleSheet(couleurCaseBleuClair, couleurCaseBleuFonce));
		}

		if (gestionnairePartie_->grilleEnnemi[y][x] && gestionnairePartie_->verifierDeplacement(&(*plateau_)[y][x])) {
			cases[i]->setStyleSheet(generateStyleSheet(couleurCaseRougeClair, couleurCaseRougeFonce));
		}
		
		if ((*plateau_)[y][x].getPossedePiece()) {
			Piece* piece = (*plateau_)[y][x].piece_;
			string nomPiece = piece->nom() + bool_en_string(piece->estBlanc());
			dessinerPiece(x, y, nomPiece);
		}
		else {
			cases[i]->setIcon(QIcon());
		}
	}

	resetStatus();
}

void ChessBoard::resetStatus() {
	if (gestionnairePartie_->getTourDeJeu().estBlanc()) {
		status_->setStatus("Tour blanc");
	}
	else {
		status_->setStatus("Tour noir");
	}

	if (gestionnairePartie_->getEchecB()) {
		status_->setStatus(status_->getCurrentStatus() + ", echec roi blanc");
	}

	if (gestionnairePartie_->getEchecN()) {
		status_->setStatus(status_->getCurrentStatus() + ", echec roi noir");
	}
}

CaseGraphique* ChessBoard::nouvelleCase(int side) {
	auto case_graphique = new CaseGraphique(side, this);
	case_graphique->setFixedSize(60, 60);
	case_graphique->setIconSize(QSize(60, 60));

	if (side == 1) {
		case_graphique->setStyleSheet(generateStyleSheet(couleurCaseVertClair, couleurCaseVertFonce));
	}
	else
	{
		case_graphique->setStyleSheet(generateStyleSheet(couleurCaseBeigeClair, couleurCaseBeigeFonce));
	}
	return case_graphique;
}

ChessBoard::ChessBoard(GestionnaireStatus* p, Gestionnaire* g, QWidget* parent) :
	QMainWindow(parent)
{
	status_ = p;
	gestionnairePartie_ = g;
	plateau_ = gestionnairePartie_->getPlateau();
	auto widgetPrincipal = new QWidget(this);
	auto layoutPrincipal = new QVBoxLayout(widgetPrincipal);
	
	// label status
	statusLabel = new QLabel(this);
	statusLabel->setText("Tour blanc");
	statusLabel->setAlignment(Qt::AlignCenter);
	QFont f("Consolas", 10, QFont::Bold);
	statusLabel->setFont(f);

	// horizontal spacer
	QFrame* horizontalFrameLine = new QFrame();
	horizontalFrameLine->setFrameShape(QFrame::HLine);

	// cases
	auto grid_layout = new QGridLayout();
	grid_layout->setSpacing(0);
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

	// Menu
	auto menu_layout = new QHBoxLayout();

	// Bouton Rejouer
	QPushButton* menuButton = new QPushButton();
	menuButton->setText("Rejouer");

	// Combobox for choosing options
	positionsList = new QComboBox();
	positionsList->addItem("Queens Only");
	positionsList->addItem("Queens vs two rooks");
	positionsList->addItem("Two rooks vs two minor pieces");
	

	// adding to the layout
	menu_layout->addWidget(positionsList);
	menu_layout->addWidget(menuButton);

	layoutPrincipal->addWidget(statusLabel);
	layoutPrincipal->addWidget(horizontalFrameLine);
	layoutPrincipal->addLayout(grid_layout);
	layoutPrincipal->addLayout(menu_layout);

	QObject::connect(groupeBoutons, &QButtonGroup::idClicked, this, &ChessBoard::selectionnerCase); // ajouterChiffre prend un int, donc le ID du bouton est bon directement.
	QObject::connect(status_, &GestionnaireStatus::updateStatus, this, &ChessBoard::setStatusText);
	QObject::connect(menuButton, &QPushButton::clicked, this, &ChessBoard::selectConfig);

	setCentralWidget(widgetPrincipal);
	setWindowTitle("ChessBoard");

}

// Doit appeller la fonction correpondante sur le controlleur
void ChessBoard::selectionnerCase(int id) {
	int x = id % 8;
	int y = id / 8;
	std::cout << "(" << x << ", " << y << ")" << std::endl;
	gestionnairePartie_->selectionner(&(*plateau_)[y][x]);

	resetUI();
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

void ChessBoard::deplacerPieces(int ancienne, int nouvelle) {
	cases[nouvelle]->setIcon(cases[ancienne]->icon());
	cases[ancienne]->setIcon(QIcon());
}

void ChessBoard::setStatusText(std::string status) {
	const QString text = status.c_str();
	statusLabel->setText(text);
}

void ChessBoard::selectConfig() {
	//std::cout << "we selected : " << positionsList->currentIndex() << std::endl;
	emit OnConfigSelected(positionsList->currentIndex());
	resetUI();
}

void ChessBoard::show() {
	QWidget::show();
	resetUI();
}