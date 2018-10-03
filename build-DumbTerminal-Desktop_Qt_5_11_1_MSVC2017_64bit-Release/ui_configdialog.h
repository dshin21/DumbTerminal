/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *portSettings;
    QGroupBox *groupBox;
    QLabel *labelBps;
    QComboBox *comboBoxBps;
    QLabel *labelDataBits;
    QComboBox *comboBoxDataBits;
    QLabel *labelParity;
    QComboBox *comboBoxParity;
    QLabel *labelStopBits;
    QComboBox *comboBoxStopBits;
    QLabel *labelPortName;
    QComboBox *comboBoxPortName;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->resize(317, 408);
        buttonBox = new QDialogButtonBox(ConfigDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-40, 360, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget = new QTabWidget(ConfigDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 301, 341));
        portSettings = new QWidget();
        portSettings->setObjectName(QStringLiteral("portSettings"));
        groupBox = new QGroupBox(portSettings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 251, 231));
        labelBps = new QLabel(groupBox);
        labelBps->setObjectName(QStringLiteral("labelBps"));
        labelBps->setGeometry(QRect(10, 30, 91, 16));
        comboBoxBps = new QComboBox(groupBox);
        comboBoxBps->addItem(QString());
        comboBoxBps->addItem(QString());
        comboBoxBps->addItem(QString());
        comboBoxBps->addItem(QString());
        comboBoxBps->setObjectName(QStringLiteral("comboBoxBps"));
        comboBoxBps->setGeometry(QRect(100, 30, 141, 22));
        labelDataBits = new QLabel(groupBox);
        labelDataBits->setObjectName(QStringLiteral("labelDataBits"));
        labelDataBits->setGeometry(QRect(10, 70, 61, 20));
        comboBoxDataBits = new QComboBox(groupBox);
        comboBoxDataBits->addItem(QString());
        comboBoxDataBits->addItem(QString());
        comboBoxDataBits->addItem(QString());
        comboBoxDataBits->addItem(QString());
        comboBoxDataBits->setObjectName(QStringLiteral("comboBoxDataBits"));
        comboBoxDataBits->setGeometry(QRect(100, 70, 141, 22));
        labelParity = new QLabel(groupBox);
        labelParity->setObjectName(QStringLiteral("labelParity"));
        labelParity->setGeometry(QRect(10, 110, 61, 16));
        comboBoxParity = new QComboBox(groupBox);
        comboBoxParity->addItem(QString());
        comboBoxParity->addItem(QString());
        comboBoxParity->addItem(QString());
        comboBoxParity->setObjectName(QStringLiteral("comboBoxParity"));
        comboBoxParity->setGeometry(QRect(100, 110, 141, 22));
        labelStopBits = new QLabel(groupBox);
        labelStopBits->setObjectName(QStringLiteral("labelStopBits"));
        labelStopBits->setGeometry(QRect(10, 150, 61, 16));
        comboBoxStopBits = new QComboBox(groupBox);
        comboBoxStopBits->addItem(QString());
        comboBoxStopBits->addItem(QString());
        comboBoxStopBits->addItem(QString());
        comboBoxStopBits->setObjectName(QStringLiteral("comboBoxStopBits"));
        comboBoxStopBits->setGeometry(QRect(100, 150, 141, 22));
        labelPortName = new QLabel(groupBox);
        labelPortName->setObjectName(QStringLiteral("labelPortName"));
        labelPortName->setGeometry(QRect(10, 190, 71, 16));
        comboBoxPortName = new QComboBox(groupBox);
        comboBoxPortName->addItem(QString());
        comboBoxPortName->addItem(QString());
        comboBoxPortName->addItem(QString());
        comboBoxPortName->addItem(QString());
        comboBoxPortName->setObjectName(QStringLiteral("comboBoxPortName"));
        comboBoxPortName->setGeometry(QRect(100, 190, 141, 22));
        tabWidget->addTab(portSettings, QString());

        retranslateUi(ConfigDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "Communication Properties", nullptr));
        groupBox->setTitle(QString());
        labelBps->setText(QApplication::translate("ConfigDialog", "Bits per scond:", nullptr));
        comboBoxBps->setItemText(0, QApplication::translate("ConfigDialog", "2400", nullptr));
        comboBoxBps->setItemText(1, QApplication::translate("ConfigDialog", "1200", nullptr));
        comboBoxBps->setItemText(2, QApplication::translate("ConfigDialog", "4800", nullptr));
        comboBoxBps->setItemText(3, QApplication::translate("ConfigDialog", "9600", nullptr));

        labelDataBits->setText(QApplication::translate("ConfigDialog", "Data bits:", nullptr));
        comboBoxDataBits->setItemText(0, QApplication::translate("ConfigDialog", "8", nullptr));
        comboBoxDataBits->setItemText(1, QApplication::translate("ConfigDialog", "7", nullptr));
        comboBoxDataBits->setItemText(2, QApplication::translate("ConfigDialog", "6", nullptr));
        comboBoxDataBits->setItemText(3, QApplication::translate("ConfigDialog", "5", nullptr));

        labelParity->setText(QApplication::translate("ConfigDialog", "Parity:", nullptr));
        comboBoxParity->setItemText(0, QApplication::translate("ConfigDialog", "None", nullptr));
        comboBoxParity->setItemText(1, QApplication::translate("ConfigDialog", "Even", nullptr));
        comboBoxParity->setItemText(2, QApplication::translate("ConfigDialog", "Odd", nullptr));

        labelStopBits->setText(QApplication::translate("ConfigDialog", "Stop bits:", nullptr));
        comboBoxStopBits->setItemText(0, QApplication::translate("ConfigDialog", "1", nullptr));
        comboBoxStopBits->setItemText(1, QApplication::translate("ConfigDialog", "1.5", nullptr));
        comboBoxStopBits->setItemText(2, QApplication::translate("ConfigDialog", "2", nullptr));

        labelPortName->setText(QApplication::translate("ConfigDialog", "Connect using:", nullptr));
        comboBoxPortName->setItemText(0, QApplication::translate("ConfigDialog", "COM1", nullptr));
        comboBoxPortName->setItemText(1, QApplication::translate("ConfigDialog", "COM2", nullptr));
        comboBoxPortName->setItemText(2, QApplication::translate("ConfigDialog", "COM3", nullptr));
        comboBoxPortName->setItemText(3, QApplication::translate("ConfigDialog", "COM4", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(portSettings), QApplication::translate("ConfigDialog", "Port Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
