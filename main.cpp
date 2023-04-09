#include <QApplication>
#include <iostream>
#include <iomanip>
#include "GestionnairePartie.h"

//#include "Calc.hpp"
//#include "CalcWindow.hpp"

#include <QApplication>


using namespace std;

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

const bool blanc = true;

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.
	
	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
	#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char *argv[])
{
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);

	ChessBoard board = ChessBoard(); //interface graphique

	Plateau plateau = Plateau(&board);

	Roi* rb = new Roi(blanc);
	Roi* rn = new Roi(!blanc);

	Fou* fb = new Fou(blanc);
	Fou* fn = new Fou(!blanc);

	Tour* tb = new Tour(blanc);
	Tour* tn = new Tour(!blanc);

	Reine* qb = new Reine(blanc);
	Reine* qn = new Reine(!blanc);

	plateau[6][6].posseder(rb);
	plateau[4][2].posseder(rn);

	plateau[4][6].posseder(fb);
	plateau[0][2].posseder(fn);

	plateau[4][3].posseder(tb);
	plateau[2][6].posseder(tn);

	plateau[0][1].posseder(qb);
	plateau[7][3].posseder(qn);

	plateau.afficher();

	GestionnairePartie gestionnaire = GestionnairePartie(&plateau);

	board.show();
	return app.exec();
	//return 0;
}
