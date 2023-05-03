#include "GestionnairePartie.h"
#include "ControleurPlateau.h"

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

TEST(Echec, deplacement) {
	GestionnaireStatus status;
	Plateau plateau = Plateau();
	GestionnairePartie gestionnaire = GestionnairePartie(&plateau);
	ChessBoard board = ChessBoard(&status, &gestionnaire); //interface graphique
	ControleurPlateau controllerPlateau(&plateau, &gestionnaire, &board);

	gestionnaire.selectionner(&plateau[0][7]);
	Piece* p = plateau[0][7].piece_;
	gestionnaire.selectionner(&plateau[3][7]);

	EXPECT_EQ(plateau[0][7].piece_, nullptr);
	EXPECT_EQ(plateau[3][7].piece_, p);

}

TEST(Echec, manger_piece) {
	GestionnaireStatus status;
	Plateau plateau = Plateau();
	GestionnairePartie gestionnaire = GestionnairePartie(&plateau);
	ChessBoard board = ChessBoard(&status, &gestionnaire); //interface graphique
	ControleurPlateau controllerPlateau(&plateau, &gestionnaire, &board);

	gestionnaire.selectionner(&plateau[5][4]);
	Piece* p = plateau[5][4].piece_;
	gestionnaire.selectionner(&plateau[1][0]);

	EXPECT_EQ(plateau[5][4].piece_, nullptr);
	EXPECT_EQ(plateau[1][0].piece_, p);

}

TEST(Echec, deplacement_impossible) {
	GestionnaireStatus status;
	Plateau plateau = Plateau();
	GestionnairePartie gestionnaire = GestionnairePartie(&plateau);
	ChessBoard board = ChessBoard(&status, &gestionnaire); //interface graphique
	ControleurPlateau controllerPlateau(&plateau, &gestionnaire, &board);

	gestionnaire.selectionner(&plateau[6][5]);
	Piece* p = plateau[6][5].piece_;
	gestionnaire.selectionner(&plateau[7][7]);

	EXPECT_EQ(plateau[6][5].piece_, p);
	EXPECT_EQ(plateau[7][7].piece_, nullptr);

}

TEST(Echec, deplacement_impossible_sacrifice_roi) {
	GestionnaireStatus status;
	Plateau plateau = Plateau();
	GestionnairePartie gestionnaire = GestionnairePartie(&plateau);
	ChessBoard board = ChessBoard(&status, &gestionnaire); //interface graphique
	ControleurPlateau controllerPlateau(&plateau, &gestionnaire, &board);

	gestionnaire.selectionner(&plateau[5][4]);
	Piece* p = plateau[5][4].piece_;
	gestionnaire.selectionner(&plateau[5][5]);

	EXPECT_EQ(plateau[5][4].piece_, p);
	EXPECT_EQ(plateau[5][5].piece_, nullptr);

}

TEST(Echec, deplacement_impossible_passer_dessus) {
	GestionnaireStatus status;
	Plateau plateau = Plateau();
	GestionnairePartie gestionnaire = GestionnairePartie(&plateau);
	ChessBoard board = ChessBoard(&status, &gestionnaire); //interface graphique
	ControleurPlateau controllerPlateau(&plateau, &gestionnaire, &board);

	gestionnaire.selectionner(&plateau[0][7]);
	Piece* p1 = plateau[0][7].piece_;
	gestionnaire.selectionner(&plateau[1][7]);

	gestionnaire.selectionner(&plateau[1][0]);
	Piece* p2 = plateau[1][0].piece_;
	Piece* p3 = plateau[6][5].piece_;
	gestionnaire.selectionner(&plateau[6][5]);

	EXPECT_EQ(plateau[1][7].piece_, p1);
	EXPECT_EQ(plateau[0][7].piece_, nullptr);
	EXPECT_EQ(plateau[1][0].piece_, p2);
	EXPECT_EQ(plateau[6][5].piece_, p3);

}


#endif