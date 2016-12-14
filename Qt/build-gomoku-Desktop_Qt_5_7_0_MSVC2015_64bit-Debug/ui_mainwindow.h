/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_NewGame;
    QAction *action_DoubleTrois;
    QAction *action_CinqCassable;
    QWidget *centralWidget;
    QLabel *fieldLabel;
    QLabel *statusLabel;
    QMenuBar *menuBar;
    QMenu *menuGame;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(575, 37);
        MainWindow->setProperty("fixedSize", QVariant(QSize(400, 465)));
        action_NewGame = new QAction(MainWindow);
        action_NewGame->setObjectName(QStringLiteral("action_NewGame"));
        action_DoubleTrois = new QAction(MainWindow);
        action_DoubleTrois->setObjectName(QStringLiteral("action_DoubleTrois"));
        action_CinqCassable = new QAction(MainWindow);
        action_CinqCassable->setObjectName(QStringLiteral("action_CinqCassable"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        fieldLabel = new QLabel(centralWidget);
        fieldLabel->setObjectName(QStringLiteral("fieldLabel"));
        fieldLabel->setGeometry(QRect(12, 55, 375, 375));
        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(0, 0, 400, 40));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 575, 21));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuGame->menuAction());
        menuGame->addAction(action_NewGame);
        menuGame->addSeparator();
        menuGame->addAction(action_DoubleTrois);
        menuGame->addAction(action_CinqCassable);

        retranslateUi(MainWindow);
        QObject::connect(action_NewGame, SIGNAL(triggered()), MainWindow, SLOT(newGame()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gomoku", 0));
        action_NewGame->setText(QApplication::translate("MainWindow", "New Game", 0));
        action_DoubleTrois->setText(QApplication::translate("MainWindow", "DoubleTrois", 0));
#ifndef QT_NO_TOOLTIP
        action_DoubleTrois->setToolTip(QApplication::translate("MainWindow", "Regle Double Trois", 0));
#endif // QT_NO_TOOLTIP
        action_CinqCassable->setText(QApplication::translate("MainWindow", "CinqCassable", 0));
#ifndef QT_NO_TOOLTIP
        action_CinqCassable->setToolTip(QApplication::translate("MainWindow", "R\303\251gle CinqCassable", 0));
#endif // QT_NO_TOOLTIP
        fieldLabel->setText(QString());
        statusLabel->setStyleSheet(QApplication::translate("MainWindow", "\n"
"      font-size: 20pt;\n"
"      qproperty-alignment: AlignCenter;\n"
"     ", 0));
        statusLabel->setText(QString());
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
