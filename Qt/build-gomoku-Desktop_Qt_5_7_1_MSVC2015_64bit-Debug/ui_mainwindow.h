/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
    QAction *action_About;
    QAction *action_Screenshot;
    QWidget *centralWidget;
    QLabel *fieldLabel;
    QLabel *statusLabel;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(16, 37);
        MainWindow->setProperty("fixedSize", QVariant(QSize(400, 465)));
        action_NewGame = new QAction(MainWindow);
        action_NewGame->setObjectName(QStringLiteral("action_NewGame"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        action_Screenshot = new QAction(MainWindow);
        action_Screenshot->setObjectName(QStringLiteral("action_Screenshot"));
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
        menuBar->setGeometry(QRect(0, 0, 16, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(action_Screenshot);
        menuFile->addAction(action_NewGame);
        menuFile->addSeparator();
        menuFile->addAction(action_About);

        retranslateUi(MainWindow);
        QObject::connect(action_NewGame, SIGNAL(triggered()), MainWindow, SLOT(newGame()));
        QObject::connect(action_Screenshot, SIGNAL(triggered()), MainWindow, SLOT(saveScreenshot()));
        QObject::connect(action_About, SIGNAL(triggered()), MainWindow, SLOT(showAboutDialog()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gomoku - Blue vs Red", Q_NULLPTR));
        action_NewGame->setText(QApplication::translate("MainWindow", "New Game", Q_NULLPTR));
        action_About->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        action_Screenshot->setText(QApplication::translate("MainWindow", "Screenshot", Q_NULLPTR));
        fieldLabel->setText(QString());
        statusLabel->setStyleSheet(QApplication::translate("MainWindow", "\n"
"      font-size: 20pt;\n"
"      qproperty-alignment: AlignCenter;\n"
"     ", Q_NULLPTR));
        statusLabel->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
