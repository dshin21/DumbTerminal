/********************************************************************************
** Form generated from reading UI file 'application.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATION_H
#define UI_APPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Application
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionModify_Settings;
    QAction *actionExit;
    QAction *actionHelp;
    QWidget *centralWidget;
    QLineEdit *console;
    QLineEdit *incomingConsole;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Application)
    {
        if (Application->objectName().isEmpty())
            Application->setObjectName(QStringLiteral("Application"));
        Application->resize(912, 496);
        Application->setStyleSheet(QStringLiteral(""));
        actionConnect = new QAction(Application);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(Application);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionModify_Settings = new QAction(Application);
        actionModify_Settings->setObjectName(QStringLiteral("actionModify_Settings"));
        actionExit = new QAction(Application);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHelp = new QAction(Application);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(Application);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        console = new QLineEdit(centralWidget);
        console->setObjectName(QStringLiteral("console"));
        console->setGeometry(QRect(230, 50, 661, 401));
        console->setLayoutDirection(Qt::LeftToRight);
        console->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        console->setInputMethodHints(Qt::ImhNone);
        console->setEchoMode(QLineEdit::Normal);
        console->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        incomingConsole = new QLineEdit(centralWidget);
        incomingConsole->setObjectName(QStringLiteral("incomingConsole"));
        incomingConsole->setGeometry(QRect(10, 50, 191, 401));
        incomingConsole->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        incomingConsole->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 10, 61, 31));
        label->setStyleSheet(QLatin1String("\n"
"background-color: rgb(85, 255, 255);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(530, 9, 51, 31));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(85, 255, 255);"));
        Application->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Application);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 912, 21));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        Application->setMenuBar(menuBar);
        statusBar = new QStatusBar(Application);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Application->setStatusBar(statusBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionConnect);
        menuOptions->addAction(actionDisconnect);
        menuOptions->addAction(actionModify_Settings);
        menuOptions->addAction(actionHelp);
        menuOptions->addAction(actionExit);

        retranslateUi(Application);
        QObject::connect(actionExit, SIGNAL(triggered()), Application, SLOT(close()));

        QMetaObject::connectSlotsByName(Application);
    } // setupUi

    void retranslateUi(QMainWindow *Application)
    {
        Application->setWindowTitle(QApplication::translate("Application", "Dumb Terminal", nullptr));
        actionConnect->setText(QApplication::translate("Application", "Connect", nullptr));
        actionDisconnect->setText(QApplication::translate("Application", "Disconnect", nullptr));
        actionModify_Settings->setText(QApplication::translate("Application", "Modify Settings", nullptr));
        actionExit->setText(QApplication::translate("Application", "Exit", nullptr));
        actionHelp->setText(QApplication::translate("Application", "Help", nullptr));
        label->setText(QApplication::translate("Application", " INCOMING ", nullptr));
        label_2->setText(QApplication::translate("Application", " SENDING", nullptr));
        menuOptions->setTitle(QApplication::translate("Application", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Application: public Ui_Application {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_H
