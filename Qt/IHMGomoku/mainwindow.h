#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPixmap>
#include <QPainter>
#include <QMessageBox>
#include <QDebug>
#include <QDialog>
#include <map>
#include "Gomoku.h"
#include "IA.hh"

namespace Ui {
class MainWindow;
}

//TODO dynamic board size
#define FIELDS_WIDTH 19
#define FIELDS_HEIGHT 19
#define FIELD_XY 25

#define IMAGE_FIELD_CIRCLE "/images/circle.png"
#define IMAGE_FIELD_CROSS "/images/cross.png"
#define IMAGE_ICON "/images/icon.png"
#define MUSIC "/images/Young.mp3"
#define STATUS_TEXT_CIJOUEUR1 "Joueur 1"
#define STATUS_TEXT_CRJOUEUR2 "Joueur 2"

enum Player : uchar
{
	NO_PLAYER = 0,
	CIRCLE = 1,
	CROSS = 2,
};

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = 0);
	~MainWindow();

	bool eventFilter(QObject* object, QEvent* event);
    void showWinner(char winner);
    void FillTab(std::map<int,char> board);
    //void loop(int db, int cc, int ian, int iat);

public slots:
	void newGame();

private:
    Ui::MainWindow *ui;

    uchar fields[FIELDS_WIDTH][FIELDS_HEIGHT];
    int nombreCase;

    QPixmap canvas;

    Player turn;
    uchar winner;

    QString _j1;
    QString _j2;

    void initialize(); // used to reset the game
    void draw();
    void fieldClicked(int x, int y);
    void questionIA();
    void questionDoubleTrois();
    void questionCinqCassable();
    void questionOrbreAI();

    bool  _regleDoubleTrois;
    bool  _regleCinqCassable;
    bool  _IA;
    int   _ta;
    bool  _Running;
    int   cap[2];
    std::map<int, char> tabArbitre;
};

#endif // MAINWINDOW_H
